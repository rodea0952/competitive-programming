#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int xa, ya, xb, yb, xc, yc; cin>>xa>>ya>>xb>>yb>>xc>>yc;
    xb -= xa, yb -= ya, xc -= xa, yc -= ya;

    cout << fixed << setprecision(10) << abs(xb*yc - xc*yb) / 2.0 << endl;
}