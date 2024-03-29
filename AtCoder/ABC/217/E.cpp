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

    int q; cin >> q;
    queue<int> que;
    priority_queue<int, vector<int>, greater<int>> pque;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            que.emplace(x);
        }
        else if(op == 2){
            if(pque.size()){
                cout << pque.top() << endl;
                pque.pop();
            }
            else{
                cout << que.front() << endl;
                que.pop();
            }
        }
        else{
            while(que.size()){
                pque.emplace(que.front());
                que.pop();
            }
        }
    }

    return 0;
}