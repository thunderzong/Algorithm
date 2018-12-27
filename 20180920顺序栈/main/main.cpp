#include <iostream>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;
typedef int ElementType;

typedef struct{
    ElementType data[MAXSIZE];
    int top=-1;
}Stack;

Status Push(Stack *S1,Stack *S2,ElementType e){
    if(S1->top==MAXSIZE){
        return ERROR;
    }
    S1->top++;
    S1->data[S1->top]=e;
    //printf("%d\n",S1->data[S1->top]);
    if(S2->top==-1){
        S2->top++;

        S2->data[S2->top]=S1->data[S1->top];

        //printf("%d\n",S2->data[S2->top]);
        return OK;
    }
    if(S2->data[S2->top]>e){
        S2->top++;
        S2->data[S2->top]=e;
    }else{
        S2->top++;
        S2->data[S2->top]=S2->data[S2->top-1];
    }

    return OK;
}
Status Pop(Stack *S1,Stack *S2,ElementType e){
    if(S1->top==-1){
        return ERROR;
    }
    e=S1->data[S1->top];
    S1->top--;
    S2->top--;
    return OK;
}
int  getMin(Stack *s){
    printf(" %d\n ",s->data[s->top]);
    return s->data[s->top];
}
printStack(Stack *S1,Stack *S2){
    for(int i=0;i<=S1->top;i++){
        printf(" %d ",S1->data[i]);
        printf(" %d \n",S2->data[i]);
    }

}
int main()
{

    Stack s1,s2;
    Push(&s1,&s2,12);
    Push(&s1,&s2,13);
    Push(&s1,&s2,10);
    Push(&s1,&s2,9);
    Push(&s1,&s2,8);
    Push(&s1,&s2,7);
    Push(&s1,&s2,6);
    Push(&s1,&s2,5);
    Push(&s1,&s2,4);
    Push(&s1,&s2,3);
    Push(&s1,&s2,2);
    Push(&s1,&s2,1);
    //printf("%d\n",s1.data[s1.top]);
    printStack(&s1,&s2);

    printf("======================================================================\n");
    Pop(&s1,&s2,1);
    printStack(&s1,&s2);





    return 0;
}
