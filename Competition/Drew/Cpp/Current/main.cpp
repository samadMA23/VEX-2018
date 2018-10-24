#include "../../../Build/vexv5/include/v5.h" // NOTE: This is here for the VSCode to find the vex namespace
#include "robot-config.h"
using namespace vex;

inline double arcade_drive(vex::controller c_controller, bool reversed) { 
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
    bool lift = false, firing = false;
    while (true) {  
        p_lDrive.spin(directionType::fwd, arcade_drive(drive_controller, false), vex::velocityUnits::pct);
        p_rDrive.spin(directionType::fwd, arcade_drive(drive_controller, true), vex::velocityUnits::pct);
        p_pistonAdjuster.spin(directionType::fwd, piston_controller.Axis1.value(), vex::velocityUnits::pct);
        
        // Toggle lift
        if(piston_controller.ButtonA.pressed()){
            lift = !lift;
        }else if(lift) {
            p_elevator.spin(directionType::fwd, 100, velocityUnits::pct);
        }else if(!lift){
            p_elevator.stop();
        }
        
        // Toggle piston firing
        if(piston_controller.ButtonB.pressed()) {
            firing = !firing;
        }else if(firing){
            p_piston.spin(directionType::fwd, 100, velocityUnits::pct);
        }else if(!firing){
            p_piston.stop();
        }
        
    }
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
    
    pre_auton();

}