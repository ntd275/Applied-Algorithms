#include <bits/stdc++.h>

using namespace std;

int n;
char a[10004];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = n; i >= 1; --i){
        if(a[i] == '0'){
            a[i] = '1';
            for(int j = 1; j <= n; ++j)
                cout << a[j];
            return 0;
        }
        else
            a[i] = '0';
    }
    cout << -1;
    return 0;
}
