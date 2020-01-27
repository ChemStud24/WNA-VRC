#pragma config(Motor,  port1,           ldmotor,       tmotorNone, openLoop)
#pragma config(Motor,  port3,           lbmotor,       tmotorNone, openLoop)
#pragma config(Motor,  port4,           rbdmotor,      tmotorNone, openLoop)
#pragma config(Motor,  port5,           lfmotor,       tmotorNone, openLoop)
#pragma config(Motor,  port6,           rfmotor,       tmotorNone, openLoop)
#pragma config(Motor,  port7,           rbmotor,       tmotorNone, openLoop)
#pragma config(Motor,  port8,           lbdmotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rdmotor,       tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"



void pre_auton()
{

	bStopTasksBetweenModes = false;



}


task autonomous()
{

	motor[lfmotor] = -127;
	motor[lbmotor] = -127;
	motor[rbmotor] = 127;
	motor[rfmotor] = 127;
	wait1Msec(2000);


	//Motors drive back.

	motor[lbmotor] = 127;
	motor[lfmotor] = 127;
	motor[rfmotor] = -127;
	motor[rbmotor] = -127;
	wait1Msec(3000);

}





task usercontrol()
{
	// User control code here, inside the loop

	while(true){
		motor[rbmotor] = vexRT[Ch3];
		motor[rfmotor] = vexRT[Ch3];
		motor[lfmotor] = -vexRT[Ch2];
		motor[lbmotor] = -vexRT[Ch2];
		//Movement of Whole Robot

		if(vexRT[Btn5U] == 1){
			motor(rdmotor) = -63;
			motor(ldmotor) = 63;
		}
		//Closing.
		else {
			motor(rdmotor) = 0;
			motor(ldmotor) = 0;
		}

		if (vexRT(Btn6U) == 1){
			motor(rdmotor) = -63;
			motor(ldmotor)= -63;
			//Opening.
		}

		else {
			motor(rdmotor) = 0;
			motor(ldmotor) = 0;
		}

		if (vexRT(Btn5D) == 1){
			motor(rbdmotor) = -63;
			motor(lbdmotor) = 63;
		} //Down
		else {
			motor(rbdmotor) = 0;
			motor(lbdmotor) = 0;
		}

		if (vexRT(Btn6D) == 1){
			motor(rbdmotor) = 63;
			motor(lbdmotor) = -63;
		}
		//Up
		else {
			motor(rbdmotor) = 0;
			motor(lbdmotor) = 0;

		}
	}

}