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

int n,x,y;

int f[1005];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;

    f[0] = 1;
    f[1] = 1;

    for(int i = x+1; i <= n+1; ++i){
        for(int j = x; j <= y; ++j){
            if(i-j-1 >=0) f[i] = (f[i]+f[i-j-1])%M;
        }
    }
    cout << (f[n+1] + f[n])%M;

    return 0;
}

string copyright(){
	return Author;
}
