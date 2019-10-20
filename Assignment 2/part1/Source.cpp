//Chu Ming Sun 10196230
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
struct Set
{
	vector<int> elements;
	int sum=0;
};

//Print the Vectors
void print(vector<int> &elem)
{
	cout << "{ ";
	for (int j = 0;j < elem.size();j++)
	{
		cout << elem[j];
		if (j != elem.size() - 1)
			cout << ",";
	}
	cout << " }\n";
}
//BFI Subset
void BFI_Subset_Sum(vector<int>& S, int k)
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
				print(new_u.elements);
				return;
			}
			else
			{
				newSubsets.push_back(new_u);
				newSubsets.push_back(old_u);
			}
		}
		subsets = newSubsets;
	}
	cout << "no subset sums to the target value\n";
}

//Modified Subset
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
//Compare a and b
bool compare(Set a, Set b)
{
	return a.sum < b.sum;
}
pair<int,int> pair_sum(vector<Set> &v1,vector<Set>& v2,int k)
{
	int i = 0;
	int j = v2.size() - 1;
	while(i<v1.size()&&j>0){
		int t = v1[i].sum + v2[j].sum;
		if (t == k)
			return make_pair(i, j);
		else if (t < k)
			i++;
		else
			j--;
	}
	return make_pair(-1, -1);

}
//HS SubSet
void HS_Subset_Sum(vector<int>S, int k)
{
	int size = S.size();
	vector<int> leftS;
	vector<int> rightS;
	for (int i = 0;i < size / 2;i++)
	{
		leftS.push_back(S[i]);
	}
	for (int i = size / 2;i < size;i++)
	{
		rightS.push_back(S[i]);
	}
	vector<Set> left_subset = Modified_BFI_Subset_Sum(leftS, k);
	vector<Set> right_subset = Modified_BFI_Subset_Sum(rightS, k);

	for (int i = 0;i < left_subset.size();i++)
	{
		if (k == left_subset[i].sum)
		{
			print(left_subset[i].elements);
			return;
		}
	}
	for (int i = 0;i < right_subset.size();i++)
	{
		if (k == right_subset[i].sum)
		{
			print(right_subset[i].elements);
			return;
		}
	}
	sort(left_subset.begin(), left_subset.end(), compare);
	sort(right_subset.begin(), right_subset.end(), compare);
	pair<int, int> p = pair_sum(left_subset, right_subset, k);
	if (p.first != -1 && p.second != -1)
	{
		cout << "{";
		for (int l = 0;l < left_subset[p.first].elements.size();l++)
		{
			cout << left_subset[p.first].elements[l] << ",";
		}
		for (int l = 0;l < right_subset[p.second].elements.size();l++)
		{
			cout << right_subset[p.second].elements[l];
			if (l != right_subset[p.second].elements.size() - 1)
				cout << ",";
		}
		cout << " }\n";
		return;
	}
	cout << "no subset sums to the target value\n";

}
void main()
{
	vector<int> arr = { 3,5,3,9,18,4,5,6 };
	BFI_Subset_Sum(arr, 28);
	HS_Subset_Sum(arr, 28);
}