#pragma config(Motor,  port1,           catapult,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topright,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backleft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topleft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           hand,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float speedFactor = 0.5;
task main()
{
while (1==1)
{
//hand goes up

	if(vexRT[Btn6U] == 1)
{
 motor[hand]= 127;
}
else if(vexRT[Btn5U]== 1)
{
	motor[hand]= -127;
}
else
{motor[hand] =0;}

if(vexRT[Btn8U]==1)
{
 motor[claw]= 127;
}
else if(vexRT[Btn8D]== 1)
{
	motor[claw]= -127;
}else
	{
		motor[claw]=0;
}
//wheels
  motor[topleft]=(-vexRT[Ch3]+vexRT[Ch4])*speedFactor;
	motor[backleft]=(-vexRT[Ch3]+vexRT[Ch4])*speedFactor;
	motor[topright]=vexRT[Ch3]+vexRT[Ch4];
	motor[backright]=vexRT[Ch3]+ vexRT[Ch4];

	//catapult

	if(vexRT[Btn7U] == 1) {
 		motor[catapult]= 127;
	} else {
		motor[catapult]=0;
	}

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
