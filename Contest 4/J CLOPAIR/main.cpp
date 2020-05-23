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
struct point{
    double x,y;
    int pos;
}a[100005];
double res = 1e20;
int resl , resr;

double dis(point u,point v){
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

bool cmpy(point x, point y){
    return x.y < y.y;
}

bool cmpx(point x, point y){
    return x.x < y.x;
}

void update(int x,int y){
    double t = dis(a[x],a[y]);
    if(t < res){
        res = t;
        resl = a[x].pos;
        resr = a[y].pos;
    }
}

void mindis(int l,int r){
    if(l >= r){
        return;
    }
    if(r-l == 1){
        update(l,r);
        return;
    }

    int mid = (l+r) >> 1;
    double xmid = a[mid].x;

    mindis(l,mid);
    mindis(mid+1,r);

    sort(a+l,a+r+1,cmpy);
    for(int i = l ; i <= r;++i){
        if(abs(a[i].x-xmid) < res){
            for(int j = i+1; j <= r;++j){
                if(abs(a[j].y-a[i].y) >= res) break;
                update(i,j);
            }
        }
    }
}

int main()
{
	//ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        a[i].pos = i;
    }
    sort(a+1,a+n+1,cmpx);
    mindis(1,n);
    if(resl > resr) swap(resl,resr);
    cout << resl-1 << ' ' << resr-1 << ' ';
    printf("%0.6f",res);
    return 0;
}

string copyright(){
	return Author;
}
