#include <sys/sysctl.h>
#include <sys/mount.h>  // Correct header for disk usage on macOS
#include <iostream>
#include "SystemResourceTracker.h"

double getCPUUsage() {
    int mib[2] = {CTL_HW, HW_CPU_FREQ};
    uint64_t cpu_freq;
    size_t len = sizeof(cpu_freq);
    sysctl(mib, 2, &cpu_freq, &len, nullptr, 0);

    return cpu_freq / 1000000.0; // Convert to MHz
}

unsigned long getMemoryUsage() {
    int mib[2] = {CTL_HW, HW_MEMSIZE};
    unsigned long mem_size;
    size_t len = sizeof(mem_size);
    sysctl(mib, 2, &mem_size, &len, nullptr, 0);

    return mem_size / (1024 * 1024);  // Convert bytes to MB
}

unsigned long getDiskUsage(const std::string& path) {
    struct statfs buf;
    if (statfs(path.c_str(), &buf) == -1) {
        std::cerr << "Error fetching disk info" << std::endl;
        return 0;
    }

    unsigned long free_space = buf.f_bsize * buf.f_bfree;
    unsigned long total_space = buf.f_bsize * buf.f_blocks;

    return total_space / (1024 * 1024);  // Return total disk space in MB
}
