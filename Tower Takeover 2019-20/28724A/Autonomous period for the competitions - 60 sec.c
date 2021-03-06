#pragma config(Motor,  port2,           lf,            tmotorNone, openLoop)
#pragma config(Motor,  port3,           lb,            tmotorNone, openLoop)
#pragma config(Motor,  port4,           rf,            tmotorNone, openLoop)
#pragma config(Motor,  port5,           rb,            tmotorNone, openLoop)
#pragma config(Motor,  port6,           jaw1,          tmotorNone, openLoop)
#pragma config(Motor,  port7,           jaw2,          tmotorNone, openLoop)
#pragma config(Motor,  port8,           mbr,           tmotorNone, openLoop)
#pragma config(Motor,  port9,           mbl,           tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


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
	//First cube - the one given to us
	//Motors drive forwards.
	motor[lf] = -127;
	motor[lb] = -127;
	motor[rb] = 127;
	motor[rf] = 127;
	wait1Msec(2000);

	//Motors drive back.
	motor[lb] = 110;
	motor[lf] = 110;
	motor[rf] = -110;
	motor[rb] = -110;
	wait1Msec(1500);

	//Second Cube from the side

	//Motors drive forwards.
	motor[lf] = -110;
	motor[lb] = -110;
	motor[rb] = 110;
	motor[rf] = 110;
	wait1Msec(500);

	//Motors drive right.
	motor[lb] = 110;
	motor[lf] = 110;
	motor[rf] = 110;
	motor[rb] = 110;
	wait1Msec(500);

	//Motors drive right.
	motor[lb] = 110;
	motor[lf] = 110;
	motor[rf] = 110;
	motor[rb] = 110;
	wait1Msec(500);

	//Motors drive right.
	motor[lb] = 110;
	motor[lf] = 110;
	motor[rf] = 110;
	motor[rb] = 110;
	wait1Msec(1000);

	//Third cube - paralle to the second one

	//Stop Completely
	motor[lb] = 0;
	motor[lf] = 0;
	motor[rf] = 0;
	motor[rb] = 0;
	wait1Msec(1000);
}

//Sylvia's idea to use one cube and close one for the 15 sec before the match and have four cubes tower in the right corner for the 60 seconds period.
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
