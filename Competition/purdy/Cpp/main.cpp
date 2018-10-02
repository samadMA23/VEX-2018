// THIS FILE WAS WRITTEN BY ANDREW SCHINELLER @schineaj23 
// 10/2/2018

#include "robot-config.h"

//pragma config(Motor,  port2,           fLeft,         tmotorVex393_MC29, openLoop, reversed)
//pragma config(Motor,  port3,           fRight,        tmotorVex393_MC29, openLoop)
//pragma config(Motor,  port4,           bLeft,         tmotorVex393_MC29, openLoop, reversed)
//pragma config(Motor,  port5,           bRight,        tmotorVex393_MC29, openLoop)
//pragma config(Motor,  port6,           fDisk,         tmotorVex393_MC29, openLoop)
//pragma config(Motor,  port7,           Lift,          tmotorVex393_MC29, openLoop)

vex::motor fLeft(PORT2, gearSetting::ratio18_1, true);
vex::motor fRight(PORT3, gearSetting::ratio18_1, false);
vex::motor bLeft(PORT4, gearSetting::ratio18_1, true);
vex::motor bRight(PORT5, gearSetting::ratio18_1, false);
vex::motor fDisk(PORT6, gearSetting::ratio18_1, false);
vex::motor Lift(PORT7, gearSetting::ratio18_1, false);

vex::competition Competition;
vex::controller DriveController(controllerType::primary);

void dualJoystick() {
        fLeft.spin(directionType::fwd, DriveController.Axis3.value(), velocityUnits::pct);
        bLeft.spin(directionType::fwd, DriveController.Axis3.value(), velocityUnits::pct);
        
        bRight.spin(directionType::fwd, DriveController.Axis2.value(), velocityUnits::pct);
        fRight.spin(directionType::fwd, DriveController.Axis2.value(), velocityUnits::pct);
        
        if(DriveController.ButtonL1.pressing()) {
            fDisk.spin(directionType::fwd);
        } 
        else if(DriveController.ButtonL2.pressing()) {
            fDisk.spin(directionType::rev);
        }
        else {
            fDisk.stop();
        }
        
        
        if(DriveController.ButtonR1.pressing()) {
            Lift.spin(directionType::fwd);
        } 
        else if(DriveController.ButtonR2.pressing()) {
            Lift.spin(directionType::rev);
        }
        else {
            Lift.stop();
        }
}

void singleJoystick() {
    fLeft.spin(directionType::fwd, (DriveController.Axis3.value() + DriveController.Axis4.value()) / 2, velocityUnits::pct);
    bLeft.spin(directionType::fwd, (DriveController.Axis3.value() + DriveController.Axis4.value()) / 2, velocityUnits::pct);
    
    bRight.spin(directionType::fwd, (DriveController.Axis3.value() - DriveController.Axis4.value()) / 2, velocityUnits::pct);
    fRight.spin(directionType::fwd, (DriveController.Axis3.value() - DriveController.Axis4.value()) / 2, velocityUnits::pct);

    Lift.spin(directionType::undefined, DriveController.Axis1.value(), velocityUnits::pct);
    fDisk.spin(directionType::undefined, DriveController.Axis2.value(), velocityUnits::pct);
}

void pre_auto() {
    
}

void autonomous() {
    
}

void drivercontrol() {
    while(true) {
        dualJoystick();
    }
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
    pre_auto();
    
}
