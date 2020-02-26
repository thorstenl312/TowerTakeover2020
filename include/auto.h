#include "spline.h"
bool Red1 = true;
bool old = true;
void Auton(){
  if(Red1){
    deployRobotTask();
    arm.spin(reverse,100,rpm);
    wait(400,msec);
    arm.stop(hold);
    roller.spin(forward,100,pct);
    positiveYForward(23.5,60,30);
    wait(150,msec);
    arm.rotateFor(180, rotationUnits::deg,100, velocityUnits::pct,false);
    positiveYForward(27.5,45,30);
    while(arm.rotation(degrees)>30){
      arm.spin(reverse,200,rpm);
    }
    while(fabs(arm.velocity(pct))>1) wait(20,msec);
    arm.stop(hold);
    arm.resetRotation();
    splineRight(-29, 9.6, 200, 30); 
    positiveYForward(46,52,30);
    rollerSpin(100);
    negativeYBackward(20.4,70,30);
    turnRightO9(128);
    roller.spin(forward,100,pct);
    accelerate(100,30);
    wait(250,msec);
    stopDrive(coast);
    while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
    roller.stop(hold);
    deploy.spin(forward,100,pct);
    rollOut(40);
    stopDrive(hold);
    deployPIDAuton(1);
    driveSpin(15);
    rollerSpin(-100);
    wait(150,msec);
    driveSpin(-20);
    wait(150,msec);
    driveSpin(-45);
    wait(500,msec);
  }
  else{
    deployRobotTask();
    arm.spin(reverse,100,rpm);
    wait(400,msec);
    arm.stop(hold);
    roller.spin(forward,100,pct);
    positiveYForward(23.5,60,30);
    wait(100,msec);
    arm.rotateFor(180, rotationUnits::deg,100, velocityUnits::pct,false);
    positiveYForward(27,45,30);
    while(arm.rotation(degrees)>30){
      arm.spin(reverse,200,rpm);
    }
    while(fabs(arm.velocity(pct))>1) wait(20,msec);
    arm.stop(hold);
    arm.resetRotation();
    splineLeft(29, -9.75, 200, 30); 
    positiveYForward(46,52,30);
    rollerSpin(100);
    negativeYBackward(21.5,70,30);
    rollerSpin(50);
    turnLeftO9(-128,30);
    roller.spin(forward,100,pct);
    accelerate(100,30);
    wait(250,msec);
    stopDrive(coast);
    while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
    roller.stop(hold);
    deploy.spin(forward,100,pct);
    rollOut(40);
    stopDrive(hold);
    deployPIDAuton(1);
    driveSpin(15);
    rollerSpin(-100);
    wait(140,msec);
    driveSpin(-20);
    wait(100,msec);
    driveSpin(-45);
    wait(500,msec);
  }
}




void Skills(){
  stopDrive(hold);
  deployRobot();
  wait(300,msec);
  roller.stop(coast);
  //Score First Cube in Tower
  arm.spin(reverse,70,pct);
  wait(300,msec);
  arm.stop(hold);
  arm.resetRotation();
  arm.stop(coast);
  q=0;
  wait(200,msec);
  arm.stop(hold);
  arm.spin(reverse,30,rpm);
  task a(rollIn80);
  positiveYForward(6.5,45,30);
  arm.stop(hold);
  turnLeftO(-41,30,45);
  task::stop(a);
  arm.rotateTo(470,degrees,90,velocityUnits::pct,false);
  wait(200,msec);
  negativeXForward(-9.9, 50, 30);
  RollerL.rotateFor(-500,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-500,degrees,60, velocityUnits::pct,true);
  positiveXBackward(-1.9,50,30);
  task ar(armDown);

  //Get First Line of Cubes
  turnRightO(-0.7,55,45);
  rollerSpin(100);
  positiveYForward(39,50,30);
  task::stop(ar);
  turnRightO(19.5,30);
  positiveYForward(49,40,30);

  //Put 2nd Cube in Tower
  rollerSpin(100);
  negativeYBackward(44.5,45,30);
  rollerSpin(100);
  turnLeftO(13,30);
  rollerSpin(100);
  wait(150,msec);
  rollerSpin(0);
  task e(rollOut45);
  arm.rotateTo(510,degrees,85,velocityUnits::pct,true);
  wait(100,msec);
  RollerL.rotateFor(-700,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-700,degrees,60, velocityUnits::pct,true);
  task a2(armDown);
  wait(150,msec);

  //Get 2nd Line of Cubes
  turnLeftO(-60,30);
  negativeXForward(-6.05,35,30);
  turnRightO(-2.2,30,30);
  rollerSpin(100);
  positiveYForward(108.5,50,30);
  positiveYForward(112,45,30);
  rollerSpin(100);
  wait(1000,msec);
  negativeYBackward(109,45,30);
  task::stop(ar);

  //Get 3rd Cube in Tower
  task g(rollOut45);
  arm.rotateTo(480,degrees,100,velocityUnits::pct,true);
  task::stop(g);
  turnLeftO9(-83,30);
  waitUntil(fabs(FrontL.velocity(percent))<1);
  RollerL.rotateFor(-500,degrees,60, velocityUnits::pct,false);
  RollerR.rotateFor(-500,degrees,60, velocityUnits::pct,true);
  driveSpin(-30);
  wait(100,msec);
  stopDrive(coast);
  task a3(armDown);
  positiveXBackward(0.3,35,30);
  wait(400,msec);

  //Deploy Cubes in Goal
  turnRightO(-58,30,30);
  rollerSpin(60);
  arm.stop(hold);
  task::stop(a3);
  rollerSpin(100);
  accelerate(100);
  arm.stop(hold);
  wait(430,msec);
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
  wait(250,msec);
  driveSpin(-25);
  wait(200,msec);
  driveSpin(0);
  rollerSpin(0);
  wait(150,msec);

  //Go for 4th cube in Tower
  negativeYBackward(117,50,60);
  deployInF();
  rollerSpin(60);
  turnRightO(91.2,30,30);
  rollerSpin(60);
  positiveXForward(32.2,55,30);
  stopDrive(hold);
  wait(150,msec);
  negativeXBackward(29,45,30);
  task z(rollOut45);
  wait(150,msec);
  arm.rotateTo(615,degrees,100,velocityUnits::pct);
  task::stop(z);
  driveSpin(20);
  wait(30,msec);
  driveSpin(50);
  wait(470,msec);
  stopDrive(coast);
  wait(350,msec);
  driveSpin(-20);
  wait(30,msec);
  driveSpin(-50);
  wait(320,msec);
  stopDrive(hold);
  RollerL.rotateFor(-600,degrees,45, velocityUnits::pct,false);
  RollerR.rotateFor(-600,degrees,45, velocityUnits::pct,true);
  stopDrive(hold);
  turnRightO(187,30,50);
  driveSpin(-60);
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
  if(old){
  accelerate(70,30);
  wait(250,msec);
  while(fabs(BackR.velocity(rpm)) > 5 && fabs(BackL.velocity(rpm)) > 5 && fabs(FrontL.velocity(rpm)) > 5 && fabs(FrontR.velocity(rpm)) > 5) wait(20,msec);
  positiveYBackward(9,50,30);
  //Place 5th Cube in Tower
  rollerSpin(100);
  stopDrive(hold);
  task zO(rollOut45);
  arm.rotateTo(610,degrees,100,velocityUnits::pct);
  task::stop(zO);
  turnLeftO(99,30,35);
  driveSpin(30);
  wait(350,msec);
  stopDrive(hold);
  RollerL.rotateFor(-600,degrees,40, velocityUnits::pct,false);
  RollerR.rotateFor(-600,degrees,40, velocityUnits::pct,true);

  //Deploy Stack In Goal
  task k(armDown2);
  negativeXBackward(0,50,30);
  stopDrive(hold);
  wait(100,msec);
  rollerSpin(60);
  //task::stop(k);
  turnRightO(220,30,60);
  rollerSpin(100);
  accelerate(80,30);
  wait(350,msec);
  stopDrive(coast);
  while(BackR.velocity(rpm) > 5 && BackL.velocity(rpm) > 5) wait(20,msec);
  arm.stop(hold);
  deploy.spin(forward,90,pct);
  rollOut(40);
  arm.stop(hold);
  stopDrive(hold);
  deployPIDAuton(1);
  wait(50,msec);
  rollerSpin(-100);
  wait(250,msec);
  driveSpin(-30);
  wait(600,msec);
  driveSpin(0);
  rollerSpin(0);}

  else{
    negativeYForward(18,70,30);
    //Place 5th Cube in Tower
    rollerSpin(100);
    wait(1000,msec);
    stopDrive(hold);
    task zO(rollOut80);
    arm.rotateTo(610,degrees,100,velocityUnits::pct,false);
    task::stop(zO);
    turnLeftO(60,30,35);
    driveSpin(70);
    wait(700,msec);
    driveSpin(-45);
    wait(300,msec);
    stopDrive(hold);
    RollerL.rotateFor(-600,degrees,50, velocityUnits::pct,false);
    RollerR.rotateFor(-600,degrees,50, velocityUnits::pct,true);
    task ip(armDown);
    negativeYBackward(25,75,30);
    //Deploy Stack In Goal
    turnLeftO(30,30,70);
    task::stop(ip);
    positiveXForward(75,80,30);
    turnRightO(140,30,70);
    accelerate(100,30);
    wait(700,msec);
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
  forwardThenTurn(25, 22, true, false);
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
