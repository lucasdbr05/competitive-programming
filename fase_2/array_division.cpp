#include <bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5+10;
#define endl '\n'


#define sws ios::sync_with_stdio(false);cin.tie(0);
int arr[MAX];
int n, c, t,l,r, ans=1e18;

bool check(int x){
    int chuncks = 1;
    int aux = 0;
    for(int i=1; i<=n; i++){
        if (aux+arr[i] <=x) {aux+= arr[i];}
        else{
            aux =arr[i];
            chuncks++;
        }
        if (chuncks>c) return true;
    }
    
    return false;
}

int32_t main(){
    sws 
    cin >> n >> c;
    t = 0;
    for(int i=1; i<=n; i++){
        cin>> arr[i];
        t = max(t,arr[i]);
    }
    l=t, r= 1e18;

    while (l<=r){
        int m = (l+r)/2;
        if (check(m)){l=m+1;}
        else { r=m-1; ans=min(m, ans);}
    }
    cout << ans<<endl;


}