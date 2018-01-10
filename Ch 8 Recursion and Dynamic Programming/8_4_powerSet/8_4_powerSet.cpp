#include <iostream>
#include <vector>
#include <set>

using namespace std;
// vector<set<int> > powerSet(const set<int> & original_set){
// 	vector<set<int> > powerset;

// }

void print(const vector<int> & v){
	cout << "[ ";
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout <<"]\n";
}

vector<vector<int> > powerSet(const vector<int> & original_set){
	vector<vector<int> > powerset;
	// add an empty set first
	powerset.push_back(vector<int>());
	for(int i=0; i<original_set.size(); i++){
		int psize = powerset.size();
		for(int j=0; j<psize; j++){
			vector<int> new_set(powerset[j]);
			new_set.push_back(original_set[i]);
			powerset.push_back(new_set);
		}
	}
	for(int i=0;i<powerset.size();i++){
		print(powerset[i]);
	}
	return powerset;
}

// the book's solution for my powerSet function is the same but uses recursion
// there is a second approach for solving the problem from the book,
// 


int main(){
	int n;
	vector<int> original_set;
	cin >> n;
	for(int i=0; i<n;i++){
		int tmp;
		cin >> tmp;
		original_set.push_back(tmp);
	}
	powerSet(original_set);
}