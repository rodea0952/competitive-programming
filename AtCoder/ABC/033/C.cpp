#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    string s; cin>>s;
    int n=s.size();

    int i=0, ans=0;
    while(i < n){
        while(1){
            if(i >= n){
                ans++;
                break;
            }

            if(s[i] == '0'){
                while(s[i] != '+' && i < n) i++;
                break;
            }
            else if(s[i] == '+'){
                ans++;
                break;
            }
            i++;
        }
        i++;
    }

    cout << ans << endl;
}