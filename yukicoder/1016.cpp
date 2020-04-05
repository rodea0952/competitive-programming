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

    vector<string> win = {"ooo", "-oo", "oo-", "-o--", "--o-"};

    string base = "o-";
    for(int i=0; i<1000; i++){
        win.emplace_back(base + "o");
        base += "--";
    }

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        bool valid = false;
        for(int i=0; i<win.size(); i++){
            if(s.find(win[i]) != string::npos){
                valid = true;
            }
        }

        cout << (valid ? "O" : "X") << endl;
    }

    return 0;
}