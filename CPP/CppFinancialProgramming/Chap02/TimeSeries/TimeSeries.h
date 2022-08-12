/*
 * TimeSeries.h
 */
#ifndef __FinancialSample__TimeSeries__
#define __FinancialSample__TimeSeries__

#include <cstddef>
#include<vector>

class TimeSeries {
    public:
        TimeSeries();
        TimeSeries(const TimeSeries &);
        TimeSeries &operator = (const TimeSeries &);
        ~TimeSeries();

        void addValue(double val);
        double stdDev();
        double mean();
        size_t size();
        double elem(int i);

    private:
        std::vector<double> m_values;
};

#endif /* defines(__FinancialSample__TimeSeries) */