#include <iostream>
#include <complex>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> Point;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }

    bool cmp_y(const Point &a, const Point &b) {
        return !equals(a.Y, b.Y) ? a.Y < b.Y : a.X < b.X;
    }
}

double closestPair(vector<Point> &points, int l, int r){
    if(r - l <= 1) return 1e9;
    int mid = (l + r) / 2;
    double x = points[mid].X;
    double d = min(closestPair(points, l, mid), closestPair(points, mid, r));
    auto iti = points.begin();
    auto itl = iti + l;
    auto itm = iti + mid;
    auto itr = iti + r;

    inplace_merge(itl, itm, itr, cmp_y);

    vector<Point> nearLine;
    for(int i=l; i<r; i++){
        if(abs(points[i].X - x) >= d) continue;

        int sz = nearLine.size();
        for(int j=sz-1; j>=0; j--){
            double dx = points[i].X - nearLine[j].X;
            double dy = points[i].Y - nearLine[j].Y;
            if(dy >= d) break;
            d = min(d, sqrt(dx * dx + dy * dy));
        }

        nearLine.emplace_back(points[i]);
    }
    
    return d;
}

int main(){
    int n; cin>>n;
    vector<Point> points;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        points.emplace_back(x, y);
    }

    sort(points.begin(), points.end());

    printf("%.10f\n", closestPair(points, 0, n));
}