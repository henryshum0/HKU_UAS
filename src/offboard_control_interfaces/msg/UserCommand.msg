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
uint8 REJECT_SPEED_INFEASIBLE = 212
uint8 REJECT_TAKEOFF_REQUIRED = 213
uint8 REJECT_TAKEOFF_HEIGHTINFEASIBLE = 214
uint8 REJECT_TAKEOFF_BEFORE_LAND = 215
uint8 REJECT_LAND_BEFORE_TAKEOFF = 216
uint8 REJECT_EMPTY_WAYPOINTS = 217

uint64 timestamp

uint8 command
uint8 response

bool use_xy

float32 x
float32 y
float32 lon
float32 lat
float32 z

float32 speed
float32 yaw

#topic user_command