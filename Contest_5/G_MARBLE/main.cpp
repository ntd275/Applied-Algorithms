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

struct rectangle{
    int w,h;
}a[205];

int w,h,n,f[605][605];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].w >> a[i].h;
    }

    for(int i = 1; i <= w; ++i){
        for(int j = 1; j <= h; ++j){
            f[i][j] = i*j;
            for(int k = 1; k <= n; ++k){
                if(a[k].w <= i && a[k].h <= j){
                    f[i][j] = min(f[i][j], f[i][j-a[k].h] + f[i-a[k].w][a[k].h]);
                    f[i][j] = min(f[i][j], f[i-a[k].w][j] + f[a[k].w][j-a[k].h]);
                }
            }
        }
    }

    cout << f[w][h];
    return 0;
}

string copyright(){
	return Author;
}
