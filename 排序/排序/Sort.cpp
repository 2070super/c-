#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int>& nums)
{
	int flag;
	for (int i = nums.size(); i >0; i--)
	{	
		flag = 0;
		for (int j = nums.size()-1; j>0; j--)
		{
			
			if (nums[j] < nums[j - 1])
			{
				swap(nums[j], nums[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			{
				break;
			}
	}
	cout << "Ã°ÅÝÅÅÐò£º";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i]<<' ';
	}
	cout << endl;
}
int partition(vector<int>& A,int low,int high)
{
	int num = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= num)
		{
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= num)
		{
			++low;
		}
		A[high] = A[low];
	}
	A[low] = num;
	return low;
}
void quick_sort1(vector<int>& nums,int low,int high)
{
	if (low < high)
	{
		int pivotpos = partition(nums, low, high);
		quick_sort1(nums, low, pivotpos-1);
		quick_sort1(nums, pivotpos + 1, high);

	}
}void quick_sort(vector<int>& nums)
{
	quick_sort1(nums, 0, nums.size() - 1);
	cout << "¿ìËÙÅÅÐò£º";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;

}
void select_sort(vector<int>& nums)
{

}
int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	quick_sort(v);
	bubble_sort(v);
	return 0;
}