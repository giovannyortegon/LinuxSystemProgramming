#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//Declaration of top-level funcions
void input(double &invest, double &rate, double &term);
void process(double invest, double rate, double term,
			 double &multiplier, double &futureValue);
void output(double invest, double rate, double term,
			double multiplier, double futureValue);
// Declaration of low-level functions
double getInput(string message);
double findMultiplier(double rate, double period);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double value);

int main()
{
	// Variable Declaration
	double invest, rate, term;
	double multiplier, futureValue;
	// Call first level functions
	input(invest, rate, term);
	process(invest, rate, term, multiplier, futureValue);
	output(invest, rate, term, multiplier, futureValue);

	return (0);
}
void input(double &invest, double &rate, double &term)
{
	invest = getInput("Enter the value of periodic investment: ");
	rate = getInput("Enter the interest rate per year: ");
	term = getInput("Enter the term (number of years): ");
}
void process(double invest, double rate, double term,
			 double &multiplier, double &futureValue)
{
	multiplier = findMultiplier(rate, term);
	futureValue = multiplier * invest;
}
void output(double invest, double rate, double term,
			double multiplier, double futureValue)
{
	printData(invest, rate, term);
	printResult(multiplier, futureValue);
}
double getInput(string message)
{
	double input;

	do
	{
		cout <<message;
		cin >>input;
	} while(input < 0.0);

	return input;
}
double findMultiplier(double rate, double period)
{
	double multiplier = 0;
	double factor = 1 + rate / 100;

	for (int i = period; i > 0; i--)
	{
		multiplier += pow(factor, i);
	}

	return (multiplier);
}
void printData(double invest, double rate, double term)
{
	cout <<endl <<"Information about period investment" <<endl;
	cout <<"Periodic Investment: " <<fixed <<setprecision(2) <<invest <<endl;
	cout <<"Interest rate: " <<rate <<fixed <<setprecision(2);
	cout <<" percent per year" <<endl;
	cout <<"Term: " <<term <<" yeard" <<endl <<endl;
}
void printResult(double multiplier, double futureValue)
{
	cout <<"Result of investment" <<endl;
	cout <<"Investment is multiplied by: " <<fixed <<setprecision(8);
	cout <<multiplier <<endl;
	cout <<"Future value: " <<fixed <<setprecision(2);
	cout <<futureValue <<endl;
}
