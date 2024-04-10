#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
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
vector<bool> primes;
vector<bool> crivo() {
	vector<bool> vis(MAX+10, true);
	for(int i=2; i<MAX; i++){
		if(!vis[i]){
			for(int j=i; j<MAX; j+=i){
				vis[i]= false;
			}
		}
	}

	return vis;
}


void fluminense(){
    int n; 
	cin >> n;

	vector<int> v(n);
	vector<float> dp(n);
	float aux = 0.0;
	for(int i=0; i < n; i++) {
		
		cin >> v[i];
	}
	for(int i=0; i<n; i++){
		dp[i]+= (1.0*v[i])/3;
		aux+= dp[i];
	}

	cout << fixed << setprecision(10)<< aux << endl;
}

int32_t main(){
    sws;    
    int T=1;
	vector<bool> primes = crivo();
    // cin >> T;
    while(T--)fluminense(); 
    
}