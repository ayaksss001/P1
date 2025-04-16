#ifndef LOGGER_C_BRIDGE_H
#define LOGGER_C_BRIDGE_H

#ifdef __cplusplus
extern "C" {
#endif

void log_debug(const char* message);
void log_info(const char* message);
void log_warning(const char* message);
void log_error(const char* message);

#ifdef __cplusplus
}
#endif

#endif // LOGGER_C_BRIDGE_H
