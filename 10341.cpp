/*
author: Igor Racca
RA:  511382
 
judge: UVa
problem: 10341
*/

#include <iostream>
#include <iomanip>
#include <cmath>

#define PREC 4

using namespace std;

int p, q, r, s, t, u;
double f(double xn) {
    return p*exp(-1*xn) + q*sin(xn) + r*cos(xn) + s*tan(xn) + t* pow(xn,2) + u;
}

int main() {
	cout.precision(PREC);
    cout.setf(ios::fixed,ios::floatfield);

    while(cin >> p >> q >> r >> s >> t >> u) {
		double left=0, right=1;
		double x, y;
	
		x = 0.0;
		double max = f(x);
		x = 1.0;
		double min = f(x);
		
		if(0<min || 0>max) {
			cout << "No solution" << endl;
			continue;
		}
	
		while(true) {
			x = left + right;
			x /= 2.0;
			
			y = f(x);
			
			if(fabs(y-0) <= 1e-6) {
				break;
			}
	
			y>0 ? left = x : right = x;	
		}
	
		cout << x << endl;
	}

	return 0;
}

