#include <iostream>
#include <vector>

using namespace std;

int magicIndex(const vector<int> & arr){
	for(int i=0; i<arr.size(); i++){
		if(arr[i] == i) return i;
	}
	return -1;
}

int magicIndex2(const vector<int> & arr){
	int low = 0;
	int high = arr.size()-1;
	while(true){
		if(arr[low] == low) return low;
		if(arr[high] == high) return high;
		if(low == high){
			if(arr[low] == low) return low;
			break;
		}
		if(arr[low] > low){
			low = arr[low];
		}
		if(arr[high] < high){
			high = arr[high];
		}
		int mid = (low + high) / 2;
		if(arr[mid] == mid){
			return mid;
		}
		else if(arr[mid] > mid){
			high = mid;
		}
		else{ // arr[mid] < mid
			low = mid;
		}
	}
	return -1;
}

// book's solution rewritten by me in iterative method
int magicIndexSolution(const vector<int> & arr){
	int low = 0;
	int high = arr.size()-1;
	while(true){
		if(low > high){
			return -1;
		}
		int mid = (low + high) / 2;
		if(arr[mid] == mid){
			return mid;
		}
		else if(arr[mid] > mid){
			high = mid - 1;
		}
		else{ // arr[mid] < mid
			low = mid + 1;
		}
	}
	// return -1;
}

// book's solution (elements in array sorted and distinct)
int magicIndexSolution2(const vector<int> & arr, int low, int high){
	if(low > high){
		return -1;
	}
	int mid = (low + high) / 2;
	if(arr[mid] == mid){
		return mid;
	}
	else if(arr[mid] > mid){
		return magicIndexSolution2(arr, low, mid-1);
	}
	else{ // arr[mid] < mid
		return magicIndexSolution2(arr, mid+1, high);
	}
}

// book's solution (elements in array sorted, not distinct)
int magicIndexSolutionNotDistinct2(const vector<int> & arr, int low, int high){
	if(low > high){
		return -1;
	}
	int mid = (low + high) / 2;
	if(arr[mid] == mid){
		return mid;
	}
	// search left
	int leftIndex = min(mid-1, arr[mid]);
	int left = magicIndexSolution2(arr, low, leftIndex);
	if(left > 0){
		return left;
	}

	int rightIndex = max(mid+1, arr[mid]);
	int right = magicIndexSolution2(arr, rightIndex, high);
	return right;
}

int main(){
	vector<int> arr;
	int n;
	cin >> n;
	for(int i=0; i<n;i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	cout << "magic index: " << magicIndex(arr) <<endl;

	cout << "magic index: " << magicIndex2(arr) <<endl;
}