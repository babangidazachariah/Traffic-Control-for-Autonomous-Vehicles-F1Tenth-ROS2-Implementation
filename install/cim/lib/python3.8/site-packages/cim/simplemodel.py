import gurobipy as gp

def traffic_model(queue_lengths, waiting_times):
    # Create a new model
    model = gp.Model("traffic_model")

    # Define the decision variables
    x = {}
    for i in range(4):
        for j in range(4):
            for k in range(3):
                x[i, j, k] = model.addVar(vtype=gp.GRB.CONTINUOUS, name=f"x_{i}_{j}_{k}")

    # Define the objective function
    obj = gp.quicksum(queue_lengths[i][j] * waiting_times[i][j][k] * x[i, j, k] for i in range(4) for j in range(4) for k in range(3))
    model.setObjective(obj, gp.GRB.MINIMIZE)

    # Define the constraints
    for i in range(4):
        for j in range(4):
            model.addConstr(gp.quicksum(x[i, j, k] for k in range(3)) == 1)

    for i in range(4):
        for k in range(3):
            model.addConstr(gp.quicksum(x[i, j, k] for j in range(4)) == 1)

    # Optimize the model
    model.optimize()

    # Return the optimal solution
    return [x[i, j, k].x for i in range(4) for j in range(4) for k in range(3)]


queue_lengths = [
    [[10, 20, 30], [40, 50, 60], [70, 80, 90], [100, 110, 120]],
    [[130, 140, 150], [160, 170, 180], [190, 200, 210], [220, 230, 240]],
    [[250, 260, 270], [280, 290, 300], [310, 320, 330], [340, 350, 360]],
    [[370, 380, 390], [400, 410, 420], [430, 440, 450], [460, 470, 480]]
]

waiting_times = [
    [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]],
    [[13, 14, 15], [16, 17, 18], [19, 20, 21], [22, 23, 24]],
    [[25, 26, 27], [28, 29, 30], [31, 32, 33], [34, 35, 36]],
    [[37, 38, 39], [40, 41, 42], [43, 44, 45], [46, 47, 48]]
]

result = traffic_model(queue_lengths, waiting_times)

print(result)
