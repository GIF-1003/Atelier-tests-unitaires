#include "ManipulateurDeChaines.h"
#include "ChaineVideException.h"
#include <cctype>
#include <stdexcept>

int ManipulateurDeChaines::compterCaracteres(const std::string& chaine) {
    return chaine.length();
}

std::string ManipulateurDeChaines::enleverEspaces(const std::string& chaine) {
    std::string resultat;
    for (char c : chaine) {
        if (!std::isspace(c)) {
            resultat += c;
        }
    }
    return resultat;
}

std::string ManipulateurDeChaines::convertirEnMinuscules(const std::string& chaine) {
    std::string resultat;
    for (char c : chaine) {
        resultat += std::tolower(c);
    }
    return resultat;
}

int ManipulateurDeChaines::compterNombreDeMots(const std::string& chaine) {
    if (chaine.empty()) {
        throw ChaineVideException();
    }

    int nbMots = 0;
    bool dansLeMot = false;

    for (char c : chaine) {
        if (std::isalnum(c)) {
            if (!dansLeMot) {
                nbMots++;
                dansLeMot = true;
            }
        } else {
            dansLeMot = false;
        }
    }

    return nbMots;
}