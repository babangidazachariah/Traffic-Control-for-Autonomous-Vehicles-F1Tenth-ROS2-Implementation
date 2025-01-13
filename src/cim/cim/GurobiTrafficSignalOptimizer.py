from gurobipy import *

def optimize_traffic_signal(queue_lengths, waiting_times):
    # Number of intersections, phases, lanes, and time steps
    num_intersections = 4 #len(queue_lengths)
    num_phases = 4  # Assuming dual-ring phases
    num_lanes = 1 #len(queue_lengths[0][0])
    num_time_steps = 1 # len(queue_lengths[0])

    # Additional input parameters
    signal_cycle_time = 100  # Signal cycle time (s)
    vehicle_speed = 50  # Vehicle speed (km/h)
    distance_between_intersections = 500  # Distance between intersections (m)
    max_yellow_duration = 5  # Maximum yellow duration (s)

    # Create Gurobi model
    model = Model("TrafficSignalOptimization")

    # Define decision variables
    g = {}
    r = {}
    y = {}
    v = {}
    w = {}

    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                g[i, j, t] = model.addVar(lb=0, ub=signal_cycle_time, name=f'g_{i+1}_{j+1}_{t+1}')
                r[i, j, t] = model.addVar(lb=0, ub=signal_cycle_time, name=f'r_{i+1}_{j+1}_{t+1}')
                y[i, j, t] = model.addVar(lb=0, ub=max_yellow_duration, name=f'y_{i+1}_{j+1}_{t+1}')

                for k in range(num_lanes):
                    v[i, j, k, t] = model.addVar(vtype=GRB.BINARY, name=f'v_{i+1}_{j+1}_{k+1}_{t+1}')
                    w[i, k, t] = model.addVar(lb=0, name=f'w_{i+1}_{k+1}_{t+1}')

    # Set objective: minimize total waiting time
    model.setObjective(quicksum(w[i, k, t] for i in range(num_intersections) for k in range(num_lanes) for t in range(num_time_steps)), GRB.MINIMIZE)

    # Intersection constraints
    for i in range(num_intersections):
        for t in range(num_time_steps):
            model.addConstr(quicksum(g[i, j, t] + r[i, j, t] + y[i, j, t] for j in range(num_phases)) == signal_cycle_time)

    # Minimum and maximum phase durations
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                model.addConstr(g[i, j, t] >= 8)
                model.addConstr(r[i, j, t] >= 8)
                model.addConstr(y[i, j, t] == max_yellow_duration)

    # Lane occupancy constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                for k in range(num_lanes):
                    model.addConstr(v[i, j, k, t] <= g[i, j, t])

    # Vehicle movement constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for t in range(num_time_steps):
                model.addConstr(quicksum(v[i, j, k, t] for k in range(num_lanes)) == 1)

    # Waiting time constraints
    for i in range(num_intersections):
        for t in range(num_time_steps):
            for k in range(num_lanes):
                model.addConstr(w[i, k, t] >= (distance_between_intersections / vehicle_speed) - quicksum(g[i, j, t] for j in range(num_phases)))
                model.addConstr(w[i, k, t] >= 0)
                #model.addConstr(w[i, k, t] == max(0, queue_lengths[i][t][k] - quicksum(g[i, j, t] for j in range(num_phases))))
                #model.addConstr(w[i, k, t] <= waiting_times[i][t][k])
                # Use separate constraints instead of direct comparison
                model.addConstr(w[i, k, t] >= queue_lengths[i][t][k] - quicksum(g[i, j, t] for j in range(num_phases)))
                model.addConstr(w[i, k, t] <= waiting_times[i][t][k])


    # Optimize the model
    model.optimize()

    # Check if optimization was successful
    if model.status == GRB.OPTIMAL:
        # Extract and return the optimal values
        result = {}
        for i in range(num_intersections):
            for j in range(num_phases):
                for t in range(num_time_steps):
                    result[f'Intersection_{i+1}_Phase_{j+1}_Time_{t+1}'] = {
                        'Green Duration': g[i, j, t].x,
                        'Red Duration': r[i, j, t].x,
                        'Yellow Duration': y[i, j, t].x,
                        'Lane Information': {
                            f'Lane_{k+1}': {
                                'Movement Allowed': v[i, j, k, t].x,
                                'Waiting Time': w[i, k, t].x
                            } for k in range(num_lanes)
                        }
                    }
        return result
    else:
        return "No optimal solution found."

# Example usage with queue lengths and waiting times
queue_lengths_example = [
    [
        [10],
        [8],
        [15],
        [12]
    ],
    [
        [14],
        [10],
        [20],
        [18]
    ],
    [
        [8],
        [6],
        [12],
        [10]
    ],
    [
        [12],
        [9],
        [16],
        [14]
    ]
]

waiting_times_example = [
    [
        [2],
        [1],
        [3],
        [2]
    ],
    [
        [3],
        [2],
        [5],
        [4]
    ],
    [
        [1],
        [0],
        [2],
        [1]
    ],
    [
        [2],
        [1],
        [4],
        [3]
    ]
]

result = optimize_traffic_signal(queue_lengths_example, waiting_times_example)
print(result)
