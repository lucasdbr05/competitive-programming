#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
ll n, m, q, x, y;
ll psum[1000010];

int main(){
    cin >> n >> m;
    vector<ll> v(n+1,0);

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    while (m--){
        cin >> q >> x >> y;
        if (q==1){
            v[x]=y;
        } else if (q==2){
            memset(psum, 0, sizeof(psum));
            ll out =0;
            for (int i=x; i<=y; i++){
                // cout << "-->" <<v[i]<< " "<<psum[i]<< " ";
                psum[i]=v[i]+psum[i-1];
                out = max(out, psum[i]);
            }
            cout << out << endl;
        }
    }
}