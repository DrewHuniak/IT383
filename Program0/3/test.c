#include "dslib.h"

void pass(int a, int b)
{
    if(a!=b)
    {
        printf("Expected %d, Recieved %d\n", a, b);
        exit(1);
    }
}

int main()
{
    stack_t s;

    //Test that stack was initalized correctly
    stack_init(&s, 10);
    pass(10, s.max);
    
    //Test for empty stack
    pass(-9999, stack_pop(&s));

    //Put 1-10 on the stack
    for(int i = 1; i <= 10; i++)
    {
        stack_push(&s, i);
    }
    
    //Test that the stack does not go over capacity
    stack_push(&s, 11);

    //Check that the stack returns 10 and not 11
    pass(10, stack_pop(&s));
    
    //Check that the stack has correct values and is removing values
    pass(9, stack_pop(&s));

    pass(8, stack_pop(&s));

    stack_deallocate(&s);
    
    
    printf("All tests passed\n");

    return 0;
}