#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;
const int MAX = 2*1e5+10;
#define int long long int
typedef pair<int, int> ii;
string s;
int memo[MAX];
int n, k, ans=0;

bitset<26> chrs;
bitset<MAX> x;

void dp(){
    memo[0]=0;

    for (int i=0; i<n; i++){
        if (chrs[s[i]-'a']) x[i]=true;
        else x[i]=false;
    }
    

    for(int i=1; i<=n; i++){
        if (x[i-1]) memo[i] = memo[i-1]+1;
        else memo[i]= 0;
        ans += memo[i];
    }


}

int32_t main(){
    
    cin >> n >> k;

    cin>> s;

    for (int i =0; i<k; i++){
        char c; cin>> c;
        chrs[c-'a']=true;
    }

    
   
    

    
    dp();
    

    cout << ans << endl;
    
}