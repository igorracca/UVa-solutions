/*
author: Igor Racca
RA:  511382

judge: UVa
problem: 12049
*/

#include<iostream>
#include<algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
	vector<int> l1;
	vector<int> l2;
	vector<int> out;
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n,m;
		cin >> n;
		cin >> m;
		
		int e;
		for(int j=0; j<n; j++) {
			cin >> e;
			l1.push_back(e);
		}
		for(int j=0; j<m; j++) {
			cin >> e;
			l2.push_back(e);
		}
		
		vector<int>::iterator min1 = min_element(l1.begin(), l1.end());
		vector<int>::iterator min2 = min_element(l2.begin(), l2.end());
		
		int minimum = min(*min1, *min2);
		if(minimum < 0);
		
		sort(l1.begin(), l1.begin()+n);
		sort(l2.begin(), l2.begin()+m);
		
		int i1=0, i2=0;
		while(!(i1==n && i2==m)) {
			if(l1[i1] == l2[i2]) {
				if(i1<n) {
					i1++;
				}		 
				if(i2<m) {
					i2++;				
				}
			} else
			if(i1 == n) {
				out.push_back(l2[i2]);
				i2++;			
			} else
			if(i2 == m) {
				out.push_back(l1[i1]);
				i1++;
			} else {
				if(l1[i1] > l2[i2]) {
					out.push_back(l2[i2]);
					i2++;
				} else {
					out.push_back(l1[i1]);
					i1++;
				}	
			}
		}
		
		cout << out.size() << "\n";
		out.clear();
		l1.clear();
		l2.clear();
	}	
	
	return 0;
}
