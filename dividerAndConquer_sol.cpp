#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, vector<int>> solution(int no_of_switches, int n, bool reversed)
{
	//------------------------------sefety codition--------------------------------------------
	if (n == 0 || n < 1){
	    vector<int> vec = { };
	    return make_pair(0, vec);
    	}
        //------------------------------------base case---------------------------------------------
	if (n == 1){
	    cout << no_of_switches - 1 << "\t";
	    vector<int> vec = { no_of_switches - 1 };
	    return make_pair(1, vec);
	}
        //------------------------------------base case---------------------------------------------
	if (n == 2 && !reversed){
	    cout << no_of_switches - 2 << "\t" << no_of_switches - 1 << "\t";
	    vector<int> vec = { no_of_switches - 2,no_of_switches - 1 };
	    return make_pair(2, vec);
	}

	if (n == 2 && reversed){
	    cout << no_of_switches - 1 << "\t" << no_of_switches - 2 << "\t";
	    vector<int> vec = { no_of_switches - 1,no_of_switches - 2 };
	    return make_pair(2, vec);
	}

	if (!reversed){
	    int sum = 0;
	    //----------------------------turn off n-2 switches from right-------------------------------
	    pair<int, vector<int>> result1 = solution(no_of_switches, n - 2, reversed);
	    sum = result1.first;
	    //--------------------- turn off toggle right switch to n-2 switches from right----------------
	    cout << no_of_switches - n << "\t";
	    sum++;
	    //--------------------- turn on n-2 switches from right----------------------------------------  
	    pair<int, vector<int>> result2 = solution(no_of_switches, n - 2, !reversed);
	    sum += result2.first;
            //---------------------- solve same problem for n-1 switches------------------------------------
	    pair<int, vector<int>> result3 = solution(no_of_switches, n - 1, reversed);
	    sum += result3.first;
            //----------------------returning min number and sequece---------------------------------------
	    vector<int> vec;
	    for (int i = 0; i < result1.second.size(); i++)
	       vec.push_back(result1.second[i]);
	    vec.push_back(no_of_switches - n);
	    for (int i = 0; i < result2.second.size(); i++)
   	       vec.push_back(result2.second[i]);
	    for (int i = 0; i < result3.second.size(); i++)
	       vec.push_back(result3.second[i]);
	    return make_pair(sum, vec);
	}
	else{
	    int sum = 0;
	    //---------------------- solve same problem for n-1 switches------------------------------------
	    pair<int, vector<int>> result1 = solution(no_of_switches, n - 1, reversed);
	    sum = result1.first;
	    //--------------------- turn on n-2 switches from right----------------------------------------  
            pair<int, vector<int>> result2 =  solution(no_of_switches, n - 2, !reversed);
            sum += result2.first;
            //--------------------- turn on n-2 switches from right---------------------------------------- 
	    cout << no_of_switches - n << "\t";
	    sum++;
	    //----------------------------turn off n-2 switches from right-------------------------------
	    pair<int, vector<int>> result3 = solution(no_of_switches, n - 2, reversed);
	    sum += result3.first;
	    //----------------------returning min number and sequece---------------------------------------
	    vector<int> vec;
	    for (int i = 0; i < result1.second.size(); i++)
    	      vec.push_back(result1.second[i]);
    	    for (int i = 0; i < result2.second.size(); i++)
    	      vec.push_back(result2.second[i]);
    	    vec.push_back(no_of_switches - n);
    	    for (int i = 0; i < result3.second.size(); i++)
    	      vec.push_back(result3.second[i]);
    	    return make_pair(sum, vec);
	}
}
int main()
{
    int no_of_switches = 5;
    cout << "sequence : ";
    pair<int, vector<int>> result = solution(no_of_switches, no_of_switches,0);
    cout << "\nmin number = " << result.first << endl;
}
