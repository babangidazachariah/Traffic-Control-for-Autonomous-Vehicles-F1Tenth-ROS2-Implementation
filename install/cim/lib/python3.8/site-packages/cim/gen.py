import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl

# Define universe of discourse
input1_range = np.arange(0, 11)
input2_range = np.arange(0, 11)
output1_range = np.arange(0, 101)
output2_range = np.arange(0, 101)

# Define fuzzy sets
input1 = ctrl.Antecedent(input1_range, 'input1')
input2 = ctrl.Antecedent(input2_range, 'input2')
output1 = ctrl.Consequent(output1_range, 'output1')
output2 = ctrl.Consequent(output2_range, 'output2')

# Define membership functions
input1['low'] = fuzz.trimf(input1_range, [0, 0, 5])
input1['medium'] = fuzz.trimf(input1_range, [0, 5, 10])
input1['high'] = fuzz.trimf(input1_range, [5, 10, 10])

input2['low'] = fuzz.trimf(input2_range, [0, 0, 5])
input2['medium'] = fuzz.trimf(input2_range, [0, 5, 10])
input2['high'] = fuzz.trimf(input2_range, [5, 10, 10])

output1['low'] = fuzz.trimf(output1_range, [0, 0, 50])
output1['high'] = fuzz.trimf(output1_range, [0, 50, 100])

output2['low'] = fuzz.trimf(output2_range, [0, 0, 50])
output2['high'] = fuzz.trimf(output2_range, [0, 50, 100])

# Define fuzzy rules
rule1 = ctrl.Rule(input1['low'] & input2['low'], [output1['low'], output2['low']])
rule2 = ctrl.Rule(input1['medium'] & input2['medium'], [output1['high'], output2['high']])
rule3 = ctrl.Rule(input1['high'] & input2['high'], [output1['low'], output2['high']])

# Create fuzzy system
fuzzy_ctrl = ctrl.ControlSystem([rule1, rule2, rule3])
fuzzy_system = ctrl.ControlSystemSimulation(fuzzy_ctrl)

# Input values
fuzzy_system.input['input1'] = 0
fuzzy_system.input['input2'] = 5

# Evaluate the system
fuzzy_system.compute()

# Output values
print("Output1:", fuzzy_system.output['output1'])
print("Output2:", fuzzy_system.output['output2'])
