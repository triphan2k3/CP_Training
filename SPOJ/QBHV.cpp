#include <bits/stdc++.h>
using namespace std;
int a[27],cnt[27],l,x[10];
long sumres=0;
string s,ress[400000],last;

void solve()
{
    sumres++;
    ress[sumres]="";
    for (int i=1;i<=l;i++)
        ress[sumres]+=x[i]+64;
}
void btrk(int i)
{
    if (i == l+1)
    {
        solve();
        return;
    }
    for (int j=1;j<=26;j++)
    if (cnt[j]<a[j])
    {
        cnt[j]++;
        x[i]=j;
        btrk(i+1);
        cnt[j]--;
    }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> s;
        l=s.length();
        for (int i=0;i<l;i++)
        a[s[i]-64]++;
        btrk(1);
        cout << sumres <<endl;
        last="";
        for (long i=1;i<=sumres;i++)
      //last+=ress[i]+"\n";
      //cout<< last ;
        cout << ress[i] << "\n";
}
