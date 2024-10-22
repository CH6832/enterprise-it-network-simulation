#include "Process.hpp"

// Constructor
Process::Process(int id, int burstTime, int priority) 
    : id(id), burstTime(burstTime), waitingTime(0), priority(priority) {}
