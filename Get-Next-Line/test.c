#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int fd = open("/Users/wting/42cursus/get_next_line.c/Get-Next-Line/test", O_RDONLY);
	char *a;
	// int i = 0;

	a = get_next_line(fd);
	printf("%s", a);
	free (a);

	a = get_next_line(fd);
	printf("%s", a);
	free (a);

	a = get_next_line(fd);
	printf("%s", a);
	free (a);

	a = get_next_line(fd);
	printf("%s", a);
	free (a);
	system("leaks output");
}