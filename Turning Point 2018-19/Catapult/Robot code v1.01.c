#pragma config(Motor,  port10,          BFG,  				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,          	rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           coilone,   		 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           hook1,       	 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           coiltwo,   		 tmotorVex393_MC29, openLoop)
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

			motor[rb] = -127;
			motor[rf] = -127;
			motor[lb] = 127;
			motor[lf] = 127;
			wait1Msec(3000);
			motor[rb] = 127;
			motor[rf] = 127;
			motor[lb] = -127;
			motor[lf] = -127;
			wait1Msec(3000);
			motor[rb] = 0;
			motor[rf] = 0;
			motor[lb] = 0;
			motor[lf] = 0;
		}


			// ..........................................................................
			// Insert user code here.
			// ..........................................................................

<<<<<<< HEAD
task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    //drive
			motor[rb] = vexRt[Ch1] + vexRt[Ch2];
			motor[rf] = vexRt[Ch1] + vexRt[Ch2];
			motor[lf] = vexRt[Ch1] - vexRt[Ch2];
			motor[lb] = vexRt[Ch1] - vexRt[Ch2];


		 //flipper
		  if (vexRT(Btn5U) == 1 && vexRT(Btn5D)==0)
		  {
			motor[leftFlipper] = -30;
			motor[rightFlipper] = 30;
			}
			else if	(vexRT[Btn5D] == 1 && vexRT(Btn5U) == 0)
			{
				motor[leftFlipper] = 30;
				motor[rightFlipper] = -30;
			}
			else
=======
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
>>>>>>> a252ff4fa4ec32e792f0e5927b259a424173b9e8
			{
				//drive
				motor[rb] = vexRT[Ch2];
				motor[rf] = vexRT[Ch2];
				motor[lb] = -vexRT[Ch3];
				motor[lf] = -vexRT[Ch3];

				//Load

				if (vexRT(Btn8L) == 1 && vexRT(Btn8D)==0)
				{
					motor[coilone] = -127;
					motor[coiltwo] = 127;
					;
				}
				else if	(vexRT[Btn8D] == 1 && vexRT(Btn8L) == 0)
				{
					motor[coilone] = 127;
					motor[coiltwo] = -127;
				}
				else
				{
					motor[coilone] = 0;
					motor[coiltwo] = 0;

					//"Mechanized Ball Launching Device"
					if (vexRT(Btn7U) == 1 && vexRT(Btn7D)==0)
					{
						motor[BFG] = -127;

					}
					else if	(vexRT[Btn7D] == 1 && vexRT(Btn7U) == 0)
					{
						motor[BFG] = 127;

					}
					else
					{
						motor[BFG] = 0;

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
					}
{


		}
		}
				}

			}















/*We're no strangers to love*/
/*You know the rules and so do I*/
/*A full commitment's what I'm thinking of*/
/*You wouldn't get this from any other guy*/
/*I just wanna tell you how I'm feeling*/
/*Gotta make you understand*/
/*Never gonna give you up*/
/*Never gonna let you down*/
/*Never gonna run around and desert you*/
/*Never gonna make you cry*/
/*Never gonna say goodbye*/
/*Never gonna tell a lie and hurt you*/














/* Courtesy of Ethan A. Collis*/
