#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(0);



int main(){_ 
    int n; cin >> n;
    vector<int> fat(11);
    fat[0]=1;
    for (int i = 1; i<=10; i++) fat[i]= i*fat[i-1];
    int ans = 0;
    for (int i=10; i>0; i--){
        int at = n/fat[i];
        ans += at;
        n -= at*fat[i];
    }
    cout <<ans<< endl;
}