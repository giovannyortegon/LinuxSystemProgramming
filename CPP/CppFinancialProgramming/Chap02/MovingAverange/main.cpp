/*
 * main.cpp
 */
#include"MACalculator.h"

#include<iostream>

/*
 * The main function receives parameters passed to the prpgram
 * and calls the MACalculator class
 */

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cout <<"Usage: progName <num periods>" <<std::endl;
        return (1);
    }

    int num_periods = atoi(argv[1]);
    double price;
    MACalculator calculator(num_periods);

    for (;;) {
        std::cin >> price;
        if (price == -1) {
            break;
        }
        calculator.addPriceQuote(price);
    }
    
    std::vector<double> ma = calculator.calculateMA();

    for (int i = 0; i < ma.size(); i++) {
        std::cout <<"average value: " <<i <<" = " <<ma[i] << std::endl;
    }

    std::vector<double> ema = calculator.calculateEMA();

    for (int i = 0; i < ema.size(); i++) {
        std::cout <<"exponential average value " <<i <<" = " << ema[i] <<std::endl;
    }

    return (0);
}