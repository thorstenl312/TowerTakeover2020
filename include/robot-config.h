using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontL;
extern motor FrontR;
extern motor BackL;
extern motor BackR;
extern motor arm;
extern encoder encoderL;
extern encoder encoderY;
extern encoder encoderR;
extern motor RollerR;
extern motor RollerL;
extern controller Controller1;
extern controller partnerC;
extern motor deploy;
extern inertial inert;
extern line check;
extern line dep;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );