#include "task.h"
#define WHEEL_DIAMETER_IN_LR 3.28 //Diameter of tracking wheels
#define WHEEL_DIAMETER_IN_S 3.28
double pi = 3.14159;
// The distance between the tracking wheels and the centre of the robot in inches
#define L_DISTANCE_IN 2.75 //Distance of tracking wheels to center of robot
#define R_DISTANCE_IN 2.75
#define S_DISTANCE_IN 4.75 //Distance of back tracking wheel to center of robot
// The number of tick per rotation of the tracking wheel
#define TICKS_PER_ROTATION 360.0
#define SPIN_TO_IN_LR (WHEEL_DIAMETER_IN_LR * 3.14159265 / TICKS_PER_ROTATION) //Converts Ticks to Inches
#define SPIN_TO_IN_S (WHEEL_DIAMETER_IN_S * 3.14159265 / TICKS_PER_ROTATION)
double a = 0, y = 0, x = 0, q = 0, Q = 0, L = 0, R = 0; //Variables used later on
int leftLst = 0;
int rightLst = 0;
int backLst = 0;
int trackPosition()
{
  while(true){
  int left = encoderL.position(degrees);
  int right = encoderR.position(degrees);
  int back = encoderY.position(degrees);
	L = (left - leftLst) * SPIN_TO_IN_LR; // The amount the left side of the robot moved
	R = (right - rightLst) * SPIN_TO_IN_LR; // The amount the right side of the robot moved
	double S = (back - backLst) * SPIN_TO_IN_S; // The amount the back side of the robot moved
	// Update the last values
	leftLst = left;
	rightLst = right;
	backLst = back;

	double h; // The hypotenuse of the triangle formed by the middle of the robot on the starting position and ending position and the middle of the circle it travels around
	double i; // Half on the angle that I've traveled
	double h2; // The same as h but using the back instead of the side wheels
	a = ((L - R) / (L_DISTANCE_IN + R_DISTANCE_IN))*1.01; // The angle that I've traveled
	if (a)
	{
		double r = R / a; // The radius of the circle the robot travel's around with the right side of the robot
		i = a / 2.0;
		double sinI = sin(i);
		h = ((r + R_DISTANCE_IN) * sinI) * 2.0;

		double r2 = S / a; // The radius of the circle the robot travel's around with the back of the robot
		h2 = ((r2 + S_DISTANCE_IN) * sinI) * 2.0;
	}
	else
	{
		h = R;
		i = 0;

		h2 = S;
	}
	double p = i + q; // The global ending angle of the robot
	double cosP = cos(p);
	double sinP = sin(p);

	// Update the global position
	y += h * cosP;
	x += h * sinP;

	y += h2 * -sinP; // -sin(x) = sin(-x)
	x += h2 * cosP; // cos(x) = cos(-x)
	q += a; //Angle
  if(q>=6.2831853) q=q-6.2831853; //"Wrapping" doesn't count over 360/below -360
  else if(q<= -6.2831853) q=q+6.2831853;
  Q = q*180/pi; //Converts radians to degrees
  wait(10,msec);
  } return(0);
}
void resetPosition() //Resets Odometry
{
	leftLst = rightLst = backLst = 0;
  y = x  = a = q = Q = 0;
}
int debug(){ 
  while(true){
    printf("Q: %.2f", Q);
    printf("\nX: %.2f", x);
    printf("\nY: %.2f\n", y);
    wait(200, msec);
  }
  return(0);
}