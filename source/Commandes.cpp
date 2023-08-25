/**
* Definition des méthodes/constructeurs de la classe Commandes.
* \file   Commandes.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#include"Commandes.hpp"

using namespace std;



int Commandes::trouverCommande(const string& entree) {
	for (int i = 0; i < commandes_.size(); i++) {
		for (int j = 0; j < commandes_[i].size(); j++) {
			if (commandes_[i][j] != entree[j]) break;

			if (j == commandes_[i].size() - 1) return i;

		}
	}

	return -1;
}

void Commandes::look(const string& entree, shared_ptr<Salle> salleActuelle) {
	if (entree.length() == 4) {
		salleActuelle->afficherSalle();
		return;
	}
	string objet;
	for (int i = 4; i < entree.length(); i++) {
		objet += entree[i];
	}
	
	auto listeObjets = salleActuelle->getObjets();
	for (int i = 0; i < listeObjets.size(); i++) {
		auto set = listeObjets[i]->getNomsPossibles();
		if (set.count(objet)) {
			cout << listeObjets[i]->getDescription()<<"\n";
			return;
		}
	}

	cout << "cette commande n'est pas reconnue...\n";
	
}

void Commandes::use(const string& entree, shared_ptr<Salle> salleActuelle, Carte& carte) {
	if (entree.length() == 3) {
		cout << "Il faut utiliser quelque chose...\n";
		return;
	}

	string objet;
	for (int i = 3; i < entree.length(); i++) {
		objet += entree[i];
	}

	auto listeObjets = salleActuelle->getObjets();
	for (int i = 0; i < listeObjets.size(); i++) {
		auto set = listeObjets[i]->getNomsPossibles();
		if (set.count(objet)) {
			listeObjets[i].get()->utiliserObjet(carte);
			return;
		}
	}
	
	cout << "cette commande n'est pas reconnue...\n";
	
}

void Commandes::help(const string& entree) {
	cout << "look : permet d'avoir la description d'un objet ou de la salle si aucun arguments n'est fourni\n";
	cout << "use : permet d'utiliser l'objet spécifiee\n";
	cout << "help : permet de voir les differebtes commandes\n";
	cout << "exit : quitte le jeu\n";
}
void Commandes::checkCommande(const string& entree, shared_ptr<Salle> salleActuelle, Carte& carte) {
	int commande = trouverCommande(entree);
	switch (commande)
	{
	case 0:
		look(entree,salleActuelle);
		break;
	case 1:
		use(entree,salleActuelle, carte);
		break;
	case 2:
		help(entree);
		break;
	default:
		cout << "Commande Invalide...\n";
		break;
	}
}

