/*
author: Igor Racca
RA:  511382
 
judge: UVa
problem: 679
*/

#include <stdio.h>
#include <bitset>

int main() {
	
	int l, i, d;
	
	scanf("%d", &l);
	while(true) {
		if(l == -1) {
			break;
		}
		
		for(int j=0; j<l; j++) {
			scanf("%d %d", &d, &i);
			
	        i--;
	        int p = 0;
	
	        for (int k = 0; k < (d - 1); k++) {
	            if (i >= 1 << (d - 2 - k)) {
	                i -= 1 << (d - 2 - k);
	                p += 1 << k;
	            }
	        }
	        p += 1 << (d - 1);     
	       	printf("%d\n", p);
		}
	
		scanf("%d", &l);
	}
	
	return 0;
}
