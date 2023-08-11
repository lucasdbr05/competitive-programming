#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int li = 101;
const int MAX= 1e6+10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int N, W;
vector<int> w, v;
ll memo[110][1000100];


ll dp(int i, int c){
    if (c<0) return -LINF;
    if (i==N) return 0;
    
    if (memo[i][c] != -1) return memo[i][c];

    return memo[i][c] = max(dp(i+1, c),dp(i+1, c-w[i])+v[i]);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> W;
    w.resize(N);v.resize(N);
    for (int i=0; i<N;i++){
        cin >> w[i] >> v[i];
    }

    memset(memo, -1, sizeof(memo));
    
    cout << dp(0, W) << endl;
     
}