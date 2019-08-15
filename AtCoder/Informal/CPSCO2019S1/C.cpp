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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> v(n, 0);
    for(int i=0; i<k; i++){
        v[n-1-i] = 1;
    }

    int ans=1e9;
    do{
        ll sum=0;
        for(int i=0; i<n; i++){
            if(v[i]) sum += a[i];
        }

        int cnt=0;
        ll num=5000000000;
        while(sum > 0){
            while(sum - num >= 0){
                cnt++;
                sum -= num;
            }

            num /= 5;

            while(sum - num >= 0){
                cnt++;
                sum -= num;
            }

            num /= 2;
        }

        chmin(ans, cnt);

    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}