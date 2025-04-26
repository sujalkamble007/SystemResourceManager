#include <iostream>
#include <unistd.h>
#include "SystemResourceTracker.h"

int main() {
    while (true) {
        std::cout << "CPU Usage: " << getCPUUsage() << " MHz" << std::endl;
        std::cout << "Memory Usage: " << getMemoryUsage() << " MB" << std::endl;
        std::cout << "Disk Usage: " << getDiskUsage("/") << " MB" << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        sleep(5);  // Wait 5 seconds before fetching again
    }

    return 0;
}
