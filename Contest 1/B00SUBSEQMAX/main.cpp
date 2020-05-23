#include <bits/stdc++.h>

using namespace std;

int s[1000001],n;

int main()
{
    cin >> n;
    for(int i = 1;i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    int _min = 0, res = s[1];
    for(int i = 1; i <= n; i++)
    {
        res = max(res, s[i]-_min);
        _min = min(_min,s[i]);
    }
    cout << res;
    return 0;
}
