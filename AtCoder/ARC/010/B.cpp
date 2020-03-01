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

    vector<bool> is_holiday(366, false);
    for(int i=0; i<366; i++){
        if(i % 7 == 0 || i % 7 == 6) is_holiday[i] = true;
    }

    map<string, int> md2num;
    int cnt = 0;
    for(int i=1; i<=12; i++){
        int d = -1;
        if(i == 2) d = 29;
        else if(i == 4 || i == 6 || i == 9 || i == 11) d = 30;
        else d = 31;

        for(int j=1; j<=d; j++){
            string s = to_string(i) + '/' + to_string(j);
            md2num[s] = cnt++;
        }
    }

    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        int num = md2num[s];
        while(num < 366){
            if(!is_holiday[num]){
                is_holiday[num] = true;
                break;
            }
            num++;
        }
    }

    int ans = 0;
    for(int i=0; i<366; i++){
        int cur = 0;
        while(i < 366 && is_holiday[i]){
            cur++;
            i++;
        }
        chmax(ans, cur);
    }

    cout << ans << endl;

    return 0;
}