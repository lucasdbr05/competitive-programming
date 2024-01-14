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
#define vii vector<vector<int>>
 
 
vector<vector<int>> ans{
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1},
    };
 
struct Matrix {
    vii m;
 
    int r, c;
 
    Matrix(vii mat) {
        m = mat;
        r = m[0].size();
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
        assert(c == o.r); // garantir que da pra multiplicar
        vii res(r, vector<int>(o.c, 0));
 
        for(int i =0; i < r; i++) {
            for(int k = 0; k < c; k++) {
                for(int j = 0; j < o.c; j++) {
                    res[i][j] = (res[i][j] +(m[i][k]*o.m[k][j])%MOD) % MOD;
                }
            }
        }
 
        return Matrix(res);
    }
};
 
Matrix fexp(Matrix b, int e, int n) {
    if(e == 0) return Matrix(n, n, true); // identidade
    Matrix res = fexp(b, e/2, n);
    res = (res * res);
    if(e%2) res = (res * b);
 
    return res;
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
    
    Matrix mtx(comb);
    vector<int> p {1,2,4,8, 16, 32};
    if(n<=6){
        cout << p[n-1];
    }else{
        // n-=6;
        Matrix curr = fexp(mtx, n, 6);
 
        int out = 0;

        // for(int i=0; i<6; i++){
        //     for(int j=0; j<6; j++){
        //         cout << curr.m[i][j]<< " ";
        //     }
        //     cout << endl;
        // }

        // cout << endl;
 
        for(int i=0; i<6; i++){
            out = (out + (curr.m[0][i]*p[6-i-1])%MOD)%MOD;
        }
        cout << out << endl;
    }
}