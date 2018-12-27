#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//function declaration 
int merge(int arr[],int Left,int mid,int Right);
void sortProcess(int arr[],int Left,int Right);

int smallSum(int arr[],int length){
	if(length<2){
		return 0;
	}
	return mergeSort(arr,0,length-1);
} 

int mergeSort(int arr[],int Left,int Right){
	if(Left==Right){
		return  0;
	} 
	int mid=Left+((Right-Left)>>1);
	return mergeSort(arr,Left,mid)+mergeSort(arr,mid+1,Right)+merge(arr,Left,mid,Right);
} 

//void sortProcess(int arr[],int Left,int Right){
//	if(Left==Right){
//		return ;
//	}
//	int mid=Left+((Right-Left)>>1);//L和R中点的位置(L+R)/2 
//	sortProcess(arr,Left,mid);
//	sortProcess(arr,mid+1,Right);
//	merge(arr,Left,mid,Right);
//	
//}


int merge(int arr[],int Left,int mid,int Right){
	int help[Right-Left+1];
	int length=Right-Left+1;
	int i=0;
	int p1=Left;
	int p2=mid+1; 
	int res=0;
	while(p1<=mid && p2<=Right){
		res+=arr[p1]<arr[p2]?(Right-p2+1)*arr[p1]:0;
		help[i++]=arr[p1]<arr[p2] ? arr[p1++]	:	arr[p2++];
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
	return res;
}


int main(int argc, char *argv[]) {
	
	int arr[] ={1,3,4,2,5,234,34,5,56,5467,5,757,673,7,3,41254,5646,546,345,2234,2,543,52,3,43,324,32,344,3543,2312,413,2,6546,7867,9,6564,3,123,567,65};
	int length=sizeof(arr)/sizeof(arr[0]);
	printf("数组长度为：%d\n",length);
	int res=smallSum(arr,length);
	printf("和为：%d",res);
	return 0;

}
