#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd = open("./node", O_RDONLY);
	if(fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return 0;
}
