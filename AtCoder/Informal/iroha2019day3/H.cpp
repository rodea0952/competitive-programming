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
    int q; cin>>q;
    while(q--){
        char c; cin>>c;
        ll e; cin>>e;
        ll num=0;

        int cNum=-1;
        int alphaNum=-1;
        while(num != 63){
            if(e % (1LL << num) == 0 && e >= (1LL << num)){
                if((e / (1LL << num)) <= 25){
                    cNum = num;
                    alphaNum = (e / (1LL << num));
                    break;
                }
            }

            num++;
        }

        if(cNum == -1){
            cout << -1 << endl;
            continue;
        }

        int sum=0;
        bool cUse=false;
        string ans="";
        for(char ch='a'; ch<='z'; ch++){
            if(ch == c){
                for(int i=0; i<cNum; i++) ans += c;
                cUse = true;
            }
            else{
                ans += ch;
                sum++;
            }

            if(sum == alphaNum){
                break;
            }
        }

        if(!cUse){
            for(int i=0; i<cNum; i++) ans += c;
        }

        cout << ans << endl;
    }
}