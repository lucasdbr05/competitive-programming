#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef pair <int, int> ii;
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// queue<int> h[1005];
int h[2000];
// stack<ii> st;
char grid[2000][2000];
int n, m, out=0;



int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        for (int j=0; j<m; j++){
            grid[i][j]= str[j];
            if (grid[i][j]=='.'){
                h[j]++;
            } else{
                h[j]=0;
            }
        }

        stack<int> st;
        

        for (int j=0; j<=m; j++){
            while(!st.empty() && h[st.top()]> h[j]){
                int top = st.top(); st.pop();
                int w = !st.empty()? j-st.top()-1: j;
                out = max(out, h[top]*w);
            }
            if (j<m) st.push(j);
        }
    }

    cout << out << endl;
}






// int main(){
//     _
//     cin >> n >> m;
//     for (int i=0; i<n; i++){
//         string str;
//         cin >> str;
//         for (int j=0; j<m; j++){
//             grid[i][j]= str[j];
//             if (grid[i][j]=='*'){
//                 h[j].push(i);
//             }
//         }
//     }

//     for (int j=0; j<m;j++) h[j].push(n);
    

//     for (int i=0; i< n; i++){
//         for (int j=0; j<m; j++){
//             if (h[j].front()< i){
//                 h[j].pop();
//             }
//         }

//         for (int j=0; j<m;j++){
//             int b =j;

//             while(!st.empty() && h[j].front()-i<st.top().second){
//                 ii p =  st.top(); st.pop();
//                 b= p.first;
//                 out = max(out, (j-p.first)*p.second);
//             }
//             st.push({b, h[j].front()-i});
//         }

//         while(!st.empty()){
//             ii p = st.top(); st.pop();
//             out = max(out, (m-p.first)*p.second);
//         }

//     }
//     cout << out << endl;
// }