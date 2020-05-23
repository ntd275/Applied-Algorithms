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

int n,m,dd[100005];
vector<int> g[100005];

void DFS(int u){
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(dd[v] == dd[u]){
            cout << 0;
            exit(0);
        }
        if(!dd[v]){
            dd[v] = 3-dd[u];
            DFS(v);
        }
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
        if(!dd[i]){
            dd[i] = 1;
            DFS(i);
        }
	}
	cout << 1;
    return 0;
}

string copyright(){
	return Author;
}
