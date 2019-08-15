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
    int A = 0, X = 1, Z = 2, B = 3, W = 4, Y = 5;
    while(1){
        string s; cin>>s;
        if(s == "#") return 0;

        bool valid = true;
        int cv = A;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(cv == A){
                if(s[i] == '0') cv = X;
                else cv = Y;
            }
            else if(cv == X){
                if(s[i] == '0') valid = false;
                else cv = Z;
            }
            else if(cv == Z){
                if(s[i] == '0') cv = W;
                else cv = B;
            }
            else if(cv == B){
                if(s[i] == '0') cv = Y;
                else cv = X;
            }
            else if(cv == W){
                if(s[i] == '0') cv = B;
                else cv = Y;
            }
            else{
                if(s[i] == '0') cv = X;
                else valid = false;
            }
        }

        if(valid && cv == B){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}