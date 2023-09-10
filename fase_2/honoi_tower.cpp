#include <bits/stdc++.h>
using namespace std;
const int MAX= 2e5+10;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
int num;

void hanoi(int s, int d, int a, int n){
    if (n<=0) return;

    hanoi(s,a,d, n-1);
    cout << s <<  " "<< d<< endl;
    hanoi(a,d,s,n-1);
}

int32_t main(){
    sws
    cin>> num;



    cout << (1<<num)-1<< endl;

    hanoi(1,3,2, num);


}