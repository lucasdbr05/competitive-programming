#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;

int h[MAX];
int memo[MAX];
int n, k;

//      -->>Top-down
// int dp(int i){
//     if (i==0) return 0;
//     if (memo[i]!=-1) return memo[i];

//     int ret = INF;
//     for (int j=max(0, i-k); j<i; j++){
//         ret= min(ret, dp(j)+abs(h[j]-h[i]));
//     }

//     memo[i]=ret;
//     return ret;
// }


//      -->>Bottom-up
// int dp(){
   
// }

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >>h[i];
    }    
    
    memo[1]=0;
    for (int i=2; i<=n; i++){

        if (i-2>0)memo[i]= min(memo[i-1]+abs(h[i]-h[i-1]), memo[i-2]+abs(h[i]-h[i-2]));
        else memo[i]=memo[i-1]+abs(h[i]-h[i-1]);

    }

    cout << memo[n]<< endl;
}