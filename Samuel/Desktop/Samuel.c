#pragma config(Motor,  port9,           LIFT,          tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
 while(true)
 {
  motor[port9] = vexRT[Ch2];
 }


}
