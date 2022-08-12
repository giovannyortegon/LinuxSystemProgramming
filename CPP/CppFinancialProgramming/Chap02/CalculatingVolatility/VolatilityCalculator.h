/*
 * VolatilityCalculator.h
 */
#ifndef __FinancialSample__VolatilityCalculator__
#define __FinancialSample__VolatilityCalculator__

#include<vector>

class VolatilityCalculator {
    public:
        VolatilityCalculator();
        ~VolatilityCalculator();
        VolatilityCalculator(const VolatilityCalculator &v);
        VolatilityCalculator &operator = (const VolatilityCalculator &v);

        void addPrice(double price);
        double rangeVolatility();
        double stdDev();
        double mean();
        double avgDailyRange();

    private:
        std::vector<double> m_prices;
};

#endif /* defined(__FinancialSample__VolatilityCalculator__) */