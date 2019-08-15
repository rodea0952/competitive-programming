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
    int a, b;
    while(cin>>a>>b){
        vector<int> deg(110, 0);
        deg[a]++;
        deg[b]++;
        while(1){
            cin>>a>>b;
            if(a == 0) break;
            deg[a]++;
            deg[b]++;
        }

        bool valid = true;
        if(deg[1] % 2 == 0) valid = false;
        if(deg[2] % 2 == 0) valid = false;

        for(int i=3; i<105; i++){
            if(deg[i] % 2 == 1) valid = false;
        }

        if(valid){
            cout << "OK" << endl;
        }
        else{
            cout << "NG" << endl;
        }
    }
}