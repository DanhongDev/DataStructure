#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

static int hash(int key, int size)
{
    return key % size;
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;
    n->next = next;
}

int Initialize(ChainHash* h, int size) 
{
    // h->size = size;
    // h->table = calloc(size, sizeof(int));

    int i;
    if((h->table = calloc(size, sizeof(Node*))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for(i=0; i<size; i++)
    {
        h->table[i] = NULL;
    }

    return 1;
}