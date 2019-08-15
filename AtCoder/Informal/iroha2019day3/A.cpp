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
    ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
    cin>>A>>B>>C>>D>>E>>F>>G>>H>>I>>J>>K>>L>>M>>N>>O>>P>>Q>>R>>S>>T>>U>>V>>W>>X>>Y>>Z;

    cout << A - B << endl;
    cout << C + D << endl;
    cout << max(F - E + 1, 0LL) << endl;
    cout << (G + H + I) / 3 + 1 << endl;
    if(J == 1) cout << "a" << endl;
    if(J == 2) cout << "aa" << endl;
    if(J == 3) cout << "aaa" << endl;
    if(J == 4) cout << "aaai" << endl;
    if(J == 5) cout << "aaaji" << endl;
    if(J == 6) cout << "aabaji" << endl;
    if(J == 7) cout << "agabaji" << endl;
    if(J == 8) cout << "dagabaji" << endl;

    int cnt=0;
    ll num1, num2=INF;
    for(int i=0; ; i++){
        if((61 * i + L) % 59 == K){
            cnt++;
        }

        if(cnt == M){
            num1 = 61 * i + L;
            break;
        }
    }

    vector<ll> perfectNumber{6, 28, 496, 8128, 33550336, 8589869056, 137438691328};
    for(int i=0; i<7; i++){
        if(N <= abs(perfectNumber[i] - num1)){
            chmin(num2, perfectNumber[i]);
        }
    }

    cout << min(num1, num2) << endl;
    cout << max(num1, num2) << endl;
    cout << ((O + P + Q) * (R + S + T) * (U + V + W) * (X + Y + Z)) % 9973 << endl;
}