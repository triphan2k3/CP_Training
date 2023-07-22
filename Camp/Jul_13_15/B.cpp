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
int X, Y;
 
bool inside(int u){
    return (u >= X) && (u <= Y);
}
 
int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int> s(m + 1);
    for (int i =  1; i <= m; i++){
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
 
    cin >> X >> Y;
    int ans = 0;
    for (int k = 1; k <= m; k++)
        if (inside(s[k]) && inside(s[m] - s[k])){
            ans = k + 1;
            break;
        }
    
    cout << ans;
    
    return 0;
}