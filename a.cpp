#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
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
const int MAX= 305;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int x1 = 0, x2 = 0, x3 = 0;
double memo[MAX][MAX][MAX];
int n; 


double dp(int v1, int v2, int v3){
    if(v1==0 && v2==0 && v3==0) {
        return 0;
    }
    if(v1<0 || v2<0 || v3<0) {
        return 0;
    }

    if(memo[v1][v2][v3]>0) return memo[v1][v2][v3];

    double aux = (1.0*(n+ (v1*dp(v1-1, v2, v3)+v2*dp(v1+1, v2-1, v3)+v3*dp(v1, v2+1, v3-1))))/(v1+v2+v3);

    return memo[v1][v2][v3] = aux;

}


void solve(){
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        int c; cin >> c;
        if(c==1) x1++;
        if(c==2) x2++;
        if(c==3) x3++;
    }


    cout<< setprecision(15) << dp(x1, x2, x3)<< endl;


    
}

signed main(){
    sws;    

    for(int i=0; i<=300; i++)
        for(int j=0; j<=300; j++)
            for(int k=0; k<=300; k++)
                memo[i][j][k]=-1;
    int T=1;
    // cin >> T;
    while(T--)solve(); 
    
}