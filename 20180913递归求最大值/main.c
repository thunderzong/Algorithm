#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Recurve(int arr[],int Left,int Right){
	
	if (Left==Right){
		return arr[Left];
	}
	int mid=(Left+Right)/2;
	int maxLeft=Recurve(arr,Left,mid);
	int maxRight=Recurve(arr,mid+1,Right);
	return compare(maxLeft,maxRight);
	
}

int compare(int num1,int num2){
	return num1		>	num2	?	num1	:	num2; 
}
int main(int argc, char *argv[]) {
	int arr[]={2,1,6,5,8,3,4,12,13,141,1536,56,7,568,678,
				68,795,5435,2,423,5454,6,5,756,7,5,867,856,
				43,4,23,5,567,46352,4,56,432,35,6435236,3523,
				2335,43,245,32,5,324,54,2};
	int i=0;
	printf("%d\n",sizeof(i));
	//getLength(arr);
	int *p=&arr[7];
	
	printf("%d\n",sizeof(*p)); 
	
	int length=sizeof(arr)/sizeof(arr[0]);
	
	printf("数组的长度为：%d\n",length);
	
	for(i=0;i<length;i++){
		printf("第%d元素为：%d\n",i,arr[i]); 
	}
	
	printf("最大值为：%d",Recurve(arr,0,length-1));
	return 0;

}
