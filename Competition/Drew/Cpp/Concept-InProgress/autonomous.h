#ifndef AUTONOMOUS_H_
#define AUTONOMOUS_H_
using namespace vex;

namespace auto {
    class AutoFunctions {
        public:
        void stopRobot();
        void moveForward(uint32_t time, double speed);
        void moveBackward(uint32_t time, double speed);
        void leftSpin(uint32_t time, double speed); 
        void rightSpin(uint32_t time, double speed);
        void rightVeer(uint32_t time, double speed, double o);
        void leftVeer(uint32_t time, double speed, double o);
        void feedBall(uint32_t time);
        bool fireBall();
        
        private:
        bool stopBetweenFunctions = true;

        private enum LIFT_STATES {
            STOPPED,
            STARTED,
            READY
        };
        
    }; extern AutoFunctions functions;

    enum class LIFT_STATES {
        STOPPED,
        STARTED,
        READY
    };
};
#endif /* AUTONOMOUS_H_ */

