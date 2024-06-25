#pragma once

#include <fstream>
#include <mutex>
#include <string>

class Logger {
public:
    Logger(const std::string& filename);
    void log(const std::string& message);

private:
    std::ofstream logFile;
    std::mutex jobMutex;
};