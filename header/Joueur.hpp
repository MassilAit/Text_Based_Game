/**
* Classe Joueur contenant le nom du joueur ainsi que la salle actuelle du joueur.
* \file   Joueur.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include"Salle.hpp"

class Joueur {
public:
	Joueur();
	std::shared_ptr<Salle> getSalle() const;
	const std::string& getNomJoueur()const;
	void setsalleActuelle(std::shared_ptr<Salle> nouvelleSalle);
	void setNomJoueur(const std::string& nomJoueur);

private:
	std::string nomJoueur_;
	std::shared_ptr<Salle> salleActuelle_;
};
