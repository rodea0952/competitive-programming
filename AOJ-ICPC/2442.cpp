#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

int main(){
    int n; cin>>n;
    vector<double> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    vector<double> length;
    for(int i=0; i<n; i++){
        double dist = sqrt(abs(x[i] - x[(i+1)%n]) * abs(x[i] - x[(i+1)%n]) + abs(y[i] - y[(i+1)%n]) * abs(y[i] - y[(i+1)%n]));
        length.emplace_back(dist);
    }

    if(n % 2 == 1){
        cout << "NA" << endl;
        return 0;
    }

    bool valid = true;
    for(int i=0; i<n/2; i++){
        if(!equals(length[i], length[i+n/2])) valid = false;
    }

    if(valid){
        double ansx = (x[0] + x[n/2]) / 2;
        double ansy = (y[0] + y[n/2]) / 2;
        printf("%.10f %.10f\n", ansx, ansy);
    }
    else{
        cout << "NA" << endl;
    }
}