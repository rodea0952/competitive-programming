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
    int n; cin>>n;
    map<int, bool> mp;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x] = 0;
    }
    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x] = 1;
    }

    ll cnta=0, cntb=0;
    ll ans=1;
    for(auto i : mp){
        if(i.sc == 0) cnta++;
        else cntb++;

        if(cnta && cntb){
            ans *= cnta * cntb;
            cnta--;
            cntb--;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}