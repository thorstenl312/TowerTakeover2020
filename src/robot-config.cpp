#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontL = motor(PORT14, ratio18_1, false);
motor FrontR = motor(PORT20, ratio18_1, true);
motor BackL = motor(PORT11, ratio18_1, false);
motor BackR = motor(PORT19, ratio18_1, true);
motor arm = motor(PORT4, ratio18_1, true);
motor deploy = motor(PORT12, ratio36_1, false);
encoder encoderL = encoder(Brain.ThreeWirePort.G);
encoder encoderY = encoder(Brain.ThreeWirePort.A);
encoder encoderR = encoder(Brain.ThreeWirePort.C);
motor RollerR = motor(PORT17, ratio18_1, true);
motor RollerL = motor(PORT7, ratio18_1, false);
controller Controller1 = controller(primary);
inertial inert = inertial(PORT11);
line check = line(Brain.ThreeWirePort.E);
line dep = line(Brain.ThreeWirePort.F);
// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}