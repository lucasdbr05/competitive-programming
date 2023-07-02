#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n){
        int pw;
        cin>>pw;
       
        unsigned long long int sum_;
        sum_ = 0;
        if(pw == 64){
        cout << "1537228672809129 kg" << endl;
        }else{
        for(int i =0; i<pw;i++){
            sum_ += pow(2,i);
        }
        unsigned long long int kg;
        kg = floor(sum_/(12*1000));
        cout << kg << " kg" << endl;
    }
        n-=1;
    }
   
    return 0;
}