#user input
#for user publishing waypoints/missions to drone

#missions
uint8 TAKEOFF = 1
uint8 LAND = 2
uint8 WAYPOINT = 3
uint8 AIRDROP = 4
uint8 MAPPING = 5
uint8 EXECUTE = 99
uint8 POPLAST = 100

uint8 SUCCESS = 200
uint8 REJECT = 210
uint8 REJECT_SETPOINT_OUTOFREACH = 211
uint8 REJECT_SPPED_INFEASIBLE = 212
uint8 REJECT_TAKEOFF_HEIGHTINFEASIBLE = 213
uint8 REJECT_MISSING_TAKEOFF = 214
uint8 REJECT_MISSING_LAND = 215

uint64 timestamp

float32 lon
float32 lat

float32 x
float32 y
float32 z

float32 yaw

uint8 command
bool use_xyz

uint8 response

#topic user_command