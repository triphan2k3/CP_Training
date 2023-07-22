#include <bits/stdc++.h>
#define TASK ""
#define pb push_back
#define ii pair<int,int>
#define iii pair<ii,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=a; i>b ; i--)
using namespace std;

const int N=(int)1e2+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int ans[N][N];
ii p[4][4];
void nothing() {
    p[1][1]={1,2};
    p[1][3]={3,4};
    p[3][1]={5,6};
    p[3][3]={7,8};
}
void solve(int i,int j,int x) {
    int st=i%4;
    int nd=j%4;
    if (x==0) //dat ngang
    {
        ans[i][j]=ans[i][j+1]=p[st][nd].F;
        ans[i+1][j]=ans[i+1][j+1]=p[st][nd].S;
    } else {
        ans[i][j]=ans[i+1][j]=p[st][nd].F;
        ans[i][j+1]=ans[i+1][j+1]=p[st][nd].S;
    }
}
void write(int x) {
    char v=x+'a';
    cout << v;
}
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    nothing();
    while (t--) {
        int n,m,k;
        cin >> m >> n >> k;
        int xoay=0;
        //n phai chan
        if (n%2==1) {
            swap(m,n);
            k=m*n/2 - k;
            xoay=1;
        }
        int dec=0;
        if (m%2==1) {
            m--;
            k-=n/2;
            dec=1;
        }
        if (k<0) {
            cout <<"NO\n";
            continue;
        }

        if (k%2) {
            cout <<"NO\n";
            continue;
        }
        cout << "YES\n";
        int x=1,y=1;
        for(int i=2;i<=m*n/2;i+=2) {
            int id=i>k ? 1:0;
            solve(x,y,id);
            y+=2;
            if (y>n) {
                x+=2;
                y=1;
            }
        }
        if (dec) {
            ++m;
            for (int i=1;i<=n;i+=2)
                ans[m][i]=ans[m][i+1]=9+i%4;
        }
        if (xoay) {
            FOR(i,1,n) {
            FOR(j,1,m)
                write(ans[j][i]);
            cout << "\n";
            }
        } else {
            FOR(i,1,m) {
            FOR(j,1,n)
                write(ans[i][j]);;
            cout << "\n";
            }
        }

    }
}
