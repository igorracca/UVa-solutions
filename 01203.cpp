/*
author: Igor Racca
RA:  511382

judge: UVa
problem: 01203
*/

#include<iostream>
#include<queue>
#include <string>
#include <vector>

using namespace std;

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};

int main() {
	
	vector<int> registers;
	vector<int>periods;
	vector<int>time;
	priority_queue<int,vector<int>, compare > pq;
	
	string in;
	while(true) {
		cin >> in;
		if(in == "#") {
			break;
		}
		int r, p;
		cin >> r;
		cin >> p;
		registers.push_back(r);
		periods.push_back(p);
		time.push_back(p);	
	}
	int k, outputs=0, timer=0;
	cin >> k;
	while(true) {
		for(int j=0; j<registers.size(); j++) {
			if(time[j] == 0) {
				pq.push(registers[j]);
				time[j] = periods[j];
			}
			time[j]--;
		}	

		while(!pq.empty()) {
			int r = pq.top();
			pq.pop();
			cout << r << "\n";
			outputs++;
			if(outputs == k) {
				break;
			}
		}		
			
		if(outputs == k) {
				break;
			}	
		timer++;
	}
	
	return 0;
}
