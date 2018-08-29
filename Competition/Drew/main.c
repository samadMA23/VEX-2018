//////////////////////////////////////
//	File: 			main.c							//
//	Author: 		Andrew Schineller		//
//	Date:				8/29/2018	3:56PM		//
//////////////////////////////////////

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bDisplayCompetitionStatusOnLcd = false;
}

task autonomous()
{

}

task usercontrol()
{
	while(true)
	{
		break; // NOTE: Remove when you have code
	}
}
