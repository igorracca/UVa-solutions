/*
author: Igor Racca
RA:  511382

judge: UVa
problem: 441
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define K 6

using namespace std;

void printPossibleGames(vector<int> &S, vector<int> &out, int sel, int ini, int k) {
	if(sel == K) {
		for(int i=0; i<out.size(); i++) {
			cout << out[i];
			if(i!=out.size() -1) {
				cout << " ";
			}	
		}
		cout << "\n";
	} else {
		for(int i=ini; i<k; i++) {
			out.push_back(S[i]);
			printPossibleGames(S, out, sel+1, i+1, k);
			out.pop_back();
		}
	}
}

int main() {
	int k, t=0;
	vector<int> S, out;
	
	while(true) {
		cin >> k;
		if(k == 0) {
			break;
		} else
		if(t != 0) {
			cout << "\n";
		}
		
		for(int i=0; i<k; i++) {
			int s;
			cin >> s;
			S.push_back(s);
		}
		
		printPossibleGames(S, out, 0, 0, k);
		
		S.clear();
		out.clear();
		t++;
	}
	
	
	return 0;
}
