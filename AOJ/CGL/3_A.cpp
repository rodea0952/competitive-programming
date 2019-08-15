#include <iostream>
#include <complex>
#include <utility>
#include <vector>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double convexArea(Polygon pol){
    int n = pol.size();
    if(n == 0) return 0.0;
    Point basep = pol[0];

    double S = 0.0;
    for(int i=1; i<n-1; i++){
        Vector a = pol[i] - basep;
        Vector b = pol[i+1] - basep;
        S += cross(a, b) / 2;
    }

    return S;
}

int main(){
    int n; cin>>n;
    Polygon pol;
    while(n--){
        double x, y; cin>>x>>y;
        pol.emplace_back(x, y);
    }

    printf("%.1f\n", convexArea(pol));
}