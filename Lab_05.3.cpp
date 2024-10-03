#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

double h(const double x);

int main() {
    double rp, rk, z;
    int n;

    cout << "rp = "; cin >> rp;
    cout << "rk = "; cin >> rk;
    cout << "n = "; cin >> n;

    if (n <= 0) {
        cout << " n " << endl;
        return 1;
    }

    double dr = (rk - rp) / n;
    double r = rp;

    cout << fixed << setprecision(4);
    cout << "-------------------------" << endl;
    cout << setw(8) << "r" << " |" << setw(13) << "z" << " |" << endl;
    cout << "-------------------------" << endl;

    while (r <= rk) {
        z = h(r + 1) + pow(h(r * r + 1), 2) + 1;
        cout << "-------------------------" << endl;
        cout << setw(8) << r << " |" << setw(13) << z << " |" << endl;
        cout << "-------------------------" << endl;
        r += dr;
    }
    return 0;
}

double h(const double x) {
    if (abs(x) >= 1)
    { 
        return (cos(x) + 1) / exp(x);
    }
    else {
        double S = 0;
        int n = 0;
        double a = x;
        S = a;
        do {
            n++;
            double R = (x * x) / ((2 * n + 3) * (2 * n + 2));
            a *= R;
            S += a;
        } while (n < 6);
        return (1.0 / pow(sin(x), 2));
    }
}
