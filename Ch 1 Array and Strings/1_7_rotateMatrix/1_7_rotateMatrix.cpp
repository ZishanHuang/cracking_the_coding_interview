#include <iostream>
#include <vector>
#include <string>

using namespace std;

// rotate an NxN matrix by 90 degrees

void print(const vector<vector<float> > & matrix){
	cout << endl;
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[i].size(); j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
// wrong solution, this transpose the matrix, not rotate the matrix
void transpose(vector<vector<float> > & matrix){
	for(int i=0; i<matrix.size(); i++){
		for(int j=i+1; j<matrix[i].size(); j++){
			float tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}
// rotate 90 degrees right, assuming NxN matrix
void rotate(vector<vector<float> > & matrix){
	cout << "in rotate\n";
	int n = matrix.size();
	for(int i=0; i<n/2; i++){
		cout << "i=" << i<<endl;
		for(int j=i; j<n - i-1; j++){
			cout <<"j="<<j<<endl;
			float tmp = matrix[i][j];
			matrix[i][j] = matrix[n-j-1][i];
			matrix[n-j-1][i] = matrix[n-(i)-1][n-j-1];
			// matrix[n-i-1][n-j-1] = matrix[n-(n-j-1)-1][n-i-1];
			matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
			matrix[j][n-i-1] = tmp;
			// print(matrix);
		}
	}
	cout << "end rotate\n";
}



int main(){
	int size;
	vector<vector<float> > matrix;
	cin >> size;
	for(int i=0; i<size*size; i++){
		if(i%size == 0){
			matrix.push_back(vector<float>());
		}
		int entry;
		cin >> entry;
		matrix[i/size].push_back(entry);
	}
	print(matrix);
	rotate(matrix);
	print(matrix);
}