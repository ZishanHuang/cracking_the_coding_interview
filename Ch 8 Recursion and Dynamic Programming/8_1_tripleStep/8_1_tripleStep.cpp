#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v){
	cout <<endl;
	for(int i=0;i<v.size();i++){
		cout << v[i] <<" ";
	}
	cout <<endl;
}
int countWays(int n){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	return countWays(n-1) + countWays(n-2) + countWays(n-3);
	// int count = 0;
	// count += countWays(n-1);
	// count += countWays(n-2);
	// count += countWays(n-3);
	// return count;
}
int countWays2(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;

	vector<int> num_ways(n+1, 0);
	num_ways[0] = 1;
	num_ways[1] = 1;
	num_ways[2] = 2;
	for(int i=3; i<num_ways.size();i++){
		// num_ways[i] is previously 0, so num_ways[i] = count... also works
		num_ways[i] += num_ways[i-1] + num_ways[i-2] + num_ways[i-3];
	}

	return num_ways[n];
}

int countWays3(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;

	int a = 1;
	int b = 1;
	int c = 2;
	int num_ways = 0;
	for(int i=3; i<n+1; i++){
		// a = num_ways(n-3)
		// b = num_ways(n-2)
		// c = num_ways(n-1)
		num_ways = a + b + c;
		a = b;
		b = c;
		c = num_ways;
	}

	return num_ways;
}

// this solution is from the online c++ solution, rather unefficient
int countWaysFromCTCI(int n , vector<int> v){

	if (n==0){
		return 1;
	}

	int sum = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if(n>=v[i]){
			sum = sum + countWaysFromCTCI((n-v[i]),v);
		}	
	}
	return sum;
}

int main(){
	int n_steps;
	cin >> n_steps;
	cout << countWays(n_steps) <<endl;
	cout << countWays2(n_steps) <<endl;
	cout << countWays3(n_steps) <<endl;

	vector<int> v;	// vector to store possible step sizes
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	int noOfWays = countWaysFromCTCI(n_steps,v);
	cout<<noOfWays<<endl;	// Total number of stairs = 6
}