#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    string s; cin>>s;

    int sum1=0, sum2=0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') sum1++;
        else{
            if(sum1 > 0) sum1--;
            else sum2++;
        }
    }

    cout << string(sum2, '(') << s << string(sum1, ')') << endl;
}