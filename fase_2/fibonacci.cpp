#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
typedef pair<int, int> ii;
const int MAX=1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

void fib_mul(vector<vector<int>>& F, vector<vector<int>>& M){
    int a11 = ((F[0][0]*M[0][0])%MOD+ (F[0][1]*M[1][0])%MOD)%MOD;
    int a12 = ((F[0][0]*M[0][1])%MOD+ (F[0][1]*M[1][1])%MOD)%MOD;
    int a21 = ((F[1][0]*M[0][0])%MOD+ (F[1][1]*M[1][0])%MOD)%MOD;
    int a22 = ((F[1][0]*M[0][1])%MOD+ (F[1][1]*M[1][1])%MOD)%MOD;
    F[0][0]= a11;
    F[0][1]= a12;
    F[1][0]= a21;
    F[1][1]= a22;
}

void pwr(vector<vector<int>>& F, int n){
    vector<vector<int>> M = {{1,1}, {1,0}};
    for (int i=2; i<n; i++){
        fib_mul(F,M);
    }

}

int fibonnaci_matrix(int n){
    vector<vector<int>> F = {{1,1}, {1,0}};
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
    cout << fibonacci(x).first<< endl;
}