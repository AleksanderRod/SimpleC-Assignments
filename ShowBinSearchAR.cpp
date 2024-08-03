// Author: Aleksander Rodriguez
// Course: COSC 2436
// Program Set 3
// References: None


#include <iostream>

using namespace std;

int main()
{
	char yes = 'y';
	
	do
	{
		int N;
		int R;
		int Rtest = 0;
		int first = 1;
		int middle;
		int last;
		bool found = false;

		// ask the user the max number and the number to search
		cout << "Enter largest range value [1-100000]: ";
		cin >> N;
		cout << "Enter search target: ";
		cin >> R;
		cout << endl;

		last = N;
	
		// modified binary search for this problem
		if(R > 0)
		{
			while (!found)
			{
				middle = ((first + last) / 2);
				if (middle == R)
				{
					found = true;
					cout << first << "-" << middle << "-" << last << endl;
				}
				else if (R < middle)
				{
					cout << first << "-" << middle << "-" << last << endl;
					last = middle - 1;
				}
				else
				{
					cout << first << "-" << middle << "-" << last << endl;
					first = middle + 1;
				}
			}
		}
		else {
			R = 0;
			while (!found)
			{
				middle = ((first + last) / 2);
				if (middle == R)
				{
					found = true;
					
				}
				else if (R < middle)
				{
					cout << first << "-" << middle << "-" << last << endl;
					last = middle - 1;
				}
				else
				{
					cout << first << "-" << middle << "-" << last << endl;
					first = middle + 1;
				}
			}
			found = false;

		}

		//if found cout got it or not got it
		if (found == true)
			cout << "GOT IT!"<< endl ;
		else
			cout << "NOT GOT IT!" << endl; // when will it "not got it"??

		//Check case
		cout << endl << "Run Again (Y/N): ";
		cin >> yes;
		cout << endl << endl;

	} 
	while (yes == 'Y' || yes == 'y');
	return 0;
}