#include <bits/stdc++.h>
#define TASK "1454F"
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

const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int a[N],l[N],r[N],mL[N],mR[N];
int main() {
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i,1,n)
            cin >> a[i];

        map<int,int> mi,ma;
        FOR(i,1,n) {
            if (!mi[a[i]])
                mi[a[i]]=i;
            mL[i]=max(mL[i-1],a[i]);
        }
        mR[n+1]=0;
        FOD(i,n,1) {
            if (!ma[a[i]])
                ma[a[i]]=i;
            mR[i]=max(mR[i+1],a[i]);
        }

        a[n+1]=0;
        deque<int> q;
        q.push_back(0);
        FOR(i,1,n) {
            while (q.size() && a[q.back()] >= a[i])
                q.pop_back();
            l[i]=q.back()+1;
            q.push_back(i);
        }
        q.clear();
        q.push_back(n+1);
        FOD(i,n,1) {
            while (q.size() && a[q.back()] >= a[i])
                q.pop_back();
            r[i]=q.back()-1;
            q.push_back(i);
        }
        int kt=0;
        FOR(i,1,n) {
            if (mL[l[i]-1] == a[i] && a[i] == mR[r[i]+1]) {
                cout << "YES\n"
                     << l[i]-1 << " "
                     << r[i]-l[i]+1 << " "
                     << n-r[i] << "\n";
                kt=1;
                break;
            }
            int lef=-1,rig=-1;
            if (mL[l[i]-1] == a[i])
                lef=l[i]-1;
            else
                if ((mi[a[i]] < l[i]) || mi[a[i]] == i) continue;
            else
                if (mL[mi[a[i]]] == a[i])
                lef=mi[a[i]];
            else continue;

            if (mR[r[i]+1] == a[i])
                rig=r[i]+1;
            else
                if ((ma[a[i]] > r[i]) || ma[a[i]] == i) continue;
            else
                if (mR[ma[a[i]]]==a[i])
                rig=ma[a[i]];
            else continue;
            kt=1;
            cout << "YES\n"
                 << lef << " "
                 << rig-lef-1 << " "
                 << n-rig+1 << "\n";
            break;
        }
        if (kt==0)
            cout << "NO\n";
    }

}
