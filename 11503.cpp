/*

#################################################
TIME LIMIT EXCEEDED
Soluion: Implement Union Find
#################################################

author: Igor Racca
RA:  511382

judge: UVa
problem: 11503
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
	public:
		string name;
		int network;	
};

int findANetwork(vector<User> users, User u) {
	int index = -1;
	for(int i=0; i<users.size(); i++) {
		if(u.name == users[i].name) {	
			index = users[i].network;
			break;
		}
	}
	return index;
}

void updateNetwork(vector<User> &users, int oldN, int newN) {
	for(int i=0; i<users.size(); i++) {
		if(users[i].network == oldN) {
			users[i].network = newN;
		}
	}
}

void countNetwork(vector<User> &users, int network) {
	int c=0;
	for(int i=0; i<users.size(); i++) {
		if(users[i].network == network) {
			c++;
		}
	}
	cout << c << "\n"; 
}

int main() {
	vector<User> users;
	
	int c;
	cin >> c;
	for(int i=0; i<c; i++) {
		int lastNetwork=0;
		int lastFriendshipNetwork;
		
		int f;
		cin >> f;
		for(int j=0; j<f; j++) {
			string p1, p2;
			cin >> p1;
			cin >> p2;
			
			User u;
			u.name = p1;			
			int p1network = findANetwork(users, u);
			u.name = p2;
			int p2network = findANetwork(users, u);

			//1st case: no one is in a network
			if(p1network==-1 && p2network==-1) {
				u.network = lastNetwork;
				users.push_back(u);
				u.name = p1;
				users.push_back(u);
				
				lastFriendshipNetwork = lastNetwork;
			} else
			//2nd case: just p1 is in a network
			if(p1network!=-1 && p2network==-1) {
				u.network = p1network;
				users.push_back(u);
				
				lastFriendshipNetwork = p1network;
			} else
			//3rd case: just p2 is in a network
			if(p1network==-1 && p2network!=-1) {
				u.name = p1;
				u.network = p2network;
				users.push_back(u);
				
				lastFriendshipNetwork = p2network;
			} else {
			//4th case: both are in a network
				updateNetwork(users, p2network, p1network);
				lastFriendshipNetwork = p1network;
			}
						
			lastNetwork++;
			countNetwork(users, lastFriendshipNetwork);
		} 	
		users.clear();
	}
	
	return 0;
}

