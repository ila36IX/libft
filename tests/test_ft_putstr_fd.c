#include "tests.h"

int main()
{
	const char *file_path = "/tmp/file_descriptor_tests.txt";
	int OK = TRUE;

	int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putstr_fd("Testing is everything!", fd);

	close(fd);

	fd = open(file_path, O_RDONLY);

	char buffer[24];
	ssize_t bytes_read = read(fd, buffer, 24);

	buffer[22] = '\0';

	if (bytes_read > 0)
	{
		if (strcmp(buffer, "Testing is everything!") != 0)
			OK = FALSE;
	}

	close(fd);
	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putstr_fd(NULL, fd);
	close(fd);
	
	if (OK)
		TEST_PASS("putstr_fd");
	else
		TEST_FAIL("putstr_fd");

	return 0;
}
