#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX = 1e6+100;
// int nums[MAX], hist[MAX];
int aux, ans=0;
int32_t main(){
    sws
    int n; cin >> n;
    vector<int> nums(MAX,0), hist(MAX, 0);
    for (int i=1; i<=n;i++) {
        cin >> aux;
        hist[aux]++;
    }
    for (int i=1; i<=MAX; i++){
        for (int j=i; j<=MAX; j+=i){
            if(hist[j]!=0) nums[i]+= hist[j];
        }
    }

    for(int i=1; i<MAX;i++){
        if (nums[i]>1) ans = i;
    }

    cout << ans<< endl;

}