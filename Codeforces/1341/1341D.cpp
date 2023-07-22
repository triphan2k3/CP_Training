#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define TASK "1341D"
using namespace std;
const int N=200000;
const int khuon[10]={119,18,93,91,58,107,111,82,127,123};
int a[4000];
int f[2009][12][2009],tmp[2009][2009],proc[2009][20];

void _cin(int _i) {
    string s;
    cin >> s;
    int k=0;
    int j=0;
    FOR(i, 0, 6)
        if (s[i]=='1') k+=1<<(6-i);
    a[_i]=k;
}
int numbit(int i)
{
    int j=0;
    while (i)
    {
        if (i%2) j++;
        i/=2;
    }
    return j;
}
int same(int i, int j)
{
    i=i & j;
    return numbit(i);
}
void setup() {
    FOR(i, 0, (1<<7)-1)
        FOR(j, 0, 9)
            proc[i][j]=-1;
    FOR(i, 0, (1<<7)-1) {
        int v=numbit(i);
        FOR(j, 0, 9)

            if (same(i,khuon[j]) == v) proc[i][j] = numbit(khuon[j]) - v;
        }
}

int main()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   //numbit(118);
   // same(118,123);

    setup();

        int n,k;
        cin >> n >> k;
        FOR(i, 1, n)
            _cin(i);
        tmp[n+1][k]=1;
        for (int i=n; i>=1; i--)
        {

            for (int j=0; j<=k; j++)
                for (int x=0;x<=9;x++) {
                    int add = proc[a[i]][x];
                    //if (add==-1 || j+add>k)
                       if (add<0) continue;

                    f[i][x][j]=tmp[i+1][j+add];
                    if (f[i][x][j]) tmp[i][j]=1;
                }
        }
        if (tmp[1][0]==0)
        {
            cout<<"-1\n";
            return 0;
        }
        int co=0;
        string s="";
        for (int i=1;i<=n;i++)
            for (int x=9;x>=0;x--)
                if (f[i][x][co] && proc[a[i]][x]>=0) {
                    co+=proc[a[i]][x];
                    s=s+(char)(x+'0');
                    break;
                }
        int start=-1;
        FOR(i,0,s.size()-1)
            if (s[i]!='0') {
                start=i;
                break;
            }
        if (start==-1) cout<<0;
        else
            FOR(i,start,s.size()-1)
                cout<<s[i];
        //cout<<"\n";


}
