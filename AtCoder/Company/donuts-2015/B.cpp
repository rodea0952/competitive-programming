#pragma GCC optimize("O3")
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

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> b(m), c(m);
    vector<vector<int>> I(m, vector<int>(n));
    for(int i=0; i<m; i++){
        cin>>b[i]>>c[i];
        for(int j=0; j<c[i]; j++) cin>>I[i][j], I[i][j]--;
    }

    vector<int> perm(n, 0);
    for(int i=0; i<9; i++) perm[i] = 1;
    sort(all(perm));

    int ans = 0;
    do{
        int sum = 0;
        vector<bool> join(n, false);
        for(int i=0; i<n; i++){
            if(perm[i]){
                sum += a[i];
                join[i] = true;
            }
        }

        for(int i=0; i<m; i++){
            int cnt = 0;
            for(int j=0; j<c[i]; j++){
                cnt += join[I[i][j]];
            }
            if(3 <= cnt) sum += b[i];
        }

        chmax(ans, sum);

    }while(next_permutation(all(perm)));

    cout << ans << endl;

    return 0;
}