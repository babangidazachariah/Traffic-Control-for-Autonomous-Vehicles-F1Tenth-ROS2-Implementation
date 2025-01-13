#import simpful as sf
from simpful import *

#create FIS model
FIS = FuzzySystem()

# Define the linguistic variables
#queueLength = FuzzySet('queueLength', 0, 10)
#waitingTime = sf.FuzzyVariable('waitingTime', 0, 30)
#speed = sf.FuzzyVariable('speed', 0, 3)
#distance = sf.FuzzyVariable('distance', 0, 3)
#phaseDuration = sf.FuzzyVariable('phaseDuration', 0, 15)


# Define the membership functions for each variable
q1 = FuzzySet(function=Triangular_MF(a=0, b=3, c=5), term='short')
q2 = FuzzySet(function=Triangular_MF(a=4, b=6, c=8), term='long')
q3 = FuzzySet(function=Triangular_MF(a=7, b=9, c=10), term='verylong')
FIS.add_linguistic_variable("queueLength", LinguisticVariable([q1, q2, q3], concept="Queue Length", universe_of_discourse=[0,10]))


w1 = FuzzySet(function=Triangular_MF(a=0, b=10, c=15), term='small')
w2 = FuzzySet(function=Triangular_MF(a=13, b=20, c=25), term='large')
w3 = FuzzySet(function=Triangular_MF(a=23, b=26, c=30), term='verylarge')
FIS.add_linguistic_variable("waitingTime", LinguisticVariable([w1, w2, w3], concept="Waiting Time", universe_of_discourse=[0,30]))

s1 = FuzzySet(function=Triangular_MF(a=0, b=0.5, c=1.0), term='low')
s2 = FuzzySet(function=Triangular_MF(a=0.8, b=1.5, c=2.0), term='high')
s3 = FuzzySet(function=Triangular_MF(a=1.8, b=2.5, c=3.0), term='veryhigh')
FIS.add_linguistic_variable("speed", LinguisticVariable([s1, s2, s3], concept="Speed", universe_of_discourse=[0,3]))

d1 = FuzzySet(function=Triangular_MF(a=0, b=0.5, c=1.0), term='near')
d2 = FuzzySet(function=Triangular_MF(a=0.8, b=1.5, c=2.0), term='far')
d3 = FuzzySet(function=Triangular_MF(a=1.8, b=2.5, c=3.0), term='veryfar')
FIS.add_linguistic_variable("speed", LinguisticVariable([d1, d2, d3], concept="Distance", universe_of_discourse=[0,3]))

#define output fuzzy sets and linguistic variables
p1 = FuzzySet(function=Triangular_MF(a=5, b=7.5, c=9), term='small')
p2 = FuzzySet(function=Triangular_MF(a=8.5, b=11, c=13.5), term='large')
p3 = FuzzySet(function=Triangular_MF(a=12.5, b=14, c=15), term='verylarge')
FIS.add_linguistic_variable("phaseDuration", LinguisticVariable([p1, p2, p3], concept="Phase Duration", universe_of_discourse=[5,15]))

so1 = FuzzySet(function=Triangular_MF(a=0, b=0.5, c=1.0), term='low')
so2 = FuzzySet(function=Triangular_MF(a=0.8, b=1.5, c=2.0), term='high')
so3 = FuzzySet(function=Triangular_MF(a=1.8, b=2.5, c=3.0), term='veryhigh')
FIS.add_linguistic_variable("speedOut", LinguisticVariable([so1, so2, so3], concept="Recommended Speed", universe_of_discourse=[0,3]))


# Define the rules
rule1 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule2 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule3 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule4 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule5 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule6 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule7 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule8 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule9 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule10 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule11 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule12 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule13 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule14 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule15 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule16 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule17 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule18 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule19 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule20 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule21 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule22 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule23 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule24 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule25 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  small)  AND   (speedOut  IS  veryhigh)"

rule26 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule27 = "IF(queueLength  IS  short)  AND   (waitingTime  IS  Verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  veryhigh)"

rule28 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule29 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule30 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule31 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule32 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  high)"

rule33 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  Verylarge)  AND   (speedOut  IS  high)"

rule34 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  high)"

rule35 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  Verylarge)  AND   (speedOut  IS  high)"

rule36 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  Verylarge)  AND   (speedOut  IS  high)"

rule37 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  Verylarge)  AND   (speedOut  IS  high)"

rule38 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  high)"

rule39 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  high)"

rule40 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule41 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule42 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule43 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule44 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule45 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule46 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule47 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule48 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule49 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule50 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule51 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule52 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule53 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule54 = "IF(queueLength  IS  long)  AND   (waitingTime  IS  Verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  large)  AND   (speedOut  IS  high)"

rule55 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule56 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule57 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule58 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule59 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule60 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule61 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule62 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule63 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  small)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule64 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule65 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule66 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule67 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule68 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule69 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule70 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule71 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule72 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  large)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule73 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule74 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule75 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  low)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule76 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule77 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule78 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  high)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule79 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  close) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule80 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  far) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"

rule81 = "IF(queueLength  IS  verylong)  AND   (waitingTime  IS  Verylarge)  AND   (speed  IS  veryhigh)  AND   (distance  IS  veryfar) THEN (phaseDuration  IS  verylarge)  AND   (speedOut  IS  low)"


# Define the fuzzy system
FIS.add_rules([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11, rule12, rule13, rule14, rule15, rule16, rule17, rule18, rule19, rule20, rule21, rule22, rule23, rule24, rule25, rule26, rule27, rule28, rule29, rule30, rule31, rule32, rule33, rule34, rule35, rule36, rule37, rule38, rule39, rule40, rule41, rule42, rule43, rule44, rule45, rule46, rule47, rule48, rule49, rule50, rule51, rule52, rule53, rule54, rule55, rule56, rule57, rule58, rule59, rule60, rule61, rule62, rule63, rule64, rule65, rule66, rule67, rule68, rule69, rule70, rule71, rule72, rule73, rule74, rule75, rule76, rule77, rule78, rule79, rule80, rule81])


# Evaluate the fuzzy system
FIS.set_variable("queueLength", 1)
FIS.set_variable('waitingTime', 20)
FIS.set_variable('speed', 1.8) 
FIS.set_variable('distance', 2.99)

# Print the output
print(FIS.Mamdani_inference(["phaseDuration"]))

