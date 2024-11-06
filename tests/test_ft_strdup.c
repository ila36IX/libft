#include "tests.h"

int main()
{
    int OK = TRUE;
    const char *original = "Test string for strdup";
    char *copy = ft_strdup(original);

    if (copy == NULL)
        OK = FALSE;

    else
    {
        if (strcmp(original, copy) != 0)
            OK = FALSE;
        for (size_t i = 0; i < strlen(original); i++)
            if (original[i] != copy[i])
                OK = FALSE;
        free(copy);
    }

    const char *another_original = "Another test string for strdup";
    copy = ft_strdup(another_original);

    if (copy == NULL)
    {
        OK = FALSE;
    }
    else
{
        if (strcmp(another_original, copy) != 0)
            OK = FALSE;

        for (size_t i = 0; i < strlen(another_original); i++)
            if (another_original[i] != copy[i])
                OK = FALSE;

        free(copy);
    }

    if (OK)
        TEST_PASS("strdup");
    else
        TEST_FAIL("strdup");

    return 0;
}

