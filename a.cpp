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
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
map<int, float> memo;

int n, a, x, y;
float dp(int u){
    if(u==0) return 0;
    if(memo.count(u)) return memo[u];

    memo[u] = x + dp(u/a);
    map<int, int> nxt;

    for(int i=2; i<=6; i++){
        nxt[u/i]+= 1;
    } 
    float aux  = 0.0;
    for(auto &[z, w]: nxt){
        aux+= ((1.0*w)/6.0)*dp(z);
    }

    return memo[u] = min(memo[u], (1.0*(y+aux))*6.0/5.0);
}

o_maior_do_brasil_e_o fluminense(){
    cin  >> n >> a>> x>> y;
    float ans = dp(n);

    cout << fixed << setprecision(15)<< ans << endl;
}

signed main(){
    sws;    
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}