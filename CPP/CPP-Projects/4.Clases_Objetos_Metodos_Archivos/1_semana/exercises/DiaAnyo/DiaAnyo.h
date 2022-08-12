#include<iostream>

using namespace std;

class DiaAnyo
{
    private:
        int dia, mes;
    public:
        DiaAnyo(int d, int m);
        bool igual(const DiaAnyo &d) const;
        void visualizar() const;
};