#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, k, x;
#define iii tuple<int, int, int>
const int MAX=2e5+10;
map<int, int> mp;
set<int> s;
bool cmp(iii a, iii b) {
    auto [fa, sa, ta]= a;
    auto [fb, sb, tb]= b;
    return fa<fb;
}

vector<iii> aux;
bool disj[MAX];
vector<int> arr;
int32_t main(){
    memset(disj, false, sizeof disj);
    cin >> n >> k >> x;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for (int i=1; i<n; i++){
        if (arr[i]- arr[i-1]>x){
            disj[i]= true;
            disj[i-1]= true;
            aux.push_back({arr[i]-arr[i-1], i-1, i});
        }
    }
    sort(aux.begin(), aux.end(), cmp);

    // for(auto [w, a, b]: aux){
    //     cout << w << " "<< a << " "<< b<< endl;
    // }
    for (auto [w, a,b]: aux){
        int j = (arr[b]-arr[a])/x;
        k-= j;
        if  (k<0) break;
        disj[b]=false;
        disj[a]= false;
    }
    // for (int i=0; i<n; i++) cout << disj[i]<< " ";
    // cout << endl;

    int ans =1;
    for (int i=0; i<n-1; i++){
        if(disj[i]==true and disj[i+1]==true) ans ++;
        else if(disj[i]==false and disj[i+1]==true and disj[i+2]!=true) ans ++;
    }



    cout << ans << endl;


    


}