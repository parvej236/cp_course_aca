#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    long double r;
    cin >> n >> r;

    long double pi = acosl(-1.0L);      
    long double angle = pi / n;
    long double s = sinl(angle);        
    long double R = r * s / (1.0L - s); 
    cout << fixed << setprecision(7) << (double)R << "\n";

    return 0;
}
