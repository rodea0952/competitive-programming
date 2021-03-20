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

char judge(char a, char b){
    if(a == b) return a;
    if(a == 'R' && b == 'S') return 'R';
    if(a == 'S' && b == 'R') return 'R';
    if(a == 'S' && b == 'P') return 'S';
    if(a == 'P' && b == 'S') return 'S';
    if(a == 'P' && b == 'R') return 'P';
    if(a == 'R' && b == 'P') return 'P';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    string s; cin>>s;

    while(k--){
        s += s;
        string nxt = "";
        for(int i=0; i<2*n; i+=2){
            nxt += judge(s[i], s[i + 1]);
        }
        s = nxt;
    }

    cout << s[0] << endl;

    return 0;
}