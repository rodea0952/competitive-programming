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

    if(n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }

    vector<int> ans;
    ll sum=0;
    for(int i=2; i<=30000; i++){
        if(i % 2 == 0 || i % 3 == 0){
            ans.push_back(i);
            sum += i;
        }

        if(ans.size() == n-2){
            break;
        }
    }

    for(int i=30000; i>=2; i--){
        if(!(i % 2 == 0 || i % 3 == 0)) continue;
        for(int j=30000; j>=2; j--){
            if(i == j) continue;
            if(!(j % 2 == 0 || j % 3 == 0)) continue;
            if(i == *lower_bound(ans.begin(), ans.end(), i)) continue;
            if(j == *lower_bound(ans.begin(), ans.end(), j)) continue;
            
            if((sum + i + j) % 6 == 0){
                ans.push_back(i);
                ans.push_back(j);
                goto END;
            }
        }
    }

    END:;

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}
