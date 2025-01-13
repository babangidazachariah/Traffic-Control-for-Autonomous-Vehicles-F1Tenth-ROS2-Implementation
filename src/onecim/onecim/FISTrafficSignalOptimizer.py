import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


class FuzzyIntersectionManager:
    """
        
    """
    def __init__(self):
        #define Input and Output variables
        self.queueLength = None
        self.waitingTime = None
        self.distance = None
        self.speed = None
        self.speedOut = None
        self.phaseDuration = None
        
        self.ctrl = None

        #create an instance of fis
        self.fis = self.CreateFIS()
        #self.myFis = FuzzyIntersectionManager()
        
    def CreateFIS(self):
         # Define universe of discourse
        qLRange = np.arange(0, 21, 0.01) #Assuming a maximum of 50 vehicles at 4.5m length, means distance of 4.5 * 50 = 225m
        wTRange = np.arange(0, 51, 0.01) #maximum 25s green implies average waiting time may be 50s
        sRange = np.arange(0, 5, 0.01) #speed is between 0 and 4m/s
        dRange = np.arange(0, 10, 0.01) # assuming 10m

        #Define outputs
        pDRange = np.arange(5, 26, 0.01)
        sORange = np.arange(0, 5, 0.01)


        # Define Input fuzzy sets
        waitingTime = ctrl.Antecedent(wTRange, 'waitingTime')
        queueLength = ctrl.Antecedent(qLRange, 'queueLength')
        speed = ctrl.Antecedent(sRange, 'speed')
        distance = ctrl.Antecedent(dRange, 'distance')

        #Define output fuzzy sets
        phaseDuration = ctrl.Consequent(pDRange, 'phaseDuration')
        speedOut = ctrl.Consequent(sORange, 'speedOut')


        # Define membership functions
        waitingTime['low'] = fuzz.trimf(wTRange, [0, 10, 20])
        waitingTime['high'] = fuzz.trimf(wTRange, [15, 35, 40])
        waitingTime['veryhigh'] = fuzz.trimf(wTRange, [38, 45, 50])

        
        queueLength['short'] = fuzz.trimf(qLRange, [0, 3, 10])
        queueLength['long'] = fuzz.trimf(qLRange, [7, 20, 35])
        queueLength['verylong'] = fuzz.trimf(qLRange, [30, 40, 50])
        

        distance['near'] = fuzz.trimf(dRange, [0, 1.5, 3.0])
        distance['far'] = fuzz.trimf(dRange, [2.5, 5.0, 8.0])
        distance['veryfar'] = fuzz.trimf(dRange, [6, 8.5, 10.0])


        speed['low'] = fuzz.trimf(sRange, [0, 0.5, 1.0])
        speed['high'] = fuzz.trimf(sRange, [0.8, 1.5, 2.0])
        speed['veryhigh'] = fuzz.trimf(sRange, [1.8, 2.8, 3.0])


        phaseDuration['short'] = fuzz.trimf(pDRange, [5, 7.5, 9])
        phaseDuration['long'] = fuzz.trimf(pDRange, [8.5, 13, 16])
        phaseDuration['verylong'] = fuzz.trimf(pDRange, [14, 20, 25])


        speedOut['low'] = fuzz.trimf(sRange, [0, 0.5, 1.0])
        speedOut['high'] = fuzz.trimf(sRange, [0.8, 1.5, 2.0])
        speedOut['veryhigh'] = fuzz.trimf(sRange, [1.8, 2.8, 3.0])

        # Define the rules

        rule1 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['low'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule2 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['low'] & distance['far'], [phaseDuration['short'], speedOut['veryhigh']])

        rule3 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['low'] & distance['veryfar'], [phaseDuration['short'], speedOut['veryhigh']])

        rule4 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['high'] & distance['near'], [phaseDuration['long'], speedOut['veryhigh']])

        rule5 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['high'] & distance['far'], [phaseDuration['long'], speedOut['veryhigh']])

        rule6 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['high'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule7 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['veryhigh'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule8 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['veryhigh'] & distance['far'], [phaseDuration['short'], speedOut['veryhigh']])

        rule9 = ctrl.Rule(queueLength['short'] & waitingTime['low'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule10 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['low'] & distance['near'], [phaseDuration['long'], speedOut['veryhigh']])

        rule11 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['low'] & distance['far'], [phaseDuration['long'], speedOut['veryhigh']])

        rule12 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['low'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule13 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['high'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule14 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['high'] & distance['far'], [phaseDuration['short'], speedOut['veryhigh']])

        rule15 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['high'] & distance['veryfar'], [phaseDuration['short'], speedOut['veryhigh']])

        rule16 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['veryhigh'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule17 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['veryhigh'] & distance['far'], [phaseDuration['long'], speedOut['veryhigh']])

        rule18 = ctrl.Rule(queueLength['short'] & waitingTime['high'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule19 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['low'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule20 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['low'] & distance['far'], [phaseDuration['short'], speedOut['veryhigh']])

        rule21 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['low'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule22 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['high'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule23 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['high'] & distance['far'], [phaseDuration['short'], speedOut['veryhigh']])

        rule24 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['high'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule25 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['near'], [phaseDuration['short'], speedOut['veryhigh']])

        rule26 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['far'], [phaseDuration['long'], speedOut['veryhigh']])

        rule27 = ctrl.Rule(queueLength['short'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['long'], speedOut['veryhigh']])

        rule28 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['low'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule29 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['low'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule30 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['low'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule31 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['high'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule32 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['high'] & distance['far'], [phaseDuration['verylong'], speedOut['high']])

        rule33 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['high'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['high']])

        rule34 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['veryhigh'] & distance['near'], [phaseDuration['verylong'], speedOut['high']])

        rule35 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['veryhigh'] & distance['far'], [phaseDuration['verylong'], speedOut['high']])

        rule36 = ctrl.Rule(queueLength['long'] & waitingTime['low'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['high']])

        rule37 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['low'] & distance['near'], [phaseDuration['verylong'], speedOut['high']])

        rule38 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['low'] & distance['far'], [phaseDuration['verylong'], speedOut['high']])

        rule39 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['low'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['high']])

        rule40 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['high'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule41 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['high'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule42 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['high'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule43 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['veryhigh'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule44 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['veryhigh'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule45 = ctrl.Rule(queueLength['long'] & waitingTime['high'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule46 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['low'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule47 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['low'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule48 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['low'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule49 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['high'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule50 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['high'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule51 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['high'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule52 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['near'], [phaseDuration['long'], speedOut['high']])

        rule53 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['far'], [phaseDuration['long'], speedOut['high']])

        rule54 = ctrl.Rule(queueLength['long'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['long'], speedOut['high']])

        rule55 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['low'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule56 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['low'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule57 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['low'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule58 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['high'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule59 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['high'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule60 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['high'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule61 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['veryhigh'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule62 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['veryhigh'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule63 = ctrl.Rule(queueLength['verylong'] & waitingTime['low'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule64 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['low'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule65 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['low'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule66 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['low'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule67 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['high'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule68 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['high'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule69 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['high'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule70 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['veryhigh'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule71 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['veryhigh'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule72 = ctrl.Rule(queueLength['verylong'] & waitingTime['high'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule73 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['low'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule74 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['low'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule75 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['low'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule76 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['high'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule77 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['high'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule78 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['high'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        rule79 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['near'], [phaseDuration['verylong'], speedOut['low']])

        rule80 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['far'], [phaseDuration['verylong'], speedOut['low']])

        rule81 = ctrl.Rule(queueLength['verylong'] & waitingTime['veryhigh'] & speed['veryhigh'] & distance['veryfar'], [phaseDuration['verylong'], speedOut['low']])

        self.queueLength = queueLength
        self.waitingTime = waitingTime
        self.distance = distance
        self.speed = speed
        self.speedOut = speedOut
        self.phaseDuration = phaseDuration
        
        self.ctrl = ctrl
        # Create fuzzy system
        fuzzy_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15, rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25, rule26, rule27, rule28, rule29, rule30, rule31, rule32, rule33, rule34, rule35, rule36, rule37, rule38, rule39, rule40, rule41, rule42, rule43, rule44, rule45, rule46, rule47, rule48, rule49, rule50, rule51, rule52, rule53, rule54, rule55, rule56, rule57, rule58, rule59, rule60, rule61, rule62, rule63, rule64, rule65, rule66, rule67, rule68, rule69, rule70, rule71, rule72, rule73, rule74, rule75, rule76, rule77, rule78, rule79, rule80, rule81])
        fuzzy_system = ctrl.ControlSystemSimulation(fuzzy_ctrl)

        return fuzzy_system

    def EvaluateFis(self, wTime, qLength, speed, distance):
        #print('W: ', wTime, ' Q: ', qLength, ' S: ', speed, ' D: ', distance)
        #preprocess the values
        wTime = round(wTime, 2)
        if wTime >= 50:
            wTime = 49.9
        elif wTime <= 0:
            wTime = 0.1

        qLength = round(qLength, 2)
        if qLength >= 20:
            qLength = 19.9
        elif qLength <= 0:
            qLength = 0.1


        speed = round(speed, 2)
        if speed >= 3:
            speed = 2.9
        elif speed <= 0:
            speed = 0.1


        distance = round(distance, 2)
        if distance >= 10:
            distance = 9.9
        elif distance <= 0:
            distance = 0.1
        
            
        #print('W: ', wTime, ' Q: ', qLength, ' S: ', speed, ' D: ', distance)    
        # Input values
        self.fis.input['waitingTime'] = wTime
        self.fis.input['queueLength'] = qLength
        self.fis.input['speed']       = speed
        self.fis.input['distance']    = distance

        # Evaluate the system
        self.fis.compute()
        
        return [round(self.fis.output['phaseDuration']),  round(self.fis.output['speedOut'], 1)]

    
    def GenerateFISStructure(self):
        print('Generating Controller Structure...')
        self.queueLength.view()
        self.waitingTime.view()
        self.distance.view()
        self.speed.view()
        #self.speedOut.view()
        self.phaseDuration.view()
        plt.show()

    def GenerateControlSurface(self):
        print('Generating Control Surface...')
        # Generate the control surface for phase duration
        ctrl.view.ControlSurface(self.fis, ['queueLength', 'waitingTime'], ['phaseDuration'])
        plt.title('Phase Duration Control Surface')
        plt.show()

        # Generate the control surface for recommended speed
        ctrl.view.ControlSurface(self.fis, ['queueLength', 'waitingTime'], ['speedOut'])
        plt.title('Recommended Speed Control Surface')
        plt.show()

    def GenerateControlSurfacess(self):
        ql = np.linspace(0, 20, 10)
        wt = np.linspace(0, 50, 10)
        sp = np.linspace(0, 3, 10)
        ds = np.linspace(0, 10, 10)

        wT, qL, sP, dS = np.meshgrid(wt, ql, sp, ds)

        pD = np.zeros_like(wT)
        sO = np.zeros_like(wT)

        print('Generating Control Surface...')

        for i in range(len(wt)):
            for j in range(len(ql)):
                for k in range(len(sp)):
                    for q in range(len(ds)):
                        p, s = self.EvaluateFis(wT[i, j, k, q], qL[i, j, k, q], sP[i, j, k, q], dS[i, j, k, q])
                        pD[i, j, k, q] = p
                        sO[i, j, k, q] = s

        fig = plt.figure(figsize=(15, 6))

        ax1 = fig.add_subplot(1, 2, 1, projection='3d')
        ax1.plot_surface(wT[:, :, 0, 0], qL[:, :, 0, 0], pD[:, :, 0, 0], cmap='viridis')
        ax1.set_title('Phase Duration: Waiting Time - Queue Length Control Surface')
        ax1.set_xlabel('Waiting Time')
        ax1.set_ylabel('Queue Length')
        ax1.set_zlabel('Phase Duration')

        ax2 = fig.add_subplot(1, 2, 2, projection='3d')
        ax2.plot_surface(wT[:, :, 0, 0], qL[:, :, 0, 0], sO[:, :, 0, 0], cmap='viridis')
        ax2.set_title('Speed: Waiting Time - Queue Length Control Surface')
        ax2.set_xlabel('Waiting Time')
        ax2.set_ylabel('Queue Length')
        ax2.set_zlabel('Speed')

        plt.tight_layout()
        plt.show()

    def GenerateControlSurfaces(self):
        #print('Creating Fuzzy Inference System...')
        
        ql = np.linspace(0, 21, 10)
        wt = np.linspace(0, 50, 10)
        
        sp = np.linspace(0, 3, 10)
        ds = np.linspace(0, 10, 10)
        
        # Generate mesh grid
        wT, qL, sP, dS = np.meshgrid(wt, ql, sp, ds)
        
        
        # Initialize output array
        pD = np.zeros_like(wT)  # phaseDuration based on waitingTime and queueLength
        sO = np.zeros_like(wT)  # Recommended speed based on waitingTime and queueLength
        
        print('Generating Control Surface...')
        # Evaluate fuzzy system
        for i in range(len(wt)):
            for j in range(len(ql)):
                for k in range(len(sp)):
                    for q in range(len(ds)):
                        # Evaluate your fuzzy system for each combination of X[i,j] and Y[i,j]
                         p, s = self.EvaluateFis(wT[i,j, k, q], qL[i,j, k, q], sP[i,j, k, q], dS[i,j, k, q])
                         pD[i,j, k, q] = p
                         sO[i,j, k, q] = s

        # Plot control surfaces for consequence 1
        fig = plt.figure(figsize=(10, 5))
        ax1 = fig.add_subplot(121, projection='3d')
        ax1.plot_surface(wT, qL, pD, cmap='viridis')
        ax1.set_title('Phase Duration: Waiting Time - Queue Length Control Surface')
        ax1.set_xlabel('Waiting Time')
        ax1.set_ylabel('Queue Length')
        ax1.set_zlabel('Phase Duration')
        
        # Plot control surfaces for consequence 2
        ax2 = fig.add_subplot(122, projection='3d')
        ax2.plot_surface(wT, qL, sO, cmap='viridis')
        ax2.set_title('Speed: Waiting Time - Queue Length Control Surface')
        ax2.set_xlabel('Waiting Time')
        ax2.set_ylabel('Queue Length')
        ax2.set_zlabel('Phase Duration')
        plt.tight_layout()
        plt.show()
        
# W:  0.4234166145324707  Q:  8  S:  1.0  D:  2.9066237355988904
#myfis = FuzzyIntersectionManager()
#print(fis.EvaluateFis(0.45624494552612305, 17,  1.0, 2.511981846980094))
#myfis.GenerateControlSurfacess()
"""

fuzzy_system.input['waitingTime'] = 4
fuzzy_system.input['queueLength'] = 8
fuzzy_system.input['speed']       = 1
fuzzy_system.input['distance']    = 2
fuzzy_system.compute()
print(fuzzy_system.output['phaseDuration'],  fuzzy_system.output['speedOut'])
"""