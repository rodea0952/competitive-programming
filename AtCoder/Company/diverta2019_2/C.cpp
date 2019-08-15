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

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    vector<P> seq;
    vector<bool> used(n, false);
    for(int i=n-2; i>0; i--){
        if(0 <= a[i] && !used[i]){
            used[i] = true;
            seq.emplace_back(a[0], a[i]);
            a[0] -= a[i];
        }
        else break;
    }

    for(int i=0; i<n-1; i++){
        if(a[i] <= 0 && !used[i]){
            used[i] = true;
            seq.emplace_back(a[n-1], a[i]);
            a[n-1] -= a[i];
        }
        else break;
    }

    cout << a[n-1] << endl;
    for(auto i:seq){
        cout << i.fs << " " << i.sc << endl;
    }
}