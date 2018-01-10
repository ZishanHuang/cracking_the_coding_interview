#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void compress(string & str){
	cout << "old string: " << str << endl;
	string new_str = "";
	int i=0;
	while(i<str.length()){
		char current = str[i];
		int count = 1;
		int j = i+1;
		while(j < str.length() && str[j] == current){
			count++;
			j++;
		}
		new_str += current;
		// problem with using std:to_stting or itoa, wrote solution in python instead
		char * intstr = itoa(count);
		new_str += string(intstr);
		i = j;

	}

	cout << "new string: " << new_str << endl;
	if(new_str.length() >= str.length()){
		cout << "do not convert"<<endl;
	}

	/*
	for(int i=0; i<str.length(); i++){
		char current = str[i];
		int count = 1;
		for(int j=i+1; j<str.length();j++){
			if(str[j] == current){
				count++;
			}
			else{
				break;
			}
		}
		i = 
	}
	*/

}

int main(){
	string str;
	cin >> str;
	compress(str);
}