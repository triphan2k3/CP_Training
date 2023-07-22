#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define TASK "1341C"
using namespace std;
const int N=200000;
int a[N],pos[N];
int n,t,ok;
int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin>>t;
    while (t--) {
        ok=1;
        cin >> n;
        FOR(i,1,n) {
            cin >> a[i];
            pos[a[i]]=i;
        }
        int last=n;
        int now=1;
        while (1) {
            int _last=pos[now]-1;
            for (int i=pos[now]; i<=last;i++) {
                    if (a[i] != now) { ok=0; break; }
                    now++;
                }
            last=_last;
            if (ok==0 || now==n+1) break;
        }
        if (ok) cout<< "Yes\n";
        else cout<<"No\n";
    }
}
