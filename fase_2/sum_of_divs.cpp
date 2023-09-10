#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX = 1e6+10;
const int MOD = 1e9+7;
int v[3][MAX];


int32_t main(){
    sws
    int n; cin >> n;

    
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n;j+=i){
            v[j/MAX][j%MAX]= (i+v[j/MAX][j%MAX]+ v[i/MAX][i%MAX])%MOD;
        }
    }

    cout << v[n/MAX][n%MAX]<< endl;
}