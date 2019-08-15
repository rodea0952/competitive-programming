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

namespace patch{
    template <typename T> string to_string(const T& n){
        ostringstream stm;
        stm << n;
        return stm.str();
    }
}

int main(){
    ll n; cin>>n;
    string s=patch::to_string(n);

    bool valid=true;
    for(int i=0; i<s.size(); i++){
        if(i == 0 && s[i] == '9') valid = false;
        if(i != 0 && s[i] != '9') valid = false;
    }

    if(valid && 2 <= s.size()){
        s[0]++;
        s[1]--;
        cout << s << endl;
        return 0;
    }

    ll N=n;
    ll digit=0;
    bool all9 = true;
    while(n > 0){
        digit += (n % 10LL);
        if((n % 10LL) != 9LL) all9 = false;
        n /= 10LL;
    }

    ll cnt9 = digit / 9LL;
    ll head = digit % 9LL;
    ll X=0;
    ll num=1;
    if(cnt9 == 0){
        X += head;
    }
    else{
        for(int i=0; i<cnt9; i++){
            X += num * 9LL;
            num *= 10LL;
            if(i == cnt9 - 1){
                X += num * head;
                break;
            }
        }
    }

    if(N != X){
        cout << X << endl;
    }
    else if(all9){
        cout << X + (num / 10LL) * 9LL << endl;
    }
    else{
        cout << X + num * 9LL << endl;
    }
}