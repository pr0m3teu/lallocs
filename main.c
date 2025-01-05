#include <stdio.h>
#include <string.h>

#define LALLOCS_IMPLEMENTATION
#include "lallocs.h"

int main(void)
{
    List ptrs = {0};
    char* str = lmalloc(&ptrs, sizeof(char) * 13);
    char* name = lmalloc(&ptrs, sizeof(char) * 10);

    strncpy(name, "Andrei\n", 10);
    strncpy(str, "Hello ", 13);
    printf("ptrs.size: %lu\n", ptrs.size);
    printf("%s", str);
    printf("%s", name);
    lfree(&ptrs, str);   
    lfree(&ptrs, name);
    printf("ptrs.size: %lu\n", ptrs.size);

    if (check_list(ptrs) > 0) 
    {
        fprintf(stderr, "Memory was not properly deallocated\n");
        exit(1);
    }
    return 0;
}
