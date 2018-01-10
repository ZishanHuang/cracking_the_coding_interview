#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

bool checkPermutation(const string & s1, const string &s2){
	if (s1.length() != s2.length()){
		return false;
	}
	map<char, int> count_chars;
	for(int i=0; i<s1.length(); i++){
		// if(count_chars.find(s1[i]) == count_chars.end()){
			// count_chars.insert(make_pair(s1[i], 0))
		// }
		// if(count_chars.find(s2[i]) == count_chars.end()){
			// count_chars.insert(make_pair(s2[i], 0))
		// }
		++count_chars[s1[i]];
		--count_chars[s2[i]];
	}
	for(map<char, int>::const_iterator itr = count_chars.begin(); itr != count_chars.end(); itr++){
		if(itr->second != 0){
			cout <<"false"<<endl;
			return false;
		}
	}
	cout << "true"<<endl;
	return true;
}

int main(){
	string str1;
	string str2;
	cin >> str1 >>str2;
	cout << checkPermutation(str1, str2)<<endl;
}