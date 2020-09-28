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
    int t; cin>>t;

    int lr = 0, ud = 0, q = 0;
    for(auto i:s){
        if(i == 'L') lr--;
        else if(i == 'R') lr++;
        else if(i == 'U') ud++;
        else if(i == 'D') ud--;
        else q++;
    }

    if(t == 1){
        cout << abs(lr) + abs(ud) + q << endl;
    }
    else{
        if(abs(lr) + abs(ud) <= q){
            if((q - (abs(lr) + abs(ud))) % 2 == 0){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        else{
            cout << abs(lr) + abs(ud) - q << endl;
        }
    }

    return 0;
}