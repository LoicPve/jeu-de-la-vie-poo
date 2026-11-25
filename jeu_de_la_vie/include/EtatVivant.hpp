#pragma once
#include "EtatCellule.hpp"

// Classe fille concrete representant l'etat d'une cellule vivante (herite de EtatCellule)
class EtatVivant : public EtatCellule {
public:
    bool estVivante() const override; // retourne toujours vrai car l'etat est vivant
    EtatCellule* cloner() const override; // alloue et retourne une nouvelle copie de EtatVivant
    char versCaractere() const override; // retourne le caractere '1' pour l'affichage et les fichiers
};