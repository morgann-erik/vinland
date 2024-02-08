#ifndef V_LOG
#define V_LOG

enum LogLevel { DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3, FATAL = 4 };


/* TODO
 * Create macro for this
 */
void v_Log(const char *f, const int l, const char *lvl, const char *t,
           const char *msg);

/* TODO
 * Move to internal header
 */
void v_InitFileSink();
void v_CleanUpFileSink();

#endif
