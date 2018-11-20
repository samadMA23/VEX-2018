/***********************************************************************************
This code was generated from multiple source files using NotVCS, by AusTIN CANs 2158
 https://github.com/dysproh/notvcs 
***********************************************************************************/


using namespace vex;

vex::brain Brain;

vex::competition Competition;

vex::task Task;

vex::motor p_lDrive(vex::PORT1, gearSetting::ratio18_1, false);
vex::motor p_rDrive(vex::PORT2, gearSetting::ratio18_1, false);
vex::motor p_elevator(vex::PORT3, gearSetting::ratio18_1, false);
vex::motor p_intake(vex::PORT4, gearSetting::ratio18_1, false);
vex::motor p_piston(vex::PORT5, gearSetting::ratio18_1, false);
vex::motor p_pistonAdjuster(vex::PORT6, gearSetting::ratio18_1, false);

vex::controller drive_controller(controllerType::primary);
vex::controller piston_controller(controllerType::partner);
using namespace vex;

namespace auton {
    typedef enum LIFT_STATES {
            STOPPED,
            STARTED,
            READY
        } LiftState;

    class AutoFunctions {
        private:
        bool stopBetweenFunctions = true;
        const uint32_t PISTON_LENGTH = 1500;
        LiftState mainLift = STOPPED;

        public:
        LiftState getLiftState();
        void setLiftState(LiftState newState);
        void stopDrive();
        void moveForward(uint32_t time, double speed);
        void moveBackward(uint32_t time, double speed);
        void rightTurn(uint32_t time, double speed);
        void leftTurn(uint32_t time, double speed);
        void leftSpin(uint32_t time, double speed);
        void rightSpin(uint32_t time, double speed);
        void rightVeer(uint32_t time, double speed, double o);
        void leftVeer(uint32_t time, double speed, double o);
        void feedBall(uint32_t time);
        bool fireBall();
    }; extern AutoFunctions functions;

    LiftState AutoFunctions::getLiftState(){
        return mainLift;
    }

    void AutoFunctions::setLiftState(LiftState newState){
        mainLift = newState;
    }

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
        p_rDrive.spin(directionType::rev, speed - o, velocityUnits::pct);
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
        setLiftState(STARTED);
        p_elevator.spin(directionType::fwd, 100, velocityUnits::pct);
        task::sleep(time);
        setLiftState(READY);

        p_elevator.stop();
    }

    bool AutoFunctions::fireBall(){
        if(getLiftState() != READY)
            return false;

        p_piston.spin(directionType::fwd, 100, velocityUnits::pct);
        task::sleep(PISTON_LENGTH);
        p_piston.stop();

        setLiftState(STOPPED);

        return true;
    }
};

namespace drive {
    class DriveFunctions {
        private:
        bool lift = false;
        bool firing = false;

        public:
        void mapJoystick();

        void toggleLift(){
            lift = !lift;
        }

        void toggleFire(){
            firing = !firing;
        }

        inline bool getLiftState(){
            return lift;
        }

        inline bool getFireState(){
            return firing;
        }

        inline double arcade_drive(vex::controller c_controller, bool positive) {
            if(positive)
                return (c_controller.Axis3.value() + c_controller.Axis4.value()) / 2;
            else
                return (c_controller.Axis3.value() - c_controller.Axis4.value()) / 2;
        }
    }; extern DriveFunctions functions;

    void DriveFunctions::mapJoystick() {
        p_lDrive.spin(directionType::fwd, drive::functions.arcade_drive(drive_controller, false), vex::velocityUnits::pct);
        p_rDrive.spin(directionType::fwd, drive::functions.arcade_drive(drive_controller, true), vex::velocityUnits::pct);
        p_pistonAdjuster.spin(directionType::fwd, piston_controller.Axis1.value(), vex::velocityUnits::pct);

        if(piston_controller.ButtonA.pressing()) functions.toggleLift();
        if(piston_controller.ButtonB.pressing()) functions.toggleFire();

        getLiftState() ? p_elevator.spin(directionType::fwd, 100, velocityUnits::pct) : p_elevator.stop();
        getFireState() ? p_piston.spin(directionType::fwd, 100, velocityUnits::pct) : p_piston.stop();
        }
}


void pre_auton() {
}

void autonomous() {
}

void drivercontrol() {
    while (true)
        drive::functions.mapJoystick();
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);

    pre_auton();

    return 0;
}
