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

int n,r;
int c[105][105];
int m;
int a[105],b[105],dd[105];
int res,s;

void input()
{
    string temp;
    getline(cin,temp);
    int t = 0;
    m = 0;
    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp[i] != ' ')
            t = t*10 + temp[i] - '0';
        else
        {
            a[++m] = t;
            t = 0;
        }
    }
    a[++m] = t;
}

void Try(int x)
{
    if(s >= res) return;
    if(x == m)
    {
        if(c[b[x-1]][a[m]])
            res = min(res,s + c[b[x-1]][a[m]]);
        return;
    }
    for(int i = 2; i < m; ++i)
    {
        if(!dd[i] && c[b[x-1]][a[i]])
        {
            b[x] = a[i];
            dd[i] = 1;
            s+= c[b[x-1]][a[i]];
            Try(x+1);
            s-= c[b[x-1]][a[i]];
            dd[i] = 0;
        }
    }
}


int TSP()
{
    b[1] = a[1];
    res = 1e9;
    Try(2);
    res = res == 1e9 ? 0 : res;
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("inp.txt","r",stdin);
    cin >> n >> r;
    for(int i = 1; i <=n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    string t;
    getline(cin,t);
    for(int i = 1; i <= r; ++i)
    {
        input();
        cout << TSP() << '\n';
    }
    return 0;
}

string copyright()
{
    return Author;
}
