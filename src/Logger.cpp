#include "Logger.h"
#include <iostream>

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(jobMutex);
    if (logFile) {
        logFile << message << std::endl;
    }
}
