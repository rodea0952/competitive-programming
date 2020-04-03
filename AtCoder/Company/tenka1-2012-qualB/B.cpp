#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool is_under(string s){
    while(s.front() == '_') s.erase(s.begin());
    while(s.back() == '_') s.pop_back();

    for(int i=0; i<26; i++){
        if(count(all(s), 'A' + i)) return false;
    }

    for(int i=0; i+1<s.size(); i++){
        if(s[i] == '_'){
            if(!islower(s[i+1])) return false;
        }
    }

    return true;
}

string toCamel(string s){
    int l = 0, r = 0;
    while(s.front() == '_'){
        l++;
        s.erase(s.begin());
    }
    while(s.back() == '_'){
        r++;
        s.pop_back();
    }

    string t;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '_'){
            t += toupper(s[++i]);
        }
        else{
            t += s[i];
        }
    }

    return string(l, '_') + t + string(r, '_');
}

bool isCamel(string s){
    while(s.front() == '_') s.erase(s.begin());
    while(s.back() == '_') s.pop_back();

    return (!count(all(s), '_'));
}

string to_under(string s){
    string t;
    for(int i=0; i<s.size(); i++){
        if(isupper(s[i])){
            t += '_';
        }
        t += tolower(s[i]);
    }

    return t;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin>>s;
    int n = s.size();

    if(s == string(n, '_')){
        cout << s << endl;
        return 0;
    }

    string t = s;
    while(t.front() == '_') t.erase(t.begin());

    if(!islower(t[0])){
        cout << s << endl;
        return 0;
    }

    if(is_under(s)){
        cout << toCamel(s) << endl;
    }
    else if(isCamel(s)){
        cout << to_under(s) << endl;
    }
    else{
        cout << s << endl;
    }

    return 0;
}