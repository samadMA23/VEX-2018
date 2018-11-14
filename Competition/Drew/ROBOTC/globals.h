#ifndef GLOBALS
#define GLOBALS

//	mo tors.h
#define MAX_SPEED 127
#define MIN_SPEED 1
#define NO_SPEED 0

//	auto_functions.h
float PISTON_LENGTH = 4100; //Placeholder for time piston takes to fire.

typedef enum LIFT_STATES {
	STOPPED,
	STARTED,
	READY
} Liftstate;

Liftstate	mainLift = STOPPED;
#endif /* GLOBALS */
