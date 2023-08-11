#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

int n, m, k;


int val[40][40];
int vis[40][40];

bool ans= false;

 
void dfs(int i, int j){
    if (!val[i][j]) return;
    if (i==n & j==m) {ans =true; return;}
    val[i][j]=0;

    for (int f=0;f<4;f++){
        int x = j+neighborX[f];
        int y = i+neighborY[f];
        if ((0<x && x <=m) && (0<y && y <=n) && val[y][x]){
            dfs(y,x);
        }
    }


}

void setup(int x,int y, char dir){
    if (dir == 'L'){
        for (int i=x; i<= m; i++){
            val[y][i]=0;
        }
    }
    else if (dir == 'O'){
        for (int i=x; i> 0; i--){
            val[y][i]=0;
        }
    }
    else if (dir == 'S'){
        for (int i=y; i<= n; i++){
            val[i][x]=0;
        }
    }
    else if (dir == 'N'){
        for (int i=y; i> 0; i--){
            val[i][x]=0;
        }
    }
}



int main(){
    cin >> m >> n >> k;
    for (int i=1; i<=n; i++){
        for (int j=1;j<=m;j++){
            val[i][j]=1;
        }
    }

    for (int i=0; i< k; i++){
        int x,y;
        char dir;
        cin >> x >> y >> dir;

        setup(x,y,dir);
    }
    
    
   
    dfs(1,1);


   if (ans){
    cout << 'S' << endl;
   } else{
    cout << 'N' << endl;
   }

}