#include "autonomous.h"
#include "../../../Build/vexv5/include/v5.h"

namespace auto {
	void AutoFunctions::stopDrive(){
		p_lDrive.stop();
		p_rDrive.stop();
	}

	void AutoFunctions::moveForward(int time, velocityUnits::pct speed){
		p_lDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
		p_rDrive.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
		task::sleep(time);
		stopDrive();
	}

	void AutoFunctions::moveBackward(int time, int speed){
		p_lDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
		p_rDrive.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
		Task.sleep(time);
		stopDrive();
	}

	void AutoFunctions::leftTurn(int time, int speed){
		p_lDrive.
		motor[dFrontRight] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightTurn(int time, int speed){
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::leftSpin(int time, int speed){
		motor[dFrontRight] = speed;
		motor[dBackRight] = speed;
		motor[dBackLeft] = speed *-1;
		motor[dFrontLeft] = speed *-1;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightSpin(int time, int speed){
		motor[dFrontRight] = speed *-1;
		motor[dBackRight] = speed *-1;
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightVeer(int time, int speed, int offset) {
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		motor[dBackRight] = (speed *-1) - offset;
		motor[dFrontRight] = (speed *-1) - offset;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::leftVeer(int time, int speed, int offset) {
		motor[dBackRight] = speed;
		motor[dFrontRight] = speed;
		motor[dBackLeft] = (speed *-1) - offset;
		motor[dFrontLeft] = (speed *-1) - offset;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::feedBall(int time)
	{
		mainLift = STARTED;
		motor[lift] = MAX_SPEED;
		wait1Msec(time);
		mainLift = READY; // Assuming ball has fed into the piston
										// TODO: Add actual way to check we have a ball (HW & SW)
		motor[lift] = NO_SPEED;
	}

	bool AutoFunctions::fireBall()
	{
		if(mainLift != READY)
			return false; // Ball shot failed, we return false
										// We want the ball to be fed first

		// TODO: Add adjustment function for angle of shot
		// adjustAngle(position);

		motor[piston] = MAX_SPEED;
		wait1Msec(PISTON_LENGTH); // Placeholder for time
		motor[piston] = NO_SPEED;

		mainLift = STOPPED; // Reset lift for next shot

		return true; // Shot completed successfully
	}

	short getPiston() {
		return SensorValue[piston_tracker];
	}

}