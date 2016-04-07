#include "includes.h"

#include <glog/logging.h>

#ifdef __cplusplus
extern "C" {
#endif

static void failureCallback()
{
	exit(1);
}

void glog_debug(int level, char *file, int line, const char* fmt, ...)
{
	std::string sfmt(fmt);
    int size = ((int)sfmt.size()) * 2 + 64;
    std::string str;
    va_list ap;

    while(1) {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, sfmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            break;
        }
        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }
    google::LogMessage(file, line).stream() << str;
}

void glog_init(const char *argv0, const char *log_dir)
{
	google::InitGoogleLogging(argv0);
	google::InstallFailureFunction(failureCallback);

	if (log_dir == NULL) {
		FLAGS_log_dir = "/var/log/";
	}
	else {
		FLAGS_log_dir = log_dir;
	}
	FLAGS_logtostderr = 0;
}

void glog_deinit()
{
	google::ShutdownGoogleLogging();
}

#ifdef __cplusplus
}
#endif
