#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration 
void merge(int arr[],int Left,int mid,int Right);
void sortProcess(int arr[],int Left,int Right);



void mergeSort(int arr[],int length){
	if(length<2){ 
		return ;
	}
	sortProcess(arr,0,length-1); 
} 
void sortProcess(int arr[],int Left,int Right){
	if(Left==Right){
		return ;
	}
	int mid=Left+((Right-Left)>>1);//L��R�е��λ��(L+R)/2 
	sortProcess(arr,Left,mid);
	sortProcess(arr,mid+1,Right);
	merge(arr,Left,mid,Right);
	
}

void merge(int arr[],int Left,int mid,int Right){
	int help[Right-Left+1];
	int length=Right-Left+1;
	int i=0;
	int p1=Left;
	int p2=mid+1; 
	while(p1<=mid && p2<=Right){
		help[i++]=arr[p1]<arr[p2] ? arr[p1++]:arr[p2++];
	}
	while(p1<=mid){
		help[i++]=arr[p1++];
	}
	while(p2<=Right){
		help[i++]=arr[p2++];
	}
	for(i=0;i<length;i++){
		arr[Left+i]=help[i];
	}
}


int main(int argc, char *argv[]) {
	
	int arr[]={9,3,6,8,4,5,1,2,7,7,6,9,91,67,56,34,23,41,87,94,26,69};
	int length=sizeof(arr)/sizeof(arr[0]);
	int i=0;
	printf("%d\n",length);
	printf("{");
	for(i=0;i<length;i++){
		printf(" %d ",arr[i]);
	}
	printf("}\n");
	mergeSort(arr,length);
	printf("{");
	for(i=0;i<length;i++){
		printf(" %d ",arr[i]);
	}
	printf("}");
	return 0;
}
