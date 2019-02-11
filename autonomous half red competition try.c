#pragma config(Motor,  port1,           catapult,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topright,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backleft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topleft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           hand,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

//catapult fires
 motor[catapult]= 127;
 wait1Msec(200);

 //hand goes up
 motor[hand]= -127;
 wait1Msec(520);

 motor[hand]=0;
 wait1Msec(1000);

// forwards
	motor[topleft]= 120;
	motor[backleft]= 120;
	motor[topright]= -100;
	motor[backright]= -100;
	wait1Msec(1500);

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

// turn 30 in place
	motor[topleft]= 120;
	motor[backleft]= 120;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500); //check

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

	// turn -30 in place
	motor[topleft]= -120;
	motor[backleft]= -120;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(300);

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

//old

//backwards
	motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 80;
	motor[backright]= 80;
	wait1Msec(2300);

//hand goes down
	motor[hand]= 127;
	wait1Msec(400);

	motor[hand]=0;

	//turning
	motor[topleft]= -110;
	motor[backleft]= -110;
	motor[topright]= -100;
	motor[backright]= -100;
	wait1Msec(520);

	//backwards
	motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 85;
	motor[backright]= 85;
	wait1Msec(2100);

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	motor[hand]=0;
}
