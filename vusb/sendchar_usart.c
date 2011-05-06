#include <stdint.h>
#include "oddebug.h"
#include "sendchar.h"


#if DEBUG_LEVEL > 0
/* from oddebug.c */
int8_t sendchar(uint8_t c)
{
    while(!(ODDBG_USR & (1 << ODDBG_UDRE)));    /* wait for data register empty */
    ODDBG_UDR = c;
    return 1;
}
#else
int8_t sendchar(uint8_t c)
{
    return 1;
}
#endif
