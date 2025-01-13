import cplex
from cplex.exceptions import CplexError

def optimize_traffic_signal_cplex(queue_lengths, waiting_times):
    # Number of intersections, phases, lanes, and time steps
    num_intersections = 4
    num_phases = 2  # Assuming dual-ring phases
    num_lanes = 3
    num_time_steps = len(queue_lengths[0])  # Assuming queue_lengths and waiting_times have the same length

    # Additional input parameters
    signal_cycle_time = 100  # Signal cycle time (s)
    vehicle_speed = 50  # Vehicle speed (km/h)
    distance_between_intersections = 500  # Distance between intersections (m)

    # Create CPLEX problem
    prob = cplex.Cplex()

    # Set objective: minimize total waiting time
    prob.objective.set_sense(prob.objective.sense.minimize)

    # Add g, r, and y variables
    g_var_names = [f'g_{i+1}_{j+1}_{t+1}' for i in range(num_intersections) for j in range(num_phases) for t in range(num_time_steps)]
    r_var_names = [f'r_{i+1}_{j+1}_{t+1}' for i in range(num_intersections) for j in range(num_phases) for t in range(num_time_steps)]
    y_var_names = [f'y_{i+1}_{j+1}_{t+1}' for i in range(num_intersections) for j in range(num_phases) for t in range(num_time_steps)]

    # Add g, r, and y variables
    prob.variables.add(names=g_var_names, types='I'*len(g_var_names), lb=[0]*len(g_var_names), ub=[signal_cycle_time]*len(g_var_names))
    prob.variables.add(names=r_var_names, types='I'*len(r_var_names), lb=[0]*len(r_var_names), ub=[signal_cycle_time]*len(r_var_names))
    prob.variables.add(names=y_var_names, types='I'*len(y_var_names), lb=[0]*len(y_var_names), ub=[5]*len(y_var_names))

    
    # Vehicle movement constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for k in range(num_lanes):
                for t in range(num_time_steps):
                    v_index = f'v_{i+1}_{j+1}_{k+1}_{t+1}'
                    w_index = f'w_{i+1}_{k+1}_{t+1}'

                    prob.variables.add(obj=[1], names=[v_index])
                    prob.variables.add(obj=[-1], names=[w_index])

                    prob.linear_constraints.add(
                        lin_expr=[[v_index, 1]],
                        senses=['L'],
                        rhs=[0]
                    )

                    prob.linear_constraints.add(
                        lin_expr=[[w_index, -1]],
                        senses=['L'],
                        rhs=[0]
                    )


    # Minimum and maximum phase durations
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                prob.linear_constraints.add(lin_expr=[[[f'g_{i+1}_{j+1}_{t+1}'], [1]], [[f'r_{i+1}_{j+1}_{t+1}'], [1]]], senses=['G', 'G'], rhs=[8, 8])
                prob.linear_constraints.add(lin_expr=[[[f'y_{i+1}_{j+1}_{t+1}'], [1]]], senses=['L'], rhs=[5])

    # Lane occupancy constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                for k in range(num_lanes):
                    indices = [f'v_{i+1}_{j+1}_{k+1}_{t+1}', f'g_{i+1}_{j+1}_{t+1}']
                    values = [1, -1]
                    prob.linear_constraints.add(lin_expr=[[[indices, values]], [[f'v_{i+1}_{j+1}_{k+1}_{t+1}'], [1]]], senses=['L', 'L'], rhs=[0, 0])

    # Vehicle movement constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                indices = [f'v_{i+1}_{j+1}_{k+1}_{t+1}' for k in range(num_lanes)]
                values = [1] * num_lanes
                prob.linear_constraints.add(lin_expr=[[[indices, values]], [[f'v_{i+1}_{j+1}_{k+1}_{t+1}' for k in range(num_lanes)], [1] * num_lanes]], senses=['E', 'E'], rhs=[1, 1])

    # Waiting time constraints
    for i in range(num_intersections):
        for t in range(num_time_steps):
            for k in range(num_lanes):
                indices = [f'w_{i+1}_{k+1}_{t+1}', *[f'g_{i+1}_{j+1}_{t+1}' for j in range(num_phases)]]
                values = [1, -1] * num_phases
                prob.linear_constraints.add(lin_expr=[[[indices, values]], [[f'w_{i+1}_{k+1}_{t+1}'], [1]]], senses=['G', 'L'], rhs=[0, distance_between_intersections / vehicle_speed])

    # Solve the problem
    try:
        prob.solve()
    except CplexError as exc:
        print(exc)
        return "No optimal solution found."

    # Extract and return the optimal values
    result = {}
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                result[f'Intersection_{i+1}_Phase_{j+1}_Time_{t+1}'] = {
                    'Green Duration': prob.solution.get_values(f'g_{i+1}_{j+1}_{t+1}'),
                    'Red Duration': prob.solution.get_values(f'r_{i+1}_{j+1}_{t+1}'),
                    'Yellow Duration': prob.solution.get_values(f'y_{i+1}_{j+1}_{t+1}'),
                    'Lane Information': {
                        f'Lane_{k+1}': {
                            'Movement Allowed': prob.solution.get_values(f'v_{i+1}_{j+1}_{k+1}_{t+1}'),
                            'Waiting Time': prob.solution.get_values(f'w_{i+1}_{k+1}_{t+1}')
                        } for k in range(num_lanes)
                    }
                }
    return result

# Example usage with queue lengths and waiting times
queue_lengths_example = [
    [
        [10, 12, 15],
        [8, 10, 12],
        [15, 18, 20],
        [12, 14, 16]
    ],
    [
        [14, 16, 18],
        [10, 12, 14],
        [20, 22, 25],
        [18, 20, 22]
    ],
    [
        [8, 10, 12],
        [6, 8, 10],
        [12, 15, 18],
        [10, 12, 14]
    ],
    [
        [12, 14, 16],
        [9, 11, 13],
        [16, 20, 22],
        [14, 16, 18]
    ]
]

waiting_times_example = [
    [
        [2, 3, 4],
        [1, 2, 3],
        [3, 4, 5],
        [2, 3, 4]
    ],
    [
        [3, 4, 5],
        [2, 3, 4],
        [5, 6, 7],
        [4, 5, 6]
    ],
    [
        [1, 2, 3],
        [0, 1, 2],
        [2, 3, 4],
        [1, 2, 3]
    ],
    [
        [2, 3, 4],
        [1, 2, 3],
        [4, 5, 6],
        [3, 4, 5]
    ]
]

result = optimize_traffic_signal_cplex(queue_lengths_example, waiting_times_example)
print(result)