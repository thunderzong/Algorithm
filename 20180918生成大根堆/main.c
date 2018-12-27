#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//º¯ÊıÉùÃ÷ 
void swap(int arr[],int i,int j);
void heapInsert(int arr[],int index);

void heapSort(int arr[],int length){
	if(length<2){
		return ;
	}
	int i=0;
	for(i=0;i<length;i++){
		heapInsert(arr,i);
	}
}

void heapInsert(int arr[],int index){ 
	while(arr[index]>arr[(index-1)/2]){
		swap(arr,index,(index-1)/2);
		index=(index-1)/2;
	}
}
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void heapify(int arr[],int index,int heapSize){
	int left=index*2+1;
	while(left<heapSize){
		int largest=left+1<heapSize && arr[left+1]>arr[left] ? left+1 : left;
		largest=arr[largest]>arr[index]?largest:index;
		if(largest==index){
			break;
		}
		swap(arr,largest,index);
		index=largest;
		left=index*2+1;
	}
}
int main(int argc, char *argv[]) {
	int arr[]={6,5,7,8,9,0,3,4,2,1} ;
	int length=sizeof(arr)/arr[0];
	int i=0;
	printf("{");
	for (i=0;i<length;i++){
		printf(" %d ",arr[i]);
	}
	printf("}\n");
	heapSort(arr,length);
	printf("%d\n",length);
	
	printf("{");
	for (i=0;i<length;i++){
		printf(" %d ",arr[i]);
	}
	printf("}\n"); 
	
	return 0;  
}
