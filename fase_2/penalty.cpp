#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int solve(){
    string s; cin >> s;
    int g;
    int aux1, aux2;
    int ag=0, a_int=0,ak=5,bk=5, bg=0, b_int=0, k=0;
    for (int i=0; i<(int)s.size(); i++){
        // cout << i<<" " << ag <<" " << bg<< " "<< endl;
        if(i%2){
            if(s[i]=='1')ag++;
            else if(s[i]=='?')ag++;
            ak--;
        }else{
            if(s[i]=='1')bg++;
            bk--;
        }
        if(ag>(bk+bg)|| bg>(ak+ag)){
            aux1=i+1; break;
        }
    }
    ag=0, a_int=0,ak=5,bk=5, bg=0, b_int=0;
    for (int i=0; i<(int)s.size(); i++){
        // cout << i<<" " << ag <<" " << bg<< " "<< endl;
        if(i%2==1){
            if(s[i]=='1')ag++;
            ak--;
        }else{
            if(s[i]=='1')bg++;
            else if(s[i]=='?')bg++;
            bk--;
        }
        if(ag>(bk+bg)|| bg>(ak+ag)){
            aux2=i+1; break;
        }
    }
    // cout << "----"<< endl;
    int ret = min(aux1, aux2) >=10? 10: min(aux1, aux2);
    return ret ;
}



int32_t main(){
    sws;
    int t; cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}