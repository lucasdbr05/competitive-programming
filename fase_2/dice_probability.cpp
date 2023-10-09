#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n, a, b;
int combs[1000][110];


int fexp(int b, int e){
    if (e==0) return 1;

    int ret = fexp(b, e/2);
    if(ret%2) return (ret*ret)*b;
    else return ret*ret;
}

int32_t main(){
    cin >> n >> a >> b;
    memset(combs, 0, sizeof combs);

    for (int i=0; i<6; i++){
        combs[0][i]=1;
    }

    for (int i=1; i<n; i++){
        for (int j=i; j<=6*n; j++){
            for (int k=1; k<=6; k++){
                if (j-k>=0) combs[i][j]+= combs[i-1][j-k];
            }
        }
    }
    int aux=0;
    for (int i=a-1; i<b; i++) aux+= combs[n-1][i];
    // cout << aux << endl;

    double ans = (double)aux/(double)fexp(6, n);
    cout << setprecision(6) << ans << endl;
    
    
}