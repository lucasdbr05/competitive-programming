#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;


int32_t main(){
    sws
    map<int, int> mp;
    int n,x,a,m,l,r,i, aux; cin >> n >> x;
    vector<ii> v;
    for (int j=1; j<=n; j++){
        cin>> a; v.push_back({a,j});
    }
    sort(v.begin(), v.end());

    bool val = false;
    for (int i=0; i<n; i++){
        if (val) break;
        l=0, r=n-1;
        while(l<r){
            int aux = x - v[i].first;
            
            if (l!=i && r!=i && v[l].first + v[r].first==aux){
                val = true;
                m=i;
                break;
            }

            if (v[l].first + v[r].first< aux) l++;
            else r--;

        }
    }

    if (val) cout << v[m].second<<" "<< v[l].second<< " "<<  v[r].second<< endl;
    else cout << "IMPOSSIBLE"<< endl;

}