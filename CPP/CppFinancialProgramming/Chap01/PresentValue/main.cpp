#include"CashFlowCalculator.h"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cout <<"Usage: progName <interest rate>" <<std::endl;

        return (1);
    }

    double rate = atof(argv[1]);

    CashFlowCalculator cfc(rate);

    do {
        int period;
        std::cin >> period;

        if (period == -1) {
            break;
        }

        double value;
        std::cin >> value;

        cfc.addCashPayment(value, period);
    }while (1);

    double result = cfc.presentValue();
    std::cout <<" The present values is " <<result <<std::endl;

    return (0);
}