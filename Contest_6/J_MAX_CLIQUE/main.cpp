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

int res,n,m,b[15],s;
vector<int> g[15];

void Try(int x){
    if(x > n){
        return;
    }
    int dem = 0;
    for(auto v:g[x]){
        if(b[v]) ++dem;
    }
    if(dem == s) {
        ++s;
        b[x] = 1;
        res = max(res,s);
        Try(x+1);
        b[x] = 0;
        --s;
    }
    Try(x+1);
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
    Try(1);
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
