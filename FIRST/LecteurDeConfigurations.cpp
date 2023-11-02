#include <fstream>
#include <string>
#include <stdexcept>

/*
 * Classe utilitaire qui lit un pourcentage de réduction
 * dans un fichier .txt
 * */
class LecteurDeConfigurations {
    public:
        static double lirePourcentageRemise() {
            const std::string configFileName = "config.txt";

            std::ifstream configFile(configFileName);
            if (!configFile.is_open()) {
                throw std::runtime_error("Unable to open the configuration file.");
            }

            double discountPercentage;
            configFile >> discountPercentage;

            configFile.close();

            return discountPercentage;
        }
};
