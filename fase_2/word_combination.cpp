#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
int dp[5005];
string s;


struct Trie{

    int trie[MAX][26];
    bool finish[MAX];
    int nxt = 1, len = 0;

    void add(string s){
        int node = 0;
        for(auto c: s){
            if(trie[node][c-'a'] == 0)
                node = trie[node][c-'a'] = nxt++;
            else
                node = trie[node][c-'a'];
        }
        if(!finish[node]){
            finish[node] = true;
            len++;
        }
    }

    bool find(string s, bool remove=false){
        int node = 0;
        for(auto c: s)
            if(trie[node][c-'a'] == 0)
                return false;
            else
                node = trie[node][c-'a'];
        if(remove and finish[node]){
            finish[node]=false;
            len--;
        }
        return finish[node];
    }
};


int32_t main(){
    sws;
    cin >> s;
    int  m; cin >> m;
    Trie tr;
    while(m--){
        string aux; cin >> aux;
        tr.add(aux);
    }

    int n = s.size();
    dp[n]=1;
    for(int i=n-1; i>=0; i--){
        int curr=0, ans =0;
        for (int j=i; j<n; j++){
            if(tr.trie[curr][s[j]-'a']==0) break;

            curr = tr.trie[curr][s[j]-'a'];
            if(tr.finish[curr]){
                ans = (ans+ dp[j+1]%MOD)%MOD;
            }
            dp[i]= ans;
        }
    }

    cout << dp[0]<< endl;
}