#include "vex.h"
float o;
int z = 0;
int count = 0;
bool deployOut = false;
bool skills = true;
bool fast = false;
int deplo = 0;
//Things or Multitasking
motor_group leftDrive(FrontL, BackL);
motor_group rightDrive(FrontR, BackR);
motor_group roller(RollerL, RollerR);
int acc(double cV){
  double n= pow(1.5,fabs(cV));
  if(n>30) n = 30;
  return n;
}
void accelerate(int maxSpeed,int tim = 60){
  for(int i = 1; i<=maxSpeed/10; i++){
    leftDrive.spin(forward,i*10,pct);
    rightDrive.spin(forward,i*10,pct);
    wait(tim,msec);
  }
  leftDrive.spin(forward,maxSpeed,pct);
  rightDrive.spin(forward,maxSpeed,pct);
}
void stopDrive(brakeType b){
  leftDrive.stop(b);
  rightDrive.stop(b);
}
void rollOut(int speed){
  roller.setStopping(hold);
  while(dep.value(analogUnits::range12bit) >1800){
    roller.spin(reverse, speed,pct);
  }
  roller.stop(hold);
}
void rollOutA(int speed){
  roller.setStopping(hold);
  while(check.value(analogUnits::range12bit) >2000){
    roller.spin(reverse, speed,pct);
  }
  roller.stop(hold);
}
int rollOut80(){
  while(check.value(analogUnits::range12bit) >2000){
    roller.spin(reverse, 35,pct);
  }
  roller.stop(hold);
  return(0);
}
int rollOutDep(){
  while(dep.value(analogUnits::range12bit) >2000){
    roller.spin(reverse, 60,pct);
  }
  roller.stop(hold);
  return(0);
}
int rollOut45(){
  while(check.value(analogUnits::range12bit) >2400){
    roller.spin(reverse, 60,pct);
  }
  roller.stop(hold);
  return(0);
}
int rollOut60(){
  while(check.value(analogUnits::range12bit) >2400){
    roller.spin(reverse, 60,pct);
  }
  roller.stop(hold);
  return(0);
}
int rollIn80(){
  while(check.value(analogUnits::range12bit) > 2400){
    roller.spin(forward, 80,pct);
  }
  roller.stop(hold);
  return(0);
}
int deployIn(){
  deploy.spin(reverse,100,velocityUnits::pct);
  wait(500,msec);
  deploy.stop(coast);
  while(fabs(deploy.velocity(percent))>1){
    wait(20,msec);
  }
  deploy.resetRotation();
  wait(50,msec);
  deploy.stop(coast);
  
  return(0);
}
void deployInF(){
  roller.stop(coast);
  deploy.spin(reverse,100,velocityUnits::pct);
  wait(300,msec);
  while(fabs(deploy.velocity(percent))>1){
    wait(20,msec);
  }
  roller.spin(forward,80,pct);
  deploy.resetRotation();
  wait(50,msec);
  deploy.stop(coast);
}
int armDown(){
  arm.spin(reverse,200,rpm);
      wait(250,msec);
      roller.spin(forward,45,pct);
      while(arm.rotation(degrees)>30){
        arm.spin(reverse,200,rpm);
      }
      while(fabs(arm.velocity(pct))>1) wait(20,msec);
      arm.resetRotation();
      arm.spin(forward,200,rpm);
      wait(120,msec);
      arm.stop(hold);
      wait(100,msec);
      roller.spin(forward,100,pct);
  return(0);
}
int armDown2(){
  wait(200,msec);
  arm.spin(reverse,200,rpm);
      wait(250,msec);
      roller.spin(forward,45,pct);
      while(arm.rotation(degrees)>30){
        arm.spin(reverse,200,rpm);
      }
      while(fabs(arm.velocity(pct))>1) wait(20,msec);
      arm.resetRotation();
      arm.spin(forward,200,rpm);
      wait(120,msec);
      arm.stop(hold);
      wait(100,msec);
      roller.spin(forward,100,pct);
  return(0);
}
int rollerControl(){
  while(true){
    if(Controller1.ButtonR1.pressing() && arm.rotation(degrees)<360){
      while(Controller1.ButtonR1.pressing()){
        roller.spin(forward,100,pct);
      }
      roller.stop(hold);
    }
    else if(Controller1.ButtonR1.pressing() && arm.rotation(degrees)>360){
      while(Controller1.ButtonR1.pressing()){
        roller.spin(reverse,60,pct);
      }
      roller.stop(hold);
    }
    else if(Controller1.ButtonR2.pressing()){
      while(Controller1.ButtonR2.pressing()){
        roller.spin(reverse,100,pct);
      }
      roller.stop(hold);
    }
  }
  return(0);
}
int rolle(){
  wait(850,msec);
  roller.stop(hold);
  return(0);
}
void rollerSpin(int speed){
  roller.spin(forward, speed, percent);
}
void driveSpin(int speed){
  leftDrive.spin(forward, speed, percent);
  rightDrive.spin(forward, speed, percent);
}
void deployPIDAuton(double num = 1){
  deployOut = true;
  double KP = 0.23*num;
  arm.stop(hold);
  int error = 30;
  if(dep.value(analogUnits::range12bit) >2000) rollOut(35);
  roller.stop(hold);
  while(abs(error)>5){
    stopDrive(hold);
    error = 760 - deploy.rotation(degrees);
    double speed = error *KP;
    if(speed < 35) speed = 35;
    //else if (speed<30) speed = 50;
    if(error<370) roller.stop(coast);
    deploy.spin(forward, speed, rpm);
    wait(15,msec);
  }
  deploy.stop(hold);
  stopDrive(coast);
}
void deployPIDFast(double num = 1){
  deployOut = true;
  double KP = 0.2*num;
  arm.stop(hold);
  int error = 30;
  task u(rollOutDep);
  while(abs(error)>5){
    stopDrive(hold);
    error = 553 - deploy.rotation(degrees);
    double speed = error *KP;
    if(speed < 55) speed = 55;
    if(speed > 55) speed = 100;
    roller.stop(coast);
    deploy.spin(forward, speed, rpm);
    wait(15,msec);
  }
  deploy.stop(hold);
  stopDrive(coast);
  task::stop(u);
}
void deployPID(double num =1){
  deployOut = true;
  double KP = 0.18*num;
  deploy.resetRotation();
  arm.stop(hold);
  int error = 30;
  if(dep.value(analogUnits::range12bit) >2000) rollOut(35);
  roller.stop(hold);
  while(abs(error)>5){
    stopDrive(hold);
    error = 760 - deploy.rotation(degrees);
    double speed = error *KP;
    if(speed < 30) speed = 30;
    //else if (speed<30) speed = 50;
    if(error<410) roller.stop(coast);
    deploy.spin(forward, speed, rpm);
    wait(15,msec);
  }
  deploy.stop(hold);
  stopDrive(coast);
}
void deployPIDSkills(){
  double KP = 0.22;
  int min = 43;
  //deploy.resetRotation();
  arm.stop(hold);
  int error = 30;
  /*if(deploy.rotation(deg)>30){
    KP = 0.225;
    min = 30;
  }*/
  if(deploy.rotation(deg) <150)deploy.spin(forward,80,rpm);
  rollOut(40);
  roller.stop(hold);
  while(abs(error)>5){
    error = 760 - deploy.rotation(degrees);
    double speed = error *KP;
    if(speed < min) speed = min;
    if(speed>75) speed = 100;
    if(error<320) {
      roller.stop(coast);
      deployOut = true;
    }
    deploy.spin(forward, speed, rpm);
    wait(15,msec);
  }
  deployOut = true;
  deploy.stop(hold);
  rollerSpin(0);
}
void deployRobot(){
  stopDrive(hold);
  arm.rotateFor(300,degrees,70,velocityUnits::pct);
  arm.spin(reverse,100,pct);
  wait(450,msec);
  while(fabs(arm.velocity(pct))>1) wait(20,msec);
  arm.stop(hold);
  arm.resetRotation();
}
void deployRobotTask(){
  arm.resetRotation();
  stopDrive(hold);
  arm.rotateFor(220,degrees,100,velocityUnits::pct);
  while(arm.rotation(degrees)>30){
    arm.spin(reverse,100,pct);
  }
  while(fabs(arm.velocity(pct))>1) wait(20,msec);
  arm.stop(hold);
  arm.resetRotation();
}
int armControl(){
  while(true){
    if((partnerC.ButtonA.pressing()&&Controller1.ButtonL1.pressing()) || Controller1.ButtonRight.pressing()){
      task d(rollOut45);
      arm.rotateTo(610,degrees,95,velocityUnits::pct,true);
      rollerSpin(0);
      task::stop(d);
    }
    else if(Controller1.ButtonL1.pressing() && arm.rotation(degrees)<200){
      task e(rollOut45);
      arm.rotateTo(465,degrees,95,velocityUnits::pct,true);
      rollerSpin(0);
      task::stop(e);
    }
    else if(Controller1.ButtonL1.pressing() && arm.rotation(degrees)>200){
      arm.rotateTo(610,degrees,95,velocityUnits::pct,true);
    }
    else if(Controller1.ButtonL2.pressing()){
      arm.spin(reverse,200,rpm);
      wait(250,msec);
      roller.spin(forward,45,pct);
      while(arm.rotation(degrees)>30){
        arm.spin(reverse,200,rpm);
        if(Controller1.ButtonL1.pressing()){
          arm.spin(forward,100,pct);
          wait(150,msec);
          break;
        }
      }
      while(fabs(arm.velocity(pct))>1) wait(20,msec);
      arm.resetRotation();
      arm.spin(forward,200,rpm);
      wait(120,msec);
      arm.stop(hold);
      wait(100,msec);
      roller.stop(coast);
    }
    else{
      arm.stop(hold);
    }
    if(Controller1.ButtonDown.pressing() || partnerC.ButtonR1.pressing()){
      if(deploy.rotation(deg)<150){
      rollOutA(30);
      roller.stop(hold);
      while(deploy.rotation(deg)<180){
        deploy.spin(forward,90,rpm);
      }
      while(deploy.rotation(deg)<270){
        deploy.spin(forward,45,rpm);
      }
      deploy.stop(hold);
      }
      else{
        rollerSpin(0);
      }
    }
    else if(partnerC.ButtonR2.pressing()){
      if(deploy.rotation(deg)<150){
      rollOut(30);
      roller.stop(hold);
      while(deploy.rotation(deg)<180){
        deploy.spin(forward,90,rpm);
      }
      while(deploy.rotation(deg)<270){
        deploy.spin(forward,45,rpm);
      }
      deploy.stop(hold);
      }
      else{
        rollerSpin(0);
      }
    }
    else if(Controller1.ButtonUp.pressing()){
      while(Controller1.ButtonUp.pressing()){
        deploy.spin(forward,30,rpm);
      }
      deploy.stop(hold);
    }
    else if(Controller1.ButtonB.pressing()){
      if(deployOut){
        deployOut = false;
        roller.stop(coast);
        deploy.spin(reverse,75,velocityUnits::pct);
        wait(300,msec);
        while(fabs(deploy.velocity(percent))>1){
          wait(20,msec);
        }
        deploy.resetRotation();
        wait(50,msec);
        deploy.spin(forward,75,velocityUnits::pct);
        wait(100,msec);
        deploy.stop(coast);
      }
      else{
        if(skills){
          deployPIDSkills();
        } 
        else deployPID();
      }
      
    }
    if(Controller1.ButtonLeft.pressing()){
      while(Controller1.ButtonLeft.pressing()){
        deploy.spin(reverse,35,rpm);
      }
      deploy.stop(coast);
    }
  }
  return(0);
}
void intakeStack(){
  rollerSpin(-40);
  driveSpin(40);
  wait(150,msec);
  driveSpin(80);
  rollerSpin(100);
  wait(400,msec);
}
