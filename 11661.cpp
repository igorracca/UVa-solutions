/* 
author: Igor Racca
RA:  511382

judge: UVa 
11661 - Burger Time?
*/

#include <iostream>
#include <vector>

int main() {
	std::vector<int> l;
	int n;
		
	while(true) {
		scanf("%d", &n);
		if(n == 0)
			break;
		int c;
		for(c=0; c<=n; c++) {
			char aux;
			scanf("%c", &aux);
			switch(aux) {
				case 'R': l.push_back(1); break;
				case 'D': l.push_back(2); break;
				case 'Z': l.push_back(3); break;
				case '.': l.push_back(0); break;
			}
		}
		int min = 99999999;
		int d = 0;
		int start = 0;
		for (std::vector<int>::iterator it = l.begin() ; it != l.end(); ++it) {
//			std::cout << *it;
			if(*it == 3) {
				min = 0;
				break;
			} else
			if(*it == 1) {
				d = 0;
				start = 1;
			} else
			if(*it == 2 && start==1) {
				d++;
				start = 0;
				if(d < min) {
					min = d;
				}
			} else {
				d++;
			}
		}
		d = 0;
		start = 0;
		for (std::vector<int>::reverse_iterator it = l.rbegin() ; it != l.rend(); ++it) {
//			std::cout << *it;
			if(*it == 3) {
				min = 0;
				break;
			} else
			if(*it == 1) {
				d = 0;
				start = 1;
			} else
			if(*it == 2 && start==1) {
				d++;
				start = 0;
				if(d < min) {
					min = d;
				}
			} else {
				d++;
			}
		}
		
		std::cout << min << "\n";
		l.clear();
	}

	
	return 0;
}
