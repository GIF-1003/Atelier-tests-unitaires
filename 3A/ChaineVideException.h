#ifndef CHAINE_VIDE_EXCEPTION_H
#define CHAINE_VIDE_EXCEPTION_H

#include <stdexcept>

class ChaineVideException : public std::exception {
public:
    const char* what() const noexcept override {
        return "La chaine de charactères est vide.";
    }
};

#endif // CHAINE_VIDE_EXCEPTION_H
