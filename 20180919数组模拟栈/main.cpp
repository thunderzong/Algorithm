#include <iostream>
#define N 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int arr[N];
int index=0;
void push(int obj){
	if(index==N){
		printf("Õ»Âú");
	}
	arr[index++]=obj;
}

int  pop(){
	if(index==0){
		printf("Õ»¿Õ");
		return 0; 
	}
	return arr[--index];
}
int printStack(){
	//printf("indexµÄÖµÎª%d\n",index);
	int i=index-1;
	for(i;i>=0;i--){
		printf(" %d \n",arr[i]);
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
	push(11);
	push(12);
	printStack();
	
	printf("====================================================\n");
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 
	pop(); 

	printStack();
	return 0;
}
