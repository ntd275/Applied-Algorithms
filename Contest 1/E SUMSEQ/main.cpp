#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,t,s=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t;
        s = (s + t)%1000000007;
    }
    cout << s;
    return 0;
}
