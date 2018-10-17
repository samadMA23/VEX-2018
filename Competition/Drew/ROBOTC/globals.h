#ifndef GLOBALS
#define GLOBALS

//	motors.h
#define MAX_SPEED 127
#define MIN_SPEED 1
#define NO_SPEED 0

bool liftOn = false; // Is the lift on?
bool firing = false; // Is the piston firing?

//	auto_functions.h
float PISTON_LENGTH = NULL; //Placeholder for time piston takes to fire.

typedef enum LIFT_STATES {
	STOPPED,
	STARTED,
	READY
} Liftstate;

Liftstate	mainLift = STOPPED;

#endif /* GLOBALS */
