#pragma config(Sensor, dgtl1,  loadangle,      sensorRotation)
#pragma config(Motor,  port2,           rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftFlipper,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightFlipper,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           trigger,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           load,          tmotorVex393_MC29, openLoop)
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


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol(){
  // User control code here, inside the loop

  while (true){
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
				motor[hook1] = -80;
				motor[hook2] = 80;
			}
			else if	(vexRT[Btn5D] == 1 && vexRT(Btn5U) == 0)
			{
				motor[hook1] = 80;
				motor[hook2] = -80;
			}
			else
			{
				motor[hook1] = 0;
				motor[hook2] = 0;
}
