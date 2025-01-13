import pandas as pd

#read Hybrid CIM Results
hcimsn = pd.read_csv('/home/babangida/ros_ws/FISHybridCIMsnagent.csv')
hcimew = pd.read_csv('/home/babangida/ros_ws/FISHybridCIMewagent.csv')

#read Static TLS CIM Results
scimsn = pd.read_csv('/home/babangida/ros_ws/STLSCIMsnagent.csv')
scimew = pd.read_csv('/home/babangida/ros_ws/STLSCIMewagent.csv')

#Compute network and junction-based avarage waiting times

#East-West Vehicle Performance
print("East-West Vehicle STLS Performance: ")
allAveWaitTime = scimew['waitTime'].mean()
j1AveWaitTime = scimew[scimew['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = scimew[scimew['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = scimew[scimew['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = scimew[scimew['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)

print("East-West Vehicle HybridCIM Performance: ")
allAveWaitTime = hcimew['waitTime'].mean()
j1AveWaitTime = hcimew[hcimew['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = hcimew[hcimew['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = hcimew[hcimew['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = hcimew[hcimew['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)


print("South-North Vehicle STLS Performance: ")
allAveWaitTime = scimsn['waitTime'].mean()
j1AveWaitTime = scimsn[scimsn['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = scimsn[scimsn['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = scimsn[scimsn['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = scimsn[scimsn['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)

print("South-North Vehicle HybridCIM Performance: ")
allAveWaitTime = hcimsn['waitTime'].mean()
j1AveWaitTime = hcimsn[hcimsn['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = hcimsn[hcimsn['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = hcimsn[hcimsn['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = hcimsn[hcimsn['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)


scim = pd.concat([scimew, scimsn],  ignore_index=True)
print("Overall Network Performance of STLS: ")
allAveWaitTime = scim['waitTime'].mean()
j1AveWaitTime = scim[scim['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = scim[scim['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = scim[scim['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = scim[scim['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)



hcim = pd.concat([hcimew, hcimsn],  ignore_index=True)
print("Overall Network Performance of HybridCIM: ")
allAveWaitTime = hcim['waitTime'].mean()
j1AveWaitTime = hcim[hcim['approachLeg'].str.contains('J1', case=False)]['waitTime'].mean()
j2AveWaitTime = hcim[hcim['approachLeg'].str.contains('J2', case=False)]['waitTime'].mean()
j3AveWaitTime = hcim[hcim['approachLeg'].str.contains('J3', case=False)]['waitTime'].mean()
j4AveWaitTime = hcim[hcim['approachLeg'].str.contains('J4', case=False)]['waitTime'].mean()

print('J1Ave: ', j1AveWaitTime)
print('J2Ave: ', j2AveWaitTime)
print('J3Av: ', j3AveWaitTime)
print('J4Ave: ', j4AveWaitTime)
print('NetAve: ', allAveWaitTime)