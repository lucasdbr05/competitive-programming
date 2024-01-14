#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vii vector<vi> 
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;



struct Matrix {
    vii m;
 
    int r, c;
 
    Matrix(vii mat) {
        m = mat;
        r = mat.size();
        c = m[0].size();
    }
 
    Matrix(int row, int col, bool ident=false) {
        r = row; c = col;
        m = vii(r, vector<int>(c, 0));
        if(ident) {
            for(int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }
 
    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); 
        vii res(r, vector<int>(o.c, 0));
 
        for(int i =0; i < r; i++) {
            for(int k = 0; k < c; k++) {
                for(int j = 0; j < o.c; j++) {
                    res[i][j] = (res[i][j] + m[i][k]*o.m[k][j]) % MOD;
                }
            }
        }
 
        return Matrix(res);
    }
};


Matrix m_fexp(Matrix M, int e, int n){
    if(e==0) return Matrix(n+1, n+1, true);
    
    Matrix res = m_fexp(M, e/2, n);
    res = res*res;
    if(e%2)res= res*M;
    return res;
}

void fluminense(){
    int n, m, k;cin >> n >> m >> k;
    Matrix mat(vii(n+1, vi(n+1, 0)));
    while(m--){
        int a, b; cin >> a >> b;
        mat.m[a][b]= (mat.m[a][b]+1)%MOD;
    }

    Matrix ans = m_fexp(mat, k, n);


    cout << ans.m[1][n]<< endl;


}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}