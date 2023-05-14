#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAX = 100;
int dp_moves[MAX];
vector<vector<int>> dp_seq(MAX, vector<int>());

pair<int, vector<int>> solution(bool switches[], int no_of_switches, int n)
{
	//------------------------------sefety codition------------------------------------
	if (n == 0 || n < 1) {
		vector<int> vec = { };
		return make_pair(0, vec);
	}
	//------------------------------------base case------------------------------------
	if (n == 1) {
		cout << no_of_switches - 1 << "\t";
		vector<int> vec = { no_of_switches - 1 };
		return make_pair(1, vec);
	}
	//------------------------------------base case------------------------------------
	if (n == 2) {
		cout << no_of_switches - 2 << "\t" << no_of_switches - 1 << "\t";
		vector<int> vec = { no_of_switches - 2,no_of_switches - 1 };
		return make_pair(2, vec);
	}
	int sum = 0;
	//----------------------------turn off n-2 switches from right----------------------------
	if (dp_moves[n - 2] == -1) {
		pair<int, vector<int>> result = solution(switches, no_of_switches, n - 2);
		dp_moves[n - 2] = result.first;
		dp_seq[n - 2] = result.second;
		sum = dp_moves[n - 2];
	}
	else {
		sum = dp_moves[n - 2];
		for (int i = 0; i < dp_seq[n - 2].size(); i++)
			cout << dp_seq[n - 2][i] << "\t";
	}
	//--------------------- turn off toggle right switch to n-2 switches from right----------------
	switches[no_of_switches - n] = 0;
	cout << no_of_switches - n << "\t";
	sum++;
	//--------------------- turn on n-2 switches from right---------------------------------------- 
	sum += dp_moves[n - 2];
	if (n - 2 != 1) {
		for (int i = dp_seq[n - 2].size() - 1; i >= 0; i--)
			cout << dp_seq[n - 2][i] << "\t";
	}
	else
		cout << no_of_switches - 1 << "\t";
	//---------------------- solve same problem for n-1 switches------------------------------------
	if (dp_moves[n - 1] == -1) {
		pair<int, vector<int>> result = solution(switches, no_of_switches, n - 1);
		dp_moves[n - 1] = result.first;
		dp_seq[n - 1] = result.second;
		sum += dp_moves[n - 1];
	}
	else {
		sum += dp_moves[n - 1];
		for (int i = 0; i < dp_seq[n - 1].size(); i++)
			cout << dp_seq[n - 1][i] << "\t";
	}
	//----------------------returning min number and sequece------------------------------------
	vector<int> vec;
	for (int i = 0; i < dp_seq[n - 2].size(); i++)
		vec.push_back(dp_seq[n - 2][i]);
	vec.push_back(no_of_switches - n);
	for (int i = dp_seq[n - 2].size() - 1; i >= 0; i--)
		vec.push_back(dp_seq[n - 2][i]);
	for (int i = 0; i < dp_seq[n - 1].size(); i++)
		vec.push_back(dp_seq[n - 1][i]);
	dp_moves[n] = sum;
	return make_pair(sum, vec);
}
int main()
{
	for (int i = 0; i < MAX; i++) {
		dp_moves[i] = -1;
	}
	int no_of_switches = 4;
	bool* switches = new bool[no_of_switches];
	for (int i = 0; i < no_of_switches; i++)
		switches[i] = true;
	cout << "sequence : ";
	pair<int, vector<int>> result = solution(switches, no_of_switches, no_of_switches);
	cout << "\nmin number = " << result.first << endl;
}