#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
#define vvi vector<vector<int>>


vector<vector<int>> ans{
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1},
    };

vvi mul(vvi& A, vvi& B){
    int n = A.size(),m = B[0].size();
    vvi ret(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for (int k=0; k<A[0].size(); k++){
                ret[i][j]= (ret[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
    return ret;
}


vvi matrix_exp(vvi &a, int n){
    if(n==0)return a;

    vvi aux = matrix_exp(a, n>>1);
    aux = mul(aux, aux);

    if(n&1) ans = mul(ans, aux);
    return ans;
}


int32_t main(){
    sws;
    int n; cin >> n;
    vector<vector<int>> comb{
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
    };
    

    vector<int> p {1,2,4,8, 16, 32, 64};
    if(n<=6){
        cout << p[n-1];
    }else{
        n-=6;
        comb = matrix_exp(comb,n);

        int out = 0;

        for(int i=0; i<comb[0].size(); i++){
            out = (out + (comb[0][i]*p[6-i-1])%MOD)%MOD;
        }
        cout << out << endl;
    }
}