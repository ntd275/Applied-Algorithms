#include <bits/stdc++.h>

using namespace std;

int n,m,c[21][21],f[1<<21][21];

bool bit(int x,int y){
    return (x >> y) & 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        c[u-1][v-1] = w;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!c[i][j]) c[i][j] = 1e6;

    memset(f,62,sizeof f);
    f[1][0] = 0;
    for(int i = 0; i < (1<<n); i++)
        for(int j = 0; j < n; j++){
            if(bit(i,j)){
                for(int u = 1; u < n; u++){
                    if(!bit(i,u)){
                        int y = i + (1<<u);
                        f[y][u] = min(f[y][u],f[i][j]+c[j][u]);
                    }
                }
            }
        }
    int res = 1e9;
    for(int i = 1; i < n; i++)
        res = min(res,f[(1<<n)-1][i]+c[i][0]);
    cout << res;
    return 0;
}
