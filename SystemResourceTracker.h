#include <string>   // Add this line at the top of your header file

#ifndef SYSTEM_RESOURCE_TRACKER_H
#define SYSTEM_RESOURCE_TRACKER_H

double getCPUUsage();      // Function to get CPU usage
unsigned long getMemoryUsage();  // Function to get memory usage in MB
unsigned long getDiskUsage(const std::string& path);  // Function to get disk usage

#endif
