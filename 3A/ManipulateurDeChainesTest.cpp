#include <gtest/gtest.h>
#include "ManipulateurDeChaines.h"
#include "ChaineVideException.h"

/*
 * Exercices 3A
 * */
class ManipulateurDeChainesTest : public ::testing::Test {
    protected:
        // Vous pouvez ajouter des constantes ici
        const std::string CHAINE_VIDE = "";
};

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterCaracteres_AlorsLeResultatEstZero) {
    // Préparation
    std::string chaine = CHAINE_VIDE;

    // Action
    int nbCaracteres = ManipulateurDeChaines::compterCaracteres(chaine);

    // Validation
    EXPECT_EQ(nbCaracteres, 0);
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineNonVide_QuandCompterCaracteres_AlorsLeResultatEstLeBonNombreDeCaracteres) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecEspaces_QuandSupprimerEspaces_AlorsLesEspacesSontSupprimes) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineSansEspaces_QuandSupprimerEspaces_AlorsLaChaineResteInchangee) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMajuscules_QuandConvertirEnMinuscules_AlorsLaChaineEstConvertieEnMinuscules) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineEnMinuscules_QuandConvertirEnMinuscules_AlorsLaChaineResteInchangee) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterNombreDeMots_AlorsExceptionEstLevee) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecUnMot_QuandCompterNombreDeMots_AlorsLeCompteEstUn) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParEspaces_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParCaracteresSpeciaux_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation

    // Action

    // Validation
}
