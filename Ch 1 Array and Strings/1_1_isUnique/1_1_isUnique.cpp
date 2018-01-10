#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// Given a string, check if it has all unique characters
bool isUnique(const string & str){
	// 128 is the ASCI char set,
	// 256 for the extended ASCII char set
	// might just use the size of the given charset
	if(str.length() > 128){
		return false;
	}
	for(int i=0; i<str.length()-1; i++){
		for(int j=i+1; j<str.length(); j++){
			if(str[i] == str[j]){
				return false;
			}
		}
	}
	return true;
}

bool isUnique2(const string & str){
	if(str.length() > 128){
		return false;
	}
	vector<bool> charset(128);
	for(int i=0; i<str.length();i++){
		int val = str[i];
		cout << val <<endl;
	}
	return true;
}

int main(){
	string str;
	// note: reading in string with cout will cut at a space/tab/newline
	// probably better to just have alist of test strings
	cout << "Enter string:\n";
	cin >> str;
	cout << isUnique2(str) << endl;
}