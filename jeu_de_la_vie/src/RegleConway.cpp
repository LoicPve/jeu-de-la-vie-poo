#include "RegleConway.hpp"
#include "EtatVivant.hpp"
#include "EtatMort.hpp"

// Calcule et alloue le nouvel etat de la cellule pour l'iteration suivante (t+1)
EtatCellule* RegleConway::calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisinsVivants) const {
    if (etatActuel.estObstacle()) {
        return etatActuel.cloner(); // une cellule obstacle conserve toujours son etat
    }

    if (etatActuel.estVivante()) {
        if (nbVoisinsVivants == 2 || nbVoisinsVivants == 3) {
            return etatActuel.cloner(); // une cellule vivante survit avec 2 ou 3 voisins vivants
        }
        return new EtatMort(); // sinon elle meurt par isolement ou surpopulation
    } else {
        if (nbVoisinsVivants == 3) {
            return new EtatVivant(); // une cellule morte nait avec exactement 3 voisins vivants
        }
        return new EtatMort(); // sinon elle reste morte
    }
}