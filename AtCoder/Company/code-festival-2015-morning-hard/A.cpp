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

    int n; cin>>n;
    deque<pair<ll, int>> deq;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(i % 2 == 0) deq.emplace_back(a, 0);
        else deq.emplace_back(a, 1);
    }

    int cnt = 0;
    ll ans = 0;
    while(deq.size() != 1){
        ll sum = 0, cur = 0;
        int dif = cnt % 2, same = (cnt + 1) % 2;
        if(deq.front().second == dif && deq.back().second == dif){
            if(deq.front().first < deq.back().first){
                sum = cur = deq.front().first; deq.pop_front();
                sum += deq.front().first; deq.pop_front();
                sum++;
                deq.emplace_front(sum, same);
            }
            else{
                sum = cur = deq.back().first; deq.pop_back();
                sum += deq.back().first; deq.pop_back();
                sum++;
                deq.emplace_back(sum, same);
            }
        }
        else if(deq.front().second == dif){
            sum = cur = deq.front().first; deq.pop_front();
            sum += deq.front().first; deq.pop_front();
            sum++;
            deq.emplace_front(sum, same);
        }
        else{
            sum = cur = deq.back().first; deq.pop_back();
            sum += deq.back().first; deq.pop_back();
            sum++;
            deq.emplace_back(sum, same);
        }

        cnt++;
        ans += cur;
    }

    cout << ans << endl;

    return 0;
}