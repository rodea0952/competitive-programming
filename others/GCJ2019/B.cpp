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
        bool valid = true;
        if(r == 2 && c == 2){
            valid = false;
        }
        if(r == 2 && c == 3){
            valid = false;
        }
        if(r == 2 && c == 4){
            valid = false;
        }
        if(r == 3 && c == 2){
            valid = false;
        }
        if(r == 3 && c == 3){
            valid = false;
        }
        if(r == 4 && c == 2){
            valid = false;
        }
        
        if(valid){
            cout << "Case #" << i << ": " << "POSSIBLE" << endl;
            if(r == 2 && c == 5){
                int a[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
                int b[10] = {1, 3, 5, 2, 4, 1, 3, 5, 2, 4};
                for(int j=0; j<10; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 3 && c == 4){
                int a[12] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
                int b[12] = {1, 3, 1, 2, 4, 2, 3, 1, 3, 4, 2, 4};
                for(int j=0; j<12; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 3 && c == 5){
                int a[15] = {1, 2, 1, 2, 1, 2, 3, 2, 3, 1, 3, 1, 3, 2, 3};
                int b[15] = {1, 3, 5, 1, 3, 5, 2, 4, 1, 2, 3, 4, 5, 2, 4};
                for(int j=0; j<15; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 4 && c == 3){
                int a[12] = {1, 3, 1, 2, 4, 2, 3, 1, 3, 4, 2, 4};
                int b[12] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
                for(int j=0; j<12; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 4 && c == 4){
                int a[16] = {1, 2, 3, 1, 2, 3, 1, 3, 4, 1, 4, 2, 4, 3, 2, 4};
                int b[16] = {1, 3, 1, 2, 4, 2, 3, 4, 2, 4, 3, 2, 1, 3, 1, 4};
                for(int j=0; j<16; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 4 && c == 5){
                int a[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
                int b[10] = {1, 3, 5, 2, 4, 1, 3, 5, 2, 4};

                for(int j=0; j<20; j++){
                    if(j < 10) cout << a[j % 10] << " " << b[j % 10] << endl;
                    else cout << a[j % 10] + 2 << " " << b[j % 10] << endl;
                }
            }
            if(r == 5 && c == 2){
                int a[10] = {1, 3, 5, 2, 4, 1, 3, 5, 2, 4};
                int b[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
                for(int j=0; j<10; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 5 && c == 3){
                int a[15] = {1, 3, 5, 1, 3, 5, 2, 4, 1, 2, 3, 4, 5, 2, 4};
                int b[15] = {1, 2, 1, 2, 1, 2, 3, 2, 3, 1, 3, 1, 3, 2, 3};
                for(int j=0; j<15; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
            if(r == 5 && c == 4){
                int a[10] = {1, 3, 5, 2, 4, 1, 3, 5, 2, 4};
                int b[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

                for(int j=0; j<20; j++){
                    if(j < 10) cout << a[j % 10] << " " << b[j % 10] << endl;
                    else cout << a[j % 10] << " " << b[j % 10] + 2 << endl;
                }
            }
            if(r == 5 && c == 5){
                int a[25] = {1, 2, 1, 2, 1, 2, 3, 2, 3, 1, 3, 1, 3, 2, 3, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5};
                int b[25] = {1, 3, 5, 1, 3, 5, 2, 4, 1, 2, 3, 4, 5, 2, 4, 1, 3, 5, 2, 4, 1, 3, 5, 2, 4};
                for(int j=0; j<25; j++){
                    cout << a[j] << " " << b[j] << endl;
                }
            }
        }
        else{
            cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
        }
    }
}