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

void fluminense(){
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dp1(n), dp2(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]==1){dp1[i]=1;dp2[i]=1;}
    }
    
    int l =0, r = n-1;
    
    while(l<=r){
        if(v[l]!=1)l++;
        if(v[r]!=1)r--;
        if(v[l]==1 and v[r]==1) break;
    }
    
    
    map<int, int> idx1, idx2;
    
    for(int i=l; i<=r; i++){
        if(!idx1.count(v[i]-1) and v[i]!=1)continue;
        if(idx1.count((v[i]-1))){
            dp1[i] = max(dp1[i], dp1[idx1[v[i]-1]]+1);
        }
        if(idx1.count((v[i]+1))){
            dp1[i] = max(dp1[i], dp1[idx1[v[i]+1]]+1);
        }
        
        idx1[v[i]]=i;
    }
    
    for(int i=r; i>=l; i--){
        if(!idx2.count(v[i]-1) and v[i]!=1)continue;
        if(idx2.count((v[i]-1))){
            dp2[i] = max(dp2[i], dp2[idx2[v[i]-1]]+1);
        }
        if(idx2.count((v[i]+1))){
            dp2[i] = max(dp2[i], dp2[idx2[v[i]+1]]+1);
        }
        
        idx2[v[i]]=i;
    }
    
    //for(int i=0; i<n; i++){
    //    cout << dp1[i]<< " "<< dp2[i]<< endl;
    //}
    
    int ans =0;
    for(int i=l; i<=r; i++) {
        ans = max(ans, min(2*dp1[i]-1, 2*dp2[i]-1));
    };
    cout << ans << endl;
}

int32_t main(){
    sws;    
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}








