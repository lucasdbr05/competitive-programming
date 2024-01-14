#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

bool cmp(int a, int b){return b<a;}

void fluminense(){
    int n; cin >> n;
    set<int> vis; for(int i=1; i<=n; i++)vis.insert(i);
    vector<int> v(n),aux;
    int ans =0; bool flag = true;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(vis.find(v[i])!= vis.end()) vis.erase(v[i]);
        else {aux.pb(v[i]);}
    } 

    sort(aux.begin(), aux.end(), cmp);

    for(auto num:aux){
        //cout << num << " ";
        auto it = vis.end(); it--;
        if((*it)> (num-1)/2){
            flag = false;
            break;
        }
        vis.erase((*it));
    }

    if(flag) cout << aux.size()<< endl;
    else cout << -1 << endl;

}

int32_t main(){
    sws;    
    int T=1;
    cin >> T;
    while(T--)fluminense(); 
    
}