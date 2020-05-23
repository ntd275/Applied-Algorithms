#include <bits/stdc++.h>

using namespace std;

int a[100005],n,q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<= n; i++)
        cin >> a[i];
    int res = 1;
    for(int i = 2; i<= n; i++)
        if(a[i] != a[i-1])
            res++;
    cin >> q;
    for(int i = 1; i<= q; i++)
    {
        int p,c;
        cin >> p >> c;
        if(p != 1){
            if(a[p]== a[p-1]) res++;
            if(c == a[p-1]) res--;
        }
        if(p != n){
            if(a[p] == a[p+1]) res++;
            if(c == a[p+1]) res--;
        }
        a[p] = c;
        cout << res << endl;
    }
    return 0;
}
