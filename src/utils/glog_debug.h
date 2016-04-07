#ifndef GLOG_DEBUG_H
#define GLOG_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

enum {
	INFO = 0,
	WARNING,
	ERROR,
	FATAL,
};

void glog_init(const char *argv0, const char *log_dir);
void glog_deinit();
void glog_debug(int level, char *file, int line, const char* fmt, ...);

#define GLOG_INFO(fmt, ...) glog_debug(INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define GLOG_WARN(fmt, ...) glog_debug(WARNING, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define GLOG_ERROR(fmt, ...) glog_debug(ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define GLOG_FATAL(fmt, ...) glog_debug(FATAL, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
