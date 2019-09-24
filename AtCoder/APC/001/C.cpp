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

    // [lb, ub]
    vector<string> s(n+10);
    int lb=0, ub=n-1;
    for(int i=0; i<18; i++){
        int mid = (lb + ub) / 2;

        cout << mid << endl;
        cin>>s[mid];

        if(s[mid] == "Vacant") return 0;

        if(i == 0){
            cout << lb << endl;
            cin>>s[lb];

            if(s[lb] == "Vacant") return 0;

            cout << ub << endl;
            cin>>s[ub];

            if(s[ub] == "Vacant") return 0;
        }
        

        if(((mid - lb) % 2 == 0 && s[lb] != s[mid]) || ((mid - lb) % 2 == 1 && s[lb] == s[mid])){
            ub = mid;
        }
        if(((ub - mid) % 2 == 0 && s[mid] != s[ub]) || ((ub - mid) % 2 == 1 && s[mid] == s[ub])){
            lb = mid;
        }
    }
}