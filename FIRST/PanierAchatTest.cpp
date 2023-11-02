#include <gtest/gtest.h>
#include "PanierAchat.h"
#include "LecteurDeConfigurations.cpp"

/*
 * Exercices FIRST
 * */
class PanierAchatTest : public ::testing::Test {
    protected:
        const double PRIX_ARTICLE = 100.0;
        const double PRIX_ARTICLE_2 = 50.0;
        const double PRIX_ARTICLE_3 = 75.0;
        const double POURCENTAGE_REMISE = 20.0;
        const double PRIX_ARTICLE_AVEC_REMISE = PRIX_ARTICLE - (PRIX_ARTICLE * POURCENTAGE_REMISE / 100);
        const double PRIX_TOTAL_ATTENDU_ZERO = 0.0;
        const double PRIX_TOTAL_ATTENDU = 225.0;

        const std::string NOM_ARTICLE = "Article X";
        const std::string NOM_ARTICLE_2 = "Article Y";
        const std::string NOM_ARTICLE_3 = "Article Z";
        PanierAchat panierAchat;
};

/* Ici le test est corrigé afin de venir corriger le principe "Fast" qui n'était pas respecté.
Rouler le test prenait environ 10 secondes ce qui n'est pas souhaitable pour l'exécution
d'un test unitaire. */
TEST_F(PanierAchatTest, EtantDonneDesArticles_QuandAjouterArticle_AlorsArticlesSontAjoutesAuPanier) {
    // Action
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE);
    panierAchat.ajouterArticle(NOM_ARTICLE_2, PRIX_ARTICLE);

    // Validation
    int compteAttendu = 2;
    EXPECT_EQ(compteAttendu, panierAchat.reqArticles().size());
}

/* Ici, le test a été corrigé afin de respecter le principe "Repeatable", qui n'était pas respecté auparavant.
La correction du test pour se conformer au principe "Repeatable" implique de s'assurer que le test peut être
exécuté de manière fiable et reproductible dans divers environnements. Cela se fait en évitant les dépendances
externes et en incorporant toutes les données et configurations nécessaires directement dans le test lui-même.

Il convient de noter que le troisième test dans l'exercice de la branche master n'est plus nécessaire, car il est
identique à celui ci-dessous. En effet, ce test ne respectait pas le principe "Self-Validating". Il ne comportait
aucune assertion permettant de vérifier que la remise avait été appliquée avec succès. */
TEST_F(PanierAchatTest, EtantDonneUnPanierEtUnArticle_QuandAppliquerRemise_AlorsRemiseEstAppliquee) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE);

    // Action
    panierAchat.appliquerRemise(NOM_ARTICLE, POURCENTAGE_REMISE);

    const std::vector<Article>& articles = panierAchat.reqArticles();
    Article articleAvecRemise;
    for (const auto& article : articles) {
        if (article.nom == NOM_ARTICLE) {
            articleAvecRemise = article;
        }
    }

    // Validation
    EXPECT_EQ(articleAvecRemise.prix, PRIX_ARTICLE_AVEC_REMISE);
}

TEST_F(PanierAchatTest, EtantDonneUnPanierVide_QuandReqPrixTotal_AlorsPrixTotalEstZero) {
    // Action
    double prixTotal = panierAchat.reqPrixTotal();

    // Validation
    EXPECT_EQ(prixTotal, PRIX_TOTAL_ATTENDU_ZERO);
}

TEST_F(PanierAchatTest, EtantDonneUnPanierAvecPlusieursArticles_QuandReqPrixTotal_AlorsPrixTotalEstLaSommeDuPrixDesArticles) {
    // Preparation
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE);
    panierAchat.ajouterArticle(NOM_ARTICLE_2, PRIX_ARTICLE_2);
    panierAchat.ajouterArticle(NOM_ARTICLE_3, PRIX_ARTICLE_3);

    // Action
    double prixTotal = panierAchat.reqPrixTotal();

    // Validation
    EXPECT_DOUBLE_EQ(prixTotal, PRIX_TOTAL_ATTENDU);
}

TEST_F(PanierAchatTest, EtantDonneUnPanierAvecUnArticle_QuandSupprimerArticle_AlorsArticleEstSupprime) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE, PRIX_ARTICLE);

    // Action
    panierAchat.supprimerArticle(NOM_ARTICLE);

    // Validation
    const std::vector<Article>& articles = panierAchat.reqArticles();
    EXPECT_EQ(articles.size(), 0);
}

TEST_F(PanierAchatTest, EtantDonneUnPanierSansArticle_QuandSupprimerArticle_AlorsExceptionEstLancee) {
    // Action + Validation
    EXPECT_THROW(panierAchat.supprimerArticle(NOM_ARTICLE), std::runtime_error);
}
