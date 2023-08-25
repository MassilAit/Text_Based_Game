/**
* Definition des méthodes/constructeurs de la classe Objet.
* \file   Objet.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#include"Objet.hpp"


using namespace std;

Objet::Objet() {
	nom_ = "";
	description_ = "";
	messageUtilisation_ = "";
	nomsPossibles_ = {};
}

Objet::Objet(const string& nom, const string& descritpion, const string& messageUtilisation, const unordered_set<string>& nomPossibles):
	nom_(nom),
	description_(descritpion),
	messageUtilisation_(messageUtilisation),
	nomsPossibles_(nomPossibles){}

string Objet::getNom() const {
	return nom_;
}

string Objet::getDescription() const {
	return description_;
}

unordered_set<string> Objet::getNomsPossibles() const {
	return nomsPossibles_;
}

void Objet::utiliserObjet(Carte& carte)  {
	cout << messageUtilisation_ << "\n";
	isUsed_ = true;
}



