#include "rush.h"
void    *malloc_initialize(unsigned int size)
{
    void    *tmp;

    tmp = malloc(size);
    initialize(tmp, size);
    return (tmp);
}