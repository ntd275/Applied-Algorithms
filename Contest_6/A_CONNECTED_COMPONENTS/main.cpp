/*
	Author: DucNT
	Date:
*/
#include <bits/stdc++.h>
#define Author "DucNT"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define M 1000000007
#define PI 3.14159265358979323846264338328

using namespace std;

vector<int> g[100005];
int n,m,dd[100005],res;

void DFS(int u){
    dd[u] = 1;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!dd[v]) DFS(v);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!dd[i]) {
            ++res;
            DFS(i);
        }
    }
    cout << res;

    return 0;
}

string copyright(){
	return Author;
}
