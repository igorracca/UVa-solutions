/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

author: Igor Racca

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
Problem:

Given a sequence of positive integers A and an integer T, return whether there is a *continuous sequence* of A that sums up to exactly T
Example
[23, 5, 4, 7, 2, 11], 20. Return True because 7 + 2 + 11 = 20
[1, 3, 5, 23, 2], 8. Return True because 3 + 5 = 8
[1, 3, 5, 23, 2], 7 Return False because no sequence in this array adds up to 7
Note: We are looking for an O(N) solution. There is an obvious O(N^2) solution which is a good starting point but is not the final solution we are looking for.
The solution is actually quite simple and straightforward. It does not require using any fancy recursion, algorithms or data structures. Just think how you'd solve it in O(N) on paper then write that code.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Input:

A 				(number of positive integers)
x1 x2 ... xA 	(positive integers)
T 				(target)


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Output:

True because xk + xk+1 + ... + xk+n = T 					(if the continuous sequence exists)
														or
False because no sequence in this array adds up to T 	(if the continuous sequence does not exist)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>

using namespace std;

void printSol(bool sol, int v[], int t, int b, int e) {
	if(sol == false) {
		cout << "False because no sequence in this array adds up to " << t << endl;	
		return;
	} 
	
	cout << "True because";
	for(int i=b; i<=e; i++) {
		cout << " " << v[i];
		if(i!=e) {
			cout << " +";
		}
	}
	cout << " = " << t;
}

int main() {
    int *A;
    int a, target;
    
    cout << "How many numbers in the sequence?" << endl;
	cin >> a;	
	A = new int[a];
	cout << "Inform the " << a << " numbers separeted by spaces: " << endl;
    for(int i=0; i<a; i++) {
    	cin >> A[i];
	}

	cout << "Inform the target: ";
	cin >> target;

	int begin=0, end=1, sol=false;
	
	if(a == 1) {
		if(A[0] == target) {
			begin = end = 0;
			sol=true;
		}
	} else {
		int sum = A[begin];
		while(end < a) {
			if(begin == end) {
				sum = A[begin];
				end++;
			}
			
			if((sum + A[end]) == target) {
				sol=true;
				break;
			} else
			if((sum + A[end]) < target) {
				sum += A[end];
				end++;
			} else {
				sum -= A[begin];
				begin++;
			}
		}
	}
	
	printSol(sol, A, target, begin, end);
	
	return 0;
}
