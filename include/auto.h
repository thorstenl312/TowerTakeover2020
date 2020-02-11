#include "spline.h"
bool Red1 = true;
void Auton(){
  deployRobotTask();
  arm.spin(reverse,100,rpm);
  wait(300,msec);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  positiveYForward(22,60,30);
  arm.rotateFor(180, rotationUnits::deg,100, velocityUnits::pct,false);
  positiveYForward(25.5,45,30);
  while(arm.rotation(degrees)>30){
    arm.spin(reverse,200,rpm);
  }
  while(fabs(arm.velocity(pct))>1) wait(20,msec);
  arm.stop(hold);
  arm.resetRotation();
  if(Red1==false){
    splineLeft(30, -11, 200, 30);
  } 
  else{
    splineRight(-27, 10.1, 200, 30);
  }
  positiveYForward(48,60,30);
  rollerSpin(100);
  negativeYBackward(18.7,70,30);
  if(Red1==false){
    turnLeftO9(-127.5);
  }
  else{
    turnRightO9(127.5);
  }
  roller.spin(forward,100,pct);
  accelerate(100,30);
  wait(210,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  roller.stop(hold);
  deploy.spin(forward,90,pct);
  rollOut(40);
  stopDrive(hold);
  deployPIDAuton(0.90);
  wait(100,msec);
  rollerSpin(-100);
  driveSpin(-20);
  wait(250,msec);
  driveSpin(-45);
  wait(400,msec);
}




void Skills(){
  stopDrive(hold);
  deployRobot();
  wait(500,msec);
  roller.stop(coast);
  //Score First Cube in Tower
  arm.spin(reverse,70,pct);
  wait(300,msec);
  arm.stop(hold);
  arm.resetRotation();
  q=0;
  wait(200,msec);
  task a(rollIn80);
  positiveYForward(8,45,30);
  turnLeftO(-40,30);
  task::stop(a);
  arm.rotateTo(470,degrees,90,velocityUnits::pct,false);
  wait(200,msec);
  negativeXForward(-10.15, 50, 30);
  RollerL.rotateFor(-500,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-500,degrees,60, velocityUnits::pct,true);
  positiveXBackward(-2.3,50,30);
  task ar(armDown);

  //Get First Line of Cubes
  turnRightO(1.2,55,45);
  rollerSpin(100);
  positiveYForward(39,50,30);
  task::stop(ar);
  turnRightO(17.8,30);
  positiveYForward(49,45,30);

  //Put 2nd Cube in Tower
  negativeYBackward(44.2,45,30);
  turnLeftO(12.8,60);
  wait(150,msec);
  rollerSpin(0);
  task e(rollOut80);
  wait(75,msec);
  arm.rotateTo(510,degrees,85,velocityUnits::pct,true);
  wait(100,msec);
  RollerL.rotateFor(-700,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-700,degrees,60, velocityUnits::pct,true);
  task a2(armDown);
  wait(300,msec);

  //Get 2nd Line of Cubes
  turnLeftO(-60,30);
  negativeXForward(-6.9,35);
  turnRightO(-2,40,30);
  rollerSpin(100);
  positiveYForward(108.5,50,30);
  positiveYForward(112,45,30);
  rollerSpin(100);
  wait(1000,msec);
  negativeYBackward(107.5,45,30);
  task::stop(ar);

  //Get 3rd Cube in Tower
  task g(rollOut45);
  arm.rotateTo(480,degrees,100,velocityUnits::pct,true);
  task::stop(g);
  turnLeftO9(-90,30);
  waitUntil(fabs(FrontL.velocity(percent))<1);
  RollerL.rotateFor(-500,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-500,degrees,60, velocityUnits::pct,true);
  positiveXBackward(0.5,35,30);
  task a3(armDown);
  wait(200,msec);

  //Deploy Cubes in Goal
  turnRightO(-54.5,60,30);
  rollerSpin(60);
  arm.stop(hold);
  task::stop(a3);
  accelerate(100);
  arm.stop(hold);
  wait(300,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  arm.stop(hold);
  deploy.spin(forward,100,pct);
  rollOut(40);
  arm.stop(hold);
  stopDrive(hold);
  deployPIDAuton(0.9);
  arm.stop(hold);
  wait(100,msec);
  rollerSpin(-100);
  driveSpin(10);
  wait(270,msec);
  driveSpin(-25);
  wait(470,msec);
  driveSpin(0);
  rollerSpin(0);
  deployInF();

  //Go for 4th cube in Tower
  negativeYBackward(113.3,50,60);
  turnRightO(88,30,32);
  rollerSpin(70);
  positiveXForward(27,50,30);
  stopDrive(hold);
  wait(150,msec);
  negativeXBackward(22,45,30);
  stopDrive(hold);
  task z(rollOut80);
  wait(150,msec);
  arm.rotateTo(615,degrees,100,velocityUnits::pct);
  task::stop(z);
  positiveXForward(24,45,30);
  stopDrive(hold);
  RollerL.rotateFor(-700,degrees,65, velocityUnits::pct,false);
  RollerR.rotateFor(-700,degrees,65, velocityUnits::pct,true);
  stopDrive(hold);
  turnRightO(180,60,35);
  driveSpin(-50);
  wait(250,msec);
  task a4(armDown);
  while(fabs(BackR.velocity(rpm)) > 5 && fabs(BackL.velocity(rpm)) > 5 && fabs(FrontL.velocity(rpm)) > 5 && fabs(FrontR.velocity(rpm)) > 5) wait(20,msec);
  stopDrive(coast);
  wait(150,msec);  
  task::stop(a4);
  arm.stop(hold);
  
  //Go For 2nd Line of Cubes (STATE)
  rollerSpin(100);
  driveSpin(0);
  negativeYForward(10,60,30);
  //Place 5th Cube in Tower
  rollerSpin(70);
  wait(250,msec);
  stopDrive(hold);
  task zO(rollOut80);
  wait(150,msec);
  arm.rotateTo(610,degrees,100,velocityUnits::pct);
  task::stop(zO);
  turnLeftO(95,30,35);
  positiveXForward(26,45,30);
  stopDrive(hold);
  RollerL.rotateFor(-700,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-700,degrees,60, velocityUnits::pct,true);

  //Deploy Stack In Goal
  task k(armDown);
  negativeXBackward(-2,55,30);
  rollerSpin(60);
  //task::stop(k);
  turnRightO(220,50,40);
  accelerate(80,30);
  wait(400,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  arm.stop(hold);
  deploy.spin(forward,100,pct);
  rollOut(40);
  arm.stop(hold);
  stopDrive(hold);
  deployPIDAuton(1);
  wait(50,msec);
  driveSpin(15);
  rollerSpin(-100);
  wait(250,msec);
  driveSpin(-30);
  wait(600,msec);
  driveSpin(0);
  rollerSpin(0);
}







void Red2(){
  deployRobotTask();
  //deployRobot();
  arm.stop(coast);
  wait(100,msec);
  arm.spin(reverse,100,pct);
  wait(350,msec);
  arm.stop(hold);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  positiveYForward(43,50,30);
  task ro(rolle);
  arm.spin(reverse,20,pct);
  negativeYBackward(31.2,55,30);
  splineLeft(40, -7.6, 200, 30);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  forwardThenTurn(25, 24, true, false);
  roller.spin(forward,100,pct);
  accelerate(100,20);
  wait(870,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  roller.stop(hold);
  deploy.spin(forward,100,pct);
  rollOut(40);
  arm.stop(hold);
  stopDrive(hold);
  deployPIDAuton(0.9);
  rollerSpin(-100);
  driveSpin(12);
  wait(130,msec);
  leftDrive.setStopping(coast);
  rightDrive.setStopping(coast);
  driveSpin(-25);
  wait(250,msec);
  driveSpin(-45);
  wait(400,msec);
}
void Blue2(){
  deployRobotTask();
  //deployRobot();
  arm.stop(coast);
  wait(100,msec);
  arm.spin(reverse,100,pct);
  wait(350,msec);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  positiveYForward(43,50,30);
  task ro(rolle);
  arm.spin(reverse,20,pct);
  negativeYBackward(31.6,55,30);
  splineRight(-40, 7.5, 200, 30);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  forwardThenTurn(25.2, 25, false, false);
  roller.spin(forward,100,pct);
  accelerate(100,20);
  wait(900,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  roller.stop(hold);
  deploy.spin(forward,100,pct);
  rollOut(40);
  arm.stop(hold);
  stopDrive(hold);
  deployPIDAuton(0.9);
  rollerSpin(-100);
  driveSpin(12);
  wait(130,msec);
  leftDrive.setStopping(coast);
  rightDrive.setStopping(coast);
  driveSpin(-25);
  wait(250,msec);
  driveSpin(-45);
  wait(400,msec);
}
void Blue4(){
  deployRobotTask();
  //deployRobot();
  wait(400,msec);
  arm.spin(reverse,70,pct);
  wait(200,msec);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  positiveYForward(42,40,30);
  turnRightO(20,30);
  positiveYForward(47,50,30);
  turnLeftO(11,30);
  negativeYBackward(18,65,30);
  turnLeftO9(-131,30);
  accelerate(90,30);
  wait(200,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  roller.stop(hold);
  rollOut(35);
  stopDrive(hold);
  deployPIDAuton(0.9);
  wait(50,msec);
  rollerSpin(-80);
  wait(150,msec);
  leftDrive.setStopping(coast);
  rightDrive.setStopping(coast);
  driveSpin(-25);
  wait(350,msec);
  driveSpin(-45);
  wait(400,msec);
  stopDrive(coast);
}
void Red4(){
  deployRobotTask();
  //deployRobot();
  arm.stop(coast);
  wait(400,msec);
  arm.spin(reverse,100,pct);
  wait(400,msec);
  arm.stop(hold);
  roller.spin(forward,100,pct);
  positiveYForward(40,40,30);
  turnLeftO(-20,30);
  positiveYForward(46,50,30);
  turnRightO(-11,30);
  negativeYBackward(18,65,30);
  turnRightO9(132,30);
  accelerate(90,30);
  wait(200,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  roller.stop(hold);
  rollOut(35);
  stopDrive(hold);
  deployPIDAuton(0.9);
  wait(50,msec);
  rollerSpin(-80);
  wait(50,msec);
  leftDrive.setStopping(coast);
  rightDrive.setStopping(coast);
  driveSpin(-25);
  wait(350,msec);
  driveSpin(-45);
  wait(400,msec);
  stopDrive(coast);
}
