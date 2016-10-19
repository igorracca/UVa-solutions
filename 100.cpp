/* 
author: Igor Racca
RA:  511382

judge: UVa
100 - The 3n + 1 problem
*/

#include <iostream>
#include <algorithm>

int main() {
	int i;
	int j;
	
	while(scanf("%d %d", &i, &j) != EOF) {
		std::cout << i << " " << j << " ";
		
		int aux;
		if(i > j) {
			aux = i;
			i = j;
			j = aux;
		}
		int maxCycle = 0;
		for(int n=i; n<=j; n++) {
			int m = n;
			int cycle = 0;
			while(m != 1) {	
				if(m % 2 == 0) {
					m = m/2;
				} else {
					m = 3 * m + 1;
				}
				cycle = cycle + 1;	
			}
			cycle = cycle + 1;
			if(cycle > maxCycle) {
				maxCycle = cycle;
			}
		}
		
		std::cout << maxCycle << "\n";
	}
	
	return 0;
}
