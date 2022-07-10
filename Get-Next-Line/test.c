#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int fd = open("/Users/wting/42cursus/Get-Next-Line/test", O_RDONLY);
	char *a;
	int i = 0;

	a = get_next_line(fd);
	while (i++ != 4)
	{
		printf("%s", a);
		free (a);
		a = get_next_line(fd);
	}
	system("leaks output");
}