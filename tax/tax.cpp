#include <iostream>
#include <string>  //defines the string header
// return 0 ends a program (or function) prior to its normal termination
using namespace std;

int main()
{
	// initializing variables
	string name;
	double income;
	string occupation;
	int NumChild;

	cout << "Name: ";
	getline(cin, name); 
	if (name == "")
	{
		cout << "---" << endl;
		cout << "You must enter a name";
		return 0;
	}
	
	cout << "Taxable income: ";
	cin >> income;
	if (income < 0)
	{
		cout << "---" << endl;
		cout << "The taxable income must be nonnegative";
		return 0;
	}
	cin.ignore(10000, '\n');			//get rid of all new lines so getline is not satisfied immediately without user input
	
	cout << "Occupation: ";
	getline(cin, occupation);
	if (occupation == "")
	{
		cout << "---" << endl;
		cout << "You must enter an occupation";
		return 0;
	}

	cout << "Number of children: ";
	cin >> NumChild;
	if (NumChild < 0)
	{
		cout << "---" << endl;
		cout << "The number of children must be nonnegative";
		return 0;
	}
	cin.ignore(10000, '\n');


	// Initiate variables for tax brackets
	double tax;
	double maxtax2 = 0.04 * 50000;
	double maxtax3 = 0.06 * 70000;

	// If statements for tax brackets
	if (income <= 50000)
		tax = 0.04 * income;
	if (income > 50000 && income <= 120000)
		tax = maxtax2 + (income - 50000) * 0.06;
	if (income > 120000)
		tax = maxtax2 + maxtax3 + (income - 120000)*0.09;
	
	// If statements to deduct taxes for certain occupation
	if (income > 120000 && (occupation == "engineer" || occupation == "scientist"))
		tax = tax - 70000 * 0.01;
	if ((income > 50000 && income <= 120000) && (occupation == "engineer" || occupation == "scientist"))
		tax = tax - ((income - 50000) * 0.01);

	// If statement to deduct taxes for dependents
	if (income < 120000)
		tax = tax - (200 * NumChild);

	// If statement to ensure tax is never allowed to go below zero.
	if (tax < 0)
		tax = 0;

	// Print out taxes
	cout.setf(ios::fixed);
	cout.precision(2);						// have two decimal places
	cout << "---" << endl;
	cout << name << " would pay $" << tax;
	return 0;
}
