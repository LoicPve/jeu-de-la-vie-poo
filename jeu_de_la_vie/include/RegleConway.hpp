#pragma once
#include "Regle.hpp"

// Classe fille concrete implementant les regles classiques du jeu de la vie de John Conway
class RegleConway : public Regle {
public:
    // Calcule le prochain etat selon les regles de Conway (survie a 2 ou 3 voisins, naissance a 3)
    EtatCellule* calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisinsVivants) const override;
};