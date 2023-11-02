#include "Calculateur.h"
#include <stdexcept>

int Calculateur::addition(int premierNombre, int deuxiemeNombre) {
    return premierNombre + deuxiemeNombre;
}

int Calculateur::soustraction(int premierNombre, int deuxiemeNombre) {
    return premierNombre - deuxiemeNombre;
}

int Calculateur::multiplication(int premierFacteur, int deuxiemeFacteur) {
    return premierFacteur * deuxiemeFacteur;
}

int Calculateur::division(int dividende, int diviseur) {
    if (diviseur == 0) {
        throw std::runtime_error("Une division par zéro n'est pas autorisée.");
    }
    return dividende / diviseur;
}
