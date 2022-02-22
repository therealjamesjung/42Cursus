#include "get_next_line.h"

int main()
{
    char *s;

    int fd = open("a.txt", O_RDONLY);
    int n = 0;
    while (1)
    {
        // if (n == 5)
        //     break;
        s = get_next_line(fd);
        if (!s)
            break ;
        printf("result: >%s<\n", s);
        n++;
    }
    return 0;
}