#include "rush.h"

void *ft_realloc(void *buf,  size_t before_size, size_t after_size)
{
    int i;
    uint8_t *src;
    uint8_t *dst;
    src = (uint8_t *)buf;
    dst = (uint8_t *)malloc_initialize(after_size);
    while(i < before_size)
    {
        dst[i] = src[i];
        i++;
    }
    free(buf);
    return (void *)dst;
}

s_numdict *build_dict()
{
    int fd;
    s_numdict *dict;
    if ((fd = open("numbers.dict", O_RDONLY)) == -1)
		return (0);
    
    close(fd);
    return dict;
}

char *read_line(int fd)
{
    char buf;
    char *result;
    int read_result;
    int loop;
    buf = 0;
    loop = 0;
    result = malloc_initialize(1);
    while(buf != '\n')
    {
        read_result = read(fd, buf, 1);
        if(read_result == 0)
            break;
        if(read_result == -1)
            ft_putchar("error");    
        result = ft_realloc(result, loop+1, loop+2);
        result[loop] = buf;
        result[loop+1] = 0;
        loop++;
    }
    return result;
}
