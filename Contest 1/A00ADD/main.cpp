#include <bits/stdc++.h>

using namespace std;

string a,b;

int main()
{
    cin >> a >> b;
    while(a.length() < b.length()) a = '0' + a;
    while(b.length() < a.length()) b = '0' + b;
    int r = 0;
    for(int i = a.length()-1; i >= 0; i--){
        int c = a[i] - '0' + b[i] - '0' + r;
        if(c >= 10) {
            c-= 10;
            r = 1;
        }
        else r = 0;
        a[i] = c + '0';
    }
    if(r == 1) a = '1' + a;
    cout << a;
}
