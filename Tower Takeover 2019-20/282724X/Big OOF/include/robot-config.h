using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor29 WheelR1;
extern motor29 WheelR2;
extern motor29 WheelL1;
extern motor29 WheelL2;
extern controller Controller1;
extern motor ArmRight;
extern motor ArmLeft;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );