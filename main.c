#include <stdio.h>
#define LALLOCS_IMPLEMENTATION
#include "lallocs.h"

int main(void)
{
    List ptrs = {0};
    char* str = lmalloc(&ptrs, sizeof(char) * 10);
   // // do some stuff ig
   // 
   // lfree(str);
   // if (check_list(ptrs) > 0) 
   // {
   //     fprintf(stderr, "Memory was not properly deallocated\n");
   //     exit(1);
   // }
    printf("Hello World\n");
    return 0;
}
