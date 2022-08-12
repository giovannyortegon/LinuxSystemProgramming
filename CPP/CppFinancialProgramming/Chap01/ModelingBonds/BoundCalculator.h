#ifndef __FinancialSamples__BoundCalculator__
#define __FinancialSamples__BoundCalculator__

#include<iostream>

class BoundCalculator {
    public:
        BoundCalculator(const std::string institution, int numPeriods, double principal,
                        double couponValue);
        BoundCalculator(const BoundCalculator &v);
        BoundCalculator &operator = (const BoundCalculator &v);
        ~BoundCalculator();

        double interestRate();

    private:
        std::string m_institution;
        double m_principal;
        double m_coupon;
        int m_numPeriods;
};

#endif /* __FinancialSamples__BoundCalculator__ */