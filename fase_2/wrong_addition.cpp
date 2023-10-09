#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
#define debug() 


void solve(){
    string a, res; cin >> a >> res;

    int ia = a.size()-1, ir= res.size()-1;
    string ans;

    if(a==res){
        cout << "0"<< endl; return;
    }
    if(stoll(res)< stoll(a)){
        cout << "-1" << endl; return;
    }
    while(ia>=0){
        if(a[ia]> res[ir]){
            if(res[ir-1]=='1'){
                char c = (char)(10+(res[ir]-'0')-(a[ia]-'0')+'0');
                ans = c+ ans;
                ir-=2; ia--;
            }else{
                ans = "-1";
                cout<< ans << endl;
                return;
            } 
        }else{
            char c =(char)((res[ir]-'0')-(a[ia]-'0')+'0');
            ans = c+ ans;
            ir--; ia--;
        }

        if(ir<0 && ia>=0){ans = "-1";  cout << ans << endl; return;}
    }

    for(int i=ir; i>=0; i--){ans = res[i]+ans;}
    ia=0;
    for (ia=0; ia<ans.size(); ia++){
        if(ans[ia]!='0'){
            break;
        }
    }

    for(int i=ia; i<ans.size(); i++)cout << ans[i];

    cout << endl;

}


int32_t main(){
    sws;

    int t; cin >> t;
    while(t--) solve();
    
}