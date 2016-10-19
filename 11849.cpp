/* 
author: Igor Racca
RA:  511382

judge: UVa
11849 - CD
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	unsigned n, m;
	unsigned jack[1000000];
	
	cin >> n;
	cin >> m;
	while(!((n == 0) && (m == 0))) {
//		jack = new (nothrow) unsigned [n];
		int cds=0;
		
		for(unsigned i=0; i<n; i++) {
			cin >> jack[i];
		}

		unsigned j=0, k;
		for(unsigned i=0; i<m; i++) {
			cin >> k;
			while(jack[j] < k) {
				j++;
			}
			if(jack[j] == k) {
				cds++;
			}
		}		
	
		cout << cds << "\n";
	
//		delete jack;
	
		cin >> m;
		cin >> n;	
	}
	
	return 0;
}
