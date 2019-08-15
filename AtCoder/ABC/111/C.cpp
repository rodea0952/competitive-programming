#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> v(n), ecnt(100010, 0), ocnt(100010, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i%2==0) ecnt[v[i]]++;
        else ocnt[v[i]]++;
    }

    int emax=0, enumb, omax=0, onumb;
    for(int i=1; i<=100000; i++){
        if(emax<ecnt[i]){
            emax=ecnt[i];
            enumb=i;
        }
        if(omax<ocnt[i]){
            omax=ocnt[i];
            onumb=i;
        }
    }

    if(enumb!=onumb){
        cout << n-(emax+omax) << endl;
    }
    else{
        int emax2=0, omax2=0;
        for(int i=1; i<=100000; i++){
            if(i==enumb) continue;

            if(emax2<ecnt[i]){
                emax2=ecnt[i];
            }
            if(omax2<ocnt[i]){
                omax2=ocnt[i];
            }
        }
        if(emax2>=omax2){
            cout << n-(emax2+omax) << endl;
        }
        else{
            cout << n-(emax+omax2) << endl;
        }
    }
}