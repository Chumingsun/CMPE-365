//Chu Ming Sun 10196230
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include <math>
using namespace std;
struct Set
{
	vector<int> elements;
	int sum = 0;
};
vector<Set> Modified_BFI_Subset_Sum(vector<int>& S, int k)
{
	Set emptySet;

	vector<Set> subsets;
	subsets.push_back(emptySet);

	bool flag = false;
	for (int i = 0;i < S.size();i++)
	{
		vector<Set> newSubsets;
		for (Set old_u : subsets)
		{
			Set new_u;
			new_u.elements = old_u.elements;
			new_u.elements.push_back(S[i]);
			new_u.sum = old_u.sum + S[i];
			if (new_u.sum == k)
			{
				return subsets;
			}
			else
			{
				newSubsets.push_back(new_u);
				newSubsets.push_back(old_u);
			}
		}
		subsets = newSubsets;
	}
	return subsets;
}
//compare the set a and set b
bool compare(Set a, Set b)
{
	return a.sum < b.sum;
}
//Compute the BFI_Subset_Sum operations
int Compute_BFI_Subset_Sum_Operations(vector<int>& S, int k)
{
	Set emptySet;
	vector<Set> subsets;
	subsets.push_back(emptySet);
	bool flag = false;
	int sum = 4;
	for (int i = 0;i < S.size();i++)
	{
		vector<Set> newSubsets;
		for (Set old_u : subsets)
		{

			Set new_u;
			new_u.elements = old_u.elements;
			new_u.elements.push_back(S[i]);
			new_u.sum = old_u.sum + S[i];
			sum += 3;
			if (new_u.sum == k)
			{
				return sum;
			}
			else
			{
				newSubsets.push_back(new_u);
				newSubsets.push_back(old_u);
				sum += 2;
			}
		}
		sum++;
		subsets = newSubsets;
		sum++;
	}
	return sum;
}
//pair the sums
pair<int, int> pair_sum(vector<Set> &v1, vector<Set>& v2, int k,int& sum)
{
	int i = 0;
	int j = v2.size() - 1;
	sum = sum + 2;
	while (i<v1.size() && j>0) {

		int t = v1[i].sum + v2[j].sum;
		sum = sum + 2;

		if (t == k)
			return make_pair(i, j);
		else if (t < k)
			i++;
		else
			j--;
		sum = sum + 1;
	}
	return make_pair(-1, -1);

}
//computer the HS Sums
int Compute_HS_Subset_Sum_Operations(vector<int>S, int k)
{
	int size = S.size();
	vector<int> leftS;
	vector<int> rightS;
	int sum = 3;
	for (int i = 0;i < size / 2;i++)
	{
		leftS.push_back(S[i]);
		sum++;
		sum++;
	}
	for (int i = size / 2;i < size;i++)
	{
		rightS.push_back(S[i]);
		sum++;
		sum++;
	}
	vector<Set> left_subset = Modified_BFI_Subset_Sum(leftS, k);
	vector<Set> right_subset = Modified_BFI_Subset_Sum(rightS, k);
	sum += Compute_BFI_Subset_Sum_Operations(leftS, k);
	sum += Compute_BFI_Subset_Sum_Operations(rightS, k);

	for (int i = 0;i < left_subset.size();i++)
	{
		sum++;

		if (k == left_subset[i].sum)
		{
			return sum;
		}
		sum++;

	}
	for (int i = 0;i < right_subset.size();i++)
	{
		sum++;
		if (k == right_subset[i].sum)
		{
			return sum;
		}
		sum++;

	}
	sort(left_subset.begin(), left_subset.end(), compare);
	sum += left_subset.size() * 3 * log(left_subset.size());
	sort(right_subset.begin(), right_subset.end(), compare);
	sum += right_subset.size() * 3 * log(right_subset.size());
	pair<int, int> p = pair_sum(left_subset, right_subset, k, sum);
	return sum;
}
//calculate function
void calculate()
{
	int BFI_total_sum = 0;
	int HS_total_sum = 0;
	for (int n = 4;n <= 15;n++)
	{
		srand(time(0));

		int BFI_n_sum = 0;
		int HS_n_sum = 0;
		for (int i = 1;i <= 20;i++)
		{

			int BFI_set_sum = 0;
			int HS_set_sum = 0;
			vector<int> s;
			for (int j = 0;j < n;j++)
			{
				s.push_back(rand() % 15 + 1);
			}
			vector<int> kVal;
			for (int j = 0;j < 10;j++)
			{
				kVal.push_back(rand() % 30 + 1);
			}
			for (int k : kVal)
			{
				BFI_set_sum += Compute_BFI_Subset_Sum_Operations(s, k);
				HS_set_sum += Compute_HS_Subset_Sum_Operations(s, k);
			}
			cout << "average number of operations for BFI_Subset_Sum for this set is: " << BFI_set_sum / 10 <<endl;
			cout << "average number of operations for HS_Subset_Sum for this set is: " << HS_set_sum / 10 << endl;
			BFI_n_sum += BFI_set_sum;
			HS_n_sum += HS_set_sum;
		}
		cout << "average number of operations for BFI_Subset_Sum for this n: " << BFI_n_sum / (n*20) << endl;
		cout << "average number of operations for HS_Subset_Sum for this n: " << HS_n_sum / (n * 20) <<endl;
		BFI_total_sum += BFI_n_sum;
		HS_total_sum += HS_n_sum;
	}

	cout << "Overall average number of operations for BFI_Subset_Sum: " << BFI_total_sum / 11 << endl;
	cout << "Overall number of operations for HS_Subset_Sum:" << HS_total_sum / 11 << endl;
}
void main()
{
	calculate();
}