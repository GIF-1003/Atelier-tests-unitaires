#include <algorithm>
#include <stdexcept>
#include "PanierAchat.h"

void PanierAchat::ajouterArticle(const std::string& nomArticle, double prix) {
    articles.push_back({nomArticle, prix});
}

void PanierAchat::appliquerRemise(const std::string& nomArticle, double pourcentageRemise) {
    for (auto& article : articles) {
        if (article.nom == nomArticle) {
            article.prix = article.prix - (article.prix * pourcentageRemise / 100);
            break;
        }
    }
}

double PanierAchat::reqPrixTotal() const {
    double total = 0.0;
    for (const auto& article : articles) {
        total += article.prix;
    }

    return total;
}

const std::vector<Article>& PanierAchat::reqArticles() const {
    return articles;
}

void PanierAchat::supprimerArticle(const std::string& nomArticle) {
    bool articleTrouve = false;

    for (auto it = articles.begin(); it != articles.end(); ++it) {
        if (it->nom == nomArticle) {
            articles.erase(it);
            articleTrouve = true;
            break;
        }
    }

    if (!articleTrouve) {
        throw std::runtime_error("L'article à supprimer n'existe pas dans le panier.");
    }
}
