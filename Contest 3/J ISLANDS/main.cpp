#include <bits/stdc++.h>

using namespace std;

int d[1002][1002],n,m;
char a[1002][1002];

int dem, smax;

int DFS(int i, int j){
    d[i][j] = 1;
    int t = 1;
    if(!d[i+1][j] && a[i+1][j]) t += DFS(i+1,j);
    if(!d[i-1][j] && a[i-1][j]) t += DFS(i-1,j);
    if(!d[i][j+1] && a[i][j+1]) t += DFS(i,j+1);
    if(!d[i][j-1] && a[i][j-1]) t += DFS(i,j-1);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            a[i][j] -= '0';
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            if(!d[i][j] && a[i][j]){
                smax = max(smax,DFS(i,j));
                ++dem;
            }
        }
    cout << dem << '\n';
    cout << smax;
}
