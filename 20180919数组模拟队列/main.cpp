#include <iostream>

#define N 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int arr[N];
int start=0;
int end=0;
int size=0;


 
void push(int value){
	if(size==N){
		printf("The queue is full");
		return ;
	}
	size++;	
	arr[end]=value;
	end=end==N-1?0:end+1;
}
int pop(){
	if(size==0){
		printf("The queue is empty");
		return 0;
	}	
	size--;
	int tmp=start;
	start=start==N-1?0:start+1;//如果达到末尾位置 变为开始位置
	return arr[tmp]; 
	
}
void printQuene(){
	if (size==0){
		printf("The queue is empty\n");
	}
	
	int i=start;
	for(;i<end;i++){
		printf("%d\n",arr[i]);
	}
	
	
}
int main(int argc, char** argv) {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	
	printQuene();
	printf("========================================================\n");
	
	pop();
	pop();
	pop();
	pop();
	printQuene();
	return 0;
}
