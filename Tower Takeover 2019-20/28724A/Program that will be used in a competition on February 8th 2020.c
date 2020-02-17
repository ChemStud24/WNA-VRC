#pragma config(Motor,  port2,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           c1l,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           c2r,           tmotorVex393_MC29, openLoop)
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
  bStopTasksBetweenModes = false;

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
	//Motors drive back.
	motor[lf] = -127;
	motor[lb] = -127;
	motor[rb] = 127;
	motor[rf] = 127;
	wait1Msec(2000);

	//Motors drive forward.
	motor[lb] = 110;
	motor[lf] = 110;
	motor[rf] = -110;
	motor[rb] = -110;
	wait1Msec(1500);

	//Stop Completely
	motor[lb] = 0;
	motor[lf] = 0;
	motor[rf] = 0;
	motor[rb] = 0;
	wait1Msec(1000);
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

  while (true)
  {
    	{
    		//Drive(Movement of Whole Robot)

	//RIGHT SIDE = CHANNEL 2 - CHANNEL 1
	//LEFT SIDE = CHANNEL 2+ CHANNEL 1 1

	  motor[rb] = (-vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[rf] = (-vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[lf] = (vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[lb] = (vexRT[Ch2]+vexRT[Ch1])*.75;

	//Collectors up and down
	if (vexRT(Btn7U) == 1 && vexRT(Btn7D)==0)

		{
			//up
			motor[c1l] = 63;
			motor[c2r] = -63;
		}
		else if (vexRT[Btn7D] == 1 && vexRT(Btn7U) ==0)
		{
			//down
			motor[c1l] = -63;
			motor[c2r] = 63;
		}
		else
		{
			//stop
			motor[c1l] = 0;
			motor[c2r] = 0;
		}


		//lift
		if (vexRT(Btn6U) == 1 && vexRT(Btn5U)==0)
		{
			//Up
			motor[lift] = 75;

		}
		else if (vexRT[Btn5U] == 1 && vexRT(Btn6D) == 0)
		{
			//Down
			motor[lift] = -75;

		}
		else
		{
			//Motionless
			motor[lift] = 0;
  }
}
}
}
