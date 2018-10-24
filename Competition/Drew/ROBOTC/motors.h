#pragma config(Motor,  port1,           dBackRight,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           dBackLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           dFrontRight,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           dFrontLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           piston,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           piston_adjuster, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#include "globals.h"

void singleJoystick() { //Yeah, this is arcade drive
	motor[dBackLeft] = (vexRT[Ch2] + vexRT[Ch1]) / 2;
	motor[dFrontLeft] = (vexRT[Ch2] + vexRT[Ch1]) / 2;
	motor[dBackRight] = (vexRT[Ch2] - vexRT[Ch1]) / 2;
	motor[dFrontRight] = (vexRT[Ch2] - vexRT[Ch1]) / 2;
}

void dualJoystick() {
	motor[dBackLeft] = vexRT[Ch4];
	motor[dFrontLeft] = vexRT[Ch4];
	motor[dBackRight] = vexRT[Ch2];
	motor[dFrontRight] = vexRT[Ch2];
}

void mapJoystick() {

	singleJoystick(); //single joystick control

	//Toggle lift
	if(vexRT[Btn7LXmtr2] == 1) {
		liftOn = !liftOn;
		}else if(liftOn){
		motor[lift] = MAX_SPEED;
		motor[intake] = MAX_SPEED;
		}else if(!liftOn){
		motor[lift] = NO_SPEED;
		motor[intake] = NO_SPEED;
	}

	//Toogle piston
	if(vexRT[Btn7RXmtr2] == 1){
		firing = !firing;
		}else if(firing){
		motor[piston] = 100;
		}else if(!firing){
		motor[piston] = NO_SPEED;
	}

	//Fine tuning adjustment for piston
	motor[piston_adjuster] = vexRT[Ch4Xmtr2];

}
// I like organization! :B1:
