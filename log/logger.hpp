#pragma once
#include <string>
#include <mutex>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger{
public :
    static Logger& getInstance();
    void log(LogLevel level, const std::string& message);
    void setLevel(LogLevel level);

    private :
        Logger();
        LogLevel currentLevel;
        std::mutex logMutex;

        std::string getLabel(LogLevel level);
        std::string getColor(LogLevel level);

};