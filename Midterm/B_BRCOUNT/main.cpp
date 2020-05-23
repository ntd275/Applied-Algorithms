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

string s;

long long f[1005][1005];


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    f[0][1] = 1;
    for(int i = 0 ; i < s.length(); ++i){
        if(s[i] == '('){
            for(int j = 1; j <= 1000;++j){
                f[i+1][j] = f[i][j-1];
            }
            continue;
        }
        if(s[i] == ')'){
            for(int j = 1; j <= 1000; ++j){
                f[i+1][j] = f[i][j+1];
            }
            continue;
        }
        for(int j = 1; j <= 1000;++j){
            f[i+1][j] = (f[i][j-1]+f[i][j+1]) % M;
        }
    }
    cout << f[s.length()][1];
    return 0;
}

string copyright(){
	return Author;
}
