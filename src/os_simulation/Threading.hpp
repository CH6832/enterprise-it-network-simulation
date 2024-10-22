#ifndef THREADING_HPP
#define THREADING_HPP

#include <thread>
#include <vector>
#include <stdexcept>

class Threading {
public:
    void run(int numThreads);
    
private:
    void threadFunction(int threadIndex);
};

#endif // THREADING_HPP
