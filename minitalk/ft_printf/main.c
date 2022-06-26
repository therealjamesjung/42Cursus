#include "ft_printf.h"
#include <limits.h>

void ff(va_list ap)
{
    char c;

    c = va_arg(ap, int);
    write(1, &c, 1);
}

void f(const char *s, ...)
{
    va_list ap;
    char c;
    va_start(ap, s);
    c = va_arg(ap, int);
    write(1, &c, 1);
    c = va_arg(ap, int);
    write(1, &c, 1);
    c = va_arg(ap, int);
    write(1, &c, 1);
    va_end(ap);
}

int main()
{
	// unsigned int u= 123124512;

	// printf("%p\n", h);
	int	a = ft_printf("%u", -100);
	printf("\n");
	int b= printf("%u", -100);
	printf("\n--------");
	printf("\n%d", a);
	printf("\n%d", b);
    // f("a", '0', '2', '1');
	return (0);
}
