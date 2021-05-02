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

    string s; cin>>s;

    int rev = 0;
    deque<char> deq;
    for(auto i : s){
        if(i == 'R'){
            rev ^= 1;
            continue;
        }

        if(deq.empty()){
            deq.emplace_back(i);
            continue;
        }

        if(rev == 0){
            if(deq.back() == i) deq.pop_back();
            else deq.emplace_back(i);
        }
        else{
            if(deq.front() == i) deq.pop_front();
            else deq.emplace_front(i);
        }
    }

    string ans = "";
    for(auto i : deq) ans += i;
    
    if(rev) reverse(all(ans));

    cout << ans << endl;

    return 0;
}