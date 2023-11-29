#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define arr tuple<int, int , int>
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);;


// bool cmp(pair<pii, string>a, pair<pii, string>b){
//     if(a.ff.ff!=b.ff.ff)return a.ff.ff>b.ff.ff;
//     return a.ff.ss > b.ff.ss;
// }


set<int> cls;
vector<pii> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};



void solve(){
    int n, m;cin >> n >> m;
    cls.insert(0); cls.insert(n+1);
    for(int i=0; i<m; i++){
        char curr; cin >> curr;
        if(curr=='-'){
            int x; cin >> x;
            cls.insert(x);
        }else if(curr=='+'){
            int x; cin >> x;
            cls.erase(x);
        }else{
            int a, b; cin>> a >> b;
            if(cls.size()==2){
                cout <<"possible"<< endl;
            }else{
                if(a>b)swap(a,b);
                auto tal = *cls.lower_bound(a);
                auto tau = *cls.upper_bound(a);
                auto tbl = *cls.lower_bound(b);
                auto tbu = *cls.upper_bound(b);
                cout << tal << " "<< tau<< " "<< tbl << " "<< tbu << " "<< endl;
                if(
                    ((min(tal, tbl)< a and min(tal, tbl)< b) and
                    (max(tau, tbl)< a and max(tau, tbu)< b) ) or 
                    (tal==0 and tbu==n+1)
                ) cout << "possible"<< endl;
                else cout << "impossible"<< endl;
            
            }
        }
    }
}



int32_t main(){
    sws;
    int t=1;
    // cin >> t;
    while(t--)solve();
   
    
}