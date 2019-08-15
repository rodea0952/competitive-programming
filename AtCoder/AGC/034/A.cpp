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
    int n, a, b, c, d; cin>>n>>a>>b>>c>>d;
    a--, b--, c--, d--;
    string s; cin>>s;
    bool valid = true;
    for(int i=a+1; i+1<c; i++){
        if(s[i] == '#' && s[i+1] == '#') valid = false;
    }

    for(int i=b+1; i+1<d; i++){
        if(s[i] == '#' && s[i+1] == '#') valid = false;
    }

    if(!valid){
        cout << "No" << endl;
    }
    else{
        if(a < b && b < c && c < d){
            cout << "Yes" << endl;
        }
        else if(a < c && c < b && b < d){
            cout << "Yes" << endl;
        }
        else{
            bool jump = false;
            for(int i=b-1; i+2<n && i+1<=d; i++){
                if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                    jump = true;
                }
            }

            if(jump){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}
