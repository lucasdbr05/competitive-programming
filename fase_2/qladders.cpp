#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;

int32_t main(){

    int n, k, x, ans = 1; cin >> n >> k >> x;

    vector<int> aux(n);

    for(int i = 0; i < n; i++) cin >> aux[i];

    sort(aux.begin(), aux.end());

    for(int i = 0; i < n-1; i++){

        if((aux[i+1] - aux[i]) > k && (aux[i+1] - aux[i]) <= 2*k){

            if(k) k--;
            else ans++;
        } else {

            ans ++;
        }
    }

    cout << ans << '\n';

    return 0;
}