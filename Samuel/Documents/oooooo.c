
#pragma config(Sensor, in1,    shoulder,       sensorPotentiometer)
#pragma config(Sensor, in2,    wrist,          sensorPotentiometer)
#pragma config(Motor,  port1,           rightmotor,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           armmotor1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           armmotor2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lift2,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lift1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftmotor,     tmotorVex393_HBridge, openLoop)

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
 motor[port1] = 127;
 motor[port10] =-127;
 wait1Msec(1000);
 motor[port1] = -127;
 motor[port10] = 127;
 wait1Msec(300);


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
  // User control code here, inside the loop

 	int a;
	int b;

	a = SensorValue[in1];
	b = SensorValue[in2];
	motor[port1] = -127;
 motor[port10] = 127;
 wait1Msec(3000);
 motor[port1] = 127;
 motor[port10] = -127;
 wait1Msec(3000);
 motor[port1]=127;
while(1==1)
{
	a = SensorValue[in1];
	b = SensorValue[in2];
	motor[rightmotor] = (-vexRT[Ch3] + vexRT[Ch4])/2;
  motor[leftmotor] = (vexRT[Ch3] + vexRT[Ch4])/2;
// moving
  if(vexRT[Btn5U] == true)
{
	motor[lift1] = -127;
	motor[lift2] = 127;

}


	else
{
	motor[lift1] = 0;
	motor[lift2] = 0;
}
// press 5U to make the lift/hand go up
  if(vexRT[Btn5D] == true)
  {
  	motor[port9] = 127;
  	motor[port8] = -127;
	}
	else
	{
		motor[port9] = 0;
		motor[port8] = 0;
	}
//press 5D to make the lift/hand go down
	if(vexRT[Btn6U] == true)
	{
		if(a<=600)
			motor(armmotor1) = 0;
			motor(armmotor2) = 127;
		}
		motor[armmotor1] = -127;
		motor[armmotor2] = 127;
		motor[lift1] = -0.02*(a+b-3500);
		motor[lift2] = 0.02*(a+b-3500);
// arm moving while lift keep level

		}
 if(vexRT[Btn6D])
	{
	if(a<=500)
			motor(armmotor1) = 0;
			motor(armmotor2) = 127;
		}
	motor[armmotor1] = 127;
		motor[armmotor2] = -127;
		motor[lift1] = -0.02*(a+b-3500);
		motor[lift2] = 0.02*(a+b-3500);
//arm move down while lift keep level
  }

