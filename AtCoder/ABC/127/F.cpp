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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q; cin>>q;

    ll bsum = 0;
    priority_queue<ll> head;
    priority_queue<ll, vector<ll>, greater<ll>> tail;
    ll headsum = 0, tailsum = 0;

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int a, b; cin>>a>>b;
            bsum += b;

            if(head.size() > tail.size()){
                int t = head.top();
                if(t <= a){
                    tail.emplace(a); tailsum += a;
                }
                else{
                    head.pop(); headsum -= t;
                    head.emplace(a); headsum += a;
                    tail.emplace(t); tailsum += t;
                }
            }
            else{
                if(!head.size()){
                    head.emplace(a); headsum += a;
                }
                else{
                    int t = tail.top();
                    if(a <= t){
                        head.emplace(a); headsum += a;
                    }
                    else{
                        tail.pop(); tailsum -= t;
                        tail.emplace(a); tailsum += a;
                        head.emplace(t); headsum += t;
                    }
                }
            }
        }
        else{
            ll x = head.top();
            ll ans = (x * (ll)head.size() - headsum) + (tailsum - x * (ll)tail.size()) + bsum;
            cout << x << " " << ans << endl;
        }
    }
}