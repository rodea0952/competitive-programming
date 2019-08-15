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
    int n, k; cin>>n>>k;

    int num=n;
    vector<int> v;
    for(int i=2; i*i<=n; i++){
        while(num % i == 0){
            v.eb(i);
            num /= i;
        }
    }

    if(num != 1){
        v.eb(num);
    }

    if(k <= v.size()){
        for(int i=0; i<k-1; i++){
            cout << v[i] << " ";
        }
        
        ll ans=1;
        for(int i=k-1; i<v.size(); i++){
            ans *= v[i];
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}