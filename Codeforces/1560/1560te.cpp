#include <bits/stdc++.h>
using namespace std;
bool func(int i,int j) {
    return i>j;
}
int main()
{
    vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
 
    auto m = v.begin() + v.size()/2;
    for(int x:v)
        cout << x << " ";
    cout << "\n";
    nth_element(v.begin(), m, v.end());
    for(int x:v)
        cout << x << " ";
    cout << "\n";
    // The consequence of the inequality of elements before/after the Nth one:
    assert(std::accumulate(v.begin(), m, 0) < std::accumulate(m, v.end(), 0));
 
    nth_element(v.begin(), v.begin()+1, v.end(), func);
    for(int x:v)
        cout << x << " ";
    cout << "\n";
}