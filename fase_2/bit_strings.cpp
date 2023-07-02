#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;


lli lim = 1000000007;

int power(int a,unsigned int b, lli lim){
    int ans=1;
    a= a % lim;
    while (b){
        ans=(a*ans)%lim;
        b --;

    }
    return ans;
}

int main(){
    int x;
    cin>> x;
    cout<< power(2, x, lim)<< endl;
}