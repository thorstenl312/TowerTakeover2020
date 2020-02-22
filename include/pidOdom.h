#include "odomPI.h"
#define kpO 0.23
#define kdO 0.04
#define kiO 0.01
#define kpOT 0.6///79
#define kdOT 0.04
#define kiOT 0.00008
#define kpOC 0.485
#define kdOC 0.00
#define kiOC 0.025
void positiveYForward(float pos, int maxPower = 75, int tim = 150) {
	float dif,error, lasterror = pos, totalerror = 0, t = 0, speed = 0, turnCorrection = 0, Power=30;
	while (t<tim) {
		dif = (pos-y)/(fabs(cos(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if((speed-FrontL.velocity(percent))>=10 && error>100) speed=FrontL.velocity(percent)+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(forward, speed, percent); //Give Power to Motors
		BackR.spin(forward, speed, percent);
    FrontL.spin(forward, speed, percent);
    BackL.spin(forward, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void negativeYForward(float pos, int maxPower = 75, int tim = 150) {
	float dif,error, lasterror = pos, totalerror = 0, t = 0, speed = 0, turnCorrection = 0, Power=30;
	while (t<tim) {
		dif = (y-pos)/(fabs(cos(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if((speed-FrontL.velocity(percent))>=10 && error>100) speed=FrontL.velocity(percent)+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(forward, speed, percent); //Give Power to Motors
		BackR.spin(forward, speed, percent);
    FrontL.spin(forward, speed, percent);
    BackL.spin(forward, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15 , msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void negativeYBackward(float pos,int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos, totalerror = 0,t = 0, speed = 0, turnCorrection = 0, dif, Power = 30;
	while (t<tim) {
		dif = (y-pos)/(fabs(cos(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if(speed-(fabs(FrontL.velocity(percent)))>=10 && error>100) speed=fabs(FrontL.velocity(percent))+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(reverse, speed, percent);
		BackR.spin(reverse, speed, percent);
    FrontL.spin(reverse, speed, percent);
    BackL.spin(reverse, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
	}

	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void positiveYBackward(float pos,int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos,Power=10, totalerror = 0,t = 0, speed = 0, turnCorrection = 0, dif;
	while (t<tim) {
		dif = (pos-y)/(fabs(cos(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if(speed-(fabs(FrontL.velocity(percent)))>=10 && error>100) speed=fabs(FrontL.velocity(percent))+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(reverse, speed, percent);
		BackR.spin(reverse, speed, percent);
    FrontL.spin(reverse, speed, percent);
    BackL.spin(reverse, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
	}

	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void positiveXForward(float pos, int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos, totalerror = 0, t = 0, speed = 0, turnCorrection = 0, Power= 15;
	while (t<tim) {
		float dif = (pos - x)/(fabs(sin(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if((speed-FrontL.velocity(percent))>=10 && error>100) speed=FrontL.velocity(percent)+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
    turnCorrection = (encoderL.rotation(deg) - encoderR.rotation(deg)); //Anti-Strafe
		FrontR.spin(forward, speed, percent); //Give Power to Motors
		BackR.spin(forward, speed, percent);
    FrontL.spin(forward, speed, percent);
    BackL.spin(forward, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void negativeXForward(float pos, int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos,Power=10, totalerror = 0, t = 0, speed = 0, turnCorrection = 0;
	while (t<tim) {
		float dif = (x-pos)/(fabs(sin(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if((speed-FrontL.velocity(percent))>=10 && error>100) speed=FrontL.velocity(percent)+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(forward, speed, percent); //Give Power to Motors
		BackR.spin(forward, speed, percent);
    FrontL.spin(forward, speed, percent);
    BackL.spin(forward, speed, percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
  }
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void negativeXBackward(float pos,int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos,Power=10, totalerror = 0, t = 0, speed = 0, turnCorrection = 0, dif = 0;
	while (t<tim) {
		dif = (x-pos)/(fabs(sin(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if(speed-(fabs(FrontL.velocity(percent)))>=10 && fabs(error)>300) speed=fabs(FrontL.velocity(percent))+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(reverse, speed, percent);
		BackR.spin(reverse, speed , percent);
    FrontL.spin(reverse, speed, percent);
    BackL.spin(reverse, speed , percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
	}

	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void positiveXBackward(float pos,int maxPower = 75, int tim = 150) {
	float error = 300, lasterror = pos, Power=30, totalerror = 0, t = 0, speed = 0, turnCorrection = 0;
	while (t<tim) {
		float dif = (pos-x)/(fabs(sin(q))); //Distance Left = Total Distance - Current 
    error = dif/SPIN_TO_IN_LR;
		if (error <= 0)totalerror = 0; //If outside useful range, set to 0
		if (fabs(error) < 120 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpO, D = derivative * kdO, I = totalerror * kiO;
    speed=P+I+D;
    if(speed-(fabs(FrontL.velocity(percent)))>=10 && error>100) speed=fabs(FrontL.velocity(percent))+10; //Acceleration 
    if(speed>=maxPower)speed=maxPower;
		FrontR.spin(reverse, speed , percent);
		BackR.spin(reverse, speed , percent);
    FrontL.spin(reverse, speed , percent);
    BackL.spin(reverse, speed , percent);
		lasterror = error;
    if(error>30) t = 0;
    t = t+15;
		wait(15, msec);
	}

	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void turnRightO9(float pos, int tim = 100, int maxSpeed = 50) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (error>3) {
		error = pos-Q;
		if (fabs(error) < 30 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpOC*1.05, D = derivative * kdOC, I = totalerror * kiOC;
    Power=P+I+D;
    if(Power>=maxSpeed)Power=maxSpeed;
		FrontL.spin(forward, Power, percent);
		BackL.spin(forward, Power, percent);
    FrontR.spin(reverse, Power, percent);
    BackR.spin(reverse, Power, percent);
		lasterror = error;
		wait(15, msec);
	}
  stopDrive(hold);
  wait(150,msec);
}
void turnLeftO(float pos, int tim = 250, int maxSpeed = 50) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (t<tim) {
		error = Q-pos;
		if (error < 0)totalerror = 0;
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpOT, D = derivative * kdOT, I = totalerror * kiOT;
    Power=P+I+D;
    if(Power>=maxSpeed)Power=maxSpeed;
		FrontR.spin(forward, Power, percent);
		BackR.spin(forward, Power, percent);
    FrontL.spin(reverse, Power, percent);
    BackL.spin(reverse, Power, percent);
		lasterror = error;
    if(error>2) t = 0;
    t += 15;
		wait(15, msec);
	}
  FrontR.spin(reverse, 5, percent);
	BackR.spin(reverse, 5, percent);
  FrontL.spin(forward, 5, percent);
  BackL.spin(forward, 5, percent);
  wait(50,msec);
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void turnRightO(float pos, int tim = 250, int maxSpeed = 50, double n = 1, double m =1) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (t<tim) {
		error = pos-Q;
		if (fabs(error) < 25 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpOT*m, D = derivative * kdOT*m, I = totalerror * kiOT *n;
    Power=P+I+D;
    if(Power>maxSpeed)Power=maxSpeed;
		FrontR.spin(reverse, Power, percent);
		BackR.spin(reverse, Power, percent);
    FrontL.spin(forward, Power, percent);
    BackL.spin(forward, Power, percent);
		lasterror = error;
    if(error>2) t = 0;
    t += 15;
		wait(15, msec);
	}
  FrontR.spin(forward, 5, percent);
	BackR.spin(forward, 5, percent);
  FrontL.spin(reverse, 5, percent);
  BackL.spin(reverse, 5, percent);
  wait(50,msec);
	//Stops motor to ensure accuracy
  stopDrive(coast);
}
void turnLeftO9(float pos, int tim = 100,int max=50) {
	float error = 300, lasterror = pos, totalerror = 0, t=0, Power= 10;
  //Clears the encoder
	while (error>3) {
		error = Q-pos;
		if (fabs(error) < 30 && error != 0)totalerror += error;
		else totalerror = 0;
    if (error < 0)totalerror = 0;
		//Calculation for the P, I, D terms
		float derivative = error - lasterror;
		float P = error * kpOC*1.05, D = derivative * kdOC, I = totalerror * kiOC;
    Power=P+I+D;
    if(Power>=max)Power=max;
		FrontR.spin(forward, Power, percent);
		BackR.spin(forward, Power, percent);
    FrontL.spin(reverse, Power, percent);
    BackL.spin(reverse, Power, percent);
		lasterror = error;
    if(error>2) t = 0;
    t += 15;
		wait(15, msec);
	}
  stopDrive(hold);
  wait(150,msec);
}
void swingLeft(int speed1,double angl){
  double error2=100;
  while(error2>2){
    error2  = angl-fabs(Q);
    leftDrive.stop(brake);
    if(error2>15) rightDrive.spin(forward,speed1*0.6,rpm);
    else rightDrive.spin(forward,speed1,rpm);
  }
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}
void swingRight(int speed1,double angl){
  double error2=100;
  while(error2>2){
    error2  = angl-fabs(Q);
    if(error2<15){
      leftDrive.spin(forward,speed1*0.3,rpm);
      rightDrive.spin(reverse,speed1*0.3,rpm);
    }
    else if(error2<35){
      leftDrive.spin(forward,speed1*0.6,rpm);
      rightDrive.spin(reverse,speed1*0.6,rpm);
    } 
    else{
      leftDrive.spin(forward,speed1,rpm);
      rightDrive.spin(reverse,speed1,rpm);
    }
  }
  stopDrive(hold);
  wait(100,msec);
  stopDrive(coast);
}
void forwardThenTurn(double Y, int speed, bool red, bool swing){
  double error=30;
  while(error>0.5){
    error = Y-y;
    driveSpin(speed);
  }
  arm.spin(reverse,200,rpm);
  wait(250,msec);
  while(fabs(arm.velocity(percent))>1){
    wait(20,msec);
  }
  arm.resetRotation();
  arm.stop(hold);
  if(red){
    turnRightO9(122);
  }
  else{
    turnLeftO9(-123.5);
  }
}