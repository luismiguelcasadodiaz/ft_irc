#include <iostream>

class Motor {
public:
    virtual void encender() { std::cout << "Motor encendido." << std::endl; }
};

class MotorElectrico : virtual public Motor {
public:
    void encender() override { std::cout << "Motor E encendido." << std::endl; }
};

class MotorGasolina : virtual public Motor {
public:
    void encender() override { std::cout << "Motor G encendido." << std::endl; }
};

class VehiculoHibrido : public MotorElectrico, public MotorGasolina {
public:
    void encender() override { 
		MotorElectrico::encender() ;
	    MotorGasolina::encender() ;
	}
};

int main() {
    VehiculoHibrido mi_vehiculo;
    // Esto causaría un error de compilación por ambigüedad:
    mi_vehiculo.encender(); 
    return 0;
}
