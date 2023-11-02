#ifndef ATELIER_TESTS_UNITAIRES_MANIPULATEURDECHAINES_H
#define ATELIER_TESTS_UNITAIRES_MANIPULATEURDECHAINES_H

#include <string>

class ManipulateurDeChaines {
    public:
        static int compterCaracteres(const std::string& chaine);
        static std::string enleverEspaces(const std::string& chaine);
        static std::string convertirEnMinuscules(const std::string& chaine);
        static int compterNombreDeMots(const std::string& chaine);
};

#endif //ATELIER_TESTS_UNITAIRES_MANIPULATEURDECHAINES_H
