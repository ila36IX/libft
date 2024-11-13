#include "libft.h"
#include <string.h>
#include <stdio.h>


int main()
{

        // int     tab[4];
        //
        // ft_memset(tab, -1, 4*sizeof(int));
        // for(int i = 0; i < 4; i++)
        //         printf("%d ", tab[i]);// int me = 0;
        int me = 0,r = 0;
        char str1[] = "TEST";
        char str2[] = "TEST";

        r = strlcat("aliem", "", 4);
        me = ft_strlcat(NULL, "simo", 0);
        printf("me: %d\n", me);
        printf("Original: %d\n", r);
}
