#pragma config(Sensor, dgtl1,  					loadangle,      sensorRotation)
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
/*        Autonomous Robot Program Scenario 1: V:1                     			 */
/*                            & Knuckles                                     */
/*---------------------------------------------------------------------------*/

task main()
{
	while(1==1){
	if(vexRT[Btn8L]==1){
	/*Bang Bang!(Firing the Catapult) */
	motor[leftFlipper] = -127;
	motor[rightFlipper] = 127;
	motor[load] = 127;
	wait1Msec(1200);
	motor[trigger] = 20;
	wait1Msec(500);
	motor[trigger] = 0;
	motor[load]= 0;


	/*Drivin Shovin */
	/*(Moving Forward, and Pushing the Sign)*/
	motor[rf]= -127;
	motor[lf]= -127;
	motor[rb]= -127;
	motor[lb]= -127;
	wait1Msec(2000);
	motor[rf]= 127;
	motor[lf]= -127;
	motor[rb]= 127;
	motor[lb]= -127;
	motor[leftFlipper] = -127;
	motor[rightFlipper] = 127;
	wait1Msec(2000);


	/* Drive N2: Electric Boogaloo*
	/*(Moving back and turning)*/
	motor[rf] = -127;
	motor[lf] = 127;
	motor[rb] = -127;
	motor[lb] = 127;
	motor[leftFlipper] = 127;
	motor[rightFlipper] = -127;
	wait1Msec(5000);
	motor[rf]= -127;
	motor[lf]= -127;
	motor[rb]= -127;
	motor[lb]= -127;
	wait1Msec(850);

	/*Jumpin the Shark (Scaling the Ramp)  */
	motor[rf] = -127;
	motor[lf] = 127;
	motor[lb] = 127;
	motor[rb] = -127;
	motor[leftFlipper] = -127;
	motor[rightFlipper] = 127;
	wait1Msec(5000);
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
