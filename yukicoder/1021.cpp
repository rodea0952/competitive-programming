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
    deque<int> que;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        que.emplace_back(a);
    }
    string s; cin>>s;

    for(auto i:s){
        if(i == 'L'){
            int val1 = que.front(); que.pop_front();
            int val2 = que.front(); que.pop_front();
            que.push_front(val1 + val2);
            que.push_back(0);
        }
        else{
            int val1 = que.back(); que.pop_back();
            int val2 = que.back(); que.pop_back();
            que.push_back(val1 + val2);
            que.push_front(0);
        }
    }

    int cnt = 0;
    for(auto i:que){
        if(cnt == n - 1) cout << i << endl;
        else cout << i << " ";
    }

    return 0;
}