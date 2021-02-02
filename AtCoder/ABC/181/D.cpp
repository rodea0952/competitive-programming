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
    vector<int> cnt(10, 0);
    for(int i=0; i<s.size(); i++){
        cnt[s[i] - '0']++;
    }

    bool can_make = false;
    if(s.size() == 1){
        can_make = cnt[8] == 1;
    }
    else if(s.size() == 2){
        if(stoi(s) % 8 == 0) can_make = true;
        swap(s[0], s[1]);
        if(stoi(s) % 8 == 0) can_make = true;
    }
    else{
        for(int i=100; i<1000; i++){
            string cur = to_string(i);
            if(count(all(cur), '0')) continue;
            if(i % 8 != 0) continue;

            bool valid = true;
            vector<int> need(10, 0);
            for(auto j : cur) need[j - '0']++;
            for(int j=1; j<=9; j++){
                if(need[j] > cnt[j]) valid = false;
            }
            if(valid) can_make = true;
        }
    }

    cout << (can_make ? "Yes" : "No") << endl;

    return 0;
}