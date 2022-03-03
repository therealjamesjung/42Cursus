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
        printf("%s", s);
        free(s);
        n++;
    }
    printf("asdf\n");
    while(1)
    {
        
    }
    return 0;
}