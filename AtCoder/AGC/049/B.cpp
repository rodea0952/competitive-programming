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
    string s, t; cin>>s>>t;

    queue<int> a, b;
    for(int i=0; i<n; i++){
        if(s[i] == '1') a.emplace(i);
        if(t[i] == '1') b.emplace(i);
    }

    if(a.size() < b.size()){
        cout << -1 << endl;
        return 0;
    }

    if((b.size() - a.size()) % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    while(b.size()){
        int i = b.front(); b.pop();
        while(a.size() && a.front() < i){
            if(a.size() < 2){
                cout << -1 << endl;
                return 0;
            }
            int head = a.front(); a.pop();
            int tail = a.front(); a.pop();
            ans += tail - head;
        }

        if(!a.size()){
            cout << -1 << endl;
            return 0;
        }

        ans += a.front() - i;
        a.pop();
    }

    if(a.size() % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    while(2 <= a.size()){
        int head = a.front(); a.pop();
        int tail = a.front(); a.pop();
        ans += tail - head;
    }

    cout << ans << endl;

    return 0;
}