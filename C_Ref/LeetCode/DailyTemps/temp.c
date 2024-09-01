#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000

typedef struct
{
    int elements[100000];
    int n;
} stack_t;


int pop(stack_t* s)
{
    if(s->n == 0)
    {
        printf("BADD\n");
        return -1;
    }

    (s->n)--;
    int ret = s->elements[s->n];
    printf("Pop %d\n", ret);
    return ret;
}

void push(stack_t* s, int x)
{
    if(s->n == STACK_SIZE)
    {
        return;
    }
    printf("Push %d\n", x);

    s->elements[s->n] = x;
    ++(s->n);
}

int peak(stack_t* s)
{
    if(s->n == 0)
    {
        return -1;
    }

    return s->elements[s->n -1];
}


int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int* ret = calloc(temperaturesSize , sizeof(int));
    *returnSize = temperaturesSize;
    
    stack_t* s = malloc(sizeof(stack_t));
    int N = temperaturesSize;
    int* temp = temperatures;
    int index = 0;
    
    while(1)
    {
        printf("Index = %d\n", index);
        // If stack empty need to push something and move on
        // If next point is less than the previous point, push to stack and move on
        if((s->n == 0) || (temp[index] <= temp[index-1]))
        {
            push(s, index);
            ++index;
            if(index == N)
            {
                return ret;
            }
            printf("\n");
            continue;
        }

        // Reached a point where the value at top of the stack has a warmer
        // day i.e. today, pop it if its greater then the value at the top
        // of the stack
        if(temp[index] > temp[peak(s)])
        {
            int prev = pop(s);
            ret[prev] = index - prev;   
        }
        else
        {
            push(s, index);
            ++index;
            if(index == N)
            {
                return ret;
            }
        }
        printf("\n");
    }
}

int main()
{
    int size = 8;
    int in[] = {73,74,75,71,69,72,76,73};
    int ret;
    int* soln = dailyTemperatures(in, 8, &ret);

    int i;
    for(i = 0; i < ret; ++i)
    {
        printf("%d\n", soln[i]);
    }
}