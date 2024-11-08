#include "tests.h"

void del_content(void *content)
{
	free(content);
}

void to_upper(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}

void *map_to_upper(void *content)
{
	char *str = strdup((char *)content);
	if (!str)
		return NULL;
	char *ptr = str;
	while (*ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = *ptr - 32;
		ptr++;
	}
	return str;
}

int test_ft_lstnew()
{
	int passed = 1;

	t_list *node1 = ft_lstnew(strdup("1"));
	if (!node1 || strcmp(node1->content, "1") != 0)
	{
		TEST_FAIL("ft_lstnew - regular string");
		passed = 0;
	}

	t_list *node_null = ft_lstnew(NULL);
	if (!node_null || node_null->content != NULL)
	{
		TEST_FAIL("ft_lstnew - NULL content");
		passed = 0;
	}

	if (passed)
		TEST_PASS("ft_lstnew");

	ft_lstdelone(node1, del_content);
	ft_lstdelone(node_null, del_content);
	return passed;
}

int test_ft_lstadd_front()
{
	int passed = 1;
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(strdup("1"));
	t_list *node2 = ft_lstnew(strdup("2"));
	t_list *node3 = ft_lstnew(strdup("3"));

	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);

	if (strcmp(head->content, "1") != 0 || 
		strcmp(head->next->content, "2") != 0 || 
		strcmp(head->next->next->content, "3") != 0)
	{
		TEST_FAIL("ft_lstadd_front");
		passed = 0;
	}
	else
	TEST_PASS("ft_lstadd_front");

	ft_lstclear(&head, del_content);
	return passed;
}

int test_ft_lstsize()
{
	int passed = 1;
	t_list *head = NULL;

	if (ft_lstsize(head) != 0)
	{
		TEST_FAIL("ft_lstsize - empty list");
		passed = 0;
	}

	ft_lstadd_front(&head, ft_lstnew(strdup("1")));
	ft_lstadd_front(&head, ft_lstnew(strdup("2")));
	ft_lstadd_front(&head, ft_lstnew(strdup("3")));

	if (ft_lstsize(head) != 3)
	{
		TEST_FAIL("ft_lstsize - three elements");
		passed = 0;
	}

	if (passed)
		TEST_PASS("ft_lstsize");

	ft_lstclear(&head, del_content);
	return passed;
}

int test_ft_lstlast()
{
	int passed = 1;
	t_list *head = NULL;

	if (ft_lstlast(head) != NULL)
	{
		TEST_FAIL("ft_lstlast - empty list");
		passed = 0;
	}

	ft_lstadd_back(&head, ft_lstnew(strdup("1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("3")));

	if (strcmp(ft_lstlast(head)->content, "3") != 0)
	{
		TEST_FAIL("ft_lstlast - last element");
		passed = 0;
	}

	if (passed)
		TEST_PASS("ft_lstlast");

	ft_lstclear(&head, del_content);
	return passed;
}

int test_ft_lstadd_back()
{
	int passed = 1;
	t_list *head = NULL;

	t_list *node1 = ft_lstnew(strdup("1"));
	ft_lstadd_back(&head, node1);
	if (strcmp(head->content, "1") != 0)
	{
		TEST_FAIL("ft_lstadd_back - empty list");
		passed = 0;
	}

	ft_lstadd_back(&head, ft_lstnew(strdup("2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("3")));

	if (strcmp(ft_lstlast(head)->content, "3") != 0)
	{
		TEST_FAIL("ft_lstadd_back - non-empty list");
		passed = 0;
	}

	if (passed)
		TEST_PASS("ft_lstadd_back");

	ft_lstclear(&head, del_content);
	return passed;
}

int test_ft_lstdelone()
{
	int passed = 1;
	t_list *node = ft_lstnew(strdup("test"));
	t_list *next = ft_lstnew(strdup("next"));
	node->next = next;

	ft_lstdelone(node, del_content);

	if (strcmp(next->content, "next") != 0)
	{
		TEST_FAIL("ft_lstdelone");
		passed = 0;
	}
	else
	TEST_PASS("ft_lstdelone");

	ft_lstdelone(next, del_content);
	return passed;
}

int test_ft_lstclear()
{
	int passed = 1;
	t_list *head = NULL;

	ft_lstadd_back(&head, ft_lstnew(strdup("1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("3")));

	ft_lstclear(&head, del_content);

	if (head != NULL)
	{
		TEST_FAIL("ft_lstclear");
		passed = 0;
	}
	else
	TEST_PASS("ft_lstclear");

	return passed;
}

int test_ft_lstiter()
{
	int passed = 1;
	t_list *head = NULL;

	ft_lstadd_back(&head, ft_lstnew(strdup("test1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("test2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("test3")));

	ft_lstiter(head, to_upper);

	if (strcmp(head->content, "TEST1") != 0 ||
		strcmp(head->next->content, "TEST2") != 0 ||
		strcmp(head->next->next->content, "TEST3") != 0)
	{
		TEST_FAIL("ft_lstiter");
		passed = 0;
	}
	else
	TEST_PASS("ft_lstiter");

	ft_lstclear(&head, del_content);
	return passed;
}

int test_ft_lstmap()
{
	int passed = 1;
	t_list *head = NULL;

	ft_lstadd_back(&head, ft_lstnew(strdup("test1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("test2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("test3")));

	t_list *new_list = ft_lstmap(head, map_to_upper, del_content);

	if (!new_list || 
		strcmp(new_list->content, "TEST1") != 0 ||
		strcmp(new_list->next->content, "TEST2") != 0 ||
		strcmp(new_list->next->next->content, "TEST3") != 0)
	{
		TEST_FAIL("ft_lstmap");
		passed = 0;
	}
	else
	TEST_PASS("ft_lstmap");

	ft_lstclear(&head, del_content);
	ft_lstclear(&new_list, del_content);
	return passed;
}

int main()
{
	int all_passed = 1;

	// Run all tests
	all_passed &= test_ft_lstnew();
	all_passed &= test_ft_lstadd_front();
	all_passed &= test_ft_lstsize();
	all_passed &= test_ft_lstlast();
	all_passed &= test_ft_lstadd_back();
	all_passed &= test_ft_lstdelone();
	all_passed &= test_ft_lstclear();
	all_passed &= test_ft_lstiter();
	all_passed &= test_ft_lstmap();

	if (all_passed)
		TEST_PASS("bonus");
	else
		TEST_FAIL("bonus");

	return !all_passed;
}
