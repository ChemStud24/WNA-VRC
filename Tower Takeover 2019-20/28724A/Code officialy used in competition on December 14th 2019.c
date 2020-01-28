#pragma config(Motor,  port2,           lf,       	tmotorNone, openLoop)
#pragma config(Motor,  port3,           lb,       	tmotorNone, openLoop)
#pragma config(Motor,  port4,           rf,      		tmotorNone, openLoop)
#pragma config(Motor,  port5,           rb,       	tmotorNone, openLoop)
#pragma config(Motor,  port6,           ev1,      	tmotorNone, openLoop)
#pragma config(Motor,  port7,           ev2,      	tmotorNone, openLoop)
#pragma config(Motor,  port8,           jaw1,     	tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           jaw2,     	tmotorVex393_MC29, openLoop)

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
	//Motors drive forwards.
	motor[lf] = -127;
	motor[lb] = -127;
	motor[rb] = 127;
	motor[rf] = 127;
	wait1Msec(2000);

	//Motors drive back.
	motor[lb] = 127;
	motor[lf] = 127;
	motor[rf] = -127;
	motor[rb] = -127;
	wait1Msec(3000);
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

	while (true)
	{
		//Drive(Movement of Whole Robot)
		motor[rb] = vexRT[Ch3];
		motor[rf] = vexRT[Ch3];
		motor[lf] = -vexRT[Ch2];
		motor[lb] = -vexRT[Ch2];


		//Jaw (Closey Lefty Righty Loosey)
		if (vexRT(Btn5U) == 1 && vexRT(Btn6U)==0)
		{
			//Down
			motor[jaw1] = 63;
			motor[jaw2] =  -63;
		}
		else if (vexRT[Btn6U] == 1 && vexRT(Btn5U) == 0)
		{
			//Up
			motor[jaw1] = -63;
			motor[jaw2] = 63;
		}
		else
		{
			motor[jaw1] = 0;
			motor[jaw2] = 0;
		}


		//Elevator
		if (vexRT(Btn5D) == 1 && vexRT(Btn6D)==0)
		{
			//Down
			motor[ev1] = -63;
			motor[ev2] = 63;
		}
		else if (vexRT[Btn6D] == 1 && vexRT(Btn5D) == 0)
		{
			//Up
			motor[ev1] = 63;
			motor[ev2] = -63;
		}
		else
		{
			//Motionless
			motor[ev1] = 0;
			motor[ev2] = 0;


			//Auton Tester
			if (vexRT(Btn8U) == 1 && vexRT(Btn8D)==0)
			{

				//Motors drive forwards.
				motor[lf] = -127;
				motor[lb] = -127;
				motor[rb] = 127;
				motor[rf] = 127;
				wait1Msec(2000);

				//Motors drive back.
				motor[lb] = 127;
				motor[lf] = 127;
				motor[rf] = -127;
				motor[rb] = -127;
				wait1Msec(3000);

				//Stop Completely
				motor[lb] = 0;
				motor[lf] = 0;
				motor[rf] = 0;
				motor[rb] = 0;
				wait1Msec(1000);
			}
			else
			{
				//Motionless
				motor[lb] = 0;
				motor[lf] = 0;
				motor[rf] = 0;
				motor[rb] = 0;
			}

		}
	}


}



//Shrine of Wisdom and Fortune:
//
//							"Let them fight." -Dr. Ishiro Seriwaza

//





//Archive:








/* Courtesy of Ethan A. Collis, Circa 2019*/
