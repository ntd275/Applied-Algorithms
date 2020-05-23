#include <bits/stdc++.h>

using namespace std;

string s[101],p;
int f[100005];
long long res[105];
int n;

void prepare()
{
    s[0] = "0";
    s[1] = "1";
    int x = min(28,n);
    for(int i = 2; i <= x; ++i)
        s[i] = s[i-1]+s[i-2];
    for(int i = 0 ; i <= n; ++i)
    {
        res[i] = -1;
    }
}

void prepareKMP()
{
    int id = 0;
    f[0] = -1;
    f[1] = 0;
    for(int i = 2; i <= p.length(); ++i)
    {
        while(id != -1 && p[i-1] != p[id])
        {
            id = f[id];
        }
        f[i] = ++id;
    }
}

long long KMP(string x)
{
    int id = 0;
    long long dem = 0;
    for(int i = 0; i < x.length(); ++i)
    {
        while(id != -1 && x[i] != p[id])
        {
            id = f[id];
        }
        if(++id == p.length())
        {
            id = f[id];
            ++dem;
        }
    }
    return dem;
}

long long calcmid(int x)
{
    while(!s[x].length())
        x-=2;
    int t = p.length()-1;
    string st = s[x-1].substr(max(0,(int)s[x-1].length()-t),min(t,(int)s[x-1].length()))+s[x-2].substr(0,min(t,(int)s[x-2].length()));
    return KMP(st);
}

long long calc(int x)
{
    if(res[x] != -1)
        return res[x];
    if(x <= 28)
        return res[x] = KMP(s[x]);
    long long t1 = calc(x-1);
    long long t2 = calc(x-2);
    long long t3 = calcmid(x);
    return res[x] = t1 + t2 + t3;
}

int main()
{
    int dem = 0;
    while(cin >> n >> p)
    {
        prepare();
        prepareKMP();
        cout <<"Case "<< ++dem << ": " <<calc(n) << '\n';
    }
    return 0;
}
