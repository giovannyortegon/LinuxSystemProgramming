#include<iostream>
#include"cuenta.h"
#include"cuenta_ahorro.h"
#include"cuenta_corriente.h"
#include"cuenta_corriente_plus.h"

void visualizar(CCuenta &);

int main() {
    CCuenta cuenta01;

    try {
        //Error, el saldo es negativo
        cuenta01 = CCuenta{"cliente 01", "cuenta 01", -10000, 1.5};
        visualizar(cuenta01);
    } catch (const char * error) {
        std::cout <<error <<std::endl;
    }

    // LLamada al constructor CCuentaCorriente sin argumentos
    CCuentaCorriente cuenta02;
    // LLamafa al contructor CCuentaCorriente con argumentos
    CCuentaCorriente cuenta03{"cliente 03", "11111111111", 200000, 1.75, 0.01, 6};

    // LLamada al operado de asignacion  de CuentaCorriente
    cuenta02 = cuenta03;
    // equvalente a: cuenta02.CCuentaCorriente::operator=(cuenta03)
    visualizar(cuenta02);

    // Llamada al constructor copia CCuentaCorriente
    CCuentaCorriente cuenta04 { cuenta03 };
    // CCuentaCorriente cuenta04 = cuenta03;
    visualizar(cuenta04);

    std::cout <<"\nCuenta corriente plus"<<std::endl;

    CCuentaCorrientePlus cuenta05;
    cuenta05.asignarNombre("Cliente 05");
    cuenta05.asignarCuenta("1234567890");
    cuenta05.asignarTipoDeInteres(1.0);
    cuenta05.asignarTransExentas(0);
    cuenta05.asignarImportePorTrans(0.01);
    cuenta05.ingreso(20000);
    cuenta05.reintegro(5000);
    cuenta05.intereses();
    cuenta05.comisiones();
    visualizar(cuenta05);

    // Conversion CCuentaCorrientePlus a CCuentaCorriente - Permitida
    CCuentaCorriente cuenta06 { cuenta05 };
    visualizar(cuenta06);

    // Conversion de CCuentaCorrientePlus a CCuenta - Permitida
    cuenta01 = cuenta05;        // cuenta01.CCuenta::operator=(cuenta05)
    visualizar(cuenta01);

    // Conversion de CCuenta a CCuentaCorriente - No Permitida
    // cuenta06 = cuenta01;
    // Equivalente a: cuenta06.CCuentaCorriente::operator=(cuenta01)

    return (0);
}
void visualizar(CCuenta & cuenta) {
    std::cout << cuenta.obtenerNombre() << std::endl;
    std::cout << cuenta.obtenerCuenta() << std::endl;
    std::cout << cuenta.obtenerSaldo() << std::endl;
    std::cout << cuenta.obtenerTipoDeInteres() << std::endl;
}
