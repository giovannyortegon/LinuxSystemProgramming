#include "CompoundIntRateCalculator.h"

int main(int argc, char * argv[]) {
    if (argc != 4) {
        std::cout <<"Usage: progName <interest rate> <present value> <num periods>" <<std::endl;
        return (1);
    }

    double rate = atof(argv[1]);
    double value = atof(argv[2]);
    int num_periods = atof(argv[3]);

    CompoundIntRateCalculator cIRCal(rate);
    double res = cIRCal.multiplePeriod(value, num_periods);

    double contRes = cIRCal.continuousCompounding(value, num_periods);

    std::cout <<" future value for multiple period compounding is " << res <<std::endl;
    std::cout <<" future value for continuos compounding is " <<contRes <<std::endl;

    return (0);
}