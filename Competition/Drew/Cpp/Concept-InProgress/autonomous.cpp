#include "autonomous.h"
#include "../Current/robot-config.h"
#include "../../../Build/vexv5/include/v5.h"

using namespace vex;

void AutoFunctions::stopDrive(){
	p_lDrive.stop();
	p_rDrive.stop();
}

void AutoFunctions::moveForward(uint32_t time, double speed){
	p_lDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
	p_rDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
	task::sleep(time); 
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::moveBackward(uint32_t time, double speed){
	p_lDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
	p_rDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::leftTurn(uint32_t time, double speed){
	p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::rightTurn(uint32_t time, double speed){
	p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::leftSpin(uint32_t time, double speed){
	p_lDrive.spin(directionType::rev, speed, velocityUnits::pct);
	p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::rightSpin(uint32_t time, double speed){
	p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	p_rDrive.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::rightVeer(uint32_t time, double speed, double o){
	p_lDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	p_rDrive.spin(directionType::rev, speed - o, velocityUnits::pct)
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::leftVeer(uint32_t time, double speed, double o){
	p_lDrive.spin(directionType::rev, speed - o, velocityUnits::pct);
	p_rDrive.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(time);
	if(stopBetweenFunctions) stopDrive();
}

void AutoFunctions::feedBall(uint32_t time){
	mainLift = STARTED;
	p_elevator.spin(directionType::fwd, 100, velocityUnits::pct);
	task::sleep(time);
	mainLift = READY; // Assuming ball has fed into the piston
	// TODO: Add actual way to check we have a ball (HW & SW)
	p_elevator.stop();
}

bool AutoFunctions::fireBall(){
	if(mainLift != READY)
		return false; // Ball shot failed, we return false
	// We want the ball to be fed first

	// TODO: Add adjustment function for angle of shot
	// adjustAngle(position);

	p_piston.spin(directionType::fwd, 100, velocityUnits::pct);
	task::sleep(PISTON_LENGTH); // Placeholder for time
	p_piston.stop();

	mainLift = STOPPED; // Reset lift for next shot

	return true; // Shot completed successfully
}