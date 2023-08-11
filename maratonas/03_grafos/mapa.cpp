#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> ii;
const int MAX = 1e5+10;

int neighborX[4]= {1,0,-1,0};
int neighborY[4]= {0,1,0,-1};

int n,m,i,j;
vector<vector<char>> matrix(MAX);
vector<vector<int>> vis(MAX);
vector<vector<ii>> parents(MAX);
vector<vector<int>>dis(MAX);
ii o, ans;
queue<ii> q;


bool isVal(int i, int j){
    if (0>=i) return false;
    if (n<i) return false;
    if (0>=j) return false;
    if (m<i) return false;
    if (vis[i][j]) return false;
    if (matrix[i][j]!='H') return false;
    return true;
}


int main(){_
    cin >> n >> m;

    for (int i =1; i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> matrix[i][j];
            if (matrix[i][j]=='o') o={i,j};
        }
    }

    q.push(o); vis[o.first][o.second]=1;
    
    while(!q.empty()){
        ans = q.front();q.pop();

        for (int f=0;f<4;f++){
            i=ans.first+neighborY[f];
            j=ans.second+neighborX[f];

            if (isVal(i,j)){
                q.push({i,j});
                vis[i][j]=1;
                // parents[i][j]= ans;
                // dis[i][j]= dis[ans.first][ans.second]+1;
            }
        }
    }

    cout << ans.first << " "<< ans.second<< endl;
}