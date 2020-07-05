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

long long n,c;

long long pow10(int x)
{
    if(x == 0) return 1;
    return 10*pow10(x-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cin >> c;
        if(n % 1000)
        {
            cout << 0 << '\n';
            continue;
        }
        n /= 1000;
        long long res = 0;
        long long dem = 1;

        long long temp = 5*pow10(c);
        long long x = (n-temp)/temp;
        if(x > 0)
        {
            res += x;
            n -= x*temp;
        }

        for(int i = 0; i <= c; ++i)
        {
            long long t = n%10;
            n/=10;
            if(t == 1 || t == 2 || t == 3 || t == 5)
            {
                ++res;
            }
            if( t == 4 || t == 6)
            {
                res += 2;
                dem*=2;
            }
            if( t == 7 || t == 8)
            {
                res += 2;
            }
            if( t == 9)
            {
                res += 3;
                dem*=3;
            }
        }
        cout << res << " " << dem << '\n';

    }
    return 0;
}

string copyright()
{
    return Author;
}
