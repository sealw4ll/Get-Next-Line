all:
	gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=100 -o output && ./output
s:
	gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=100 -fsanitize=address -g3 -o output
	./output