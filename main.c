#include <stdio.h>
#include <string.h>

#define LALLOCS_IMPLEMENTATION
#include "lallocs.h"

int main(void)
{
    List ptrs = {0};
    char* str = lmalloc(&ptrs, sizeof(char) * 13);
    strncpy(str, "Hello World\n", 13);
    printf("%s\n", str);
    
    printf("ptrs->start: %p\n", ptrs.start);
    printf("ptrs->start->right: %p\n", ptrs.start->right);
    printf("ptrs->start->ptr: %p\n", ptrs.start->ptr);
    printf("str: %p\n", str);


   // // do some stuff ig
   // 
   // lfree(str);
   // if (check_list(ptrs) > 0) 
   // {
   //     fprintf(stderr, "Memory was not properly deallocated\n");
   //     exit(1);
   // }
    return 0;
}
