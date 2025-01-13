# IntersectionBSM.msg

#The IntersectionBSM.msg simulates a DSRC Basic Safety Message broadcasted by vehicles

#The identification of the vehicle publishing the DSRCMessage
string vehicleid

# The name of Junction
string junctionid

# Current path on which the vehicle is approaching the intersection
string approachleg

# Planned path (trajectory) the vehicle will follow after the intersection
string departleg

# Distance from stop line
float64 distfromstopline

# The point where the vehicle is at currently
float32[] point


# The time the DSRC message was generated at some distance away from a stop line
float64 arrivaltime

# Earlier (string): The vehicle type: two-seater, minicompact, subcompact, compact, mid-size and large/full-size cars --- based on https://www.fueleconomy.gov/feg/info.shtml#sizeclasses
# Later(int): Based on vehicle type codes found at https://actar.org/pdf/ca_veh1.pdf
int32 vehicletype

# Current speed of vehicle - used for decision as to which vehicle utilizes the intersection first
float64 speed

# The priority of vehicles may be used to influence schedule and is between 0 and N depending on the classes of priority
int32 priority

#Stopped time of vehicle within the intersection zone
float64 stoppedtime

#Timestamp of the message 
float64 timestamp