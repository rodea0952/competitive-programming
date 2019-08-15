#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin>>s;

    if(s[0] == 'W' && s[1] == 'W'){
        if(s[5] == 'W' && s[6] == 'W') cout << "Si" << endl;
        else cout << "Mi" << endl;
    }
    else if(s[2] == 'W' && s[3] == 'W'){
        if(s[7] == 'W' && s[8] == 'W') cout << "La" << endl;
        else cout << "Re" << endl;
    }
    else if(s[4] == 'W' && s[5] == 'W'){
        if(s[9] == 'W' && s[10] == 'W') cout << "So" << endl;
        else cout << "Do" << endl;
    }
    else cout << "Fa" << endl;
}