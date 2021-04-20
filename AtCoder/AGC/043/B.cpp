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

vector<int> f(1000010);
void init(){
    for(int i=1; i<=1000000; i++){
        int cur = i;
        while(cur % 2 == 0) cur /= 2, f[i]++;
    }
    for(int i=1; i<=1000000; i++){
        f[i] += f[i - 1];
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; string s; cin>>n>>s;

    for(int i=0; i<n; i++) s[i]--;

    init();

    int ret = 0;
    for(int i=0; i<n; i++){
        int cnt2 = f[n - 1] - (f[n - 1 - i] + f[i]);
        if(cnt2 > 0) continue;
        ret += s[i] - '0';
        ret %= 2;
    }

    if(ret == 1){
        cout << 1 << endl;
        return 0;
    }

    bool exist1 = false;
    for(int i=0; i<n; i++){
        if(s[i] == '1') exist1 = true;
    }

    if(exist1){
        cout << 0 << endl;
        return 0;
    }

    ret = 0;
    for(int i=0; i<n; i++){
        int cnt2 = f[n - 1] - (f[n - 1 - i] + f[i]);
        if(cnt2 > 0) continue;
        ret += (s[i] - '0') / 2;
        ret %= 2;
    }

    if(ret == 1) cout << 2 << endl;
    else cout << 0 << endl;

    return 0;
}