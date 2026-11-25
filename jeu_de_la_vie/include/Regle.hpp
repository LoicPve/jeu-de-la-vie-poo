#pragma once
#include "EtatCellule.hpp"

// Classe mere abstraite definissant le contrat d'une regle d'evolution du jeu de la vie
class Regle {
public:
    // Destructeur virtuel indispensable pour liberer correctement une classe fille via un pointeur Regle*
    virtual ~Regle() = default;

    // Methode virtuelle pure : calcule et alloue le prochain etat d'une cellule a partir de son etat actuel et de ses voisins vivants
    virtual EtatCellule* calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisinsVivants) const = 0;
};