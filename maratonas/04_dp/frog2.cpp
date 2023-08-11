#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;

vector<int>h;
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
void dp(){
    memset(memo, -1, sizeof (memo));
    memo[0]=0;
    for(int i=1; i<n; i++){
        memo[i] = INF;
        for(int j=max(0,i-k);j<i; j++){
            memo[i] = min(memo[i], memo[j]+abs(h[j]-h[i]));
        }
    }
    
}

int main(){
    cin >> n >> k;

    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        h.push_back(x);
    }

    
    dp();
    cout << memo[n-1] << endl;
    
}