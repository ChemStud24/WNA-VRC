#pragma config(Motor,  port1,           catapult,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topright,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backleft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topleft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           hand,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float speedFactor = 1;
task main()
{
while (1==1)
{

//wheels
  motor[topleft]=(-vexRT[Ch3]+vexRT[Ch1])*speedFactor;
	motor[backleft]=(-vexRT[Ch3]+vexRT[Ch1])*speedFactor;
	motor[topright]=vexRT[Ch3]+vexRT[Ch1];
	motor[backright]=vexRT[Ch3]+ vexRT[Ch1];

/*int leftSpeed = 127;
int rightSpeed =-100;

//wheels different speed
if(vexRT[Ch3] == 1)
{
motor [topleft]= leftSpeed;
motor [backleft]= leftSpeed;
motor [topright]= rightSpeed;
motor [backright]= rightSpeed;*/

}}
