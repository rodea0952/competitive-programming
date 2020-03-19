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

    vector<int> kaburin_return(n+10, 0);
    vector<int> C(n+10, 0);
    int kaburin = 5;
    ll ans = 0, charge = 0;
    for(int i=0; i<n; i++){
        kaburin += kaburin_return[i];
        if(0 < i) C[i] += C[i - 1];

        if(0 < charge){
            charge--;
            continue;
        }

        if(s[i] == 'N'){
            if(1 <= kaburin){
                kaburin--;
                kaburin_return[i + 7]++;
                C[i + 2]++;
                ll damage = (10 + C[i] / 10);
                ans += damage;
            }
        }
        else if(s[i] == 'C'){
            if(3 <= kaburin){
                kaburin -= 3;
                kaburin_return[i + 9] += 3;
                C[i + 4]++;
                ll damage = (50 + C[i] / 10 * 5);
                ans += damage;
                charge += 2;
            }
        }
    }

    cout << ans << endl;

    return 0;
}