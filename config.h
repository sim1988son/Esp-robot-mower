
#define SSID1  "T-2.4GHz"   // put here your acces point ssid
#define PASS1  "e6jjda64c43cet82"  // put here the password
#define SSID2  "Mi Note 10"
#define PASS2  "da6a527f264c"

// ------ pins definitions   (DO NOT CHANGE) ---------------------------------------
#define pinMotorLeft1A          25
#define pinMotorLeft1B          26
#define pinMotorRight2A         32
#define pinMotorRight2B         33
#define pinMotorMow2A           41
#define pinMotorMow2B           42
#define pinMotorCutterC1        5  //EN
#define pinMotorCutterC2        18 //EN
#define pinMotorCutterC3        19 //LEDC - PWM

#define pinSonarLeftTrigger     37
#define pinSonarRightTrigger    38
#define pinSonarCenterTrigger   39
#define pinSonarLeftEcho        pinSonarLeftTrigger
#define pinSonarRightEcho       pinSonarRightTrigger
#define pinSonarCenterEcho      pinSonarCenterTrigger

#define pinBumperLeft           34
#define pinBumperRight          35

#define pinPerimeterLeft        36
#define pinPerimeterRight       39


// finate state machine states
enum State{ 
    STATE_OFF,          // off
    STATE_ROS,          // Linux ROS control
    STATE_REMOTE,       // model remote control (R/C)
    STATE_FORWARD,      // drive forward
    STATE_ROLL,         // drive roll right/left  
    STATE_REVERSE,      // drive reverse
    STATE_CIRCLE,       // drive circle  
    STATE_ERROR,        // error
    STATE_PERI_FIND,    // perimeter find 
    STATE_PERI_TRACK,   // perimeter track
    STATE_PERI_ROLL,    // perimeter roll
    STATE_PERI_REV,     // perimeter reverse
    STATE_STATION,       // in station
    STATE_STATION_CHARGING,       // in station charging
    STATE_STATION_CHECK, //checks if station is present
    STATE_STATION_REV,   // charge reverse
    STATE_STATION_ROLL,  // charge roll
    STATE_STATION_FORW,  // charge forward
    STATE_MANUAL,       // manual navigation  
    STATE_ROLL_WAIT,    // drive roll right/left
    STATE_PERI_OUT_FORW, // outside perimeter forward driving without checkPerimeterBoundary()
    STATE_PERI_OUT_REV,   // outside perimeter reverse driving without checkPerimeterBoundary()
    STATE_PERI_OUT_ROLL,   // outside perimeter rolling driving without checkPerimeterBoundary()
    STATE_TILT_STOP,    // tilt sensor activated, stop motors, wait for un-tilt
    STATE_BUMPER_REVERSE,      // drive reverse
    STATE_BUMPER_FORWARD,      // drive forward	
};