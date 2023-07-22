#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, x, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int k = 2; ; k++) {
            ll sl = (1LL << k) - 1;
            if (n % sl == 0){
                cout << n/sl << "\n";
                break;
            }
        }

    }
}
