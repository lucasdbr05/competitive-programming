#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define ii pair<int, int>
#define iii tuple<int, int, int>
const int INF=0x3f3f3f3f3f3f3f;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<iii> hotel;

int32_t main(){
    cin>> n;
    vector<int> ans(n);
    int idx = 1;
    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        hotel.push_back({a, b, i});
    }
    
    sort(hotel.begin(), hotel.end());
    for (auto [in,out, i]:hotel){
        if(pq.empty()){
            ans[i] = idx;
            pq.push({out, idx});
            idx++;
        }else{
            auto [aux, j] = pq.top();
            if(in> aux){
                pq.pop();
                ans[i]=j;
                pq.push({out, j});
            }else{
                ans[i] = idx;
                pq.push({out, idx});
                idx++;
            }
        }
    }
    idx = 0;
    for (int i=0; i<n; i++) idx = max(ans[i], idx);

    cout <<idx--<< endl;
    for (int i=0; i<n; i++) cout << ans[i]<< " ";
    cout << endl;

}