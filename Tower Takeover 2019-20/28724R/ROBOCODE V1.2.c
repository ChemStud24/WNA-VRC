#pragma config(Motor,  port2,           lf,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lb,     				tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rb,            	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rf,         		tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift1,        	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lift2,        	tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           vac1,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           vac2,           tmotorVex393_MC29, openLoop)

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
{/*	motor[LEGSET1] = 100;
	motor[LEGSET2] = -100;
	motor[MWHEEL1] = 100;
	motor[MWHEEL2] = -100;
	wait1Msec(2200);
	motor[LEGSET1] = 0;
	motor[LEGSET2] = 0;
	motor[MWHEEL1] = 0;
	motor[MWHEEL2] = 0;
	wait1Msec(1100);
*/
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
		//Drive
		motor[rb] = vexRT[Ch2];
		motor[rf] = vexRT[Ch2];
		motor[lb] = -vexRT[Ch3];
		motor[lf] = -vexRT[Ch3];


		//Lift (Arm)
		if (vexRT(Btn6U) == 1 && vexRT(Btn6D)==0)
		{
			motor[lift1] = -105;
			motor[lift2] =  105;
		}
		else if (vexRT[Btn6D] == 1 && vexRT(Btn6U) == 0)
		{
			motor[lift1] = 105;
			motor[lift2] = -105;
		}
		else
		{
			motor[lift1] = 0;
			motor[lift2] = 0;

		//Vacuum
				if (vexRT(Btn7U) == 1 && vexRT(Btn7D)==0)
		{
			motor[vac1] = -105;
			motor[vac2] =  105;
		}
		else if (vexRT[Btn7D] == 1 && vexRT(Btn7U) == 0)
		{
			motor[vac1] = 105;
			motor[vac2] = -105;
		}
		else
		{
			motor[vac1] = 0;
			motor[vac2] = 0;



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
