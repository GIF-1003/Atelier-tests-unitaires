#include <gtest/gtest.h>
#include "Calculateur.h"

/*
 * Exercices Nommage des tests
 * */
class CalculateurTest : public ::testing::Test {

};

TEST_F(CalculateurTest, EtantDonneDeuxChiffres_QuandAddition_AlorsLaSommeEstCorrecte) {
// Étant donné
int premierNombre = 5;
int deuxiemeNombre  = 10;

// Quand
int resultat = Calculateur::addition(premierNombre, deuxiemeNombre);

// Alors
EXPECT_EQ(resultat, 15);
}

// TODO: Donner un nom au test suivant avec le principe EtantDonne-Quand-Alors
TEST_F(CalculateurTest, test2) {
// Étant donné
int premierNombre = 10;
int deuxiemeNombre = 5;

// Quand
int resultat = Calculateur::soustraction(premierNombre, deuxiemeNombre);

// Alors
EXPECT_EQ(resultat, 5);
}

// TODO: Donner un nom au test suivant avec le principe EtantDonne-Quand-Alors
TEST_F(CalculateurTest, test3) {
// Étant donné
int premierFacteur = 5;
int deuxiemeFacteur = 10;

// Quand
int resultat = Calculateur::multiplication(premierFacteur, deuxiemeFacteur);

// Alors
EXPECT_EQ(resultat, 50);
}

// TODO: Donner un nom au test suivant avec le principe EtantDonne-Quand-Alors
TEST_F(CalculateurTest, test4) {
// Étant donné
int dividende = 10;
int diviseur = 2;

// Quand
int resultat = Calculateur::division(dividende, diviseur);

// Alors
EXPECT_EQ(resultat, 5);
}

// TODO: Donner un nom au test suivant avec le principe EtantDonne-Quand-Alors
TEST_F(CalculateurTest, test5) {
// Étant donné
int dividende = 10;
int diviseur = 0;

// Quand + Alors
EXPECT_THROW(Calculateur::division(dividende, diviseur), std::runtime_error);
}
