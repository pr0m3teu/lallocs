#include <stdio.h>
#include <string.h>

#define LALLOCS_IMPLEMENTATION
#include "lallocs.h"

int main(void)
{
    const List ptrs = {0};
    const char* str = lmalloc(&ptrs, sizeof(char) * 13);
    const char* name = lmalloc(&ptrs, sizeof(char) * 10);

    strncpy(name, "Andrei\n", 10);
    strncpy(str, "Hello ", 13);

    for (size_t i = 0; i < 100000; i++)
    {
        const char* loop_message = lmalloc(&ptrs, 200);
        strncpy(loop_message, "HEEEEELLLLLOOO WOOOOORLD!!!\n", 200);
        printf("%s", loop_message);
    }
    
    printf("ptrs.size: %lu\n", ptrs.size);
    
    printf("%s", str);
    printf("%s", name);
    
    lfree_all(&ptrs);

   // lfree(&ptrs, name);
   // lfree(&ptrs, str);
    printf("ptrs.size: %lu\n", ptrs.size);

    if (check_list(ptrs) > 0) 
    {
        fprintf(stderr, "Memory was not properly deallocated\n");
        exit(1);
    }
    return 0;
}
