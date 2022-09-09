#include "Persona.h"
#include "Empleado.h"
#include "Cliente.h"

int main() {

    Persona p1("Juan", 'M', 23, "Av 32");
    std::cout <<p1.Print() <<std::endl;

    Empleado e1("Cara", 'F', 32, "Cl 32", 3400);
    std::cout <<e1.Print() <<std::endl;

    Empleado e2("Juan", 'M', 23, "Av 32", 2300);
    std::cout <<e2.Print() <<std::endl;

    Empleado * e3 = new Empleado("Ana", 'F', 21, "Cra. 12", 3459);
    std::cout <<e3->Print() <<std::endl;

    delete e3;

    Cliente c1("Jose", 'M', 27, "Av 32", true);
    std::cout <<c1.Print() <<std::endl;
    
    Cliente c2("Esteban", 'M', 23, "Cl 34", false);
    std::cout <<c2.Print() <<std::endl;


    return (0);
}