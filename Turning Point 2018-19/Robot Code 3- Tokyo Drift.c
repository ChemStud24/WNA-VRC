#pragma config(Motor,  port9,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,          	rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BFONE,   		 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           hook1,       	 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BFTWO,   		 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port2,           hook2,       	 tmotorVex393_MC29, openLoop)

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
/*                              Autonomous Task 1                            */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//Type A (Right Side)
	//Driving Forward
	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(2000);

	//Turning Around (The Tokyo Drift)
	motor[rb] = -127;
	motor[rf] = -127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(900);

	//Scaling the Ramp

	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(3500);

	//Fin
	motor[rb] = 0;
	motor[rf] = 0;
	motor[lb] = 0;
	motor[lf] = 0;
	wait1Msec(10000);

	//Type B (Left Side)
	//Driving Forward
	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(2000);

	//Turning Around (The Tokyo Drift)
	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = 127;
	motor[lf] = 127;
	wait1Msec(900);

	//Scaling the Ramp

	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(3500);

	//Fin
	motor[rb] = 0;
	motor[rf] = 0;
	motor[lb] = 0;
	motor[lf] = 0;
	wait1Msec(10000);

}


// ..........................................................................
// Insert user code here.
// ..........................................................................

// Remove this function call once you have "real" code.
//AutonomousCodePlaceholderForTesting();


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
		//drive
		motor[rb] = vexRT[Ch2];
		motor[rf] = vexRT[Ch2];
		motor[lb] = -vexRT[Ch3];
		motor[lf] = -vexRT[Ch3];

		//BFG2

		if (vexRT(Btn8L) == 1 && vexRT(Btn8D)==0)
		{
			motor[BFONE] = -100;
			motor[BFTWO] = 100;
			;
		}
		else if	(vexRT[Btn8D] == 1 && vexRT(Btn8L) == 0)
		{
			motor[BFONE] = 100;
			motor[BFTWO] = -100;
		}
		else
		{
			motor[BFONE] = 0;
			motor[BFTWO] = 0;

			}


			//Hook
			if (vexRT(Btn5U) == 1 && vexRT(Btn5D)==0)
			{
				motor[hook1] = -40;
				motor[hook2] = 40;
			}
			else if	(vexRT[Btn5D] == 1 && vexRT(Btn5U) == 0)
			{
				motor[hook1] = 40;
				motor[hook2] = -40;
			}
			else
			{
				motor[hook1] = 0;
				motor[hook2] = 0;

				//Hook (Fast Edition)
				if (vexRT(Btn7D) == 1 && vexRT(Btn7L)==0)
				{
					motor[hook1] = -120;
					motor[hook2] =  120;
				}
				else if	(vexRT[Btn7L] == 1 && vexRT(Btn7D) == 0)
				{
					motor[hook1] = 127;
					motor[hook2] = -127;
				}
				else
				{
					motor[hook1] = 0;
					motor[hook2] = 0;


					//Null Space (Testing Grounds)
					if (vexRT(Btn6U) == 1 && vexRT(Btn6D)==0)
				{
					//Running in the 90's (Clear)
					motor[rb] = 127;
					motor[rf] = 127;
					motor[lb] = -127;
					motor[lf] = -127;
					wait1Msec(3000);

					//Awkwardly Walking Backwards in the 90's (Clear)
					motor[rb] = -127;
					motor[rf] = -127;
					motor[lb] = 127;
					motor[lf] = 127;
					wait1Msec(3000);

					//Mr.Right (Clear)
					motor[rb] = -127;
					motor[rf] = -127;
					motor[lb] = -127;
					motor[lf] = -127;
					wait1Msec(900);

					//It's a new way i like to be
					motor[rb] = 127;
					motor[rf] = 127;
					motor[lb] = -127;
					motor[lf] = -127;
					wait1Msec(1600);

					//Dr. Left
					motor[rb] = 127;
					motor[rf] = 127;
					motor[lb] = 127;
					motor[lf] = 127;
					wait1Msec(900);

					//Cap Positioning (Calibrate)
					motor[hook1] = -40;
					motor[hook2] = 40;
					wait1Msec(200);
					motor[rb] = 127;
					motor[rf] = 127;
					motor[lb] = -127;
					motor[lf] = -127;
					wait1Msec(400);

					//Flip (Calibrate)
					motor[hook1] = 80;
					motor[hook2] = -80;
					wait1Msec(200);



				}


				}
				{


				}
			}
		}

	}








//"According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible"
//																													-The Bee Movie (2008)
















//"How should I start it? You like jazz? No, that's no good."
















/* Courtesy of Ethan A. Collis*/
