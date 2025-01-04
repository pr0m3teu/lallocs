#ifndef LALLOCS_H_
#define LALLOCS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    Node* left;
    Node* right;
    void* ptr;
};

typedef struct {
    Node* start;
    size_t items;
} List;

void* lmalloc(List* ptrs, uint64_t size);

#ifdef LALLOCS_IMPLEMENTATION

void* lmalloc(List* ptrs, uint64_t size)
{
    if (ptrs == NULL)
    {
       fprintf(stderr, "ERROR: List param cannot be NULL\n");
       exit(1);
    }
    void* ptr = malloc(size);
    Node* p = List->start;

    while(p->right != NULL)
    {
        p = p->right;
    }
    p->right = malloc(sizeof(Node));

    p->right->left = p;
    p->right->right = NULL;
    p->right->ptr = ptr;

    return ptr;
}

#endif // LALLOCS_IMPLEMENTATION
#endif // LALLOCS_H_
