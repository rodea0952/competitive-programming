#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    // dp[i] := 長さが i+1 であるような増加部分列における最終要素の最小値
    vector<int> dp(n, 1e9);
    for(int i=0; i<n; i++){
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }

    cout << lower_bound(dp.begin(), dp.end(), 1e9) - dp.begin() << endl;
}