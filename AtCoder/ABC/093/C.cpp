#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int a, b, c; cin>>a>>b>>c;
    int x = max({a, b, c});

    if((a + b + c) % 2 == x % 2) cout << (3 * x - (a + b + c)) / 2 << endl;
    else cout << (3 * (x + 1) - (a + b + c)) / 2 << endl;
}