#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_
using namespace vex;

vex::brain Brain;

vex::competition Competition;

vex::motor  p_lDrive(vex::PORT1, gearSetting::ratio18_1, false);
vex::motor  p_rDrive(vex::PORT2, gearSetting::ratio18_1, false);
vex::motor  p_elevator(vex::PORT3, gearSetting::ratio18_1, false); // Setting elevator to 18:1, might change ratio when build complete.
vex::motor  p_intake(vex::PORT4, gearSetting::ratio18_1, false);
vex::motor  p_piston(vex::PORT5, gearSetting::ratio18_1, false);
vex::motor  p_pistonAdjuster(vex::PORT6, gearSetting::ratio18_1, false);

vex::controller drive_controller(controllerType::primary); // Setting primary to drive
vex::controller piston_controller(controllerType::partner);

#endif /* ROBOT_CONFIG_H_ */