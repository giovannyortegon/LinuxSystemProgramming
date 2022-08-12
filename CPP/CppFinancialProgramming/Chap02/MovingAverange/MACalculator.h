/*
 * MACalculator.h
 */
#ifndef __FinancialSample__MACalculator__

#include <vector>

class MACalculator{
    public:
        MACalculator(int period);
        MACalculator(const MACalculator &);
        MACalculator &operator = (const MACalculator &);
        ~MACalculator();

        void addPriceQuote(double close);
        std::vector<double> calculateMA();
        std::vector<double> calculateEMA();

    private:
        // number of periods used in the calculation
        int m_numPeriods;
        std::vector<double> m_prices;
};

#endif /* defined(__FinalcialSample__MACalculator__) */