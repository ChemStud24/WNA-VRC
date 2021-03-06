#pragma config(Motor,  port2,           lf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rf,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           c1l,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           c2r,           tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
//Drive(Movement of Whole Robot)

	//RIGHT SIDE = CHANNEL 2 - CHANNEL 1
	//LEFT SIDE = CHANNEL 2+ CHANNEL 1 1

	  motor[rb] = (-vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[rf] = (-vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[lf] = (vexRT[Ch2]+vexRT[Ch1])*.75;
		motor[lb] = (vexRT[Ch2]+vexRT[Ch1])*.75;

		while (true)
		{
	//Collectors up and down
	if (vexRT(Btn7U) == 1 && vexRT(Btn7D)==0)
		{
			//up
			motor[c1l] = 63;
			motor[c2r] = -63;
		}
		else if (vexRT[Btn7D] == 1 && vexRT(Btn7U) == 0)
		{
			//down
			motor[c1l] = -63;
			motor[c2r] = 63;
		}
		else
		{
			//stop
			motor[c1l] = 0;
			motor[c2r] = 0;
		}


		//lift
		if (vexRT(Btn6U) == 1 && vexRT(Btn5U)==0)
		{
			//Up
			motor[lift] = 63;

		}
		else if (vexRT[Btn5U] == 1 && vexRT(Btn6D) == 0)
		{
			//Down
			motor[lift] = -63;

		}
		else
		{
			//Motionless
			motor[lift] = 0;


			//Auton Tester
			if (vexRT(Btn8U) == 1 && vexRT(Btn8D)==0)
			{

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
				wait1Msec(2000);

				//Stop Completely
				motor[lb] = 0;
				motor[lf] = 0;
				motor[rf] = 0;
				motor[rb] = 0;
				wait1Msec(1000);
			}
			else
			{
				//Motionless
				motor[lb] = 0;
				motor[lf] = 0;
				motor[rf] = 0;
				motor[rb] = 0;
			}
  }
 }
}
