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
    int n = s.size();

    // 全て同じ数字
    vector<int> num(n);
    for(int i=0; i<n; i++){
        num[i] = s[i] - '0';
    }

    sort(all(num));

    if(num.front() == num.back()){
        cout << -1 << endl;
        return 0;
    }

    // 先頭が 0 になる
    if(num.front() == 0 && num[n-2] == 0){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<n-1; i++){
        if(num[i] != num[i+1]){
            swap(num[i], num[i+1]);
            break;
        }
    }

    reverse(all(num));
    for(int i=0; i<n; i++){
        cout << num[i];
    }
    cout << endl;

    return 0;
}