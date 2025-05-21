#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
	ifstream inputfile("../input.txt");
	vector<vector<int>> values;
	string line;

	while (getline(inputfile, line))
	{
		istringstream iss(line);
		values.push_back(vector<int>(istream_iterator<int>(iss), istream_iterator<int>()));
	}
	inputfile.close();

	int result = 0;
	for (size_t i = 0; i < values.size(); i++)
	{
		bool safe = false;
		bool increasing = false;
		bool decreasing = false;

		for (size_t j = 0; j < values[i].size() - 1; j++)
		{
			int val1 = values[i][j];
			int val2 = values[i][j+1];

			if (val2 > val1)
			{
				increasing = true;
			}
			else if (val2 < val1)
			{
				decreasing = true;
			}

			if (abs(val1 - val2) <= 3 && abs(val1 - val2) >= 1)
			{
				safe = true;
			}
			else
			{
				safe = false;
				break;
			}

			if (increasing && decreasing)
			{
				safe = false;
				break;
			}

		}

		if (safe)
		{
			result++;
		}
	}

	cout << result << endl;
	return 0;
}
