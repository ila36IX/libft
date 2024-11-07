#include "tests.h"

int main()
{
	const char *file_path = "/tmp/file_descriptor_tests.txt";

	int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(-2147483647, fd);

	close(fd);

	fd = open(file_path, O_RDONLY);

	char buffer[13];
	ssize_t bytes_read = read(fd, buffer, 12);

	buffer[12] = '\0';

	if (bytes_read > 0)
	{
		if (strcmp("-2147483647", buffer) == 0)
			TEST_PASS("ft_putnbr_fd");
		else
			TEST_FAIL("ft_putnbr_fd");
	}

	close(fd);
	return 0;
}
