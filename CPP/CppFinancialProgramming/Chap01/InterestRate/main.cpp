#include "IntRateCalculator.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc != 3) {
        cout <<"Usage: ProgName <interest rate> <value> " <<endl;
        return (1);
    }

    double rate = atof(argv[1]);
    double value = atof(argv[2]);

    IntRateCalculator irCalculator(rate);
    double res = irCalculator.singlePeriod(value);
    cout <<" result is: " <<res <<endl;

    return (0);
}