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

int n,res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
    n = 1000 - n;
    int a[] = {500,100,50,10,5,1};
    for(int i = 0; i < 6; ++i){
        while(n >= a[i]){
            n-= a[i];
            ++res;
        }
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
