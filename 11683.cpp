/* 
author: Igor Racca
RA:  511382

judge: UVa
11683 - Laser Sculpture
*/

#include <iostream>

using namespace std;

int main() {
	
	size_t array_size = 10000;
	int x[array_size];
	int A, C;
	
	cin >> A;
	cin >> C;	
	while(!((C == 0) && (A == 0))){
		int laserC = 0;
		if(A == 0 || C == 0) {
			
		} else {
			for(int i=0; i<C; i++) {
				cin >> x[i];
			}
			for(int i=A; i>0; i--) {
				bool laserOn = false;
				for(int j=0; j<C; j++) {
//					cout << "i=" << i << " x[j]=" << x[j] << " \n";
					if(x[j] < i) {
						if(!laserOn) {
							laserOn = true;
							laserC++;
						}
					} else {
						laserOn = false;
					}
				}
			}
		}
		
		cout << laserC << "\n";
		
		cin >> A;
		cin >> C;
	}
	
	return 0;
}
