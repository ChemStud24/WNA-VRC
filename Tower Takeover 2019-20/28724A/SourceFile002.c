#pragma config(Motor,  port1,           leftmotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightmotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		motor[rightmotor] = vexRT[Ch5];
		motor[leftmotor] = vexRT[Ch5];

		if (vexRT(Btn5U) == 1 && (vexRT(Btn5D) == 0))
			motor(rightmotor) = -100;
			motor(leftmotor) = 100;
		}



}