#include <stdio.h>
#include "libftprintf.h"

int main(void) {
	int n;

	n = printf("The character is: %c\n", ';');
	printf("Chars printed: %d\n", n);
	n = ft_printf("The character is: %c\n", ';');
	printf("Chars printed: %d\n", n);
	printf("The number is: %d\n", 15);
	ft_printf("The number is: %d\n", 15);
	printf("The number is: %k\n", 5);
	ft_printf("The number is: %k\n", 5);
	return 0;
}