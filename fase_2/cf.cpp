#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long int
#define ii pair<int, int>
const int MOD = 1e9+7;
const int MAX= 1e6+10;
const int INF= (1*4+10)*(1e10+10);

void solve(){
    int ans = 0;
    int n, k;
    cin>> n >> k;
    vector<int> pres(n+1);
    vector<vector<int>> comps(n+5);
    vector<int> a(n+3),h(n+3);
    for(int i=1;i<=n; i++)cin >> a[i];
    for(int i=1;i<=n; i++)cin >> h[i];

    for (int i=1; i<=n; i++)pres[i] = h[i]%h[i-1];
    int c=1;
    for(int i=1; i<=n; i++){
        if(pres[i]==0) comps[c].push_back(a[i]);
        else{
            c++;
            comps[c].push_back(a[i]);
        }
    }

    for(int i=1; i<=c; i++){
        vector<int> v = comps[i];
        int aux = 0;
        int l=0, r=0;
        while(r<(int)v.size() and l<(int)v.size()){

            if(aux + v[r]>k){
                if(l>r) r=l;
                else {
                    aux-= l;
                    l++;
                }
            }else{
                aux += v[r];
                r++;
            }
            ans = max(ans, l-r);
        }
    }

    cout << ans << endl;

}

int32_t main(){
    sws;
    int t;cin >> t; 
    while (t--) solve();
    
}