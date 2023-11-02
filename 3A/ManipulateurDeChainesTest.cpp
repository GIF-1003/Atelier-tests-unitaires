#include <gtest/gtest.h>
#include "ManipulateurDeChaines.h"
#include "ChaineVideException.h"

/*
 * Exercices 3A
 * */
class ManipulateurDeChainesTest : public ::testing::Test {
    protected:
        const std::string CHAINE_VIDE = "";
        const std::string CHAINE_NON_VIDE = "Bonjour";
        const std::string CHAINE_AVEC_ESPACES = "Bonjour, le monde !";
        const std::string CHAINE_SANS_ESPACES = "Bonjour,lemonde!";
        const std::string CHAINE_EN_MAJUSCULES = "BONJOUR, LE MONDE !";
        const std::string CHAINE_EN_MINUSCULES = "bonjour, le monde !";
        const std::string CHAINE_AVEC_CARACTERES_SPECIAUX = "Bonjour,;le monde!";
};

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterCaracteres_AlorsLeResultatEstZero) {
    // Préparation
    std::string chaine = CHAINE_VIDE;

    // Action
    int nbCaracteres = ManipulateurDeChaines::compterCaracteres(chaine);

    // Validation
    EXPECT_EQ(nbCaracteres, 0);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineNonVide_QuandCompterCaracteres_AlorsLeResultatEstLeBonNombreDeCaracteres) {
    // Préparation
    std::string chaine = CHAINE_NON_VIDE;

    // Action
    int nombreCaracteres = ManipulateurDeChaines::compterCaracteres(chaine);

    // Validation
    EXPECT_EQ(nombreCaracteres, 7);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecEspaces_QuandEnleverEspaces_AlorsLesEspacesSontSupprimes) {
    // Préparation
    std::string chaine = CHAINE_AVEC_ESPACES;

    // Action
    std::string resultat = ManipulateurDeChaines::enleverEspaces(chaine);

    // Validation
    EXPECT_EQ(resultat, CHAINE_SANS_ESPACES);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineSansEspaces_QuandEnleverEspaces_AlorsLaChaineResteInchangee) {
    // Préparation
    std::string chaine = CHAINE_SANS_ESPACES;

    // Action
    std::string result = ManipulateurDeChaines::enleverEspaces(chaine);

    // Validation
    EXPECT_EQ(result, CHAINE_SANS_ESPACES);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMajuscules_QuandConvertirEnMinuscules_AlorsLaChaineEstConvertieEnMinuscules) {
    // Préparation
    std::string chaine = CHAINE_EN_MAJUSCULES;

    // Action
    std::string resultat = ManipulateurDeChaines::convertirEnMinuscules(chaine);

    // Validation
    EXPECT_EQ(resultat, CHAINE_EN_MINUSCULES);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineEnMinuscules_QuandConvertirEnMinuscules_AlorsLaChaineResteInchangee) {
    // Préparation
    std::string chaine = CHAINE_EN_MINUSCULES;

    // Action
    std::string resultat = ManipulateurDeChaines::convertirEnMinuscules(chaine);

    // Validation
    EXPECT_EQ(resultat, CHAINE_EN_MINUSCULES);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterNombreDeMots_AlorsExceptionEstLevee) {
    // Préparation
    std::string chaine = CHAINE_VIDE;

    // Action + Validation
    EXPECT_THROW(ManipulateurDeChaines::compterNombreDeMots(chaine), ChaineVideException);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecUnMot_QuandCompterNombreDeMots_AlorsLeCompteEstDeUn) {
    // Préparation
    std::string chaine = CHAINE_NON_VIDE;

    // Action
    int nombreDeMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nombreDeMots, 1);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParEspaces_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation
    std::string chaine = CHAINE_AVEC_ESPACES;

    // Action
    int nombreDeMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nombreDeMots, 3);
}

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParCaracteresSpeciaux_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation
    std::string chaine = CHAINE_AVEC_CARACTERES_SPECIAUX;

    // Action
    int nombreDeMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nombreDeMots, 3);
}
