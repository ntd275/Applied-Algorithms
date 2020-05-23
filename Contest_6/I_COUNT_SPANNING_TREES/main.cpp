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

int n,m,root[25],s,res;

pair<int,int> a[30];

int getroot(int u)
{
    return root[u] ? getroot(root[u]) : u;
}



void Try(int x)
{
    if(x > m) return;
    int p = getroot(a[x].F);
    int q = getroot(a[x].S);
    if(p != q)
    {
        ++s;
        if(s == n-1) ++res;
        else
        {
            root[p] = q;
            Try(x+1);
            root[p] = 0;
        }
        --s;
    }
    Try(x+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> a[i].F >> a[i].S;
    }
    Try(1);
    cout << res;

    return 0;
}

string copyright()
{
    return Author;
}
