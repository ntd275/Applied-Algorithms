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

int n,d[100005],res;
vector<int>g[100005];

void DFS(int u){
    int leaf = 1;
    for(auto v:g[u]){
        if(!d[v]){
            leaf = 0;
            d[v] = 1;
            DFS(v);
        }
    }
    res += leaf;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 1;i < n; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
	}
	d[1] = 1;
	DFS(1);
	cout << res;
    return 0;
}

string copyright(){
	return Author;
}
