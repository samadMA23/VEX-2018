#ifndef AUTONOMOUS_H_
#define AUTONOMOUS_H_
using namespace vex;

namespace auto {
    class AutoFunctions {
        public:
            void stopRobot();
            void moveForward(float time, velocityUnits::pct speed);
            void moveBackward(float time, velocityUnits::pct speed);
            void leftSpin(float time, velocityUnits::pct speed); 
            void rightSpin(float time, velocityUnits::pct speed);
            void rightVeer(float time, velocityUnits::pct speed, int o);
            void leftVeer(float time, velocityUnits::pct speed, int o);
            void feedBall(float time);
            bool fireBall();

    } extern AutoFunctions functions;

    enum class LIFT_STATES {
        STOPPED,
        STARTED,
        READY
    };
};
#endif /* AUTONOMOUS_H_ */

