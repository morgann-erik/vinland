#ifndef V_LOG
#define V_LOG

enum LogLevel { DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3, FATAL = 4 };

#define V_LogDebug(msg) v_Log(__FILE__, DEBUG, __LINE__, msg)
#define V_LogInfo(msg) v_Log(__FILE__, INFO, __LINE__, msg)
#define V_LogWarning(msg) v_Log(__FILE__, WARNING, __LINE__, msg)
#define V_LogError(msg) v_Log(__FILE__, ERROR, __LINE__, msg)
#define V_LogFatal(msg) v_Log(__FILE__, FATAL, __LINE__, msg)

void v_SetLogLevel(enum LogLevel value);
/* TODO
 * Create macro for this
 */
void v_Log(const char *f, const enum LogLevel lvl, const int l,
           const char *msg);

/* TODO
 * Move to internal header
 */
void v_InitFileSink();
void v_CleanUpFileSink();

#endif
