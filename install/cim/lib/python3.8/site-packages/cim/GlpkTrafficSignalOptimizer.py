from pulp import *

def create_traffic_signal_model(num_intersections, num_phases, num_lanes, num_time_steps,
                                signal_cycle_time, max_speed, queue_lengths, waiting_times):

    model = LpProblem("TrafficSignalOptimization", LpMinimize)

    # Decision Variables
    v = LpVariable.dicts("v", (range(num_intersections), range(num_phases), range(num_lanes), range(num_time_steps)),
                         cat=LpBinary)
    w = LpVariable.dicts("w", (range(num_intersections), range(num_lanes), range(num_time_steps)),
                         cat=LpBinary)
    g = LpVariable.dicts("g", (range(num_intersections), range(num_phases), range(num_time_steps)),
                         lowBound=8, upBound=100)
    r = LpVariable.dicts("r", (range(num_intersections), range(num_phases), range(num_time_steps)),
                         lowBound=8, upBound=100)
    y = LpVariable.dicts("y", (range(num_intersections), range(num_phases), range(num_time_steps)),
                         upBound=5)

    # Objective Function
    model += lpSum(waiting_times[i, k, t] for i in range(num_intersections)
                   for k in range(num_lanes) for t in range(num_time_steps))

    # Constraints

    # Traffic signal cycle time constraint
    for i in range(num_intersections):
        model += lpSum(g[i][j][t] + r[i][j][t] for j in range(num_phases) for t in range(num_time_steps)) >= signal_cycle_time

    # Dual-ring traffic signal phases constraint
    for i in range(num_intersections):
        for j in range(num_phases):
            model += lpSum(v[i][j][k][t] for k in range(num_lanes) for t in range(num_time_steps)) <= 1

    # Vehicle movement constraints
    for i in range(num_intersections):
        for j in range(num_phases):
            for k in range(num_lanes):
                for t in range(num_time_steps):
                    model += v[i][j][k][t] - w[i][k][t] == 0

    # Speed constraints
    for i in range(num_intersections):
        model += lpSum(v[i][j][k][t] * max_speed for j in range(num_phases)
                       for k in range(num_lanes) for t in range(num_time_steps)) <= max_speed

    # Queue length constraints
    for i in range(num_intersections):
        model += lpSum(w[i][k][t] for k in range(num_lanes) for t in range(num_time_steps)) == queue_lengths[i]

    return model

# Example usage:
num_intersections = 4
num_phases = 2
num_lanes = 3
num_time_steps = 10
signal_cycle_time = 60
max_speed = 50
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


model = create_traffic_signal_model(num_intersections, num_phases, num_lanes, num_time_steps,
                                    signal_cycle_time, max_speed, queue_lengths_example, waiting_times_example)
model.solve()

# # Access the solution values using model.variables()
#pip install networkx matplotlib seaborn
#pip install pygraphviz
#apt install libgraphviz-dev
#pip install pygraphviz 
#pip install gurobipy