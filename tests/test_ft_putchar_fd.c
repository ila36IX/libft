#include "tests.h"

int main()
{
	const char *file_path = "/tmp/file_descrriptor_tests.txt";

	int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putchar_fd('A', fd);

	close(fd);

	fd = open(file_path, O_RDONLY);

	char buffer[2];
	ssize_t bytes_read = read(fd, buffer, 1);

	buffer[1] = '\0';

	if (bytes_read > 0)
	{
		if (buffer[0] == 'A')
			TEST_PASS("putchar_fd");
		else
			TEST_FAIL("putchar_fd");
	}

	close(fd);
	return 0;
}
