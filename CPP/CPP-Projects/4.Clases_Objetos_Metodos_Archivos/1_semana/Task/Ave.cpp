#include "Inicio.h"
#include "Ave.h"

// Constructor
Ave::Ave(string nom, string t, string t_sang, string c_plumas):
Inicio(nom, t, t_sang), color_plumas(c_plumas)
{
    setPlumas(color_plumas);
}
// Metodos
void Ave::setPlumas(string c_plumas)
{
    color_plumas = c_plumas;
}
string Ave::getPlumas() const
{
    return color_plumas;
}