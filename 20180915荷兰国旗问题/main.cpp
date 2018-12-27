#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	
}
int partition(int arr[],int L,int R,int num){
	int less=L-1;
	int more=R+1;
	int cur=L;
	while(cur<more){
		if(arr[cur]< num){
			swap(arr,++less,cur++);
			
		}else if(arr[cur]>num){
			swap(arr,--more,cur);
		}else {
			cur++;
		}
	}
	return 1;
} 
void change(int arr[]){
	arr[0]=arr[1];
}
int main(int argc, char** argv) {
	
	int num=10;
	int arr[]={12,2,4,5,7,8,3,45,6,1,9,10,13,11,14,15,16,17,10};
	int length=sizeof(arr)/sizeof(arr[0]);
	partition(arr,0,length-1,num);
	//change(arr);
	printf("{");
	for(int i=0;i<length;i++){
		printf(" %d ",arr[i]);
	}
	printf("}");
	return 0;
}

