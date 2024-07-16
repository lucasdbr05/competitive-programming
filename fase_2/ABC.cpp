#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define o_maior_do_brasil_e_o void
#define int long long int
#define float double
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define vpii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
vpii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX= 1e6+5;
const int MOD= 998244352;
const int MOD1= 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Matrix {
    vvi m;
 
    int r, c;
 
    Matrix(vvi mat) {
        m = mat;
        r = mat.size();
        c = m[0].size();
    }
 
    Matrix(int row, int col, bool ident=false) {
        r = row; c = col;
        m = vvi(r, vector<int>(c, 0));
        if(ident) {
            for(int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }
 
    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); 
        vvi res(r, vector<int>(o.c, 0));
 
        for(int i =0; i < r; i++) {
            for(int k = 0; k < c; k++) {
                for(int j = 0; j < o.c; j++) {
                    res[i][j] = (res[i][j] + (m[i][k]*o.m[k][j])%MOD) % MOD;
                }
            }
        }
 
        return Matrix(res);
    }
};


Matrix m_fexp(Matrix M, int e, int n){
    if(e==0) return Matrix(n, n, true);
    
    Matrix res = m_fexp(M, e/2, n);
    res = res*res;
    if(e%2)res= res*M;
    return res;
}

int fexp(int b, int e){
    if (e==0) return 1;

    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD1)*b)%MOD1;
    else return (ans*ans)%MOD1;
}

o_maior_do_brasil_e_o fluminense(){
    int n; cin >> n;  
    vvi v = {
        {0, 1},
        {1, 1},
    };
    
    Matrix fib(v);
    Matrix fib_n = m_fexp(fib, n, 2);
    int ans = fexp(2, fib_n.m[0][1]);
    // cout << fib_n.m[0][0] << esp << fib_n.m[0][1] << endl;
    // cout << fib_n.m[1][0] << esp << fib_n.m[1][1] << endl;

    cout << ans << endl;
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}