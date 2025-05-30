#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

void sortList(vector<int>& list);

int main()
{
	vector<int> left_list;
	vector<int> right_list;
	ifstream inputfile("../input.txt");

	int left, right;
	while (inputfile >> left >> right)
	{
		left_list.push_back(left);
		right_list.push_back(right);
	}
	inputfile.close();

	sortList(left_list);
	sortList(right_list);

	int result = 0;
	for (size_t i = 0; i < left_list.size(); i++)
	{
		int count = 0;

		for (size_t j = 0; j < right_list.size(); j++)
		{
			if (left_list[i] == right_list[j])
			{
				count++;
			}
			else if (right_list[j] > left_list[i])
			{
				break;
			}
		}
		
		result += (left_list[i] * count);
	}

	cout << result << endl;

	return 0;
}

void sortList(vector<int>& list)
{
	bool swap = true;

	while (swap)
	{
		swap = false;

		for (size_t i = 0; i < list.size() - 1; i++ )
		{
            if (list[i] > list[i + 1])
            {
                int temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                swap = true;
            }
		}
	}
}
