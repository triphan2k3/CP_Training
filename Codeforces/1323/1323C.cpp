#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inp ".INP"
#define out ".OUT"
using namespace std;
string s;
int n;

int main()
{
    int k=0,L=0,ans=0,last=0;;
    cin>>n>>s;
    for (int i=0;i<s.size();i++)
        L+=s[i]=='(' ? 1:-1;
    if (L!=0)
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<s.size();i++)
    {
        int pre=L;
        L+=s[i]=='(' ? 1:-1;
        if (L>0) continue;
        if (L==0 && pre<0)
            ans+=i-last+1;
        if (L<0 && pre==0)
            last=i;
    }
    cout<<ans;
}
