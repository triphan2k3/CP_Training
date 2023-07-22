/*   2023-07-13   */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int MaxN = (int)(2e6) + 5;
int cnt[MaxN];
int n, k;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    int maxA = -1;
    int minA = INF;
 
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        maxA = max(maxA,x);
        minA = min(minA,x);
        cnt[x]++;
    }
    for (int i = 1; i <= maxA + k; i++) cnt[i] += cnt[i - 1];
 
 
    if (minA <= k + 1) cout << minA;
    else {
        for (int d = minA; d >= 1; d--){
            int num = 0;
            for (int j = d; j <= maxA; j += d)
                num += cnt[j + k] - cnt[j - 1];
            if (num == n){
                cout << d;
                break;
            }
        }
    }
    return 0;
}