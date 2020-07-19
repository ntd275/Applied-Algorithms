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

int n,m,a[1005],c[1005][1005],res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> c[i][j];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> a[i];
    for(int i = 1; i < m ; ++i)
        res += c[a[i]][a[i+1]];
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
