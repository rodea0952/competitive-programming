#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

double convexDiameter(Polygon pol){
    int n = pol.size();
    if(n <= 1) return 0;
    if(n == 2) return abs(pol[0] - pol[1]);

    int i = 0, j = 0;
    for(int k=0; k<n; k++){
        if(!(pol[i] < pol[k])) i = k;
        if(pol[j] < pol[k]) j = k;
    }

    double diameter = 0;
    int si = i, sj = j;
    while(i != sj || j != si){
        diameter = max(diameter, abs(pol[i] - pol[j]));
        if(cross(pol[(i+1)%n] - pol[i], pol[(j+1)%n] - pol[j]) < -EPS){
            i = (i + 1) % n;
        }
        else{
            j = (j + 1) % n;
        }
    }

    return diameter;
}

int main(){
    int n; cin>>n;
    Polygon pol;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        pol.emplace_back(x, y);
    }

    printf("%.10f\n", convexDiameter(pol));
}