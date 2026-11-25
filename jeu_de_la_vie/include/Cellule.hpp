#pragma once
#include "EtatCellule.hpp"

// Classe representant une cellule de la grille
class Cellule {
private:
    EtatCellule* m_etat; // etat de la cellule du type de la classe "EtatCellule", utilisation d'un pointeur car classe abstraite

public:
    Cellule(); // constructeur par defaut (initialise la cellule a l'etat mort)

    // Constructeur parametre : cree une cellule avec un etat deja alloue (ex: new EtatVivant()).
    Cellule(EtatCellule* etat);

    // Constructeur de copie : cree une nouvelle cellule en copiant une cellule existante (ex: Cellule c2(c1);).
    // Utilisation de cloner() pour creer un nouvel EtatCellule en memoire -> les deux cellules sont independantes.
    Cellule(const Cellule& autre);

    // Operateur d'affectation : copie l'etat d'une cellule dans une autre deja existante (ex: c2 = c1;).
    // Verifie qu'il ne s'agit pas de la meme cellule, supprime l'ancien etat puis clone celui de l'autre.
    // Evite bug si modification de l'etat d'une des 2 cellules 
    Cellule& operator=(const Cellule& autre);

    ~Cellule(); // destructeur (libere la memoire allouee pour m_etat)

    bool estVivante() const; // retourne vrai si la cellule est vivante, faux sinon
    const EtatCellule& getEtat() const; // retourne  l'etat actuel de la cellule
    void setEtat(EtatCellule* nouvelEtat); // remplace l'etat actuel par un nouvel etat
};
