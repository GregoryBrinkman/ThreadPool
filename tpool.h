#ifndef __ADULT_SWIM_IN_THE_TPOOL
#define __ADULT_SWIM_IN_THE_TPOOL

/* typedef struct tpool_t pool; */

extern int tpool_init(void (*process_task)(int));

extern int tpool_add_task(int newtask);
#endif



