#include <bits/stdc++.h>
#define PI 3.141592653589793

using namespace std;

int n,f;
double a[10005];

int check(double x)
{
    long long dem = 0;
    for(int i = 1; i <= n; ++i)
    {
        dem += (long long) (PI*a[i]*a[i]/x);
    }
    return dem >= f+1;
}

double solve()
{
    double l = 0,r = 1e8*PI;

    while(r - l > 1e-6)
    {
        double mid = (l+r)/2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> f;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        printf("%0.6f\n",solve());
    }
    return 0;
}
