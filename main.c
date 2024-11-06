#include "libft.h"

void print_list(t_list *lst)
{
    printf("List contents: ");
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void del_content(void *content)
{
    free(content);
}

void to_upper(void *content) {
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
}

void *map_func(void *content) {
    char *str = strdup((char *)content);
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    return str;
}

int main(void) {
    t_list *list = NULL;
    t_list *new_node;
    t_list *mapped_list;

    printf("\n=== Testing ft_lstnew ===\n");
    // Test ft_lstnew
    char *content1 = strdup("first");
    char *content2 = strdup("second");
    char *content3 = strdup("third");
    
    new_node = ft_lstnew(content1);
    printf("Created new node with content: %s\n", (char *)new_node->content);

    printf("\n=== Testing ft_lstadd_front ===\n");
    // Test ft_lstadd_front
    ft_lstadd_front(&list, new_node);
    new_node = ft_lstnew(content2);
    ft_lstadd_front(&list, new_node);
    print_list(list);

    printf("\n=== Testing ft_lstsize ===\n");
    // Test ft_lstsize
    printf("List size: %d\n", ft_lstsize(list));

    printf("\n=== Testing ft_lstlast ===\n");
    // Test ft_lstlast
    t_list *last = ft_lstlast(list);
    printf("Last node content: %s\n", (char *)last->content);

    printf("\n=== Testing ft_lstadd_back ===\n");
    // Test ft_lstadd_back
    new_node = ft_lstnew(content3);
    ft_lstadd_back(&list, new_node);
    print_list(list);

    printf("\n=== Testing ft_lstiter ===\n");
    // Test ft_lstiter
    printf("Before ft_lstiter:\n");
    print_list(list);
    ft_lstiter(list, to_upper);
    printf("After ft_lstiter (to uppercase):\n");
    print_list(list);

    printf("\n=== Testing ft_lstmap ===\n");
    // Test ft_lstmap
    mapped_list = ft_lstmap(list, map_func, del_content);
    printf("Mapped list:\n");
    print_list(mapped_list);

    printf("\n=== Testing ft_lstclear ===\n");
    // Test ft_lstclear
    ft_lstclear(&mapped_list, del_content);
    printf("Mapped list after clear (should be NULL): %p\n", (void *)mapped_list);

    printf("\n=== Testing ft_lstdelone ===\n");
    // Test ft_lstdelone with the first node
    t_list *temp = list->next;
    ft_lstdelone(list, del_content);
    list = temp;
    printf("List after deleting first node:\n");
    print_list(list);

    // Clean up remaining list
    ft_lstclear(&list, del_content);
    
    printf("\nAll tests completed!\n");
    return 0;
}
