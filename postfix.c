#include<stdlib.h>
#include<string.h>

struct ArrayStack{														/*Creating an structure to give value define the given stack*/
	int top;
	int capacity;
	char *array;
};
struct ArrayStack * CreateStack(int n)									/*Creating an pointer of structure type to address the structure pointing towards stack*/
{
	struct ArrayStack *stack;
	stack = malloc(sizeof(struct ArrayStack));
	stack->top=-1;
	stack->capacity=n;
	stack->array=malloc(sizeof(char)*stack->capacity);/*Creating a dynamic array pointed by array pointer in structure*/
	return(stack);
}
int ifFill(struct ArrayStack *stack)	/*Checking if the given stack is full or not*/
{
	struct ArrayStack *temp;
	temp = stack;
	if(temp->top==temp->capacity-1)
	{
		return(1);
	}
	else
	return(0);
}
int ifEmpty(struct ArrayStack *stack) /*Checking if the given stack is empty or not*/
{
	struct ArrayStack * temp;
	temp = stack;
	if(temp->top==-1)
	{
		printf("The Stack is Empty");
		return(1);
	}
	else
	return(0);
}
void Push(struct ArrayStack *stack, char ch) /*Adding values if space avialable*/
{
	if(!ifFill(stack))
	{
		stack->top++;
		stack->array[stack->top]=ch;
	}
	else
	printf("The stack is full");
}
char Pop(struct ArrayStack *stack) /*Poping out the value if present*/
{
	char ch;
	if(!ifEmpty(stack))
	{
		ch=stack->array[stack->top];
		stack->top--;
		return(ch);
	}
}
int main()
{
	printf("Welcome to World of Post Increment\n\nHello Guys!!!\nFirst it is Important for us to know what is post-incremet, right?\nSo Let me Give you an example\nWe Have term A+((B+C)+(D+E)*F)/G\nThe Post increment form of this is :\nABC+DE+F*+G/+\nTake it term by term\nSo are you ready(Please cover the whole equations with brackets)?\n\n");
	
	static int j=0;
	char abc[21];
	int i;
	char c, chh;
	struct ArrayStack * stack;  /*Making a dynamic structure*/
	char ch[100];
	printf("Please Enter the Equation and also cover it with brackets\n"); /*getting value from users to perform operations*/
	scanf("%s",ch);
	int a = strlen(ch);
	stack = CreateStack(a);
	Push(stack,ch[0]);            /*Checking the required condition and pushing and popping value according to it*/
	
	for(i=1;i<a;i++)
	{
		if((ch[i]<=90&&ch[i]>=65)||(ch[i]>=97&&ch[i]<=122)||(ch[i]>=48&&ch[i]<=57))
		{
			abc[j]=ch[i];
			
			j++;
		}
		else if(ch[i]==40)
		Push(stack,ch[i]);
		else if(ch[i]==42)
		Push(stack,ch[i]);
		else if(ch[i]==43)
		{
		while(((ch[i]==43&&stack->array[stack->top]==42)||(ch[i]==43&&stack->array[stack->top]==47)))
		{
		abc[j]=Pop(stack);
		j++;
		}
		Push(stack,ch[i]);
		}
		else if(ch[i]==45)
		{
		while((ch[i]==45&&stack->array[stack->top]==42)||(ch[i]==45&&stack->array[stack->top]==43)||(ch[i]==45&&stack->array[stack->top]==47)||(ch[i]==45&&stack->array[stack->top]==45))
		{
		abc[j]=Pop(stack);
		j++;
		}
		Push(stack,ch[i]);
		}
		else if(ch[i]==47)
		{
		while((ch[i]==47&&stack->array[stack->top]==42))
		{
		abc[j]=Pop(stack);
		j++;
		}
		Push(stack,ch[i]);
		}
		
		else if(ch[i]==41)
		{
			chh=Pop(stack);
			while(chh!=40)
			{
				abc[j]=chh;
				chh=Pop(stack);
				j++;
			}
			
		}
	}
	printf("%s",abc);
	printf("\nAnd Here is Your answer!!!!\n\nHope you Enjoy");
	
	
}
