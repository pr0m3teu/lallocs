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
    size_t size;
} List;

void* lmalloc(List* ptrs, uint64_t size);
void lfree(List* ptrs, void* ptr);
int check_list(List ptrs);

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
        ptrs->size = 1;

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
    check_ptr(p->next);

    ptrs->size++;
    p->next->prev = p;
    p->next->next= NULL;
    p->next->ptr = ptr;

    return ptr;
}

void lfree(List* ptrs, void* ptr)
{
    Node* p = ptrs->start;
    ptrs->size--;
    if(p->ptr == ptr)
    {
        free(p->ptr);
        p->ptr = NULL;

        p = ptrs->start->next;
        ptrs->start->next = NULL;
        ptrs->start->ptr = NULL;
        free(ptrs->start);
        ptrs->start = p;
        return;
    }

    while(p != NULL)
    {    
        Node* p_next = p->next;
        if (p->ptr == ptr)
        {
            if (p->prev != NULL) p->prev->next = p->next;
            if (p->next != NULL) p->next->prev = p->prev;

            free(p->ptr);
            p->ptr = NULL;
            p->prev = NULL;
            p->next = NULL;
            free(p);
        }
        p = p_next;
    }
        
}

int check_list(List ptrs)
{
    return ptrs.size;
}

#endif // LALLOCS_IMPLEMENTATION
#endif // LALLOCS_H_
