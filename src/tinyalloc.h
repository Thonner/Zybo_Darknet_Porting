#include <stdbool.h>
#include <stddef.h>

bool ta_init();
void *ta_alloc(size_t num);
void *ta_calloc(size_t num, size_t size);
bool ta_free(void *ptr);
void *ta_realloc(void *free, size_t num);

size_t ta_num_free();
size_t ta_num_used();
size_t ta_num_fresh();
bool ta_check();
