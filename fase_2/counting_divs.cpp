#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX = 1e6+100;
int crivo[MAX];
#define endl '\n'


int32_t main(){
    int n;cin >> n;

    for (int i=1; i<=MAX; i++){
        for (int j=i; j<=MAX; j+= i){
            crivo[j]++;
        }
    }
    

    while (n--){
        int m; cin >> m;
        cout << crivo[m]<< endl;
    }
    
}

