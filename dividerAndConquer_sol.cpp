#include <iostream>
using namespace std;

int step = 0;

void state(bool switches[], int no_of_switches)
{
	cout << "step " << step << "    ";
	for (int i = 0; i < no_of_switches; i++)
	cout << switches[i] << "\t";
	cout << endl;
	step++;
}
void solution(bool switches[], int no_of_switches, int n, bool reversed)
{
	if (n == 0 || n < 1)
	return;

	if (n == 1)
	{
		cout << "n = 1"  << endl;
		if (switches[no_of_switches - 1] != 0)
		{
			switches[no_of_switches - 1] = 0;  state(switches, no_of_switches);
		}

		return;
	}

	if (n == 2 && !reversed)
	{
		cout << "n = 2" << endl;
		if (switches[no_of_switches - 2] != 1)
		{
			switches[no_of_switches - 2] = 1;    state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 1)
		{
			switches[no_of_switches - 1] = 1;    state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 2] != 0)
		{
			switches[no_of_switches - 2] = 0;     state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 1)
		{
			switches[no_of_switches - 1] = 1;	  state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 2] != 0)
		{
			switches[no_of_switches - 2] = 0;     state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 0)
		{
			switches[no_of_switches - 1] = 0;    state(switches, no_of_switches);
		}

		return;
	}

	if (n == 2 && reversed)
	{
		cout << "n = 2 reversed" << endl;
		if (switches[no_of_switches - 2] != 0)
		{
			switches[no_of_switches - 2] = 0;     state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 0)
		{
			switches[no_of_switches - 1] = 0;    state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 2] != 0)
		{
			switches[no_of_switches - 2] = 0;     state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 1)
		{
			switches[no_of_switches - 1] = 1;	  state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 2] != 1)
		{
			switches[no_of_switches - 2] = 1;    state(switches, no_of_switches);
		}

		if (switches[no_of_switches - 1] != 1)
		{
			switches[no_of_switches - 1] = 1;    state(switches, no_of_switches);
		}

		return;
	}

	if (!reversed)
	{
		//--------------------- turn off n-2 switches from right
		solution(switches, no_of_switches, n - 2, reversed);

		//--------------------- turn off toggle right switch to n-2 switches from right
		cout << "zering a bit from left" << endl;
		switches[no_of_switches - n] = 0;   state(switches, no_of_switches);
		
		//--------------------- turn on n-2 switches from right
		solution(switches, no_of_switches, n - 2, !reversed);

		//---------------------- solve same problem for n-1 switches
		solution(switches, no_of_switches, n - 1, reversed);
	}
	else
	{
		solution(switches, no_of_switches, n - 1, reversed);

		solution(switches, no_of_switches, n - 2, !reversed);

		cout << "oning a bit from left" << endl;
		switches[no_of_switches - n] = 1;   state(switches, no_of_switches);
		
		solution(switches, no_of_switches, n - 2, reversed);
	}
}

int main()
{
	int no_of_switches = 6;
	bool* switches = new bool[no_of_switches];
	for (int i = 0; i < no_of_switches; i++)
	switches[i] = true;
	state(switches, no_of_switches);
	solution(switches, no_of_switches, no_of_switches, 0);
}