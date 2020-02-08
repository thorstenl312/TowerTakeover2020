#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontL = motor(PORT10, ratio18_1, false);
motor deploy = motor(PORT9, ratio36_1, false);
motor arm = motor(PORT16, ratio18_1, true);
motor BackR = motor(PORT20, ratio18_1, true);
motor BackL = motor(PORT19, ratio18_1, false);
motor FrontR = motor(PORT17, ratio18_1, true);
motor RollerL = motor(PORT14, ratio18_1, false);
motor RollerR = motor(PORT11, ratio18_1, true);

encoder encoderL = encoder(Brain.ThreeWirePort.C);
encoder encoderY = encoder(Brain.ThreeWirePort.E);
encoder encoderR = encoder(Brain.ThreeWirePort.A);

controller Controller1 = controller(primary);
line check = line(Brain.ThreeWirePort.G);
line dep = line(Brain.ThreeWirePort.H);
// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}