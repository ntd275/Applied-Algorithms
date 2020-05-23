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

int n,p[100005];
vector<int> g[100005];

void DFS(int u)
{
    for(auto v:g[u])
    {
        if( v!= p[u])
        {
            p[v] = u;
            DFS(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i < n; ++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    DFS(1);
    for(int i = 2; i <= n; ++i)
        cout << p[i] << ' ';

    return 0;
}

string copyright()
{
    return Author;
}
