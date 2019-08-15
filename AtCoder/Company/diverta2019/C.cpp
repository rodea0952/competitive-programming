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
    int n; cin>>n;
    vector<string> s(n);
    vector<int> cnt(3, 0);
    int ans=0;
    int sumcnt=0;
    vector<bool> validA(n, false), validB(n, false);
    for(int i=0; i<n; i++){
        cin>>s[i];
        for(int j=0; j<s[i].size()-1; j++){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }

        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A'){
            cnt[2]++;
        }
        else if(s[i][0] == 'B'){
            cnt[1]++;
            validB[i] = true;
        }
        else if(s[i][s[i].size()-1] == 'A'){
            cnt[0]++;
            validA[i] = true;
        }
    }

    int sum=0;
    for(int i=0; i<n; i++){
        if(validA[i] || validB[i]){
            sum++;
        }
    }

    if(cnt[2] > 0){
        if(cnt[1] > 0 && cnt[0] > 0){
            ans += cnt[2] + 1;
            cnt[2] = 0;
            cnt[1]--;
            cnt[0]--;
        }
        else if(cnt[1] > 0){
            ans += cnt[2];
            cnt[2] = 0;
            cnt[1]--;
        }
        else if(cnt[0] > 0){
            ans += cnt[2];
            cnt[2] = 0;
            cnt[0]--;
        }
        else{
            ans += cnt[2] - 1;
            cnt[2] = 0;
        }
    }

    cout << ans + min(cnt[0], cnt[1]) << endl;
}
