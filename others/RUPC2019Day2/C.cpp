#include <bits/stdc++.h>
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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    string s; cin>>s;

    // count i -> j 
    int num[10][10];
    memset(num, 0, sizeof(num));
    for(int i=0; i<n-1; i++){
        num[s[i]-'0'][s[i+1]-'0']++;
    }

    vector<int> v(9);
    iota(v.begin(), v.end(), 1);

    ll costmin=INF;
    vector<int> ans(9);
    do{
        int phone[3][3];
        for(int i=0; i<9; i++){
            phone[i/3][i%3]=v[i];
        }

        int cost[10][10];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cost[phone[i/3][i%3]][phone[j/3][j%3]]=abs(i/3-j/3)+abs(i%3-j%3);
            }
        }

        ll sum=0;
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++){
                sum+=cost[i][j]*num[i][j];
            }
        }

        if(sum<costmin){
            costmin=sum;
            ans=v;
        }

    }while(next_permutation(v.begin(), v.end()));

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << ans[i*3+j];
        }
        cout << endl;
    }
}