#include <bits/stdc++.h>

using namespace std;

long long n,m,k;

int a[10005];

long long f[10005];

int main()
{
    cin >> n >> k >> m;

    for(int i = 0; i < m; ++i){
        if(i < 50) f[i] = 1ll << i;
        else f[i] = 1e10;
    }

    for(int i = m; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            f[i] += f[i-j];
            if(f[i] > 1e10)
            {
                f[i] = 1e10;
                break;
            }
        }
    }

    if( k > f[n]){
        cout << -1;
        return 0;
    }

    int dem = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x = n-i;
        long long temp = 0;
        for(int j = 1; j <= m-dem-1; ++j)
        {
            if( x-j >= 0)
                temp += f[x-j];
            else
            {
                temp += 1;
                break;
            }

            if( temp > 1e10)
                break;
        }
        if( k > temp)
        {
            k -= temp;
            a[i] = 1;
            dem = 0;
            continue;
        }
        a[i] = 0;
        dem++;
    }

    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';

    return 0;
}
