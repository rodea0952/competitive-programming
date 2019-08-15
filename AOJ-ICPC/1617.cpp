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

vector<string> calc(string s){
    vector<string> v;
    int pre = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '\"'){
            string t = s.substr(pre, i - pre + 1);
            v.eb(t);

            pre = i;
        }
    }

    string t = s.substr(pre, s.size() - 1 - pre + 1);
    v.eb(t);

    return v;
}

int main(){
    while(1){
        string s1; cin>>s1;
        if(s1 == ".") return 0;
        string s2; cin>>s2;

        if(s1 == s2){
            cout << "IDENTICAL" << endl;
            continue;
        }

        auto ans1 = calc(s1);
        auto ans2 = calc(s2);        

        int dif = 0;
        for(int i=0; i<ans1.size() && i<ans2.size(); i++){
            if(i % 2 == 0){
                if(ans1[i] != ans2[i]) dif = 2;
            }
            else{
                if(ans1[i] != ans2[i]) dif++;
            }
        }

        if(dif == 1){
            cout << "CLOSE" << endl;
        }
        else{
            cout << "DIFFERENT" << endl;
        }
    }
}