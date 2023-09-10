#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef tuple <int, int, int> ii;
// typedef long long int ll;
const int MAX= 1e8+5;
const int INF= 0x3f3f3f3f;
int m, k, x, y;

ii escolhe_min(ii a, ii b){
    auto [ta1, t1a1, t1ak] = a;
    auto [tak, tka1, tkak] = b;
    if (ta1<tak){
        return {ta1+1, t1a1, t1ak};
    }else{
        return {tak+1, tka1, tkak};
    }
}

int32_t main(){
    int t; cin>>t;
    while (t--){
        cin >> m >>k>> x >> y;
        vector<ii> arr(m+1);
        arr[0]= {0,0,0};
        for (int i=1; i<=m; i++){
            auto [total, a1, ak] = arr[i];
            
            if (i-k<0){
                if (a1<x) arr[i]= {total, a1+1, ak};
                else arr[i]= {total+1, a1, ak};
            }else{
                auto [ta1, t1a1, t1ak] = arr[i-1];
                auto [tak, tka1, tkak] = arr[i-k];
                if (ta1< tak){
                    if (t1a1<x)arr[i] = {ta1, t1a1+1, tkak+k};
                } if (tak< ta1){
                    if (tkak<y) arr[i] = {tak, tka1, tkak+k};
                }
                else{
                    if (tka1<t1a1){
                        if (tkak<y) arr[i] = {tak, tka1, tkak+k};
                        else escolhe_min(arr[i-1], arr[i-k]);
                    } else{
                        if (t1a1<x)arr[i] = {ta1, t1a1+1, tkak+k};
                        else escolhe_min(arr[i-1], arr[i-k]);
                    }
                }
            }
        }
        auto [fancy, ignore, ige] = arr[m];
        cout << fancy << endl;
    }
}