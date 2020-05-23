#include <bits/stdc++.h>

using namespace std;

int a[1000001],n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
