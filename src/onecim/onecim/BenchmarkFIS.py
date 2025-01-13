import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


class ObservationModule:
    """
        
    """
    def __init__(self):
        #Define Input and Output variables
        self.queueCount = None
        self.arrivalRate = None
        self.trafficIntensity = None
        
        #create an instance of fis
        self.fis = self.CreateFIS()
        
        #self.myFis = FuzzyIntersectionManager()
        
    def CreateFIS(self):
         # Define universe of discourse
        qCount = np.arange(0, 21, 0.1) #Queue Count
        aRate = np.arange(0, 1.1, 0.01) #Arrival Rate
        
        #Define outputs
        tIntensity = np.arange(0, 7, 0.1) #Traffic Intensity
        


        # Define Input fuzzy sets
        queueCount = ctrl.Antecedent(qCount, 'queueCount')
        arrivalRate = ctrl.Antecedent(aRate, 'arrivalRate')
        
        #Define output fuzzy sets
        trafficIntensity = ctrl.Consequent(tIntensity, 'trafficIntensity')
       


        # Define membership functions
        queueCount['NS'] = fuzz.trimf(qCount, [0, 0, 7])
        queueCount['S'] = fuzz.trimf(qCount, [0, 3, 10])
        queueCount['M'] = fuzz.trimf(qCount, [2.7, 10, 17])
        queueCount['L'] = fuzz.trimf(qCount, [10, 16.5, 20])
        queueCount['PL'] = fuzz.trimf(qCount, [13, 20, 20])


        arrivalRate['NS'] = fuzz.trimf(aRate, [0, 0, 0.37])
        arrivalRate['S'] = fuzz.trimf(aRate, [0, 0.2, 0.5])
        arrivalRate['Z'] = fuzz.trimf(aRate, [0.18, 0.5, 0.83])
        arrivalRate['M'] = fuzz.trimf(aRate, [0.5, 0.8, 1.0])
        arrivalRate['PM'] = fuzz.trimf(aRate, [0.63, 1.0, 1.0])
        
        trafficIntensity['VD'] = fuzz.trimf(tIntensity, [0, 0, 2.1])
        trafficIntensity['D'] = fuzz.trimf(tIntensity, [0, 1, 3])
        trafficIntensity['M'] = fuzz.trimf(tIntensity, [0.9, 3, 5.1])
        trafficIntensity['U'] = fuzz.trimf(tIntensity, [3, 5, 6.0])
        trafficIntensity['VU'] = fuzz.trimf(tIntensity, [3.9, 6.0, 6.0])
        

        
        # Define the rules

        rule1 = ctrl.Rule(queueCount['NS'] & arrivalRate['NS'], [trafficIntensity['VD']])

        rule2 = ctrl.Rule(queueCount['NS'] & arrivalRate['S'], [trafficIntensity['D']])

        rule3 = ctrl.Rule(queueCount['NS'] & arrivalRate['Z'], [trafficIntensity['M']])

        rule4 = ctrl.Rule(queueCount['NS'] & arrivalRate['M'], [trafficIntensity['U']])

        rule5 = ctrl.Rule(queueCount['NS'] & arrivalRate['PM'], [trafficIntensity['U']])

        rule6 = ctrl.Rule(queueCount['S'] & arrivalRate['NS'], [trafficIntensity['VD']])

        rule7 = ctrl.Rule(queueCount['S'] & arrivalRate['S'], [trafficIntensity['D']])

        rule8 = ctrl.Rule(queueCount['S'] & arrivalRate['Z'], [trafficIntensity['M']])

        rule9 = ctrl.Rule(queueCount['S'] & arrivalRate['M'], [trafficIntensity['U']])

        rule10 = ctrl.Rule(queueCount['S'] & arrivalRate['PM'], [trafficIntensity['VU']])

        rule11 = ctrl.Rule(queueCount['M'] & arrivalRate['NS'], [trafficIntensity['D']])

        rule12 = ctrl.Rule(queueCount['M'] & arrivalRate['S'], [trafficIntensity['M']])

        rule13 = ctrl.Rule(queueCount['M'] & arrivalRate['Z'], [trafficIntensity['M']])

        rule14 = ctrl.Rule(queueCount['M'] & arrivalRate['M'], [trafficIntensity['U']])

        rule15 = ctrl.Rule(queueCount['M'] & arrivalRate['PM'], [trafficIntensity['VU']])

        rule16 = ctrl.Rule(queueCount['L'] & arrivalRate['NS'], [trafficIntensity['D']])

        rule17 = ctrl.Rule(queueCount['L'] & arrivalRate['S'], [trafficIntensity['M']])

        rule18 = ctrl.Rule(queueCount['L'] & arrivalRate['Z'], [trafficIntensity['M']])

        rule19 = ctrl.Rule(queueCount['L'] & arrivalRate['M'], [trafficIntensity['VU']])

        rule20 = ctrl.Rule(queueCount['L'] & arrivalRate['PM'], [trafficIntensity['VU']])

        rule21 = ctrl.Rule(queueCount['PL'] & arrivalRate['NS'], [trafficIntensity['D']])

        rule22 = ctrl.Rule(queueCount['PL'] & arrivalRate['S'], [trafficIntensity['M']])

        rule23 = ctrl.Rule(queueCount['PL'] & arrivalRate['Z'], [trafficIntensity['U']])

        rule24 = ctrl.Rule(queueCount['PL'] & arrivalRate['M'], [trafficIntensity['VU']])

        rule25 = ctrl.Rule(queueCount['PL'] & arrivalRate['PM'], [trafficIntensity['VU']])

       
        self.queueCount = queueCount
        self.arrivalRate = arrivalRate
        self.trafficIntensity = trafficIntensity
        
        # Create fuzzy system
        fuzzy_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15, rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25])
        fuzzy_system = ctrl.ControlSystemSimulation(fuzzy_ctrl)

        return fuzzy_system

    def EvaluateFis(self, qCount, aRate):
        
        #preprocess the values
        qCount = round(qCount, 2)
        if qCount >= 20:
            qCount = 19.9
        elif qCount <= 0:
            qCount = 0.1

        aRate = round(aRate, 2)
        if aRate >= 1.0:
            aRate = 0.9
        elif aRate <= 0:
            aRate = 0.1

            
        #print('W: ', wTime, ' Q: ', qLength, ' S: ', speed, ' D: ', distance)    
        # Input values
        self.fis.input['arrivalRate'] = aRate
        self.fis.input['queueCount'] = qCount
        

        # Evaluate the system
        self.fis.compute()
        
        return round(self.fis.output['trafficIntensity'])
        
    def GenerateFISStructure(self):
        #prints FIS Structure
        self.queueCount.view()
        self.arrivalRate.view()
        self.trafficIntensity.view()
        plt.show()
        
    def GenerateControlSurface(self):
        #print('Creating Fuzzy Inference System...')
        
        qc = np.linspace(0, 20, 100)
        ar = np.linspace(0, 1, 100)
        
        # Generate mesh grid
        qC, aR = np.meshgrid(qc, ar)
        
        
        # Initialize output array
        tI = np.zeros_like(qC)  # trafficIntensity based on arrivalRate and queueCount
        
        print('Generating Control Surface...')
        # Evaluate fuzzy system
        for i in range(len(qc)):
            for j in range(len(ar)):
                
                # Evaluate your fuzzy system for each combination of X[i,j] and Y[i,j]
                 t = self.EvaluateFis(qC[i,j], aR[i,j])
                 #print(t)
                 tI[i,j] = t
                 

        # Plot control surfaces for consequence 1
        fig = plt.figure(figsize=(10, 5))
        ax1 = fig.add_subplot(121, projection='3d')
        ax1.plot_surface(qC, aR, tI, cmap='viridis')
        ax1.set_title('Traffic Intensity:  Queue Count - Arrival Rate Control Surface')
        ax1.set_xlabel('Queue Count')
        ax1.set_ylabel('Arrival Rate')
        ax1.set_zlabel('Traffic Intensity')
        
        plt.tight_layout()
        plt.show()
        





class DecisionModule:
    """
        
    """
    def __init__(self):
        #Define Inputs and Outputs variables
        self.curPhaseIntensity = None
        self.nextPhaseIntensity = None
        self.phaseExtension = None
        #create an instance of fis
        self.fis = self.CreateFIS()
        #self.myFis = FuzzyIntersectionManager()
    
        
    def CreateFIS(self):
        # Define universe of discourse
        cPhase = np.arange(0, 7, 0.1) #Current Phase Traffic Intensity
        nPhase = np.arange(0, 7, 0.1) #Next Phase Traffic Intensity
        
        #Define outputs
        dExtend = np.arange(0, 31, 0.1) #Extend Phase
        


        # Define Input fuzzy sets
        curPhase = ctrl.Antecedent(cPhase, 'curPhase')
        nextPhase = ctrl.Antecedent(nPhase, 'nextPhase')
        
        #Define output fuzzy sets
        durExtend = ctrl.Consequent(dExtend, 'durExtend')
       


        # Define membership functions
        curPhase['VD'] = fuzz.trimf(cPhase, [0, 0, 2.1])
        curPhase['D'] = fuzz.trimf(cPhase, [0, 1, 3])
        curPhase['M'] = fuzz.trimf(cPhase, [0.9, 3, 5.1])
        curPhase['U'] = fuzz.trimf(cPhase, [3, 5, 6.0])
        curPhase['VU'] = fuzz.trimf(cPhase, [3.9, 6.0, 6.0])
        
        nextPhase['VD'] = fuzz.trimf(nPhase, [0, 0, 2.1])
        nextPhase['D'] = fuzz.trimf(nPhase, [0, 1, 3])
        nextPhase['M'] = fuzz.trimf(nPhase, [0.9, 3, 5.1])
        nextPhase['U'] = fuzz.trimf(nPhase, [3, 5, 6.0])
        nextPhase['VU'] = fuzz.trimf(nPhase, [3.9, 6.0, 6.0])
        

        durExtend['NS'] = fuzz.trimf(dExtend, [0, 0, 10.9])
        durExtend['S'] = fuzz.trimf(dExtend, [0, 5, 15])
        durExtend['M'] = fuzz.trimf(dExtend, [4.9, 15, 25.9])
        durExtend['L'] = fuzz.trimf(dExtend, [15, 25, 30.0])
        durExtend['PL'] = fuzz.trimf(dExtend, [19.9, 30, 30.0])
        # Define the rules

        rule1 = ctrl.Rule(curPhase['VD'] & nextPhase['VD'], [durExtend['NS']])

        rule2 = ctrl.Rule(curPhase['VD'] & nextPhase['D'], [durExtend['NS']])

        rule3 = ctrl.Rule(curPhase['VD'] & nextPhase['M'], [durExtend['NS']])

        rule4 = ctrl.Rule(curPhase['VD'] & nextPhase['U'], [durExtend['NS']])

        rule5 = ctrl.Rule(curPhase['VD'] & nextPhase['VU'], [durExtend['NS']])

        rule6 = ctrl.Rule(curPhase['D'] & nextPhase['VD'], [durExtend['S']])

        rule7 = ctrl.Rule(curPhase['D'] & nextPhase['D'], [durExtend['S']])

        rule8 = ctrl.Rule(curPhase['D'] & nextPhase['M'], [durExtend['NS']])

        rule9 = ctrl.Rule(curPhase['D'] & nextPhase['U'], [durExtend['NS']])

        rule10 = ctrl.Rule(curPhase['D'] & nextPhase['VU'], [durExtend['NS']])

        rule11 = ctrl.Rule(curPhase['M'] & nextPhase['VD'], [durExtend['M']])

        rule12 = ctrl.Rule(curPhase['M'] & nextPhase['D'], [durExtend['L']])

        rule13 = ctrl.Rule(curPhase['M'] & nextPhase['M'], [durExtend['M']])

        rule14 = ctrl.Rule(curPhase['M'] & nextPhase['U'], [durExtend['S']])

        rule15 = ctrl.Rule(curPhase['M'] & nextPhase['VU'], [durExtend['S']])

        rule16 = ctrl.Rule(curPhase['U'] & nextPhase['VD'], [durExtend['PL']])

        rule17 = ctrl.Rule(curPhase['U'] & nextPhase['D'], [durExtend['L']])

        rule18 = ctrl.Rule(curPhase['U'] & nextPhase['M'], [durExtend['L']])

        rule19 = ctrl.Rule(curPhase['U'] & nextPhase['U'], [durExtend['M']])

        rule20 = ctrl.Rule(curPhase['U'] & nextPhase['VU'], [durExtend['S']])

        rule21 = ctrl.Rule(curPhase['VU'] & nextPhase['VD'], [durExtend['PL']])

        rule22 = ctrl.Rule(curPhase['VU'] & nextPhase['D'], [durExtend['PL']])

        rule23 = ctrl.Rule(curPhase['VU'] & nextPhase['M'], [durExtend['PL']])

        rule24 = ctrl.Rule(curPhase['VU'] & nextPhase['U'], [durExtend['L']])

        rule25 = ctrl.Rule(curPhase['VU'] & nextPhase['VU'], [durExtend['M']])

       
        self.curPhaseIntensity = curPhase
        self.nextPhaseIntensity = nextPhase
        self.phaseExtension = durExtend
        
        # Create fuzzy system
        fuzzy_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15, rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25])
        fuzzy_system = ctrl.ControlSystemSimulation(fuzzy_ctrl)

        return fuzzy_system

    def EvaluateFis(self, cIntensity, nIntensity):
        #preprocess the values
        cIntensity = round(cIntensity, 2)
        if cIntensity >= 6.0:
            cIntensity = 5.9
        elif cIntensity <= 0:
            cIntensity = 0.1

        nIntensity = round(nIntensity, 2)
        if nIntensity >= 6.0:
            nIntensity = 5.9
        elif nIntensity <= 0:
            nIntensity = 0.1

            
        #print('W: ', wTime, ' Q: ', qLength, ' S: ', speed, ' D: ', distance)    
        # Input values
        self.fis.input['curPhase'] = cIntensity
        self.fis.input['nextPhase'] = nIntensity
        

        # Evaluate the system
        self.fis.compute()
        
        return round(self.fis.output['durExtend'])
    
    def GenerateFISStructure(self):
        #prints FIS Structure
        self.curPhaseIntensity.view()
        self.nextPhaseIntensity.view()
        self.phaseExtension.view()
        plt.show()
        
    def GenerateControlSurface(self):
        #print('Creating Fuzzy Inference System...')
        
        ci = np.linspace(0, 6, 100)
        ni = np.linspace(0, 6, 100)
        
        # Generate mesh grid
        cI, nI = np.meshgrid(ci, ni)
        
        
        # Initialize output array
        eD = np.zeros_like(cI)  # extend duration based on traffic intensity of current and next phase
        
        print('Generating Control Surface...')
        # Evaluate fuzzy system
        for i in range(len(ci)):
            for j in range(len(ni)):
                
                # Evaluate your fuzzy system for each combination of X[i,j] and Y[i,j]
                 t = self.EvaluateFis(cI[i,j], nI[i,j])
                 eD[i,j] = t
                 
        # Plot control surfaces for consequence 1
        fig = plt.figure(figsize=(10, 5))
        ax1 = fig.add_subplot(121, projection='3d')
        ax1.plot_surface(cI, nI, eD, cmap='viridis')
        ax1.set_title('Phase Extension:  Current - Next Phase Intensity Control Surface')
        ax1.set_xlabel('Current Phase Intensity')
        ax1.set_ylabel('Next Phase Intensity')
        ax1.set_zlabel('Phase Duration Extension')
        
        plt.tight_layout()
        plt.show()
        
#fis = DecisionModule()
#fis.GenerateFISStructure()
#fis.GenerateControlSurface()