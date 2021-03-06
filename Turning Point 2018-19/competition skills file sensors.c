#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           catapult,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topright,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backleft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topleft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           hand,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

//catapult fires
 motor[catapult]= 127;
 wait1Msec(200);

 //hand goes up
 motor[hand]= -127;
 wait1Msec(650);

 motor[hand]=0;
 wait1Msec(1000);

wait1Msec(1000);

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]<650)
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= 120;
	motor[backleft]= 120;
	motor[topright]= -83;
	motor[backright]= -83;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= 83;
	motor[backleft]= 83;
	motor[topright]= -120;
	motor[backright]= -120;
}
  else {
  motor[topleft]= 100;
	motor[backleft]= 100;
	motor[topright]= -100;
	motor[backright]= -100;
}
}


	// turn 30 in place
	motor[topleft]= 120;
	motor[backleft]= 120;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500); //check

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

	// turn -30 in place
	motor[topleft]= -120;
	motor[backleft]= -120;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(300);

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

	//Backwards

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]>-1120)
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;

} else {
  motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 100;
	motor[backright]= 100;
}
}
//hand goes down
	motor[hand]= 127;
	wait1Msec(500);

	motor[hand]=0;

	//turning
	motor[topleft]= -110;
	motor[backleft]= -110;
	motor[topright]= -100;
	motor[backright]= -100;
	wait1Msec(470);

		//Backwards

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]>-1885)
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;

} else {
  motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 100;
	motor[backright]= 100;
}
}

	//end
	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	motor[hand]=0;

  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
float speedFactor = 0.7;
while (1==1)
{
//hand goes up

	if(vexRT[Btn6U] == 1)
{
 motor[hand]= 127;
}
else if(vexRT[Btn5U]== 1)
{
	motor[hand]= -127;
}
else
{motor[hand] =0;}

if(vexRT[Btn8U]==1)
{
 motor[claw]= 127;
}
else if(vexRT[Btn8D]== 1)
{
	motor[claw]= -127;
}else
	{
		motor[claw]=0;
}
//wheels
  motor[topleft]=(-vexRT[Ch3]+vexRT[Ch1])*speedFactor;
	motor[backleft]=(-vexRT[Ch3]+vexRT[Ch1])*speedFactor;
	motor[topright]=vexRT[Ch3]+vexRT[Ch1];
	motor[backright]=vexRT[Ch3]+ vexRT[Ch1];

	//catapult

	if(vexRT[Btn7U] == 1) {
 		motor[catapult]= 127;
	} else {
		motor[catapult]=0;
	}

/*int leftSpeed = 127;
int rightSpeed =-100;
//wheels different speed
if(vexRT[Ch3] == 1)
{
motor [topleft]= leftSpeed;
motor [backleft]= leftSpeed;
motor [topright]= rightSpeed;
motor [backright]= rightSpeed;*/

}
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();
  }
}
