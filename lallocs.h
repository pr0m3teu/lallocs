#ifndef LALLOCS_H_
#define LALLOCS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    Node* prev;
    Node* next;
    void* ptr;
};

typedef struct {
    Node* start;
    size_t items;
} List;

void* lmalloc(List* ptrs, uint64_t size);

#ifdef LALLOCS_IMPLEMENTATION
static void check_ptr(void* ptr)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "ERROR: Could not allocate any more memory\n");
        exit(1);
    }
}

void* lmalloc(List* ptrs, uint64_t size)
{
    if (ptrs == NULL)
    {
       fprintf(stderr, "ERROR: List param cannot be NULL\n");
       exit(1);
    }

    if (ptrs->start == NULL)
    {
        // This ptrs->start should also be deallocated at some point
        ptrs->start = malloc(sizeof(Node));
        check_ptr(ptrs->start);

        ptrs->start->next = NULL;
        ptrs->start->prev = NULL;

        void* ptr = malloc(size);
        check_ptr(ptr);

        ptrs->start->ptr = ptr;
        return ptr;
    }

    void* ptr = malloc(size);
    check_ptr(ptr);
    Node* p = ptrs->start;

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = malloc(sizeof(Node));
    check_ptr(ptr);

    p->next->prev = p;
    p->next->next= NULL;
    p->next->ptr = ptr;

    return ptr;
}



#endif // LALLOCS_IMPLEMENTATION
#endif // LALLOCS_H_
