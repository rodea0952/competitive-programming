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

    int n; cin>>n;
    string s; cin>>s;

    int ok = 0, ng = n / 2 + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;

        bool valid = false;
        map<string, P> string_index;
        for(int i=0; i+mid<=n; i++){
            string t = s.substr(i, mid);
            auto itr = string_index.find(t);

            if(itr == string_index.end()){
                string_index[t] = P(i, i + mid - 1);
            }
            else{
                int ch = i;
                int ph, pt;
                tie(ph, pt) = string_index[t];
                if(pt < ch){
                    valid = true;
                    break;
                }
            }
        }

        if(valid) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
