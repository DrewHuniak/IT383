#ifndef DSLIB_H
#define DSLIB_H

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int count;
    int *data;
    int max;

};
typedef struct stack stack_t;

void stack_init(stack_t *s, int capacity);
int stack_size(stack_t *s);
int stack_pop(stack_t *s);
void stack_push(stack_t *s, int e);
void stack_deallocate(stack_t *s);


#endif