#include <bits/stdc++.h>

using namespace std;

int n,k;
long long res = 0;
struct point{
    int x,m;
} a[1002];

bool cmp(point a, point b){
    return a.x < b.x;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i<= n; i++)
        cin >> a[i].x >> a[i].m;
    sort(a+1,a+n+1,cmp);
    for(int i = n; a[i].x > 0; i--){
        int t = (a[i].m-1)/k + 1;
        res += (1ll*t*a[i].x) << 1;
        int r = k - (a[i].m-1)%k - 1;
        while(r > 0 && a[i-1].x > 0){
            int temp = a[i-1].m;
            a[i-1].m = max(0,temp-r);
            r = max(0,r-temp);
            if(a[i-1].m == 0) i--;
        }
    }

    for(int i = 1; a[i].x < 0; i++){
        int t = (a[i].m-1)/k + 1;
        res += (-1ll*t*a[i].x) << 1;
        int r = k - (a[i].m-1)%k - 1;
        while(r > 0 && a[i+1].x < 0){
            int temp = a[i+1].m;
            a[i+1].m = max(0,temp-r);
            r = max(0,r-temp);
            if(a[i+1].m == 0) i++;
        }
    }
    cout << res;
}
