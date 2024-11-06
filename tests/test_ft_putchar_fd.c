#include "tests.h"

int	main(void)
{
	int		OK;
	char	c;
	int		fd;
	char	temp_file[] = "/tmp/ft_putchar_fd_test_69";
			char buffer[2] = {0};

	OK = TRUE;
	c = 'A';
	fd = mkstemp(temp_file);

	{
		ft_putchar_fd(c, fd);
		close(fd);
		fd = open(temp_file, O_RDONLY);
		if (fd == -1)
		{
			TEST_FAIL("ft_putchar_fd failed to open temporary file");
			OK = FALSE;
		}
		else
		{
			if (read(fd, buffer, 1) != 1 || buffer[0] != c)
			{
				TEST_FAIL("ft_putchar_fd did not write the correct character to the file");
				OK = FALSE;
			}
			else
			{
				TEST_PASS("ft_putchar_fd writes to a file correctly");
			}
			close(fd);
			unlink(temp_file);
		}

	if (OK)
		TEST_PASS("ft_putchar_fd");
	else
		TEST_FAIL("ft_putchar_fd");
	return (0);
}
