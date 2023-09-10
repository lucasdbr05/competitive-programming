#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define elif else if
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
int n,l,r, m;
vector<ii> v;

int32_t main(){
    sws
    cin >> n>> m;

    for (int i=1; i<=n; i++){
        int x; cin >> x; v.push_back({x,i});
    }
    sort(v.begin(), v.end());

    for (int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            l=j+1;r=n-1;
            while(l<r){
                int val = v[i].first+v[j].first+v[l].first+v[r].first;
                if (val==m and (l!=r&&i!=j&&l!=i &&r!=j)){
                    cout << v[l].second << " "<< v[r].second <<" "<< v[i].second <<" "<< v[j].second;
                    return 0;
                }else if(val> m){
                    r--;
                }else{
                    l++;
                }

            }
        }
    }
    cout << "IMPOSSIBLE"<< endl;
}