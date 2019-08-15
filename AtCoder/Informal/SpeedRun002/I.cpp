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
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    int num1 = (a[0] + (b[1] - 1)) / b[1];
    int num2 = (a[1] + (b[0] - 1)) / b[0];

    int ans;
    if(num1 > num2){
        ans = 0;
    }
    else if(num1 < num2){
        ans = 1;
    }
    else{
        ans = -2;
    }

    for(int i=2; i<n; i++){
        num1 = (a[max(ans, 0)] + (b[i] - 1)) / b[i];
        num2 = (a[i] + (b[max(ans, 0)] - 1)) / b[max(ans, 0)];

        if(num1 < num2){
            ans = i;
        }
    }

    if(ans == -2){
        cout << ans + 1 << endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        if(i == ans) continue;

        num1 = (a[ans] + (b[i] - 1)) / b[i];
        num2 = (a[i] + (b[ans] - 1)) / b[ans];

        if(num1 <= num2){
            ans = -2;
        }
    }

    cout << ans + 1 << endl;
}