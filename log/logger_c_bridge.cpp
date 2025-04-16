#include "logger.hpp"
#include "logger.h"

void log_debug(const char* message) {
    Logger::getInstance().log(LogLevel::DEBUG, message);
}

void log_info(const char* message) {
    Logger::getInstance().log(LogLevel::INFO, message);
}

void log_warning(const char* message) {
    Logger::getInstance().log(LogLevel::WARNING, message);
}

void log_error(const char* message) {
    Logger::getInstance().log(LogLevel::ERROR, message);
}
