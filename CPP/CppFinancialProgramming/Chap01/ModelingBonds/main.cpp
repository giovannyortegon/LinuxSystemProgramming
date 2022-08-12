#include"BoundCalculator.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout <<"Usage: prigName <institution> <principal> <coupon> <num_periods>" <<std::endl;

        return (1);
    }

    std::string issuer = argv[1];
    double principal = atof(argv[2]);
    double coupon = atof(argv[3]);
    int num_periods = atoi(argv[4]);

    BoundCalculator bc(issuer, principal, coupon, num_periods);

    std::cout <<"Reading information for bond issued by " <<issuer <<std::endl;
    std::cout <<"the internal rate of return is "  <<bc.interestRate() <<std::endl;

    return (0); 
}