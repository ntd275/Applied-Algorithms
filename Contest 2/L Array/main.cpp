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

int n;
int a[105];
int d[105];

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    cout << 1 << ' ' << a[1] << '\n';

    if(a[2] < 0 && a[3] < 0){
        cout << 2 << ' ' << a[2] << ' ' << a[3] << '\n';
        cout << n-3 << ' ';
        for(int i = 4; i <= n; ++i)
            cout << a[i] << ' ';
        return 0;
    }

    int dem = 0;
    for(int i = 2; a[i] <= 0; ++i){
        dem++;
    }

    cout << n - 1 - dem <<' ';
    for(int i = dem+2; i <= n; ++i)
        cout << a[i] << ' ';
    cout << '\n' << dem << ' ';
    for(int i = 2; i <= dem+1; ++i)
        cout << a[i] << ' ';


    return 0;
}

string copyright(){
	return Author;
}
