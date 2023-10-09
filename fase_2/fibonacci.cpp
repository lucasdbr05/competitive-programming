#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
typedef pair<int, int> ii;
const int MAX=1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
#define vii vector<vector<int>>

vii fib_mul(vii& F, vii& M){
    vii FIB(2, vector<int>(2));
    int a11 = ((F[0][0]*M[0][0])%MOD+ (F[0][1]*M[1][0])%MOD)%MOD;
    int a12 = ((F[0][0]*M[0][1])%MOD+ (F[0][1]*M[1][1])%MOD)%MOD;
    int a21 = ((F[1][0]*M[0][0])%MOD+ (F[1][1]*M[1][0])%MOD)%MOD;
    int a22 = ((F[1][0]*M[0][1])%MOD+ (F[1][1]*M[1][1])%MOD)%MOD;
    FIB[0][0]= a11;
    FIB[0][1]= a12;
    FIB[1][0]= a21;
    FIB[1][1]= a22;
    return FIB;
}
vii matrix_exp(vii &a, int n){
    if(n==0){
        vii v(2, vector<int>(2));
        v[0][0]=1;v[0][1]=1;v[1][0]=1;v[1][1]=0;
        return v;
    }
    if(n==1)return a;

    vii aux = matrix_exp(a, n/2);
    vii ans = fib_mul(aux, aux);

    if(n&1) ans = fib_mul(ans, a);
    return ans;
}


void pwr(vii& F, int n){
    vii M = {{1,1}, {1,0}};
    for (int i=2; i<n; i++){
        fib_mul(F,M);
    }

}

int fibonnaci_matrix(int n){
    vii F = {{1,1}, {1,0}};
    if (n==0) return 0;
    pwr(F, n);
    return F[0][0];
}

int fexp(double a, int b){
    if (b==0) return 1;

    int res = fexp(a, b/2);
    if (b%2==1) return (int)(((res*res)%MOD)*a)%MOD;
    return (res*res)%MOD;
}

ii fibonacci(int n){
    if(n==0) return{0,1};
    auto p = fibonacci(n>>1);

    int c = p.first*(2*p.second- p.first + MOD)%MOD;
    int d = ((p.first*p.first)%MOD + (p.second*p.second)%MOD)%MOD;
    if (n&1) return {d, (c+d)%MOD};
    else return {c,d};
}

int32_t main(){
    int x; cin >> x;
    vii a(2, vector<int>(2)); a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;
    
    vii out = matrix_exp(a, x-1);
    int n  =x!=0? out[0][0]:0;
    cout << n << endl;
}