# System Resource Manager

## Overview
The **System Resource Manager** is a lightweight C++ project designed to monitor and display system resource usage, including CPU frequency, memory usage, and disk usage. This project is particularly useful for understanding how system resources are utilized in real-time, making it a valuable tool for operating system theory and resource management studies.

## Purpose
The project demonstrates how to interact with system-level APIs to fetch hardware and resource usage details. It is a practical implementation of operating system concepts such as:
- CPU resource monitoring
- Memory management
- Disk space utilization

## Features
1. **CPU Usage Monitoring**: Fetches the current CPU frequency in MHz.
2. **Memory Usage Monitoring**: Retrieves the total physical memory size in MB.
3. **Disk Usage Monitoring**: Calculates the total disk space in MB for a specified path.

## File Structure
- **SystemResourceTracker.h**: Header file containing function declarations for resource tracking.
- **SystemResourceTracker.cpp**: Implementation file with the logic to fetch system resource details.
- **main.cpp**: Entry point of the program that displays resource usage in a loop.
- **README.md**: Documentation file providing an overview of the project.

## Function Details
### `getCPUUsage()`
- **Description**: Fetches the current CPU frequency in MHz.
- **Implementation**: Uses the `sysctl` system call to query hardware information.
- **Return Value**: CPU frequency as a `double`.

### `getMemoryUsage()`
- **Description**: Retrieves the total physical memory size in MB.
- **Implementation**: Uses the `sysctl` system call to query memory size.
- **Return Value**: Memory size as an `unsigned long`.

### `getDiskUsage(const std::string& path)`
- **Description**: Calculates the total disk space in MB for the specified path.
- **Implementation**: Uses the `statfs` system call to fetch disk statistics.
- **Parameters**: 
  - `path`: The file system path to check disk usage for.
- **Return Value**: Total disk space as an `unsigned long`.

## How to Run
1. Compile the project using a C++ compiler (e.g., `g++`).
   ```bash
   g++ -o SystemResourceManager main.cpp SystemResourceTracker.cpp
   ```
2. Run the compiled executable.
   ```bash
   ./SystemResourceManager
   ```
3. The program will display CPU, memory, and disk usage every 5 seconds.

## Operating System Theory
This project aligns with the following OS concepts:
- **Resource Allocation**: Demonstrates how operating systems allocate and track hardware resources.
- **System Calls**: Utilizes system calls like `sysctl` and `statfs` to interact with the kernel.
- **Performance Monitoring**: Provides insights into system performance by monitoring key metrics.

## Notes
- The project is designed for macOS systems and may require modifications for other operating systems.
- Ensure you have the necessary permissions to access system-level APIs.

## Future Enhancements
- Add support for monitoring additional resources like network usage.
- Extend compatibility to other operating systems such as Linux and Windows.
- Implement a graphical user interface (GUI) for better visualization.

## License
This project is open-source and available under the MIT License.
