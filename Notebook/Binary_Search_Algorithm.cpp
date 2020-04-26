// A simple implementation - just to get the idea with a vector<int>
// To do a binary search, your vector has to be sorted!

int binary_search(vector<int> &vector, int &target){
	int L = 0, mid = 0, R = (int)vector.size() - 1,;

	while(L <= R){
		mid = L + (R - L) / 2; // if you try to use [(L + R) / 2] you could get a overflorw!

		if(vector[mid] == target){
			return mid;
		}
		else{
			if(vector[mid] < target){
				L = mid + 1;
			}
			else{
				R = mid - 1;
			}
		}
	}

	return -1;
}

// Lower bound - find the position of the first value >= target

int lower_bound(vector<int> &vector, int &target){
	int L = 0, mid = 0, R = (int)vector.size() - 1,;

	int ans = -1;
	while(L <= R){
		mid = L + (R - L) / 2; // if you try to use [(L + R) / 2] you could get a overflorw!

		if(vector[mid] >= target){
			ans = mid;
			R = mid - 1;
		}
		else{
			L = mid + 1;
		}
	}

	return ans ;
}