// VEX V5 C++ Project with Competition Template
#include "vex.h"
using namespace vex;

//#region config_globals
vex::brain Brain;
//#endregion config_globals



vex::motor  p_lDrive(vex::PORT1, gearSetting::ratio18_1, false);
vex::motor  p_rDrive(vex::PORT2, gearSetting::ratio18_1, false);
vex::motor  p_elevator(vex::PORT3, gearSetting::ratio18_1, false); // Setting elevator to 18:1, might change ratio when build complete.
vex::motor  p_intake(vex::PORT4, gearSetting::ratio18_1, false);
vex::motor  p_piston(vex::PORT5, gearSetting::ratio318_1, false);

vex::controller drive_controller(controllerType::primary); // Setting primary to drive
vex::controller piston_controller(controllerType::partner);

// Saw this on the VEX examples website, but I'm pretty sure this makes the robot do arcade drive
double controller_drive_axis(vex::controller c_controller, bool reversed) { 
    if(reversed)
        return (c_controller.Axis3.value() + c_controller.Axis4.value()) / 2;
    else
        return (c_controller.Axis3.value() - c_controller.Axis4.value()) / 2;
}

// Creates a competition object that allows access to Competition methods.
vex::competition Competition;

void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial positions

}

void autonomous() {
    // Place autonomous code here

}

void drivercontrol() {
    // Place drive control code here, inside the loop
    while (true) {
        // This is the main loop for the driver control.
        // Each time through the loop you should update motor
        // movements based on input from the controller.
        
        p_lDrive.spin(directionType::undefined, controller_drive_axis(drive_controller, false), vex::pct);
        p_rDrive.spin(directionType::undefined, controller_drive_axis(drive_controller, true), vex::pct);
        
        if(piston_controller.ButtonA.pressing()) {
            p_piston.spin(directionType::fwd); // NOTE: Would this always spin after being called once?
        }
        
    }
}

int main() {
    // Do not adjust the lines below

    // Set up (but don't start) callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Robot Mesh Studio runtime continues to run until all threads and
    // competition callbacks are finished.
}
