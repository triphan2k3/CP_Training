/*
                                 _ _  _| _   |_     |_  _  _  _ |   _  _|_ _
                                (_(_)(_|(/_  |_)\/  | |(_)| |(_||\/(_|_|| (/_
                                                /             _| /
*/
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
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n;
int IT[4*N];
int get(int i,int L,int R,int l,int r)
{
    if (L>=l && R<=r) return IT[i];
    if (L>r || R<l) return 0;
    if (L==R) return IT[i];
    int M=(L+R)>>1;
    int gl=get(i*2,L,M,l,r);
    int gr=get(i*2,M+1,R,l,r);
}
void update(int i,int L,int R,int l,int r)
{
    if (L>=l && R<=r) return IT[i];
    if (L>r || R<l) return 0;
    if (L==R) return IT[i];
    int M=(L+R)>>1;
    int gl=get(i*2,L,M,l,r);
    int gr=get(i*2,M+1,R,l,r);
}
int main()
{
    freopen(inp,"r",stdin);
    freopen(out,"w",stdout);

}
