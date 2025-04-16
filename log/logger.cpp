#include "logger.hpp"
#include <iostream>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

Logger::Logger(){
    currentLevel = LogLevel::DEBUG;
}

Logger& Logger::getInstance(){
    static Logger instance;
    return instance;
}

void Logger::setLevel(LogLevel level){
    currentLevel = level;
}

string Logger::getLabel(LogLevel level){
    switch (level)
    {
    case LogLevel::DEBUG: return "[DEBUG]";
    case LogLevel::ERROR: return "[ERROR]";
    case LogLevel::INFO: return "[INFO]";
    case LogLevel::WARNING: return "[WARNING]";    
    default: return"[UNKNOWN]";
    }
}

string Logger::getColor(LogLevel level){
#ifdef _WIN32
    return "";
#else
    switch(level)
    {
        case LogLevel::DEBUG: return "\033[36m";
        case LogLevel::WARNING: return "\033[33m";
        case LogLevel::ERROR: return "\033[31m";
        case LogLevel::INFO: return "\033[32m";
    }
#endif
return "\033[0m";
}

void Logger::log(LogLevel level, const string& message){
    if(level < currentLevel) return;

    lock_guard<mutex>lock(logMutex);
    time_t now = time(nullptr);
    string color = getColor(level);
    string label = getLabel(level);
    string reset = "\033m[0m";

    cout << color << "[" << ctime(&now);
    cout << "]" << label << ": " << message << reset << endl;
}