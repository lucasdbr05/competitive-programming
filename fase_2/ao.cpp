#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 6e5+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> f1, f0;

int32_t main(){
    sws;
    int m, ans=0; cin >> m;
    while(m--){
        int p,i; cin >> p >> i;
        if(i)f1.push(p);
        else f0.push(p);
    }
    
    
    
    while(!f0.empty() && !f1.empty()){
        if(f1.top()>f0.top()){
            ans += 10;
            while(!f0.empty() and f0.top()<ans){
                
                if(f0.top()+10> ans){ans = f0.top() + 10;}
                f0.pop();
            }
            
        }else{
            ans+= 10;
            while(!f1.empty() and f1.top()<ans){
        
                if(f1.top()+10>ans){ans = f1.top()+10;}
                f1.pop();
            }
        }
        
    }
    
    if(!f0.empty()){
        ans+=10;
        while(!f0.empty() ){
            if(f0.top()+10> ans) ans = f0.top()+10;
            f0.pop();
        }
        
    }
    if(!f1.empty()){
        ans+=10;
        while(!f1.empty()){
            if(f1.top()+10> ans) ans = f1.top()+10;
            f1.pop();
        }
    }
    
    cout << ans << endl;
}