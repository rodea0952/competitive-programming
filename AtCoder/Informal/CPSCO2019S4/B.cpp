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
    int n, d; cin>>n>>d;
    vector<string> s(d);
    for(int i=0; i<d; i++) cin>>s[i];

    vector<int> v(d);
    v[d-2] = v[d-1] = 1;

    int ans=0;
    do{
        int sum=0;
        vector<bool> valid(n, false);
        for(int i=0; i<d; i++){
            if(v[i]){
                for(int j=0; j<n; j++){
                    if(s[i][j] == 'o'){
                        valid[j] = true;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            sum += valid[i];
        }

        chmax(ans, sum);

    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}