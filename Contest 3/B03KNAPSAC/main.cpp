#include <bits/stdc++.h>

using namespace std;

int n,b;
pair < int , int > a[31];
int f[31][1000001];

int main()
{
    cin >> n >> b;
    for(int i = 1; i <= n ; i++)
        cin >> a[i].first >> a[i].second;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= b; j++){
            f[i][j]=f[i-1][j];
            if(j >= a[i].first)
                f[i][j] = max(f[i][j],f[i-1][j-a[i].first]+a[i].second);
        }
    }
    cout << f[n][b];
}
