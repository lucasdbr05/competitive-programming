#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int INF = 0x3f3f3f3f;
const int MAX= 1e6;
int n, k, ans=0;
vector<int> nums;
vector<int> coins(1000100, INF);
bool val=false;
bool cmp(int a, int b) {return a>b;}

void dp(){
    for(int aux=1; aux<=k; aux++){
        for(auto num: nums){
            if (aux-num>=0){
                coins[aux] = min(coins[aux-num]+1, coins[aux]);
            }
            
        }
    }
    if (coins[k]>INF-1000){coins[k]=-1;}
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    nums.resize(n); 
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmp);

    coins[0]=0;
    dp();
    
    cout << coins[k]<< endl;
}










