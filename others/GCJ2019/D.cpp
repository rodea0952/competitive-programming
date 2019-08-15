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
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        int r, c; cin>>r>>c;
        if(r == 4 && c == 4){
            cout << "Case #" << i << ": " << "POSSIBLE" << endl;
            int a[16] = {1, 2, 3, 1, 2, 3, 1, 3, 4, 1, 4, 2, 4, 3, 2, 4};
            int b[16] = {1, 3, 1, 2, 4, 2, 3, 4, 2, 4, 3, 2, 1, 3, 1, 4};
            for(int j=0; j<16; j++){
                cout << a[j] << " " << b[j] << endl;
            }
        }
        if(r == c){
            if(r < 4){
                cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
            }
            else{
                cout << "Case #" << i << ": " << "POSSIBLE" << endl;
                for(int j=1; j<=c-2; j++){
                    for(int k=1; j<=r; k++){
                        if(k % 2 == 1) cout << k << " " << j << endl;
                        else cout << k << " " << j + 2 << endl;
                    }
                }

                for(int j=1; j<=r; j++){
                    if(j % 2 == 1) cout << j << " " << c - 1 << endl;
                    else cout << j << " " << 2 << endl;
                }

                for(int j=1; j<=r; j++){
                    if(j % 2 == 1) cout << j << " " << c << endl;
                    else cout << j << " " << 1 << endl;
                }
            }
        }
        else{
            for(int j=1; j<=c-2; j++){
                for(int k=1; j<=r; k++){
                    if(k % 2 == 1) cout << k << " " << j << endl;
                    else cout << k << " " << j + 2 << endl;
                }
            }
        }
    }
}