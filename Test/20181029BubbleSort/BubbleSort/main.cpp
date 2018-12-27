#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<Algorithm>
using namespace std;

void bubbleSort(vector<int>&arr){
    for(int i=arr.size();i>0;i--){
        for(int j=1;j<i;j++){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}
print_vector(vector<int> arr){
    for(auto e:arr){
        cout<<e<<endl;
    }
}
vector<int> generate_rand_vector(){
    srand(time(0));
    int length=rand()%100;
    vector<int>arr(length);
    for(vector<int>::iterator it=arr.begin();it!=arr.end();it++){
        *it=rand()%1000;
    }
    return arr;
}


int main(){
    int a;
    //vector<int>arr={4,5,2,7,9,8,0,3,1,6};
    vector<int> arr1=generate_rand_vector();
    vector<int> arr2=arr1;
    print_vector(arr1);
    cout<<endl;
    sort(arr1.begin(),arr1.end());
    bubbleSort(arr2);
    print_vector(arr1);
    if(arr1==arr2){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cin>>a;

}
