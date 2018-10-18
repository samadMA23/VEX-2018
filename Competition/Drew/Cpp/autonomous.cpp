#include "autonomous.h"
#include "../../../Build/vexv5/include/v5.h"

namespace auto {
	void AutoFunctions::stopDrive(){
		p_lDrive.stop();
		p_rDrive.stop();
	}

	void AutoFunctions::moveForward(float time, velocityUnits::pct){
		p_lDrive.stop();
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::moveBackward(float time, velocityUnits::pct){
		motor[dBackRight] = speed *-1;
		motor[dBackLeft] = speed *-1;
		motor[dFrontLeft] = speed *-1;
		motor[dFrontRight] = speed *-1;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::leftTurn(float time, velocityUnits::pct){
		motor[dBackRight] = speed;
		motor[dFrontRight] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightTurn(float time, int speed){
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::leftSpin(float time, int speed){
		motor[dFrontRight] = speed;
		motor[dBackRight] = speed;
		motor[dBackLeft] = speed *-1;
		motor[dFrontLeft] = speed *-1;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightSpin(float time, int speed){
		motor[dFrontRight] = speed *-1;
		motor[dBackRight] = speed *-1;
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::rightVeer(float time, int speed, int offset) {
		motor[dBackLeft] = speed;
		motor[dFrontLeft] = speed;
		motor[dBackRight] = (speed *-1) - offset;
		motor[dFrontRight] = (speed *-1) - offset;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::leftVeer(float time, int speed, int offset) {
		motor[dBackRight] = speed;
		motor[dFrontRight] = speed;
		motor[dBackLeft] = (speed *-1) - offset;
		motor[dFrontLeft] = (speed *-1) - offset;
		wait1Msec(time);
		stopDrive();
	}

	void AutoFunctions::feedBall(float time)
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