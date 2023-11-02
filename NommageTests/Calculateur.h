#ifndef ATELIER_TESTS_UNITAIRES_CALCULATEUR_H
#define ATELIER_TESTS_UNITAIRES_CALCULATEUR_H

class Calculateur {
    public:
        static int addition(int premierNombre, int deuxiemeNombre);
        static int soustraction(int premierNombre, int deuxiemeNombre);
        static int multiplication(int premierFacteur, int deuxiemeFacteur);
        static int division(int dividende, int diviseur);
};

#endif //ATELIER_TESTS_UNITAIRES_CALCULATEUR_H
