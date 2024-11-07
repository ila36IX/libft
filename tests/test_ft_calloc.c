#include "tests.h"

int main()
{
    int OK = TRUE;
    size_t num_elements = 20;
    size_t element_size = sizeof(int);
    int *arr = (int *)ft_calloc(num_elements, element_size);

    for (size_t i = 0; i < num_elements; i++)
        if (arr[i])
            OK = FALSE;
    for (size_t i = 0; i < num_elements; i++)
        arr[i] = i + 1;

    free(arr);
    arr = (int *)ft_calloc(num_elements, element_size);

    for (size_t i = 0; i < num_elements; i++)
        if (arr[i])
            OK = FALSE;
    for (size_t i = 0; i < num_elements; i++)
        arr[i] = i + 1;

    free(arr);
    if (OK)
        TEST_PASS("calloc");
    else
        TEST_FAIL("calloc");
    return 0;
}

