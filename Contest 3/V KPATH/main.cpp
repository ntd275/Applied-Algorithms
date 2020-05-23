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

int n,m,k,res;
vector<int>g[35];
int dd[35],b[35];

void Try(int x){
    if(x == k+2){
        ++res;
        return;
    }
    int u = b[x-1];
    for(int i = 0; i< g[u].size();++i){
        int v = g[u][i];
        if(!dd[v]){
            b[x] = v;
            dd[v] = 1;
            Try(x+1);
            dd[v] = 0;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= m; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <=n ;++i){
        g[0].pb(i);
    }
    Try(1);
    cout << (res >> 1);
    return 0;
}

string copyright(){
	return Author;
}
