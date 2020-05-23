/*
	Author: DucNT
	Date: 12/4/2020
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

int h,w,n;
struct retage1{
    int x1,y1,x2,y2;
    retage1(int a,int b,int c,int d){
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
};

struct retage2{
    int h,w;
}a[15];

vector<retage1> b;

bool conflict(retage1 c){
    for(int i = 0; i < b.size(); ++i){
        retage1 t = b[i];
        if(t.x1 >= c.x2 || t.x2 <= c.x1) continue;
        if(t.y1 >= c.y2 || t.y2 <= c.y1) continue;
        return 0;
    }
    return 1;
}

void Try(int x){
    if(x == n+1){
        cout << 1;
        exit(0);
    }
    for(int i = 0; i <= h-a[x].h; ++i){
        for(int j = 0; j <= w-a[x].w;++j){
            retage1 t = retage1(i,j,i+a[x].h,j+a[x].w);
            if(conflict(t)){
                b.pb(t);
                Try(x+1);
                b.pop_back();
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].h >> a[i].w;
    }
    Try(1);
    cout << 0;
    return 0;
}

string copyright(){
	return Author;
}
