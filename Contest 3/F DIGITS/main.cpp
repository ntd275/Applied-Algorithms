#include <bits/stdc++.h>

using namespace std;

int n,a[9],d[10],res;

bool check(){
    int t = a[1]*100+a[2]*10+a[3]-a[7]*100-62+a[4]*1000+a[5]*100+a[6]*10+a[3];
    return t == n;
}

void Try(int x){
    if(x == 8) {
        if(check()) ++res;
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(!d[i]){
            d[i] = 1;
            a[x] = i;
            Try(x+1);
            d[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    cout << res;
    return 0;
}
