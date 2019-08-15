#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main(){
    int n, k; cin>>n>>k;
    vector<P> point(n);
    for(int i=0; i<n; i++){
        cin>>point[i].first>>point[i].second;
    }

    sort(point.begin(), point.end());

    map<P, int> cnt;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cnt[P(point[j].first - point[i].first, point[j].second - point[i].second)]++;
        }
    }

    for(auto i:cnt){
        cout << i.second << endl;
    }
}