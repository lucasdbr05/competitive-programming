#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long int
#define ii pair<int, int>
const int MOD = 1e9+7;
const int MAX= 1e6+10;
int fat[MAX+3], inv[MAX+3];
int n;

int fexp(int b, int e){
    if(e==0) return 1;
    int aux = fexp(b, e/2)%MOD;
    if(e%2)return (((aux*aux)%MOD)*b)%MOD;
    return (aux*aux)%MOD;
}


int32_t main(){

    fat[0]=1;inv[0]=1;
    for(int i=1; i<=MAX; i++) fat[i]= (i*fat[i-1])%MOD;
    inv[MAX]= fexp(fat[MAX], MOD-2);
    for(int i=MAX-1; i>=1; i--) inv[i]= (inv[i+1]*i)%MOD;
    
    // cout <<inv[MAX]<< endl;
    for (int i=MAX; i>=1; i--) inv[i-1]= (i*inv[i])%MOD;
    cin >> n;
    int ans =0, aux=0;
    for (int i=2; i<=n; i++){
        // cout << fat[n]<< " "<< inv[n-i]<<" "<< inv[i]<< endl; 
        if(i%2==0)aux = (aux+inv[i])%MOD;
        else aux = (aux-inv[i]+MOD)%MOD;
        // cout << aux << endl;
        // ans = (ans+aux+MOD)%MOD;
    }
    ans  = (aux*fat[n])%MOD;

    cout << ans << endl;
}