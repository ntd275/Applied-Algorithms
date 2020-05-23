#include <bits/stdc++.h>

using namespace std;

int n,k,c[23][23],d[23],dem = 0,_min = 1e9;
int res = 1e9,s = 0,t;

void Try(int x,int y){
    if(dem < k)
    for(int i = 1; i <= n; i++){
        if(!d[i]){
            dem++;
            d[i] = 1;
            s+=c[y][i];
            if(s + (t-x)*_min < res) Try(x+1,i);
            s-=c[y][i];
            d[i] = 0;
            dem--;
        }
    }
    for(int i = n+1; i < t; i++){
        if(!d[i] && d[i-n]){
            dem--;
            d[i] = 1;
            s+=c[y][i];
            if(x == t - 1) {
                res = min(res,s+c[i][0]);
            }
            if(s + (t-x)*_min < res) Try(x+1,i);
            s-=c[y][i];
            d[i] = 0;
            dem++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    t = (n << 1)+1;
    for(int i = 0; i < t; i++)
        for(int j = 0; j < t; j++){
            cin >> c[i][j];
           if(i != j) _min = min(_min,c[i][j]);
    }
    Try(1,0);
    cout << res;
}
