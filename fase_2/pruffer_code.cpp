#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k;
const int MAX= 2e5+10;
int v[MAX], freq[MAX];
vector<int> tree[MAX];
set<int> s;
int a;


int32_t main(){
    sws;
    cin >> n;

    for(int i=1; i<=n; i++){
        s.insert(i);
    }

    for (int i=0; i<n-2; i++){
        cin >>v[i];
        freq[v[i]]++;
        s.erase(v[i]);
    }  

    for(int i=0; i<n-2; i++){
        auto no = *s.begin();
        s.erase(no);
        cout << no << " "<< v[i]<< endl;
        freq[v[i]]--;
        if(freq[v[i]]==0) s.insert(v[i]);
    }

    cout << *s.begin()<< " "<< *s.rbegin()<< endl;

}