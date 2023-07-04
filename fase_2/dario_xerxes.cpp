#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    int D = 0; int X = 0;
    cin>>t;
    while(t--){
        ios::sync_with_stdio(false);
        int d=0, x=0;
        cin >> d >> x; 
        if (x==(d+1)%5 or x==(d+2)%5){
            D++;
        }else{
            X++;
        }
    }

    if (X>D) cout << "xerxes"<<"\n";
    else cout << "dario"<<"\n";
}