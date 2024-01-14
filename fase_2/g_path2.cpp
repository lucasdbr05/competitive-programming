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
const int INF = 1LL<<61;

void print_mat(vector<vector<int>> mat){
    int n = mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j]<< " ";
        }
        cout << endl;
    }
}


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
        /*if(ident) {
            for(int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }*/
    }
 
    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); 
        vii res(r, vector<int>(o.c, INF));
        for(int i =0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                for(int k = 0; k < o.c; k++) {
                    res[i][j] = min(res[i][j], m[i][k]+o.m[k][j]) ;
                }
            }
        }
 
        return Matrix(res);
    }
};


Matrix m_fexp(Matrix M, int k, int n) {
    vii r(M.m.size(), vi(M.m.size(), 0));
    Matrix res(r);
    int f = 0;
    while (k>0){
        if (k&1) {
            if (f) res = res*M;
            else res = M, f =1;
        }
        k=k>>1;
        M =M*M;
    }
    return res;
}

void fluminense(){
    int n, m, k;cin >> n >> m >> k;
    Matrix mat(vii(n, vi(n, INF)));
    while(m--){
        int a, b, c; cin >> a >> b>> c;a--;b--;
        mat.m[a][b]= min(mat.m[a][b],c);
    }
    Matrix ans = m_fexp(mat, k, n);
    //print_mat(ans.m);

    if(ans.m[0][n-1]<INF)cout << ans.m[0][n-1]<< endl;
    else cout << -1 << endl;

}

int32_t main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}