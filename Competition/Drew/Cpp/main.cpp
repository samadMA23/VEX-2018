#include "robot-config.h"
using namespace vex;

// Saw this on the VEX examples website, but I'm pretty sure this makes the robot do arcade drive
double arcade_drive(vex::controller c_controller, bool reversed) { 
    if(reversed)
        return (c_controller.Axis3.value() + c_controller.Axis4.value()) / 2;
    else
        return (c_controller.Axis3.value() - c_controller.Axis4.value()) / 2;
}

void pre_auton() {
    // All activities that occur before competition start
    // Example: setting initial positions

}

void autonomous() {
    // Place autonomous code here

}

void drivercontrol() {
    while (true) {
        
        p_lDrive.spin(directionType::undefined, arcade_drive(drive_controller, false), vex::pct);
        p_rDrive.spin(directionType::undefined, arcade_drive(drive_controller, true), vex::pct);
        
        if(piston_controller.ButtonA.pressing()) {
            p_piston.spin(directionType::fwd); // NOTE: Would this always spin after being called once?
        }
        
    }
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
    
    pre_auton();

}