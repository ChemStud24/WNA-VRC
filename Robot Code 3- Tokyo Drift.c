#pragma config(Motor,  port9,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,          	rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BFONE,   		 	 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           hook1,       	 tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           load,   		   tmotorVex393_MC29, openLoop)
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

	//Hooting Balons
	motor[BFONE] = -100;
	wait1Msec(1500);
	motor[BFONE] = 0;

	//Turning Around (The Tokyo Drift)R
	motor[rb] = 127;
	motor[rf] = 127;
	motor[lb] = 127;
	motor[lf] = 127;
	wait1Msec(1100);

	//Moving Backwards
	motor[rb] = -127;
	motor[rf] = -127;
	motor[lb] = 127;
	motor[lf] = 127;
	wait1Msec(1000);

	//Turning Around (The Tokyo Drift)R
	motor[rb] = -127;
	motor[rf] = -127;
	motor[lb] = -127;
	motor[lf] = -127;
	wait1Msec(500);

	//Scaling the Ramp
	motor[rb] = -127;
	motor[rf] = -127;
	motor[lb] = 127;
	motor[lf] = 127;
	wait1Msec(1500);
	motor[rb] = 0;
	motor[rf] = 0;
	motor[lb] = 0;
	motor[lf] = 0;
	wait1Msec(1);
	motor[hook1] = -90;
	motor[hook2] =  90;
	wait1Msec(500);
	motor[rb] = -127;
	motor[rf] = -127;
	motor[lb] = 127;
	motor[lf] = 127;
	wait1Msec(2300);

	//Fin
	motor[rb] = 0;
	motor[rf] = 0;
	motor[lb] = 0;
	motor[lf] = 0;
	wait1Msec(1000);
	motor[hook1] = 90;
	motor[hook2] = -90;
	wait1Msec(500);




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
//User control code here, inside the loop

	//while (true)
	{
		//Drive
		motor[rb] = vexRT[Ch2];
		motor[rf] = vexRT[Ch2];
		motor[lb] = -vexRT[Ch3];
		motor[lf] = -vexRT[Ch3];

		//Load
		if (vexRT(Btn7U) == 1 && vexRT(Btn7D)==0)
		{
			motor[load] = -100;
		}
		else if	(vexRT[Btn7D] == 1 && vexRT(Btn7U) == 0)
		{
			motor[load] = 0;
		}
		else
		{
			motor[load] = 0;

			//Guns
			if (vexRT(Btn5U) == 1 && vexRT(Btn5D)==0)
			{
				motor[BFONE] = -100;
			}
			else if	(vexRT[Btn5D] == 1 && vexRT(Btn5U) == 0)
			{
				motor[BFONE] = 100;
			}
			else
			{
				motor[BFONE] = 0;
				motor[BFONE] = 0;

				//Hook (Slow Edition)
				if (vexRT(Btn6U) == 1 && vexRT(Btn6D)==0)
				{
					motor[hook1] = -90;
					motor[hook2] =  90;
				}
				else if	(vexRT[Btn6D] == 1 && vexRT(Btn6U) == 0)
				{
					motor[hook1] = 90;
					motor[hook2] = -90;
				}
				else
				{
					motor[hook1] = 0;
					motor[hook2] = 0;

					//Null Space (Testing Grounds)
					if (vexRT(Btn8D) == 1 && vexRT(Btn8U)==0)
					{//Auto Version 2 (Right Side Blue)

						motor[rb] = 115;
						motor[rf] = 115;
						wait1Msec(2000);
						motor[rb] = 0;
						motor[rf] = 0;
						wait1Msec(1);



					}
				}

			}

		}
	}

}







/*
//"According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible"
//																													-The Bee Movie (2008)




//Hooting Balons
motor[BFONE] = -100;
wait1Msec(1500);
motor[BFONE] = 0;

//Turning Around (The Tokyo Drift)R
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(1100);

//Moving Backwards
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(1000);

//Turning Around (The Tokyo Drift)R
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(500);

//Scaling the Ramp
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(1500);
motor[rb] = 0;
motor[rf] = 0;
motor[lb] = 0;
motor[lf] = 0;
wait1Msec(1);
motor[hook1] = -90;
motor[hook2] =  90;
wait1Msec(500);
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(2300);

//Fin
motor[rb] = 0;
motor[rf] = 0;
motor[lb] = 0;
motor[lf] = 0;
wait1Msec(1000);
motor[hook1] = 90;
motor[hook2] = -90;
wait1Msec(500);







/* //Autonoumous Skills

//Moving Forwards
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(2100);

//Moving Backwards
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(1900);

//Turning Around (The Tokyo Drift)R
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(600);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(2200);

//Flippy Flippy Nice and Skippy (Calibrate)
motor[hook1] = 80;
motor[hook2] = -80;
wait1Msec(200);

//Moving Backwards (Calibrate)
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(1300);

//Turning Around (The Tokyo Drift)L
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(600);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(300);

//Flippy Flippy Nice and Skippy (Calibrate)
motor[hook1] = 80;
motor[hook2] = -80;
wait1Msec(200);

//Moving Backwards (Calibrate)
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(300);

//Turning Around (The Tokyo Drift)R
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(300);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(300);

//Turning Around (The Tokyo Drift)R
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(300);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(500);

//Flippy Flippy Nice and Skippy (Calibrate)
motor[hook1] = 80;
motor[hook2] = -80;
wait1Msec(200);

//Moving Backwards (Calibrate)
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(500);

//Turning Around (The Tokyo Drift)R
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(600);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(500);

//Flippy Flippy Nice and Skippy (Calibrate)
motor[hook1] = 80;
motor[hook2] = -80;
wait1Msec(200);

//Moving Backwards (Calibrate)
motor[rb] = -127;
motor[rf] = -127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(200);

//Turning Around (The Tokyo Drift)L
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(300);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(500);

//Turning Around (The Tokyo Drift)L
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = 127;
motor[lf] = 127;
wait1Msec(300);

//Moving Forwards (Calibrate)
motor[rb] = 127;
motor[rf] = 127;
motor[lb] = -127;
motor[lf] = -127;
wait1Msec(400);



//"How should I start it? You like jazz? No, that's no good."





//Archive:








/* Courtesy of Ethan A. Collis*/
