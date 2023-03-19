#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;
}
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
	print(nums);
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
	print(nums);

}
void select_sort(vector<int>& nums)
{
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int min = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
			swap(nums[i], nums[min]);
		}
	}
	cout << "Ñ¡ÔñÅÅÐò: ";
	print(nums);
}
void insert_sort(vector<int>& nums)
{
	int i, j;
	for ( i = 2; i < nums.size(); i++)
	{
		if (nums[i] < nums[i - 1])
		{
			nums[0] = nums[i]; 
			for (j = i - 1; nums[0] < nums[j]; --j)
			{
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = nums[0];
		}
	}
	cout << "Ñ¡ÔñÅÅÐò£º";
	print(nums);
}
void Count_sort(vector<int>& nums)
{
	int max = 0;
	vector<int> num;
	for (int i = 0; i < nums.size(); i++)
	{
		if (max < nums[i])
		{
			max = nums[i];
		}
	}
	vector<int> v(max+1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		v[nums[i]]++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i]; j++)
		{
			num.push_back(i);
		}
	}
	cout << "¼ÆÊýÅÅÐò£º";
	print(num);
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
	insert_sort(v);
	select_sort(v);
	Count_sort(v);
	return 0;
}