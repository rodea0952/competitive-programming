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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    ll n; cin>>n;

    ll ans = 0;
    ll cycle = 10LL;
    for(int digit=1; digit<=10; digit++){
        ans += (n / cycle) * (cycle / 10);
        ll rem = n % cycle;

        if((cycle / 10) <= rem && rem < 2LL * (cycle / 10)){
            ans += rem - (cycle / 10) + 1;
        }
        else if(2LL * (cycle / 10) <= rem){
            ans += (cycle / 10);
        }

        cycle *= 10LL;
    }

    cout << ans << endl;
}