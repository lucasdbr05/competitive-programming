#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
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
bool chess[8][8], diag_p[16], diag_s[16], col[8];
int ans =0;


void build(int i){
    if(i==8){ans++;;return;}
    for(int j=0; j<8; j++){
        if(chess[i][j] && !(diag_s[i+j] || diag_p[i+7-j]|| col[j])){
            diag_s[i+j]=true;
            diag_p[i+7-j]= true;
            col[j]= true;
            build(i+1);
            diag_s[i+j]=false;
            diag_p[i+7-j]= false;
            col[j]= false;

        }
    }
}



void fluminense(){
    char c;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> c;
            chess[i][j] = (c=='.');
        }
    }

    build(0);

    cout << ans << endl;
}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}