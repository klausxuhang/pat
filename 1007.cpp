#include <iostream>
#include <vector>
using namespace std;
typedef struct {
	int left;
	int right;
	int sum;
} ans_tuple;

ans_tuple find_max_subarray(int A[], int low, int high) {
	int this_sum, max_sum;
	this_sum = max_sum = 0;
	int left, right;
	right = left = low;
	vector<int> v_left;
	v_left.push_back(low);
	for (int i = low; i < high; ++i) {
		this_sum += A[i];
		if (this_sum > max_sum) {
			max_sum = this_sum;
			right = i;
		}
		else if (this_sum < 0) {
			this_sum = 0;
			if (i < high - 1) {
				v_left.push_back(i + 1);
			}
		}
	}
	if (max_sum == 0) {
		for (int j = low; j < high; ++j) {
			if (A[j] == 0) {
				return{ A[j],A[j],0 };
			}
		}
		return{ A[low],A[high-1],0 };
	}
	for (int i = v_left.size()-1; i >= 0; --i) {
		if (v_left[i] <= right) {
			left = v_left[i];
			break;
		}
	}
		return{ A[left],A[right],max_sum };
}
int main()
{
	int n;
	cin >> n;
	int A[10000]{};
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	ans_tuple a_t = find_max_subarray(A, 0, n);
	cout << a_t.sum << " " << a_t.left << " " << a_t.right << endl;
	system("pause");
}