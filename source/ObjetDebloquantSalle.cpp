/**
* Definition des méthodes/constructeurs de la classe ObjetDebloquantSalle.
* \file   ObjetDebloquantSalle.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#include"ObjetDebloquantSalle.hpp"

using namespace std;

ObjetDebloquantSalle::ObjetDebloquantSalle(const string& nom, const string& descritpion, const string& messageUtilisation, const unordered_set<string>& nomPossibles, const string& nouvelleConnexion, const pair<string, shared_ptr<Salle>>& nouvelleSalle, const string& nouveauMessage) :
	Objet(nom, descritpion, messageUtilisation, nomPossibles),
	salleAvecNouvelleConnexion_(nouvelleConnexion),
	nouvelleSalle_(nouvelleSalle),
	nouveauMessage_(nouveauMessage) {}

void ObjetDebloquantSalle::utiliserObjet(Carte& carte) {
	if (isUsed_) {
		cout << nouveauMessage_ << "\n";
		return;
	}

	Objet::utiliserObjet(carte);
	carte.trouverSalle(salleAvecNouvelleConnexion_)->ajouterNouvelleDirection(nouvelleSalle_);
}