
#include "dslib.h"

void stack_init(stack_t *s, int capacity)
{
    s->count = 0;
    s->max = capacity;
    s->data = (int*)malloc(sizeof(int) * capacity);
}

int stack_size(stack_t *s)
{
    return s->count;
}

int stack_pop(stack_t *s)
{
    if(s->count == 0)
    {
        return -9999;
    }

    s->count--;
    int current = s->data[s->count];
    s->data[s->count] = 0;
    return current;
}

void stack_push(stack_t *s, int e)
{
    if(s->count == s->max)
    {
        return;
    }

    
    s->data[s->count] = e;
    s->count++;
}

void stack_deallocate(stack_t *s)
{
    free(s->data);
}