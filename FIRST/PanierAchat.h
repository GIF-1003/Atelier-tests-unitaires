#ifndef ATELIER_TESTS_UNITAIRES_PANIERACHAT_H
#define ATELIER_TESTS_UNITAIRES_PANIERACHAT_H

#include <string>
#include <vector>

struct Article {
    std::string nom;
    double prix;
};

class PanierAchat {
    public:
        void ajouterArticle(const std::string& nomArticle, double prix);
        void appliquerRemise(const std::string& nomArticle, double pourcentageRemise);
        void supprimerArticle(const std::string& nomArticle);
        double reqPrixTotal() const;
        const std::vector<Article>& reqArticles() const;

    private:
        std::vector<Article> articles;
};


#endif //ATELIER_TESTS_UNITAIRES_PANIERACHAT_H
