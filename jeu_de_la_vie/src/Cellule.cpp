#include "Cellule.hpp"
#include "EtatMort.hpp"

// Constructeur par defaut : initialise la cellule avec un etat mort
Cellule::Cellule() : m_etat(new EtatMort()) {}

// Constructeur parametre : initialise la cellule avec l'etat passe en parametre
Cellule::Cellule(EtatCellule* etat) : m_etat(etat) {}

// Constructeur de copie : duplique l'etat de l'autre cellule via cloner() pour que chaque cellule ait son propre pointeur
Cellule::Cellule(const Cellule& autre) : m_etat(autre.m_etat->cloner()) {}

// Operateur d'affectation : remplace l'etat actuel par une copie de celui de l'autre cellule
Cellule& Cellule::operator=(const Cellule& autre) {
    if (this != &autre) { // evite de supprimer son propre etat en cas d'auto-affectation (c1 = c1)
        delete m_etat; // libere l'ancien etat en memoire
        m_etat = autre.m_etat->cloner(); // copie l'etat de l'autre cellule
    }
    return *this; // retourne la cellule courante par reference
}

// Destructeur : libere la memoire allouee dynamiquement pour l'etat
Cellule::~Cellule() {
    delete m_etat;
}

// Delegue la question a l'etat courant grace au polymorphisme
bool Cellule::estVivante() const {
    return m_etat->estVivante();
}

// Retourne l'objet EtatCellule pointe par m_etat sous forme de reference constante
const EtatCellule& Cellule::getEtat() const {
    return *m_etat;
}

// Libere l'ancien etat puis remplace le pointeur par le nouvel etat
void Cellule::setEtat(EtatCellule* nouvelEtat) {
    if (m_etat != nouvelEtat) { // evite de supprimer le nouvel etat s'il s'agit deja du meme pointeur
        delete m_etat; // libere l'ancien etat pour eviter une fuite memoire
        m_etat = nouvelEtat; // stocke le nouvel etat
    }
}