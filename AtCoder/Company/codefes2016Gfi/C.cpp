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
    vector<int> digit(35, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        for(ll j=0; j<32; j++){
            if(a[i] & (1LL << j)){
                digit[j]++;
            }
        }
    }

    int ans = 0;
    vector<bool> used(n, false);
    for(ll i=30; i>=0; i--){
        bool valid = false;
        ll num = (1LL << i);
        if(digit[i] % 2){
            for(int j=0; j<n; j++){
                if(a[j] == num && !used[j]){
                    ans++;
                    valid = true;
                    used[j] = true;
                    for(int k=i-1; k>=0; k--){
                        digit[k]++;
                    }
                    break;
                }
            }
        }
        else{
            valid = true;
        }

        for(int j=0; j<n; j++){
            if(num <= a[j] && !used[j]){
                a[j] -= num;
            }
        }

        if(!valid){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}