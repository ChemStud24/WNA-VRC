#pragma config(Motor,  port2,           motortwo,      tmotorNone, openLoop)
#pragma config(Motor,  port3,           motorthree,    tmotorNone, openLoop)
#pragma config(Motor,  port4,           motorfour,     tmotorNone, openLoop)
#pragma config(Motor,  port5,           motorfive,     tmotorNone, openLoop)
#pragma config(Motor,  port6,           motorsix,      tmotorNone, openLoop)
#pragma config(Motor,  port7,           motorseven,    tmotorNone, openLoop)
#pragma config(Motor,  port8,           rightmotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftmotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()

{
	while (true)
{

		if (vexRT(Btn5U) == 1){
			motor(rightmotor) = -127;
			motor(leftmotor) = 127;
		}


		else {
			motor(rightmotor) = 0;
			motor(leftmotor) = 0;
		}

		if (vexRT(Btn6U) == 1){
			motor(motortwo) = 120;
			motor(motorthree)= 120;
			motor[leftmotor]= -63;
	    motor[rightmotor]= 63;


		}

		else {
			motor(motortwo) = 0;
			motor(motorthree) = 0;
			// Programming of the Motors.
    	motor[leftmotor]= 0;
	    motor[rightmotor]= 0;
	    //clockwise and counter clockwise movement for motors left and right.

		}

}
{


    motor[motortwo] = -63;
    motor[motorthree] = 63;
    wait1Msec(2000);
    //point turn
}
{


    motor[motortwo] = 0;
    motor[motorthree] = 63;
    wait1Msec(2000);
    //Swing Turn

}


    motor[motortwo] = 55;
    motor[motorthree] = 63;
    wait1Msec(2000);

    motor[motortwo] = -63;
    motor[motorthree] = 63;
    wait1Msec(700);
    //left turn
}



{

	motor[motorthree] = 55;
	motor[motortwo] = 63;
	wait1Msec(2000);


	motor[motorthree] = -63;
	motor[motortwo] = 63;
	wait1Msec(700);
	//right turn? reverse made.
}
