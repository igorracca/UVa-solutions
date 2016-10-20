/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

author: Igor Racca

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
Problem: Subarray with given sum - 590

Given an unsorted array of non-negative integers, find a continous subarray which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 = T = 50
1 = N = 100
1 = an array element = 200

Example:

Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Explanation : 
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>

using namespace std;

int main() {
    int *A;
    int n, a, target;
    
    cin >> n;
    
	while(n--) {
		cin >> a;
		cin >> target;	
		
		A = new int[a];
		for(int i=0; i<a; i++) {
	    	cin >> A[i];
		}
	
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
		
		if(sol == false) {
			cout << -1 << endl;
		} else {
			cout << begin+1 << " " << end+1 << endl;
		}
		
		delete[] A;
	}
	
	
	return 0;
}
