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

TEST_F(CalculateurTest, EtantDonneDeuxNombres_QuandSoustraction_AlorsSoustractionEstCorrecte) {
// Étant donné
int premierNombre = 10;
int deuxiemeNombre = 5;

// Quand
int resultat = Calculateur::soustraction(premierNombre, deuxiemeNombre);

// Alors
EXPECT_EQ(resultat, 5);
}

TEST_F(CalculateurTest, EtantDonneDeuxNombres_QuandMultiplication_AlorsProduitEstCorrect) {
// Étant donné
int premierFacteur = 5;
int deuxiemeFacteur = 10;

// Quand
int resultat = Calculateur::multiplication(premierFacteur, deuxiemeFacteur);

// Alors
EXPECT_EQ(resultat, 50);
}

TEST_F(CalculateurTest, EtantDonneDeuxNombres_QuandDivision_AlorsQuotientEstCorrect) {
// Étant donné
int dividende = 10;
int diviseur = 2;

// Quand
int resultat = Calculateur::division(dividende, diviseur);

// Alors
EXPECT_EQ(resultat, 5);
}

TEST_F(CalculateurTest, EtantDonneDenominateurEgalAZero_QuandDivision_AlorsExceptionEstLevee) {
// Étant donné
int dividende = 10;
int diviseur = 0;

// Quand + Alors
EXPECT_THROW(Calculateur::division(dividende, diviseur), std::runtime_error);
}
