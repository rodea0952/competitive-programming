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
int dx2[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy2[]={0, -1, -1, -1, 0, 1, 1, 1};

int pos[26];
int dp[(1<<25)];

inline bool isValid(int &bit, int &p){
    if(bit & (1<<p)) return false;
    int y = p/5, x = p%5;

    if(0<y && y<4 && ((bit>>(p-5))^(bit>>(p+5))) & 1) return false;
    if(0<x && x<4 && ((bit>>(p-1))^(bit>>(p+1))) & 1) return false;
    return true;
}

int main(){
    fill(pos, pos+26, -1);
    vector<int> v;
    for(int i=0; i<25; i++){
        int n; cin>>n;
        if(n) pos[n] = i;
        else v.push_back(i);
    }

    dp[0] = 1;

    for(int bit=0; bit<(1<<25)-1; bit++){
        int num = __builtin_popcount(bit) + 1;

        if(pos[num] != -1){
            if(isValid(bit, pos[num])){
                int nbit = bit | (1<<pos[num]);
                dp[nbit] += dp[bit];
                dp[nbit] %= MOD;
            }
        }
        else{
            for(auto to:v){
                if(isValid(bit, to)){
                    int nbit = bit | (1<<to);
                    dp[nbit] += dp[bit];
                    dp[nbit] %= MOD;
                }
            }
        }
    }

    cout << dp[(1<<25)-1] << endl;
}