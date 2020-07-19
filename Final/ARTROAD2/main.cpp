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

int n,k,dem[5005],l[5005],r[5005],ma,res;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> k;
    for(int i = 1; i <= k; ++i)
        cin >> l[i] >> r[i];
    for(int i = 1; i <= k; ++i)
    for(int j = l[i]; j <= r[i]; ++j){
        dem[j]++;
        if(dem[j] == 1) ma++;
    }
    for(int i = 1; i <= k; ++i){
        int t1 = 0;
        for(int j = l[i]; j <= r[i]; j++){
            dem[j]--;
            if(dem[j] == 0) t1++;
        }
        if(ma-t1 > res)
        for(int j = i+1; j <= k; ++j){
            int t2 = 0;
            for(int x = l[j] ; x <= r[j]; ++x){
                dem[x]--;
                if(dem[x] == 0) t2++;
            }
            res = max(res,ma-t1-t2);
            for(int x = l[j] ; x <= r[j]; ++x){
                dem[x]++;
            }
        }
        for(int j = l[i]; j <= r[i]; j++){
            dem[j]++;
        }
    }
    cout << res;
    return 0;
}

string copyright(){
	return Author;
}
