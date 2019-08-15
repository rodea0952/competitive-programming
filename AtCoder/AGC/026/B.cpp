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
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

ll gcd(ll x, ll y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main(){
    int t; cin>>t;
    while(t--){
        ll a, b, c, d; cin>>a>>b>>c>>d;

        if(a < b || d < b){
            cout << "No" << endl;
            continue;
        }

        ll g = gcd(b, d);
        a %= g;

        ll num;
        if((c - a) < 0){
            if((c - a) % g == 0){
                num = (c - a) / g + 1;
            }
            else{
                num = (c - a) / g;
            }
        }
        else{
            num = (c - a) / g + 1;
        }

        ll MIN = a + g * num;

        cout << (b <= MIN ? "Yes" : "No") << endl;
    }
}