/* 
author: Igor Racca
RA:  511382

judge: UVa
12247 - Jollo?
*/

#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std;

int main() {

	int princess[3], prince[2];

	int cards[52];
	int rounds[3][3];
	
	cin >> princess[0];
	cin >> princess[1];
	cin >> princess[2];
	cin >> prince[0];
	cin >> prince[1];
	while(!((princess[0] == 0) && (princess[1] == 0) && (princess[2] == 0) && (prince[0] == 0) && (prince[1] == 0))) {
		
		sort(princess, princess+3);
		
		for(int i=0; i<2; i++) 
			for(int j=0; j<3; j++)
				rounds[i][j] = 0;
				
		for(int i=0; i<52; i++)
			cards[i] = 0;
			
		for(int i=0; i<2; i++) {
			for(int j=0; j<3; j++) {
				if(prince[i] > princess[j]) {
					rounds[i][j] = 1;
					cards[rounds[i][j] - 1] = 1;
				}
			}
		}
		
		int princeCard = 1;		
		if(((prince[0] < princess[1]) && (prince[1] < princess[1]))
		|| ((prince[0] < princess[1]) && (prince[1] < princess[2]))
		|| ((prince[1] < princess[1]) && (prince[0] < princess[2]))) {
			princeCard = -1;
		} else {
			int numberOfOnes = 0, numberOfTwos = 0;			
			for(int i=0; i<3; i++) {
				rounds[2][i] = rounds[0][i] + rounds[1][i];
				if(rounds[2][i] == 1) {
					numberOfOnes++;
				} else
				if(rounds[2][i] == 2) {
					numberOfTwos++;
				}
			}
			if(numberOfTwos == 0 && numberOfOnes != 3) {
				princeCard = -1;
			} else {
				if(numberOfTwos == 1) {
					princeCard = princess[2] + 1;
				} else 
				if(numberOfTwos == 2) {
					princeCard = princess[1] + 1;
				} else
				if(numberOfTwos == 3) {
					princeCard = 1;
				} else {
					princeCard = princess[2] + 1;
				}
				
				while((find(princess, princess+3, princeCard) != princess+3) 
					|| (find(prince, prince+2, princeCard) != prince+2)) {
					princeCard++;
					if(princeCard > 52) {
						princeCard = -1;
					}
				}
			}
		}
		
		cout << princeCard << "\n";
		
//		cout << "\n";
//		for(int i=0; i<3; i++) {
//			cout << "\n";
//			for(int j=0; j<3; j++)
//				cout << rounds[i][j];
//		}
			
		cin >> princess[0];
		cin >> princess[1];
		cin >> princess[2];
		cin >> prince[0];
		cin >> prince[1];	
	}
	
	return 0;
}
