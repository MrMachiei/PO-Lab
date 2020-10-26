#include <ctime>
#include <iostream>
class Stopper{
    private:
        double time;
        clock_t startTime, stopTime;
    public:
        Stopper();
        double getTime();
        void writeTime();
        void reset();
        void start();
        void stop();
};