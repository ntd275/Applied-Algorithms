#include <bits/stdc++.h>

using namespace std;

long long f[16],n,k;
int dd[10005],a[10005];

int main()
{
    cin >> n >> k;

    f[0] = 1;
    for(int i = 1; i <= 15; ++i)
        f[i] = i*f[i-1];
    if(n <= 15){
        if(k > f[n]) {
            cout << -1;
            return 0;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        int x = n-i;
        if(x > 15)
        {
            a[i] = i;
            dd[i] = 1;
            continue;
        }

        for(int j = max(1ll,n-15); j <= n; ++j)
        {
            if(!dd[j])
            {
                if(k > f[x])
                    k -= f[x];
                else
                {
                    a[i] = j;
                    dd[j] = 1;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <=n;++i)
        cout << a[i] << ' ';
    return 0;
}
