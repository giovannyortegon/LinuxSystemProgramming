#include"IntRateCalculator.h"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cout <<"Usage: programName <interest rate> <rate>" <<std::endl;
        return (1);
    }

    double rate = atof(argv[1]);
    double value = atof(argv[2]);

    IntRateCalculator irCalculate(rate);
    double res = irCalculate.singlePeriod(value);

    std::cout <<"result is " <<res <<std::endl;

    return (0);
}
