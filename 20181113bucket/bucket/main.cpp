#include <iostream>

using namespace std;

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int bucket(int value,int length,int max,int min){
    int r;
    return r=(value-min)/((max-min)/((length+1)+1));
}
void print_array(int arr[],int length){
    for(int i=0;i<length;i++){
        cout<<i<<":"<<arr[i]<<"\t";
    }
    cout<<endl;
}
void print_bool_array(bool arr[],int length){
    for(int i=0;i<length;i++){
        cout<<i<<":"<<arr[i]<<"\t";
    }
    cout<<endl;
}
void bubble(int arr[],int length){
    for(int i=length-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}
int maxGap(int arr[],int length){
    if(length<2){
        return 0;
    }
    int len=length;
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<length;i++){
        min=arr[i]<min ? arr[i]:min;
        max=arr[i]>max ? arr[i]:max;
    }
    if(min==max){
        return 0;//表示数组中只有一种数
    }
    bool hasNum[len+1];
    for(int i=0;i<len+1;i++){
        hasNum[i]=false;
    }
    int maxs[len+1];
    int mins[len+1];
    for(int i=0;i<len+1;i++){
        mins[i]=maxs[i]=0;
    }

    int bid=0;
    for(int i=0;i<length;i++){
        bid=bucket(arr[i],len,max,min);
        cout<<"bid:"<<bid<<endl;
        mins[bid]=hasNum[bid]?(mins[bid]<arr[i]?mins[bid]:arr[i]):arr[i];
        maxs[bid]=hasNum[bid]?(maxs[bid]<arr[i]?arr[i]:maxs[bid]):arr[i];
        hasNum[bid]=true;
    }
    cout<<"mins:"<<endl;
    print_array(mins,len+1);
    cout<<"maxs"<<endl;
    print_array(maxs,len+1);
    cout<<"hasNum"<<endl;
    //print_bool_array(hasNum,len+1);
    for(int i=0;i<length;i++){
        cout<<i<<":"<<hasNum[i]<<"\t"<<endl;
    }
    cout<<endl;
    int value=0;
    int lastMax=maxs[0];
    for(int i=1;i<len+1;i++){
        if(hasNum[i]){
            value=((mins[i]-lastMax)>value)?(mins[i]-lastMax):value;
            lastMax=maxs[i];
        }
    }
    cout<<"value :"<<value<<endl;
    cout<<min<<"\t"<<max<<endl;
}

int main()
{
    int arr[]={4,3,1,5,6,7,8,44,42,41,44,56,77,88,99,100};
    int length=sizeof(arr)/sizeof(int);
    maxGap(arr,length);
    //int bu=bucket(25,8,99,10);
    //int bu1=bucket(30,8,99,10);
    //cout<<bu<<endl;
    //cout<<bu1<<endl;
    bubble(arr,length);
    print_array(arr,length);
    cout << "Hello world!" << endl;
    return 0;
}
