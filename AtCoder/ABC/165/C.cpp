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

int n, m, q;
vector<int> a(60), b(60), c(60), d(60);
int ans;

void dfs(int num, int level, vector<int> &A){

    if(level == n){
        int sum = 0;
        for(int i=0; i<q; i++){
            if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        chmax(ans, sum);
        return ;
    }

    for(int i=num; i<=m; i++){
        A.emplace_back(i);
        dfs(i, level + 1, A);
        A.pop_back();
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>q;
    for(int i=0; i<q; i++) cin>>a[i]>>b[i]>>c[i]>>d[i], a[i]--, b[i]--;

    vector<int> A;
    dfs(1, 0, A);

    cout << ans << endl;

    return 0;
}
