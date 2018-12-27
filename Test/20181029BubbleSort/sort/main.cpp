#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Algorithm>
using namespace std;

void bubbleSort(vector<int>&vec){
    for(int i=vec.size();i>0;i--){
        for(int j=1;j<i;j++){
            if(vec[j-1]>vec[j]){
                swap(vec[j],vec[j-1]);
            }
        }
    }
}
void selectionSort(vector<int>&vec){

    for(int i=vec.size()-1;i>0;i--){
        int temp=i;
        for(int j=0;j<i;j++){
            if(vec[j]>vec[temp]){
                temp=j;
            }
        }
        if(temp!=i)
            swap(vec[temp],vec[i]);
    }
}
void insertSort(vector<int> &vec){
    for(int i=1;i<vec.size();i++){
        for(int j=i;j>0 && vec[j]<vec[j-1];j--){
                swap(vec[j],vec[j-1]);
        }
    }
}

void print_vector(vector<int> vec){
    for(auto e:vec){
        cout<<e<<"\t";
    }
    cout<<endl;
}
vector<int> generateRandVector(){
    srand(time(0));
    int length=rand()%100000;
    vector<int>vec(length);
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        *it=rand()%100000;
    }
    return vec;
}
bool compare(int a,int b){
    return a<b ? true : false;
}
int main()
{
    vector<int>vec=generateRandVector();
    vector<int> bubbleArr1=vec;
    vector<int> sortArr2=vec;
    vector<int>selectionArray=vec;
    vector<int>insertArr=vec;

    bubbleSort(bubbleArr1);
    sort(sortArr2.begin(),sortArr2.end());
    selectionSort(selectionArray);
    insertSort(insertArr);

    if(bubbleArr1==sortArr2&&sortArr2==selectionArray && sortArr2==insertArr){
        cout<<"True"<<endl;
    }else{
        cout<<"Error"<<endl;
    }
    cout<<"*****STL******"<<endl;
    print_vector(vec);
    cout<<"*****STL******"<<endl;
    print_vector(sortArr2);
    cout<<"*****bubble****"<<endl;
    print_vector(bubbleArr1);
    cout<<"*****selection****"<<endl;
    print_vector(selectionArray);
    cout<<"*****insert**************"<<endl;
    print_vector(insertArr);
    cout << "Hello world!" << endl;
    return 0;
}
