nclude<stdio.h>
#include <stdlib.h>

#define  MAX_SIZE 50

typedef struct Stack {
    int top;
    char *data;
}pStack;

void IntiStack(pStack *stack);
int push(pStack *stack,char e);
// char getStack(pStack *stack);
char pop(pStack *stack);

int main()
{
    pStack * ch_stack;
    IntiStack(ch_stack);
	    for(char  i='A';i<'Z';i++){
		        push(ch_stack,i);
				    }
		    while (ch_stack->top!=-1){
			        printf("%c \n",pop(ch_stack));
					    }
			    return 0;
}


void IntiStack(pStack *stack)
{
    stack->data=(char)malloc(sizeof(char)*MAX_SIZE);
	    if(!stack->data){ //如果申请的空间不存在则退出
		        exit(0);
			 }
		    stack->top=-1;
}

int push(pStack *stack,char e)
{
    if(stack->top == MAX_SIZE-1){
	        printf("Stack is full\n");
			        return 0;
					    }
	    stack->data[++(stack->top)] = e;
		
		    return  1;
}

char pop(pStack *stack)
{
    if(stack->top == -1){
	        printf("stack is empty!\n");
			        return 0;
					    }
	    char e =stack->data[stack->top];
		    (stack->top)--;
			    return  e;
}

	// char getStack(pStack *stack)
	// {
	// 	if(stack->top == -1){
	// 			printf("error!\n");
	// 					return 0;
	// 						}
	// 		return stack->data[stack->top];
	// }
