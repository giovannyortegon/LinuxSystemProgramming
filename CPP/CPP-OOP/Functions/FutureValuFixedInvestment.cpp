/***************************************************************
* The program shows how to use functions to calculate the future
*
* value of an investment that earns compound interest.
*
***************************************************************/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

// Declaration of top-level function
void input(double &invest, double &rate, double &term);
void process(double invest, double rate, double term,
			 double &multiplier, double &futureValue);
void output(double invest, double rate, double term,
			double multiplier, double futureValue);

// Declaration of low-level functions
double getInput(string message);
double findMultiplier(double rate, double term);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double futureValue);

int main()
{
// Variable Declaration
	double invest, rate, term;		// For input
	double multiplier, futureValue; // For Result
// Call first level functions
	input(invest, rate, term);
	process(invest, rate, term, multiplier, futureValue);
	output(invest, rate, term, multiplier, futureValue);

	return (0);
}
/***************************************************************
* The input function gets three inputs by calling the getInput
*
* function three times. It uses pass-by-reference to send back
*
* the values to main. After the function termination, the
*
* data values are stored in invest, rate, and term.
*
***************************************************************/
void input(double &invest, double &rate, double &term)
{
	invest = getInput("Enter the value of investment: ");
	rate = getInput("Enter the interest rate per year: ");
	term = getInput("Enter the term (number of years): ");
}
/***************************************************************
* The process function calls findMultiplier to calculate the
*
* the multiplier. It then multiplies the return value by the value
*
* invested to find the future value.
*
***************************************************************/
void process(double invest, double rate, double term,
			 double &multiplier, double &futureValue)
{
	multiplier = findMultiplier(rate, term);
	futureValue = multiplier * invest;
}
/***************************************************************
* The output function calls printData to print three given values.
*
* It then calls printResult to print the two calculated values.
*
***************************************************************/
void output(double invest, double rate, double term,
			double multiplier, double futureValue)
{
	printData(invest, rate, term);
	printResult(multiplier, futureValue);
}
/***************************************************************
* The getInput function gets the input from the user. Its only
*
* parameter is an object of type string that contains a
*
* different message in each call to ask the user to input
*
* the appropriate data. It validates the data and sends it
*
* back to the calling expression in the input function.
*
***************************************************************/
double getInput(string message)
{
	double input;

	do
	{
		cout <<message;
		cin >> input;
	} while (input < 0.0);

	return (input);
}
/***************************************************************
* The findMultiplier is very simple. The two values, rate and term,
*
* are passed to it by value. It first calculates the factor. It
*
* then returns the multiplier using the pow function.
*
***************************************************************/
double findMultiplier(double rate, double term)
{
	double factor = 1 + rate / 100;

	return (pow(factor, term));
}
/***************************************************************
* The printData function prints the three data items input by
*
* the user with appropriate explanations. It is a void function
*
* with only side effects.
*
***************************************************************/
void printData(double invest, double rate, double term)
{
	cout <<endl <<"Information about investment"<<endl;
	cout <<"Investment: " <<fixed <<setprecision(2) <<invest <<endl;
	cout <<"Interest rate: " <<rate <<fixed <<setprecision(2);
	cout <<" percent per year " <<endl;
	cout <<"Term: " <<term <<" year" <<endl <<endl;
}
/***************************************************************
* The printResult function prints the two results of the program.
*
* It prints the multiplier and the futureValue of the investment.
*
* It is also a void function with only side effects.
*
***************************************************************/
void printResult(double multiplier, double futureValue)
{
	cout <<"Investment is multiplied by: " <<fixed <<setprecision(8);
	cout <<multiplier <<endl;
	cout <<"Future value: " <<fixed <<setprecision(2);
	cout <<futureValue <<endl;
}
