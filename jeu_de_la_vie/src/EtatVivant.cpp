#include "EtatVivant.hpp"

// Retourne vrai car cet etat represente une cellule vivante
bool EtatVivant::estVivante() const {
    return true;
}

// Alloue une nouvelle instance d'EtatVivant et retourne son pointeur en tant qu'EtatCellule*
EtatCellule* EtatVivant::cloner() const {
    return new EtatVivant();
}

// Retourne le caractere '1' correspondant a une cellule vivante dans la console et les fichiers
char EtatVivant::versCaractere() const {
    return '1';
}