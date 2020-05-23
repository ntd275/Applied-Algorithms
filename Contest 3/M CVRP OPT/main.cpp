#include <bits/stdc++.h>

using namespace std;

int n,k,q,d[16],c[6],dem[6],b[16],g[16][16],tt[16];

long long res = 2e18;

long long f[1<<16][16];

bool bit(int x,int y)
{
    return (x >> y) & 1;
}

long long TSP(int a)
{
    long long t = 0,t1 = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(b[i] == a)
        {
            t += (1<<i) ;
            tt[t1++] = i;
        }
    }

    int m = dem[a];

    for(int i = 0; i <= m; ++i)
        for(int j = 0; j < (1 << (m+1)); ++j)
        {
            f[j][i] = 2e18;
        }
    f[1][0] = 0;
    for(int i = 0; i < (1<<(m+1)); ++i)
        for(int j = 0; j <= m; ++j)
        {
            if(bit(i,j))
            {
                for(int u = 1; u <= m; u++)
                {
                    if(!bit(i,u))
                    {
                        int y = i + (1<<u);
                        f[y][u] = min(f[y][u],f[i][j] + g[tt[j]][tt[u]]);
                    }
                }
            }
        }
    long long temp = 2e18;
    for(int i = 1; i <= m; ++i)
        temp = min(temp,f[(1<<(m+1))-1][i]+g[tt[i]][0]);
    return temp;
}

void update()
{
    for(int i = 1; i <= k; ++i)
    {
        if(!dem[i])
            return;
    }

    long long t = 0;
    for(int i = 1; i <= k; ++i)
    {
        t += TSP(i);
    }

    res = min(res,t);
    return;
}

void Try(int x)
{
    if(x == n+1)
    {
        update();
        return;
    }

    for(int i = 1; i <= k; ++i)
    {
        if(c[i] >= d[x])
        {
            b[x] = i;
            c[i] -= d[x];
            ++dem[i];
            Try(x+1);
            --dem[i];
            c[i] += d[x];
        }
    }
}

int main()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= n; ++i)
        cin >> d[i];

    for(int i = 0; i <= n ; ++i)
        for(int j = 0; j <= n; ++j)
        {
            cin >> g[i][j];
        }

    for(int i = 1; i <= k; ++i)
    {
        c[i] = q;
    }

    Try(1);

    cout << res;
    return 0;
}
