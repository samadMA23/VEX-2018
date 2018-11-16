#ifndef GLOBALS
#define GLOBALS

//	mo tors.h
#define MAX_SPEED 127
#define MIN_SPEED 1
#define NO_SPEED 0

//	auto_functions.h
float PISTON_LENGTH = 4100; //Time it takes for piston to fire
float FEED_LENGTH = 3000; //Time it takes to feed ball

typedef enum AUTO_SELECTION {
	RED_FRONT,
	RED_BACK,
	BLUE_FRONT,
	BLUE_BACK
} Autoselection;

typedef enum LIFT_STATES {
	STOPPED,
	STARTED,
	READY
} Liftstate;

Liftstate	mainLift = STOPPED;
Autoselection	current = RED_BACK;
#endif /* GLOBALS */
