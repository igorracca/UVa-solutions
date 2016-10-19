/*
author: Igor Racca
RA:  511382

judge: UVa
problem: 10475
*/

#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string const & a, string const & b) {
	if(a.length() > b.length()) return true;
	if(a.length() < b.length()) return false;
	
	if(a < b) return true;
	else return false;
}

void printPossibleSets(vector<string> &T, vector<vector<string> > &P, vector<string> &out, int sel, int ini, int t, int s) {
	if(sel == s) {
		for(int i=0; i<P.size(); i++) {
			int nP = 0;
			for(int j=0; j<2; j++) {
				for(int k=0; k<out.size(); k++) {
					if(P[i][j] == out[k])
					nP++;
				}
			}
			if(nP == 2) {
				return;
			}
		}
		for(int i=0; i<out.size(); i++) {
			string cap_out = out[i];
			transform(cap_out.begin(), cap_out.end(), cap_out.begin(), ::toupper);			
			cout << cap_out;
			if(i!=out.size() -1) {
				cout << " ";
			}	
		}
		cout << "\n";
	} else {
		for(int i=ini; i<t; i++) {
			out.push_back(T[i]);
			printPossibleSets(T, P, out, sel+1, i+1, t, s);
			out.pop_back();
		}
	}
}

int main() {
	int n;
	int t, p, s;
	vector<string> T, out;
	vector<vector<string> > P;
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> t;
		cin >> p;
		cin >> s;
		
		//IN T
		for(int j=0; j<t; j++) {
			string topic;
			cin >> topic;
			T.push_back(topic);
		}
		
		sort(T.begin(), T.end(), compare);		
//		for(int j=0; j<t; j++) {
//			cout << T[j] << "\n";
//		}
//		cout << "\n";cout << "\n";

		//IN P
		for(int j=0; j<p; j++) {
			vector<string> row;
			for(int k=0; k<2; k++) {
				string topic;
				cin >> topic;
				row.push_back(topic);
			}
			P.push_back(row);
			sort(P[j].begin(), P[j].end(), compare);
		}
	
//		for(int j=0; j<p; j++) {
//			for(int k=0; k<s; k++) {
//				cout <<	P[j][k] << " ";
//			}
//			cout << "\n";
//		}
//		
//		for(int j=0; j<p; j++) {
//			cout << (P[j] == T) << "\n";	
//		}
		
		//OUT
		cout << "Set " << i+1 << ":\n";
		printPossibleSets(T, P, out, 0, 0, t, s);
		cout << "\n";
		
		T.clear();
		for(int j=0; j<p; j++) {
			P[j].clear();	
		} 
		P.clear();
		out.clear();
		t++;
	} cout << "\n";
	
	return 0;
}
