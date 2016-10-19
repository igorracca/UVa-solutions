/*
author: Igor Racca
RA:  511382
 
judge: UVa
problem: 10700
*/
 
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
 
using namespace std;
 
int main () {
   
    string in;
    vector<long long> numbers;
    vector<char> operators;
   
    int n;
    cin >> n;
    for(int m=0; m<n; m++) {
        cin >> in;
       
        // read in
        for(int i = 0; i < in.size(); i++) {
            if(in[i]=='+' || in[i]=='*') {
                operators.push_back(in[i]);
            } else {
                long long number = int(in[i]) - 48;
                if(i <= in.size()-2 && (in[i+1]>=48 && in[i+1]<=57)){
                    number *= 10;
                    number += int(in[i+1]) - 48;
                    i++;
                }
                numbers.push_back(number);
            }          
        }
       
       	//copy vectors
        vector<long long> numbers2 = numbers;
    	vector<char> operators2 = operators;
       
        // do sum first (max)
        std::vector<long long>::iterator n_it = numbers.begin();
        std::vector<char>::iterator o_it = operators.begin();
        while( o_it != operators.end()) {
            if(*o_it=='+') {
            	long aux = *n_it;
            	n_it = numbers.erase(n_it);
            	*n_it += aux;
            	o_it = operators.erase(o_it);
			} else 
			if(*o_it=='*') {
            	++n_it;
				++o_it;
			}    
        }	
        long max=1;
		n_it = numbers.begin();	
		while(n_it != numbers.end()) {
			max *= *n_it;
			++n_it;
		}
		
//		 do multiplication first (min)
        n_it = numbers2.begin();
        o_it = operators2.begin();
        while( o_it != operators2.end()) {
            if(*o_it=='*') {
            	long long aux = *n_it;
            	n_it = numbers2.erase(n_it);
            	*n_it *= aux;
            	o_it = operators2.erase(o_it);
			} else 
			if(*o_it=='+') {
            	++n_it;
				++o_it;
			}    
        }	
        long long min=0;
		n_it = numbers2.begin();	
		while(n_it != numbers2.end()) {
			min += *n_it;
			++n_it;
		}
       
//        for (std::vector<long long>::iterator it = numbers2.begin() ; it != numbers2.end(); ++it) {
//            cout << *it << "\n";
//        }
// 
//        for (std::vector<char>::iterator it = operators2.begin() ; it != operators2.end(); ++it) {
//            cout << *it << "\n";
//        }
    
        cout << "The maximum and minimum are " << max << " and " << min << ".\n";
        
        numbers.clear();
        operators.clear();
        numbers2.clear();
        operators2.clear();
    }
   
    return 0;
}
