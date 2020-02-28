#include "pidOdom.h"
void splineLeft(float firstAngle, float X, int speed, int speed2){
  while(fabs(firstAngle-Q)>2){
    rightDrive.spin(reverse,speed,rpm);
    leftDrive.spin(reverse,speed2,rpm);
  }
  while(fabs(X-x)>5){
    rightDrive.spin(reverse,speed,rpm);
    leftDrive.spin(reverse,speed,rpm);
  }
  while(fabs(X-x)>1){
    rightDrive.spin(reverse,speed*0.5,rpm);
    leftDrive.spin(reverse,speed*0.5,rpm);
  }
  stopDrive(brake);
  double error = 30;
  while(error>4.3){
    error = fabs(Q)-1.5;
    int zoom = error*2.5;
    if(zoom<=55){
      zoom = 55;
    }
    rightDrive.stop(brake);
    leftDrive.spin(reverse,zoom,rpm);
    wait(20,msec);
  }
  stopDrive(hold);
}
void splineRight(float firstAngle, float X, int speed, int speed2){
  while(fabs(Q-firstAngle)>2){
    rightDrive.spin(reverse,speed2,rpm);
    leftDrive.spin(reverse,speed,rpm);
  }
  while(fabs(x-X)>1){
    rightDrive.spin(reverse,speed,rpm);
    leftDrive.spin(reverse,speed,rpm);
  }
  stopDrive(brake);
  int error = 30;
  while(error>2){
    error = fabs(Q)-2;
    int zoom = error*2.4;
    if(zoom<=50){
      zoom = 50;
    }
    leftDrive.stop(brake);
    rightDrive.spin(reverse,zoom,rpm);
    wait(20,msec);
  }
  //leftDrive.stop(brake);
  //rightDrive.stop(coast);
  //turnRightO(0);
	//Stops motor to ensure accuracy
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}
void uTurnLeft(int speed1, int speed2,int angl){
  leftDrive.spin(forward,speed2,rpm);
  int error2=100;
  while(error2>2){
    error2  = angl+Q;
    rightDrive.spin(forward,speed1,rpm);
  }
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}