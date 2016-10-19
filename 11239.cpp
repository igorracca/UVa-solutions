/*
author: Igor Racca
RA:  511382

judge: UVa
problem: 11683
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <ctype.h>

#define p_size 100

using namespace std;

class Signup {
	public:
		string project;
		set<string> students;	
};


bool signup_comp(Signup const & a, Signup const & b) {
	if(a.students.size() > b.students.size()) return true;
	if(a.students.size() < b.students.size()) return false;
	
	if(a.project < b.project) return true;
	else return false;
}

int main() {
	set<string> names;
	Signup *signups;
	string in;

	while(true) {
		getline(cin, in);
		
		if(in == "0") {
			break;
		}
		
		int project=0;
		signups = new Signup[p_size];
		
		while(true) {
			if(in == "1") {
				break;
			}	
			
			// Store project name
			signups[project].project = in;
			
			// Read students
			while(true) {	
				getline(cin, in);
				
				if(isupper(in[0]) || (in == "1")) {
					break;
				} else {
					bool exists = false;
					set<string>::iterator it;
					
					if(names.find(in) == names.end()) {
						names.insert(in);				
					} else {
						exists = true;
					}
					
					for(int i=0; i<project; i++) {
						it = signups[i].students.find(in);
						if(it != signups[i].students.end()) {
							if(i != project) {
								signups[i].students.erase(it);
							}			
							exists = true;
							break;
						}
					}
					
					if(!exists) {
						signups[project].students.insert(in);
					}
		
				}
			}
			
			project++;
		}
		
		sort(signups, signups+project, signup_comp);
		
		for(int i=0; i<project; i++) {
			cout << signups[i].project << " " << signups[i].students.size() << "\n";
		}		
		
		delete[] signups;
		names.clear();
	}
	
}
