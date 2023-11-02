# Atelier tests unitaires

Dans cet atelier, nous allons aborder les meilleures pratiques pour écrire des tests unitaires efficaces et bien structurés. Nous allons nous concentrer sur trois principes importants pour les tests unitaires : "Given-When-Then" (Étant donné-Quand-Alors), "Arrange-Act-Assert" (Préparation-Action-Validation) et "FIRST".

Le principe "Given-When-Then" vise à nommer les tests de manière claire et concise, en décrivant les différentes étapes d'un test. Nous allons apprendre à structurer nos tests en utilisant cette convention pour faciliter la compréhension de leur comportement.

Ensuite, nous aborderons le principe "Arrange-Act-Assert", qui nous aide à organiser nos tests de manière logique et compréhensible. Ce principe nous permet de séparer les différentes étapes d'un test, ce qui facilite la compréhension du test.

Enfin, nous allons explorer le principe "FIRST", qui décrit cinq caractéristiques importantes que nos tests devraient posséder : "Fast" (Rapide), "Independent" (Indépendant), "Repeatable" (Répétable), "Self-validating" (auto-validation) et "Timely" (En temps opportun). Nous allons comprendre comment respecter ces caractéristiques pour écrire des tests unitaires fiables et efficaces.

Tout au long de l'atelier, nous allons appliquer ces principes en complétant des fichiers de test pour différentes classes. Vous aurez l'occasion de pratiquer et de renforcer vos compétences en matière de tests unitaires.

## Nommage des tests
Une convention existe pour bien nommer les tests de manière claire et compréhensible.
Le principe se nomme given-when-then. Cela permet de décrire les différentes étapes d'un
test de manière concise. 

#### Given (Étant donné) 
- On veut donner un nom qui représente la configuration initiale du test, soit les préconditions nécessaires pour effectuer le test. On décrit l’état initial du système ou de l’environnement dans lequel le test va être effectué.
   Par exemple : givenUserWithValidCredentials_when…_then… 
#### When (Quand) 
- C'est l'étape qui correspond à l'action ou le comportement qui est testé. C'est souvent le nom de la fonction que l'on teste. Cette étape décrit l’action déclencheur qui va être exécutée pour vérifier le comportement attendu du système.
   Par exemple : givenUserWithValidCredentials_whenLogin_then…

#### Then (Alors) 
- C'est l'étape qui correspond au résultat attendu du test. Le nom doit refléter ce que les assertions et vérifications viennent effectuer, soit que le comportement de la fonction testée est correct.
   Par exemple : givenUserWithValidCredentials_whenLogin_thenUserIsLoggedInSuccesfully

En suivant cette structure, on peut nommer nos tests unitaires de manière descriptive et facilement compréhensible. On cherche à venir faciliter la compréhension du test même si une personne n'est pas familière avec le code source. On cherche aussi à venir documenter le comportement de notre code. Cela passe par avoir des noms de tests clairs, concis et qui exprime l'intention du test.

### Exercice 1
L'exercice 1 se base sur la classe Calculateur dans le dossier NommageTests.

#### Calculateur
La classe Calculateur fournit des méthodes pour effectuer des opérations mathématiques simples.

- addition(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur somme.
- soustraction(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur différence.
- multiplication(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur produit.
- division(int a, int b): Cette méthode prend deux nombres en entrée et retourne leur quotient. Si la division par zéro est tentée, une exception ValueError est levée avec le message "Une division par zéro n'est pas autorisée."

Complétez le fichier de test CalculateurTest.cpp présent dans le dossier NommageTests qui utilise la librairie Google Test. 
Le but de cet exercice est de pratiquer la convention de nommage de tests Given(Étant donné)-When(Quand)-Then(Alors).

## Arrange-Act-Assert
Une autre convention afin de mieux structurer les tests unitaires de manière claire et compréhensible.
On veut pouvoir séparer les différentes étapes d'un test de manière logique et facilement compréhensible.

#### Arrange (Préparation) 
- Prépare les données de test, c'est-à-dire la mise en place des préconditions nécessaires pour exécuter le test. Correspond au given dans le nommage de notre test.

#### Act (Action)
- On appelle la méthode sous test. Cette étape représente l'action ou le comportement qui est testé.

#### Assert (Validation)
- Valide le résultat. C'est ici qu'on effectue les vérifications et les assertions pour s'assurer que le comportement de la fonction que l'on teste est correct.

Facile de repérer les différentes parties du test.
Permet de facilement comprendre le test, même pour une personne qui n'est pas familière avec le code source. On devrait être en mesure de comprendre ce que le code source accompli seulement avec la lecture des tests unitaires.

### Exercice 2
L'exercice 2 se base sur la classe ManipulateurDeChaines dans le dossier 3A.

#### ManipulateurDeChaines
La classe ManipulateurDeChaines fournit des méthodes pour manipuler les chaînes de caractères.

- compterCaracteres(const std::string& chaine): Cette méthode prend une chaîne de caractères en entrée et retourne le nombre de caractères dans la chaîne.
- enleverEspaces(const std::string& chaine): Cette méthode prend une chaîne de caractères en entrée et supprime tous les espaces de la chaîne.
- convertirEnMinuscules(const std::string& chaine): Cette méthode prend une chaîne de caractères en entrée et retourne une nouvelle chaîne en minuscules.
- compterNombreDeMots(const std::string& chaine): Cette méthode prend une chaîne de caractères en entrée et retourne le nombre de mots dans la chaîne.

Complétez le fichier de test ManipulateurDeChainesTest.cpp présent dans le dossier 3A. 
Le but de cette exercice est de pouvoir être en mesure de bien séparer un test unitaire avec la convention Arrange(Préparation)-Act(Action)-Assert(Validation).

## FIRST

#### Fast (Rapide)
- Les tests doivent être rapides et doivent pouvoir rouler rapidement. Si les tests sont lents, on ne voudra pas les rouler souvent et donc on ne pourra pas trouver les problèmes assez rapidement pour les corriger. On ne se sentira pas assez confiant pour faire le ménage dans le code.

#### Independent (Indépendant)
- Les tests ne doivent pas dépendre l'un de l'autre. Un test ne devrait pas mettre en place des conditions pour le prochain. On devrait pouvoir rouler chaque test indépendamment et dans l'ordre que l'on veut. Par exemple, quand un test échoue, le premier échoué cause une cascade de tests qui échouent faisant en sorte qu'il devient difficile de savoir lequel est en cause.

#### Repeatable (Répétable)
- Les tests devraient être répétables dans n'importe quel environnement. On devrait être en mesure de rouler les tests dans l'environnement de production, dans l'environnement de QA etc. Si les tests ne sont pas répétables dans tous les environnements, on a alors une excuse du pourquoi ils échouent.

#### Self-validating (auto-validation)
- Les tests devraient avoir une valeur booléenne en sortie. Soit les tests passent ou ils échouent. On ne devrait pas avoir à lire un fichier de log afin de dire si les tests passent ou pas. On ne devrait pas avoir à manuellement comparer 2 fichiers de textes pour savoir si un test passe. Si les tests ne sont pas vrais ou faux, un test qui échoue devient subjectif et rouler les tests pourraient prendre beaucoup de temps.

#### Timely (En temps opportun)
- Les tests doivent être écrits au bon moment, c'est-à-dire très proches du moment où le code est créé. En suivant cette approche, on garantit l'écriture d'un code plus propre et plus facilement testable. En écrivant les tests tôt dans le processus de développement, on s'assure que le code est bien structuré et que les comportements attendus sont correctement définis. Tester trop tard peut conduire à un code mal structuré, moins modulaire et plus difficile à tester.

### Exercice 3
L'exercice 3 se base sur la classe PanierAchat dans le dossier FIRST.

#### PanierAchat
La classe PanierAchat représente un panier d'achat avec des articles.

- ajouterArticle(const std::string& nomArticle, double prix): Cette méthode permet d'ajouter un article au panier avec son nom et son prix.
- appliquerRemise(const std::string& nomArticle, double pourcentageRemise): Cette méthode applique une réduction en pourcentage sur le prix d'un article spécifié dans le panier.
- reqPrixTotal(): Cette méthode retourne le coût total de tous les articles dans le panier.
- reqArticles(): Cette méthode retourne la liste de tous les articles dans le panier.
- supprimerArticle(const std::string& nomArticle): Cette méthode permet de supprimer un article spécifique du panier. Si l'article n'existe pas dans le panier, une exception std::runtime_error est levée avec le message "L'article à supprimer n'existe pas dans le panier."

Complétez le fichier de test PanierAchatTest.cpp présent dans le dossier FIRST. 
Le but de cette exercice est de pouvoir identifier les principes FIRST dans des tests
unitaires. Vous devez corriger et compléter les tests présents dans le fichier de PanierAchatTest.cpp afin de respecter ces principes.
