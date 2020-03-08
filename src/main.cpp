/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "C:/Program Files (x86)/VEX Robotics/VEXcode/sdk/vexv5/include/v5_color.h"
#include "auto.h"
using namespace vex;
float exponent=1.4;
double num = 1;
double accel = 1.5;
int b=5; //Auton Selection based on number
competition Competition;

void pre_auton(void) {
  task check(debug);
  task Odom(trackPosition);
  Brain.Screen.setFont(mono60);
  if(skills) Brain.Screen.printAt(100, 100,"SKILLS");
  else if(Red1) Brain.Screen.printAt(100, 100,"RED");
  else Brain.Screen.printAt(100, 100,"BLUE");
  deploy.resetRotation();
  arm.resetRotation();
  encoderL.resetRotation();
  encoderR.resetRotation();
  encoderY.resetRotation();
  resetPosition();
  resetPosition();
  resetPosition();
  vexcodeInit();
}
void autonomous(void) {
  roller.setMaxTorque(100, pct);
  //rollerSpin(-80);
  deploy.stop(coast);
  if(skills) Skills();
  else Auton();

}
void usercontrol(void) {
  stopDrive(hold);
  resetPosition();
  roller.setStopping(hold);
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(mono15); //Makes font on brain smaller to allow for space
  if(skills){
    deployRobotTask();
    num = 0.75;
  } 
  task chweck(debug);
  task od(trackPosition);
  task ar(armControl);
  task r(rollerControl);
  roller.setMaxTorque(100,percent);
  while (true) {
    leftDrive.setStopping(coast);
    rightDrive.setStopping(coast);
    double xAxis = Controller1.Axis2.position(percent), yAxis = Controller1.Axis3.position(percent);
    if(fabs(xAxis)<5) xAxis = 0; //Deadzone
    if(fabs(yAxis)<5) yAxis = 0; 
    double R = fabs(xAxis)/100, S = fabs(yAxis)/100;
    double B = pow(R,exponent)*100, A = pow(S,exponent)*100; //Joystick scaled to make it easier to control
    Brain.Screen.printAt(10, 15, "Odom X: %.2f",x); //Prints out X value
    Brain.Screen.printAt(10, 30, "Odom Y: %.2f",y); //Prints out Y value
    Brain.Screen.printAt(10, 45, "Odom θ: %.2f", Q); //Prints out Angle
    Brain.Screen.printAt(10, 75, "Line Sensor: %d", dep.value(analogUnits::range12bit)); //Prints Left Encoder
    Brain.Screen.printAt(10, 90, "Right Encoder: %.1f", encoderR.position(degrees)); //Prints Right Encoder
    Brain.Screen.printAt(10, 105, "Back Encoder: %.1f", encoderY.rotation(degrees));  //Prints Back Encoder
    Brain.Screen.drawRectangle(10, 135, 96, 96 ); //Prints out Field
    Brain.Screen.drawCircle(15+x*2/3,226-y*2/3, 3,ClrCornflowerBlue); //Prints out Location of Robot
    if(xAxis<0) B=B*-1; //If joystick is negative, go in the negative direction
    if(yAxis<0) A=A*-1;
    if(deployOut){
      if(yAxis<0 || xAxis<0){
        rollerSpin(-100);
        driveSpin(-24);
      }
      else if(yAxis>0 || xAxis>0){
        driveSpin(18);
      }
      else{
        driveSpin(0);
        rollerSpin(0);
      }
    }
    else{
      if((A<0 && B>0) || (A>0 && B<0)){
        leftDrive.spin(forward, A*0.45, percent); //Drive Control
        rightDrive.spin(forward, B*0.45, percent);
      }
      else if((A<=0 && B<=0) || (A>=0 && B>=0)){
        /*if(A==0) leftDrive.stop(coast);
        else if(fabs(A)>fabs(leftDrive.velocity(pct)) && fabs(leftDrive.velocity(pct))<12) leftDrive.spin(forward,A/fabs(A) * 15, pct);
        else if(A-leftDrive.velocity(pct)>acc(leftDrive.velocity(pct))) leftDrive.spin(forward,leftDrive.velocity(pct)+acc(leftDrive.velocity(pct)), pct);
        else if(A-leftDrive.velocity(pct)<-(leftDrive.velocity(pct))) leftDrive.spin(forward,leftDrive.velocity(pct)-acc(leftDrive.velocity(pct)), pct);
        else */leftDrive.spin(forward,A*num,pct);
        /*if(B==0) rightDrive.stop(coast);
        else if(fabs(B)>fabs(rightDrive.velocity(pct)) && fabs(rightDrive.velocity(pct))<12) rightDrive.spin(forward,B/fabs(B) * 15, pct);
        else if(B-rightDrive.velocity(pct)>acc(rightDrive.velocity(pct))) rightDrive.spin(forward,rightDrive.velocity(pct)+acc(rightDrive.velocity(pct)), pct);
        else if(B-rightDrive.velocity(pct)<-acc(rightDrive.velocity(pct))) rightDrive.spin(forward,rightDrive.velocity(pct)-acc(rightDrive.velocity(pct)), pct);
        else */rightDrive.spin(forward,B*num,pct);
      }
      if(A==0) leftDrive.stop(coast);
      if(B==0) rightDrive.stop(coast);
    }
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
