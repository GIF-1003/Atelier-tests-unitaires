# Atelier de tests unitaires
Ce projet sert de référence pour un atelier de tests unitaires en Python, complémentant la version C++ disponible dans la branche principale (master). L'objectif principal de ce projet est de fournir aux étudiants une comparaison des concepts et pratiques de tests unitaires dans un autre langage de programmation.

## Description des classes
### Calculator
La classe Calculator fournit des méthodes pour effectuer des opérations mathématiques simples.

- add(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur somme.
- subtract(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur différence.
- multiply(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur produit.
- divide(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur quotient. Si une division par zéro est tentée, une exception runtime_error est levée avec le message "Division by zero is not allowed."

### StringManipulator
La classe StringManipulator fournit des méthodes pour manipuler les chaînes de caractères.

- countCharacters(const std::string& str): Cette méthode prend une chaîne de caractères en entrée et retourne le nombre de caractères dans la chaîne.
- removeSpaces(const std::string& str): Cette méthode prend une chaîne de caractères en entrée et supprime tous les espaces de la chaîne.
- convertToLowercase(const std::string& str): Cette méthode prend une chaîne de caractères en entrée et retourne une nouvelle chaîne en minuscules.
- countNumberOfWords(const std::string& str): Cette méthode prend une chaîne de caractères en entrée et retourne le nombre de mots dans la chaîne.

### ShoppingCart
La classe ShoppingCart représente un panier d'achat avec des articles.

- addItem(const std::string& itemName, double price): Cette méthode permet d'ajouter un article au panier avec son nom et son prix.
- applyDiscount(const std::string& itemName, double discountPercentage): Cette méthode applique une réduction en pourcentage sur le prix d'un article spécifié dans le panier.
- getTotalCost(): Cette méthode retourne le coût total de tous les articles dans le panier.
- getItems(): Cette méthode retourne la liste de tous les articles dans le panier.
- removeItem(const std::string& itemName): Cette méthode permet de supprimer un article spécifique du panier. Si l'article n'existe pas dans le panier, une exception RuntimeError est levée avec le message "The article to be deleted does not exist in the shopping cart."
