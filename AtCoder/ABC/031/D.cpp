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

int k, n;
vector<string> v(60);
vector<string> w(60);
vector<string> fians(10);

void rec(int cnt, string t){
    if(cnt == k + 1){
        vector<int> l(k+1);
        for(int i=0; i<t.size(); i++){
            l[i+1] = (t[i] - '0');
        }

        vector<string> ans(k+1, "");
        bool valid = true;
        for(int i=0; i<n; i++){
            string num = v[i];
            int scnt=0;
            for(int j=0; j<num.size(); j++){
                if(scnt + l[num[j]-'0'] > w[i].size()){
                    valid = false;
                    break;
                }

                if(ans[num[j]-'0'] == ""){
                    // 初めて ans[num[j]] を決めるとき
                    ans[num[j]-'0'] = w[i].substr(scnt, l[num[j]-'0']);
                    scnt += l[num[j]-'0'];
                }
                else{
                    if(ans[num[j]-'0'] != w[i].substr(scnt, l[num[j]-'0'])){
                        valid = false;
                        break;
                    }
                    else{
                        scnt += l[num[j]-'0'];
                    }
                }
            }

            if(scnt != w[i].size()) valid = false;

            if(!valid) break;
        }
            
        if(valid){
            for(int i=1; i<=k; i++){
                fians[i] = ans[i];
            }
        }
        return ;
    }

    // num に対応する文字列の長さが 1 のとき
    rec(cnt+1, t+="1");

    // num に対応する文字列の長さが 2 のとき
    t.pop_back();
    rec(cnt+1, t+="2");

    // num に対応する文字列の長さが 3 のとき
    t.pop_back();
    rec(cnt+1, t+="3");
}

int main(){
    cin>>k>>n;
    for(int i=0; i<n; i++) cin>>v[i]>>w[i];

    rec(1, "");

    for(int i=1; i<=k; i++){
        cout << fians[i] << endl;
    }
}