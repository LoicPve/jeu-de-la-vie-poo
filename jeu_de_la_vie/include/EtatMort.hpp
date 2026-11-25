#pragma once
#include "EtatCellule.hpp"

// Classe fille concrete representant l'etat d'une cellule morte (herite de EtatCellule)
class EtatMort : public EtatCellule {
public:
    bool estVivante() const override; // retourne toujours faux car l'etat est mort
    EtatCellule* cloner() const override; // alloue et retourne une nouvelle copie de EtatMort
    char versCaractere() const override; // retourne le caractere '0' pour l'affichage et les fichiers
};