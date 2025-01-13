import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


class FISBasedDecentralizedCIM:
    """
        
    """
    def __init__(self):
        #create an instance of fis
        self.fis = self.CreateFIS()
        #self.myFis = FuzzyIntersectionManager()
        
    def CreateFIS(self):
        # Define universe of discourse
        dRange = np.arange(0, 10, 0.01) 
        qRange = np.arange(0, 51, 0.01) 
        pRange = np.arange(5, 26, 0.01) 
		
        
        # Define Input fuzzy sets
        distance = ctrl.Antecedent(dRange, 'distance')
        queueLength = ctrl.Antecedent(qRange, 'queueLength')
        
        #Define output fuzzy set
        phaseDuration = ctrl.Consequent(pRange, 'phaseDuration')
        
        # Define membership functions
        queueLength['short'] = fuzz.trimf(qRange, [0, 3, 10])
        queueLength['long'] = fuzz.trimf(qRange, [7, 20, 35])
        queueLength['veryLong'] = fuzz.trimf(qRange, [30, 40, 50])


        distance['near'] = fuzz.trimf(dRange, [0, 1.5, 3.0])
        distance['far'] = fuzz.trimf(dRange, [2.5, 5.0, 8.0])
        distance['veryFar'] = fuzz.trimf(dRange, [6, 8.5, 10.0])
        
        phaseDuration['small'] = fuzz.trimf(pRange, [5, 7.5, 9])
        phaseDuration['large'] = fuzz.trimf(pRange, [8.5, 13, 16])
        phaseDuration['veryLarge'] = fuzz.trimf(pRange, [14, 20, 25])

        rule1 = ctrl.Rule(distance['near'] & queueLength['short'], [phaseDuration['small']])
        rule2 = ctrl.Rule(distance['near'] & queueLength['long'], [phaseDuration['large']])
        rule3 = ctrl.Rule(distance['near'] & queueLength['veryLong'], [phaseDuration['veryLarge']])
        rule4 = ctrl.Rule(distance['far'] & queueLength['short'], [phaseDuration['large']])
        rule5 = ctrl.Rule(distance['far'] & queueLength['long'], [phaseDuration['large']])
        rule6 = ctrl.Rule(distance['far'] & queueLength['veryLong'], [phaseDuration['veryLarge']])
        rule7 = ctrl.Rule(distance['veryFar'] & queueLength['short'], [phaseDuration['veryLarge']])
        rule8 = ctrl.Rule(distance['veryFar'] & queueLength['long'], [phaseDuration['veryLarge']])
        rule9 = ctrl.Rule(distance['veryFar'] & queueLength['veryLong'], [phaseDuration['veryLarge']])
        
        # Create fuzzy system
        fuzzy_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9])
        fuzzy_system = ctrl.ControlSystemSimulation(fuzzy_ctrl)

        return fuzzy_system

    def EvaluateFIS(self, qLength, distance):
        #print(' Q: ', qLength, ' D: ', distance)
        #preprocess the values
        
        qLength = round(qLength, 2)
        if qLength >= 50:
            qLength = 49.0
        elif qLength <= 0:
            qLength = 0.1


        distance = round(distance, 2)
        if distance >= 10:
            distance = 9.0
        elif distance <= 0:
            distance = 0.1
        
            
        #print(' Q: ', qLength, ' D: ', distance)    
        # Input values
        
        self.fis.input['queueLength'] = qLength
        self.fis.input['distance']    = distance

        # Evaluate the system
        self.fis.compute()
        
        return round(self.fis.output['phaseDuration'])

    def GenerateControlSurface(self):
        #print('Creating Fuzzy Inference System...')
        
        ql = np.linspace(0, 50, 100)
        
        ds = np.linspace(0, 10, 100)
        
        # Generate mesh grid
        qL, dS = np.meshgrid(ql, ds)
        
        
        # Initialize output array
        pD = np.zeros_like(qL)  # phaseDuration based on waitingTime and queueLength
        
        print('Generating Control Surface...')
        # Evaluate fuzzy system
        
        for i in range(len(ql)):
            
            for j in range(len(ds)):
                # Evaluate your fuzzy system for each combination of X[i,j] and Y[i,j]
                 p = self.EvaluateFis(qL[i,j], dS[i,j])
                 pD[i,j] = p
                 

        # Plot control surfaces for consequence 1
        fig = plt.figure()
        ax1 = fig.add_subplot(111, projection='3d')
        ax1.plot_surface(qL, dS, pD, cmap='viridis')
        ax1.set_title('Phase Duration: Waiting Time - Queue Length Control Surface')
        ax1.set_xlabel('Waiting Time')
        ax1.set_ylabel('Queue Length')
        ax1.set_zlabel('Phase Duration')
        plt.show()
        