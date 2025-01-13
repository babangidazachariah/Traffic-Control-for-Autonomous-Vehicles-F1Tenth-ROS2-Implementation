# DSRCMessage.msg

#The identification of the vehicle publishing the DSRCMessage
string vehicleid

# The time the DSRC message was generated at some distance away from a stop line
float64 initialtime

# Current time the DSRC message was generated
float64 currenttime

# Current path on which the vehicle is approaching the intersection
string approachleg

# Planned path (trajectory) the vehicle will follow after the intersection
string departureleg

# Distance to stop line
float64 disttostopline

# Distance from stop line
float64 distfromstopline

# The point where the vehicle is at currently
float32[] point

# Current speed of vehicle - used for decision as to which vehicle utilizes the intersection first
float64 speed

