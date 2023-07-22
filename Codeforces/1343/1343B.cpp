#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200001;
int a[N],b[N];
int n,t;

int main()
{
    cin >> t;
    b[0] = -1;
    for (int i=1; i<=100000; i++) {
        a[i] = a[i-1]+2;
        b[i] = b[i-1]+2;
    }
    while (t--) {
        cin >> n;
        if (n % 4) {
            cout << "NO\n";
            continue;
        }
        n /= 2;
        ll sum=1LL*(a[1] + a[n])*n/2 - 1LL*(b[1] + b[n-1])*(n-1)/2;
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        for (int i = 1; i < n; i++)
            cout << b[i] << " ";
        cout << sum << "\n";


    }
}

