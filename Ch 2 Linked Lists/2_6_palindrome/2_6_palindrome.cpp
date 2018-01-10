#include <iostream>
#include <string>
#include <list>

using namespace std;
struct Node
{
 int data = 0;
 Node *next = NULL;
};



bool checkPalindrom(const list<int> & lst){
	list<int>::const_iterator itr1 = lst.begin();
	list<int>::const_iterator itr2 = lst.end();
	itr2--;
	while(itr1 != itr2){
		if(*itr1 != *itr2){
			return false;
		}
		itr1++;
		itr2--;
	}
	return true;
}
int main(){
	while(true){
		int n;
		cin >> n;
		if(n==-1){
			break;
		}
		list<int> lst;
		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			lst.push_back(tmp);
		}
		cout << "Read in list of size "<< n<<endl;
		for(list<int>::iterator itr=lst.begin();itr!= lst.end();itr++){
			cout << *itr <<" ";
		}
		cout << endl;
		if(checkPalindrom(lst) == true){
			cout << "true"<<endl;
		}
		else{
			cout << "false"<<endl;
		}
	}
}