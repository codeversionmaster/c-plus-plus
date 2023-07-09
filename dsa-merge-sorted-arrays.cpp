#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		static void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
};

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;

	while(i >= 0 && j >= 0) 
	{
		if(nums2[j] >= nums1[i]) 
		{
			nums1[k] = nums2[j];
			cout << "k: " << k << " nums1[k]: " << nums1[k] << endl;
			j = j - 1;
			k = k - 1;
		}
		else
		{
			nums1[k] = nums1[i];
			cout << "k: " << k << " nums1[k]: " << nums1[k] << endl;
			i = i - 1;
			k = k - 1;
		}
	}

	if(i >= 0) 
	{
		while(i >= 0)
		{
			nums1[k] = nums1[i];
			cout << "k: " << k << " nums1[k]: " << nums1[k] << endl;
			i = i - 1;
			k = k - 1;
		}
	}
	else if(j >= 0)
	{
		while(j >= 0)
		{
			nums1[k] = nums2[j];
			cout << "k: " << k << " nums1[k]: " << nums1[k] << endl;
			j = j - 1;
			k = k - 1;
		}
	}
}

int main()
{
	int m, n;
	vector<int> nums1, nums2;

	//For taking the inputs from standard input, uncomment below section
	/*
	int input;

	cout << "Enter m" << endl;
	cin >> m;

	cout << "Enter the first vector, press Enter after each variable" << endl;
	for(int i = 0; i < m; i++) {
		if(cin >> input)
			nums1.push_back(input);
	}

	cout << "Enter n" << endl;
	cin >> n;

	cout << "Enter the second vector, press Enter after each variable" << endl;
	for(int i = 0; i < n; i++) {
		if(cin >> input) {
			nums2.push_back(input);
			nums1.push_back(0);
		}
	}
	*/

	//Directly assigning for ease of use
	m = 3;
	n = 4;
	nums1 = { 2, 4, 6, 0, 0, 0, 0};
	nums2 = { 3, 4, 7, 9};

	cout << "Before - nums1 array is:" << endl;
	for(auto elem:nums1)
		cout << elem << endl;

	cout << "Before - nums2 array is:" << endl;
	for(auto elem:nums2)
		cout << elem << endl;

	Solution::merge(nums1, m, nums2, n);

	cout << "After - nums1 array is:" << endl;
	for(auto elem:nums1)
		cout << elem << endl;

	cout << "After - nums2 array is:" << endl;
	for(auto elem:nums2)
		cout << elem << endl;

}
