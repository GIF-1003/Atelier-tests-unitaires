#include <gtest/gtest.h>
#include "PanierAchat.h"
#include "LecteurDeConfigurations.cpp"

/*
 * Exercices FIRST
 * */
class PanierAchatTest : public ::testing::Test {
    protected:
        PanierAchat panierAchat;
        // Vous pouvez ajouter des constantes ici
        const double PRIX_ARTICLE_INITIAL = 100.0;
        const double POURCENTAGE_REMISE = 25.0;
        const double PRIX_FINAL_APRES_REMISE = PRIX_ARTICLE_INITIAL * (100.0 - POURCENTAGE_REMISE) / 100.0;
        const std::string NOM_ARTICLE = "Article X";
};

// TODO: Trouvez le principe non respecté et corrigez le test suivant
TEST_F(PanierAchatTest, EtantDonneDesArticles_QuandAjouterArticles_AlorsArticlesSontAjoutesAuPanier) {
    // Action
    const int articles = 100000000;
    for (int i = 0; i < articles; ++i) {
        panierAchat.ajouterArticle("Article" + std::to_string(i), 10.0);
    }

    // Validation
    EXPECT_EQ(panierAchat.reqArticles().size(), articles);
}

// TODO: Trouvez le principe non respecté et corrigez le test suivant
TEST_F(PanierAchatTest, EtantDonneUnPanierEtUnArticle_QuandAppliquerRemise_AlorsRemiseEstAppliquee) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE_INITIAL);

    // Action
    double pourcentageRemise = LecteurDeConfigurations::lirePourcentageRemise();
    panierAchat.appliquerRemise(NOM_ARTICLE, pourcentageRemise);

    const std::vector<Article>& articles = panierAchat.reqArticles();
    Article articleAvecRemise;
    for (const auto& article : articles) {
        if (article.nom == NOM_ARTICLE) {
            articleAvecRemise = article;
        }
    }

    // Validation
    EXPECT_EQ(articleAvecRemise.prix, PRIX_FINAL_APRES_REMISE);
}

// TODO: Trouvez le principe non respecté et corrigez le test suivant
TEST_F(PanierAchatTest, EtantDonneUnPanierAvecUnArticle_QuandAppliquerRemise_AlorsRemiseEstAppliquee) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE_INITIAL);

    // Action
    panierAchat.appliquerRemise(NOM_ARTICLE, POURCENTAGE_REMISE);

    // Validation
    const std::vector<Article>& articles = panierAchat.reqArticles();
    for (const auto& article : articles) {
        if (article.nom == NOM_ARTICLE) {
            std::cout << "Prix de remise pour Article X: " << article.prix << std::endl;
            break;
        }
    }
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierVide_QuandReqPrixTotal_AlorsPrixTotalEstZero) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierAvecPlusieursArticles_QuandReqPrixTotal_AlorsPrixTotalEstLaSommeDuPrixDesArticles) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierAvecUnArticle_QuandSupprimerArticle_AlorsArticleEstSupprime) {
    // Préparation

    // Action

    // Validation
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierSansArticle_QuandSupprimerArticle_AlorsExceptionEstLancee) {
    // Préparation

    // Action

    // Validation
}
