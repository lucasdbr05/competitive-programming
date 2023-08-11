#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
int n, m;


vector<int> v;
const int MOD = 1e9+7;
const int MAX = 1e6+5;


bool cmp (int mid){
    int aux =0;
    for (int i=0; i<n; i++){
        aux+= (v[i]/mid);
        if (aux >=m) return true;
    }
    return false;
}




int32_t main(){
    sws;
    cin>> n >> m;
    int ans=0, aux, x;
    
    for (int i=0; i<n; i++){
        cin >>x;  v.push_back(x);
    }

    // sort(v.begin(), v.end(), cmp);
    int l=1, r=1e9+1, mid;

    while (l<=r){
        mid =(l+r)/2;

        if (cmp(mid)){
            ans =mid;
            l =mid+1;
        } else{
            r=mid-1;
        }
    }

    cout << ans << endl;


    return 0;
}