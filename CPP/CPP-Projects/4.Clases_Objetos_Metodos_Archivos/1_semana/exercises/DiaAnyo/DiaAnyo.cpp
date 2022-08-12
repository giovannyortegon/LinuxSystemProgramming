#include "DiaAnyo.h"

DiaAnyo::DiaAnyo(int d, int m)
{
    dia = d;
    mes = m;
}
bool DiaAnyo::igual(const DiaAnyo &d)const
{
    if ((dia == d.dia) && (mes == d.mes))
        return true;
    else
        return false;
}
void DiaAnyo::visualizar() const
{
    cout <<"mes: " <<mes <<", dia: " <<dia <<endl;
}