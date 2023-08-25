/**
* Definition des méthodes de la classe Joueur.
* \file   Joueur.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/

#include"Joueur.hpp"

using namespace std;

Joueur::Joueur() {
	nomJoueur_ = "Unknown";
	salleActuelle_ = nullptr;
}

shared_ptr<Salle> Joueur::getSalle() const {
	return salleActuelle_;
}

const string& Joueur::getNomJoueur()const {
	return nomJoueur_;
}

void Joueur::setsalleActuelle(shared_ptr<Salle> nouvelleSalle) {
	salleActuelle_ = nouvelleSalle;
}

void Joueur::setNomJoueur(const string& nomJoueur) {
	nomJoueur_ = nomJoueur;
}