all:
	gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=2 -o output && ./output
s:
	gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=100 -fsanitize=address -g3
	./a.out