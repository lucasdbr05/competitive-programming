#include <bits/stdc++.h>
using namespace std;

int memo[2020][2020];
const int INF = 0x3f3f3f3f;
int s, n;
int value[2020], wgt[2020];

int pd(int ind, int cap)
{
    if (cap < 0)
        return -INF;
    if (ind == n)
        return 0;

    int &pdm = memo[ind][cap];
    if (pdm != -1)
        return pdm;

    return pdm = max(pd(ind + 1, cap - wgt[ind]) + value[ind], pd(ind + 1, cap));
}

// vector<int> ans;

// void recover(int ind, int cap){
//     if (ind ==n) return;

//     int pega = value[ind]+ pd(ind+1, cap - wgt[ind]);
//     int passa = pd(ind+1, cap);

//     if (pega>=passa){
//         ans.push_back(ind);
//         recover(ind+1, cap - wgt[ind]);
//     } else{
//         recover(ind+1, cap);
//     }
// }

int main()
{
    // cin >> max weigt >> quantity of items
    cin >> s >> n;

    for (int i = 0; i < n; i++)
        cin >> wgt[i] >> value[i];

    memset(memo, -1, sizeof(memo));
    cout << pd(0, s) << endl;

    // recover(0,s);
    // int profit = 0;
    // int total_wgt = 0;

    // for (auto x: ans){
    //     profit += value[x];
    //     total_wgt = wgt[x];
    // }
    // assert(profit == pd(0,s) && total_wgt<= s);

    // for (auto x: ans)
    //     cout << x<< " ";

    // cout<< endl;
}