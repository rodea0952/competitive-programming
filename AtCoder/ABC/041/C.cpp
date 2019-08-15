#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n; cin>>n;
    vector<P> g(n);
    for(int i=0; i<n; i++) {
        int a; cin>>a;
        g[i] = make_pair(a, i+1);
    }

    sort(g.begin(), g.end());

    for(int i=n-1; i>=0; i--){
        cout << g[i].second << endl;
    }
}