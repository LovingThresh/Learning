#include "Queue.h"

void Customer::set(const long when) {
    arrive = when;
    processtime = std::rand() % 3 + 1;
}