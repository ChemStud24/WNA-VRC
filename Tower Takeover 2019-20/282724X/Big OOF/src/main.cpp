/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\jdbla                                            */
/*    Created:      Tue Jan 07 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// WheelR1              motor29       B               
// WheelR2              motor29       C               
// WheelL1              motor29       D               
// WheelL2              motor29       E               
// Controller1          controller                    
// ArmRight             motor         1               
// ArmLeft              motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
double RightSpeed;
double LeftSpeed;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
RightSpeed=Controller1.Axis2.value();
LeftSpeed=Controller1.Axis3.value();
if(RightSpeed>0){
WheelR1.spin(forward,RightSpeed,percent);
WheelR2.spin(forward,RightSpeed,percent);
}else{
  WheelR1.spin(reverse,-RightSpeed,percent);
  WheelR2.spin(reverse,-RightSpeed,percent);
}
if(LeftSpeed>0){
WheelL1.spin(forward,LeftSpeed,percent);
WheelL2.spin(forward,LeftSpeed,percent);
}else{
  WheelL1.spin(reverse,-LeftSpeed,percent);
  WheelL2.spin(reverse,-LeftSpeed,percent);
}
  }
ArmRight.spin(reverse,-200,rpm);
ArmRight.spin(forward,200,rpm);
ArmLeft.spin(forward,200,rpm);
ArmLeft.spin(reverse,-200,rpm);
ArmLeft.setVelocity(200,rpm);
ArmLeft.setVelocity(-200,rpm);
ArmRight.setVelocity(200,rpm);
ArmRight.setVelocity(-200,rpm);

}