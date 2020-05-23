#include <bits/stdc++.h>

using namespace std;

int k,n;

long long f[1002][1002];

int main()
{
    cin >> k >> n;
    for(int i = 0; i <= n; i++){
        f[0][i] = f[i][i] = 1;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++)
            if(i <= j)
            f[i][j] = (f[i][j-1] + f[i-1][j-1])%1000000007;
    }
    cout << f[k][n];
    return 0;
}
