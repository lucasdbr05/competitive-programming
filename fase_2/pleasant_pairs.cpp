#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define ii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;

const int MAX=2e5+10;
string s;
vector<iii> aux;

int32_t main(){
    int t; cin >> t;

    while(t--){
        cin>>n;
        vector<ii> v(n);
        for(int i=0; i<n; i++) {cin >> v[i].first; v[i].second=i+1;}
        sort(v.begin(), v.end());
        int ans =0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (v[i].first*v[j].first >2*n) break;
                if (v[i].first*v[j].first==(v[i].second+v[j].second)) ans++;
            }
        }
        cout << ans << endl;
    }

}