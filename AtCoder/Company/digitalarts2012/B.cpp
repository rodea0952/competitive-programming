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

    if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz"){
        cout << "NO" << endl;
        return 0;
    }

    if(s.size() == 1){
        cout << 'a' << --s[0] << endl;
        return 0;
    }

    char base = s[0];
    bool all_same = true;
    for(auto i : s){
        if(i != base) all_same = false;
    }

    if(all_same){
        if(base == 'a'){
            cout << (char)('a' + (int)(s.size() - 1)) << endl;
        }
        else if(base == 'z'){
            s[0]--;
            cout << 'a' << s << endl;
        }
        else{
            s[0]++, s[1]--;
            cout << s << endl;
        }
        return 0;
    }

    string t = s;
    for(int i=0; i<s.size(); i++){
        rotate(t.begin(), t.begin() + 1, t.end());
        if(s != t){
            cout << t << endl;
            return 0;
        }
    }

    return 0;
}