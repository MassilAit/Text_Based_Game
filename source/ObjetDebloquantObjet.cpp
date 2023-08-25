/**
* Definition des méthodes/constructeurs de la classe ObjetDebloquantObjet.
* \file   ObjetDebloquantObjet.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#include"ObjetDebloquantObjet.hpp"

using namespace std;

ObjetDebloquantObjet::ObjetDebloquantObjet(const string& nom, const string& descritpion, const string& messageUtilisation, const unordered_set<string>& nomPossibles, const string& salleAvecNouvelObjet, shared_ptr<Objet> nouvelObjet, const string& nouveauMessage) :
	Objet(nom, descritpion, messageUtilisation, nomPossibles),
	salleAvecNouvelObjet_(salleAvecNouvelObjet),
	nouveauMessage_(nouveauMessage) {
	nouvelObjet_ = move(nouvelObjet);
}

void ObjetDebloquantObjet::utiliserObjet(Carte& carte) {
	if (isUsed_) {
		cout << nouveauMessage_ << "\n";
		return;
	}

	Objet::utiliserObjet(carte);
	carte.trouverSalle(salleAvecNouvelObjet_)->ajouterObjet(nouvelObjet_);
}