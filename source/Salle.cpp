/**
* Definition des méthodes de la classe Salle.
* \file   Salle.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/

#include"Salle.hpp"
#include"Objet.hpp"

using namespace std;

Salle::Salle() {
	nomSalle_ = "Salle Vide";
	descriptionSalle_ = "Cette salle est vide";
	directions_ = {};
}

Salle::Salle(const string& nomSalle, const string& descriptionSalle, vector<string> direcitionsPossibles) {
	nomSalle_ = nomSalle;
	descriptionSalle_ = descriptionSalle;
	for (int i = 0; i < direcitionsPossibles.size(); i++) {
		directions_.push_back(make_pair(direcitionsPossibles[i], nullptr));
	}
}

void Salle::setDirectionSalle(const string& direction, shared_ptr<Salle> salle) {
	for (int i = 0; i < directions_.size(); i++) {
		if (directions_[i].first == direction) {
			directions_[i].second = salle;
			return;
		}
	}
}

const string& Salle::getNom() const {
	return nomSalle_;
}

const string& Salle::getDescription() const {
	return descriptionSalle_;
}

vector<pair<string, shared_ptr<Salle>>> Salle::getDirections() const {
	return directions_;
}

shared_ptr<Salle> Salle::verifierDirection(const string& directionAVerifier) {

	for (int i = 0; i < directions_.size(); i++) {
		if (directionAVerifier == directions_[i].first) {
			return directions_[i].second;
		}
	}

	return nullptr;
}

void Salle::ajouterNouvelleDirection(pair<string, shared_ptr<Salle>> nouvelleDirection) {
	directions_.push_back(nouvelleDirection);
}

string Salle::convertirDirection(const string& directionAConvertir) const {
	if (directionAConvertir == "N") return " est au Nord";
	if (directionAConvertir == "S") return " est au Sud";
	if (directionAConvertir == "E") return " est a l'Est";
	if (directionAConvertir == "O") return " est a l'Ouest";
	return "";
}

void Salle::afficherSalle() const {
	cout << "----" << nomSalle_ << "----" << endl;
	cout << descriptionSalle_ << endl;
	cout << "Vous remarquez : "<<"\n";

	for (int i = 0; i < objets_.size(); i++)
	{
		cout <<"\t" << objets_[i]->getNom() << "\n";
	}
	cout << "\n";
	for (int i = 0; i < directions_.size(); i++) {
		cout << directions_[i].second->getNom() << convertirDirection(directions_[i].first) << " (" << directions_[i].first << ")" << endl;
	}
	
	
}

void Salle::setObjets(vector<shared_ptr<Objet>> objets) {
	objets_ = {};
	for (int i = 0; i < objets.size();i++) {
		objets_.push_back(objets[i]);
	}
}

void Salle::ajouterObjet(shared_ptr<Objet> nouvelObjet) {
	objets_.push_back(nouvelObjet);
}

vector<shared_ptr<Objet>> Salle::getObjets() const {
	return objets_;
}