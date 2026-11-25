#pragma once

// Classe mere abstraite representant l'etat d'une cellule
// ne peut pas etre instanciee directement
// utile pour toutes les classes filles concretes :EtatVivant, EtatMort, EtatObstacle
class EtatCellule {
public:
    // Destructeur virtuel indispensable pour liberer correctement une classe fille via un pointeur EtatCellule*
    virtual ~EtatCellule() = default;

    // retourne vrai si l'etat correspond a une cellule vivante, faux sinon
    virtual bool estVivante() const = 0;

    // retourne faux pour les cellules normales 
    virtual bool estObstacle() const { return false; }

    //alloue et retourne une copie independante de l'etat courant (utilisee par Cellule lors des copies)
    virtual EtatCellule* cloner() const = 0;

    // retourne le caractere representant l'etat pour l'affichage ou les fichiers (1 ou 0)
    virtual char versCaractere() const = 0;
};