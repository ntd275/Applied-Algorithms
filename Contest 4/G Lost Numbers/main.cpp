#include <bits/stdc++.h>

using namespace std;

int a[5],b[7],c[7]={0,4,8,15,16,23,42},d[7];

void check(){
    if(b[1]*b[2] == a[1] && b[2]*b[3] == a[2] && b[4]*b[5] == a[3] && b[5]*b[6] == a[4]){
        cout << "! ";
        for(int i = 1;i <= 6; ++i)
            cout << b[i] << ' ';
        exit(0);
    }
}

void Try(int x){
    if(x == 7) {
        check();
        return;
    }
    for(int i = 1; i <= 6; ++i)
        if(!d[i]){
            d[i] = 1;
            b[x] = c[i];
            Try(x+1);
            d[i] = 0;
        }
}

int main()
{
    cout << "? 1 2\n";
    cin >> a[1];
    cout << "? 2 3\n";
    cin >> a[2];
    cout << "? 4 5\n";
    cin >> a[3];
    cout << "? 5 6\n";
    cin >> a[4];
    Try(1);
    return 0;
}
