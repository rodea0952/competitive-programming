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

int n;
vector<string> s(100010);
vector<char> ans(100010);

void dfs(int idx, int a, int b, int c){
    if(a < 0 || b < 0 || c < 0) return ;
    
    if(idx == n){
        cout << "Yes" << endl;
        for(int i=0; i<n; i++) cout << ans[i] << endl;
        exit(0);
    }

    if(s[idx] == "AB"){
        ans[idx] = 'A';
        dfs(idx + 1, a + 1, b - 1, c);
        ans[idx] = 'B';
        dfs(idx + 1, a - 1, b + 1, c);
    }
    else if(s[idx] == "AC"){
        ans[idx] = 'A';
        dfs(idx + 1, a + 1, b, c - 1);
        ans[idx] = 'C';
        dfs(idx + 1, a - 1, b, c + 1);
    }
    else{
        ans[idx] = 'B';
        dfs(idx + 1, a, b + 1, c - 1);
        ans[idx] = 'C';
        dfs(idx + 1, a, b - 1, c + 1);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c; cin>>n>>a>>b>>c;
    for(int i=0; i<n; i++) cin>>s[i];

    dfs(0, a, b, c);

    cout << "No" << endl;

    return 0;
}
