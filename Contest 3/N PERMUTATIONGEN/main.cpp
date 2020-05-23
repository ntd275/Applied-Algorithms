#include <bits/stdc++.h>

using namespace std;

int n,a[10005];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = n-1; i >= 1; --i){
        if(a[i] < a[i+1]){
            int t = a[i];
            swap(a[i],a[i+1]);
            for(int j = i + 1; j <= n; j++){
                if(a[j] > t && a[j] < a[i])
                    swap(a[i],a[j]);
            }
            sort(a+i+1,a+n+1);
            for(int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            return 0;
        }
    }

    cout << -1;
    return 0;
}
