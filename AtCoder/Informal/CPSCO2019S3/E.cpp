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
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<ll>> digit(n+10, vector<ll>(35, 0));
    vector<vector<ll>> sumdigit(n+10, vector<ll>(35, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=32; j++){
            if(a[i] & (1LL << j)){
                digit[i][j]++;
            }

            sumdigit[i+1][j] = sumdigit[i][j] + digit[i][j];
        }
    }

    for(int i=0; i<n; i++){
        ll ans = 0;
        for(int j=0; j<=32; j++){
            if(sumdigit[i+1][j] % 2 == 1){
                ans += (ll)(i + 1 - sumdigit[i+1][j]) * (1LL << j);
            }
            else{
                ans += sumdigit[i+1][j] * (1LL << j);
            }
        }

        cout << ans << endl;
    }
}