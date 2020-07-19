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

int n, a[1005],res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1,a+n+1);
    a[n+1] = a[n+2] = a[n+3] = 2000;
    int i = 1;
    while(i <= n){
        if(a[i+2] - a[i] <= 10){
            res++;
            i+=3;
            continue;
        }
        if(a[i+1] - a[i] <= 20){
            res++;
            i+=2;
            continue;
        }
        res++;
        i+=1;
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
