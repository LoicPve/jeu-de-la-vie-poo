#include "EtatMort.hpp"

// Retourne faux car cet etat represente une cellule morte
bool EtatMort::estVivante() const {
    return false;
}

// Alloue une nouvelle instance d'EtatMort et retourne son pointeur en tant qu'EtatCellule*
EtatCellule* EtatMort::cloner() const {
    return new EtatMort();
}

// Retourne le caractere '0' correspondant a une cellule morte dans la console et les fichiers
char EtatMort::versCaractere() const {
    return '0';
}