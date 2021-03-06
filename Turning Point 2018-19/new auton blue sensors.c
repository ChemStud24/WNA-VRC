#pragma config(Sensor, dgtl9,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           catapult,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           topright,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backleft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           topleft,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           hand,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//works
task main(){

//catapult fires
 motor[catapult]= 127;
 wait1Msec(200);

 //hand goes up
 motor[hand]= -127;
 wait1Msec(650);

 motor[hand]=0;
 wait1Msec(1000);

wait1Msec(1000);

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]<650) //change
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= 120;
	motor[backleft]= 120;
	motor[topright]= -83;
	motor[backright]= -83;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= 83;
	motor[backleft]= 83;
	motor[topright]= -120;
	motor[backright]= -120;
}
  else {
  motor[topleft]= 100;
	motor[backleft]= 100;
	motor[topright]= -100;
	motor[backright]= -100;
}
}

	// turn 30 in place
	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= -120;
	motor[backright]= -120;
	wait1Msec(500); //check

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

	// turn -30 in place
	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 120;
	motor[backright]= 120;
	wait1Msec(300); //check

	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	wait1Msec(500);

	//Backwards

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]>-1120)//change
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;

} else {
  motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 100;
	motor[backright]= 100;
}
}
//hand goes down
	motor[hand]= 127;
	wait1Msec(500);

	motor[hand]=0;

//turning
	motor[topleft]= 110;
	motor[backleft]= 110;
	motor[topright]= 100;
	motor[backright]= 100;
	wait1Msec(520);

	//Backwards

SensorValue[RightEncoder]=0;
SensorValue[LeftEncoder]=0;

while(SensorValue[LeftEncoder]>-1125)//change
{
	if(SensorValue[RightEncoder]> SensorValue[LeftEncoder]){

	motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;
}

	else if(SensorValue[LeftEncoder] >  SensorValue[RightEncoder]){

  motor[topleft]= -83;
	motor[backleft]= -83;
	motor[topright]= 120;
	motor[backright]= 120;

} else {
  motor[topleft]= -100;
	motor[backleft]= -100;
	motor[topright]= 100;
	motor[backright]= 100;
}
}

	//end
	motor[topleft]= 0;
	motor[backleft]= 0;
	motor[topright]= 0;
	motor[backright]= 0;
	motor[hand]=0;

}
