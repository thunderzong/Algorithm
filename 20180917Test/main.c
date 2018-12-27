//#include <iostream>
//#include<vector>
//#include<cstdlib>
//#include<ctime>
//#include<Algorithm>
//using namespace std;
//
//void bubbleSort(vector<int> &vec){
//    for(int i=vec.size();i>0;i--){
//        for(int j=1;j<i;j++){
//            if(vec[j-1]>vec[j]){
//                swap(vec[j],vec[j-1]);
//            }
//        }
//    }
//}
//void selectionSort(vector<int> *vec){
//    int temp=0;
//    for(int i=vec.size()-1;i>0;i--){
//        for(int j=0;j<i;j++){
//            if(vec[j+1]>vec[j]){
//                temp=j+1;
//            }
//        }
//        swap(vec[temp],vec[i]);
//
//    }
//
//}
//void print_vector(vector<int> vec){
//    for(auto e:vec){
//        cout<<e<<endl;
//    }
//}
//vector<int> generateRandVector(){
//    srand(time(0));
//    int length=rand()%100;
//    vector<int>vec(length);
//    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
//        *it=rand()%1000;
//    }
//    return vec;
//}
//bool compare(int a,int b){
//    return a<b ? true : false;
//}
//int main()
//{
//    vector<int>bubbleArr1=generateRandVector();
//    vector<int>sortArr2=bubbleArr1;
//    vector<int>selectionArray=generateRandVector();;
//
//    bubbleSort(bubbleArr1);
//    sort(sortArr2.begin(),sortArr2.end());
//    selectionArray(&selectionArray);
//
//    if(bubbleArr1==sortArr2){
//        cout<<"True"<<endl;
//    }else{
//        cout<<"Error"<<endl;
//    }
//    cout<<"*****STL??D¨°******"<<endl;
//    print_vector(sortArr2);
//    cout<<"*****?¡ã?Y??D¨°****"<<endl;
//    print_vector(bubbleArr1);
//    cout<<"*****??????D¨°****"<<endl;
//    print_vector(selectionArray);
//    cout << "Hello world!" << endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#define N 10
//void createArray(){
//	static int arr[N]; 
//
//} 
//int main() {
//	createArray();
//	for(int i=0;i<N;i++){
//		cout<<arr[i]<<endl;
//	}	
//	int num[10];
//	for(int i=0;i<10;i++){
//		cout<<num[i]<<endl;
//	}
//	return 1;
//}


#include <iostream>
#include <string>
using namespace std;

class Ship
{
        string shipName;
        string shipYear;
    public:
        Ship(string n = "KHAN ", string y = "2000")
        {
            shipName = n;
            shipYear = y;
        }
        void setShipName(string n) { shipName = n; }
        void setShipYear(string y) { shipYear = y; }
        string getShipName() const { return shipName; }
        string getShipYear() const { return shipYear; }
        virtual void print() const {cout << this->getShipName() << this->getShipYear();}
};

class Cruiseship : public Ship
{
        int numPass;
    public:
        Cruiseship(int numPass) : Ship("software engineer ", "2018")
        { this->numPass = numPass; }
        void setNumPass(int num) { numPass = num; }
        int getNumPass() const { return numPass; }
        void print() const
        { cout << this->getShipName() << this->getNumPass(); }
};

class CargoShip : public Ship
{
        int cargoCapacity;
    public:
        CargoShip(int cargoCapacity) : Ship("JILIN ", "2018")
        { this->cargoCapacity = cargoCapacity; }
        void setCargoCapacity(int cc) { cargoCapacity = cc; }
        int getCargoCapacity() const { return cargoCapacity; }
        void print() const
        { cout << this->getShipName() << this->getCargoCapacity(); }
};

int main()
{
    const int NUM_SHIPS = 3;

    Ship *ships[NUM_SHIPS] =
        {
            new Ship,
            new Cruiseship(2000),
            new CargoShip(900)
        };
for (int i=0; i<3; i++)
{ 
    ships[i]->print();
    cout<<endl;
}    
for (int i=0; i<3; i++)
    delete ships[i];
}
