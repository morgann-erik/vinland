#include "log.h"
int main(void) {
    v_InitFileSink();
    v_SetLogLevel(INFO);
    v_Log(__FILE__, DEBUG, __LINE__, "TEST");
    v_Log(__FILE__, FATAL, __LINE__, "FATAL");

    v_SetLogLevel(DEBUG);
    v_Log(__FILE__, DEBUG, __LINE__, "TEST");
    v_Log(__FILE__, FATAL, __LINE__, "FATAL");
    v_CleanUpFileSink();
    return 0;
}
