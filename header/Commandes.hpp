/**
* Classe Commandes permetant la gestion des différentes commandes du jeu.
* \file   Commandes.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#pragma once
#include<vector>
#include<string>
#include<memory>
#include"Carte.hpp"

class Commandes {
public:
	
	void checkCommande(const std::string& entree, std::shared_ptr<Salle> salleActuelle, Carte& carte);



private:
	std::vector<std::string> commandes_ = { "look","use","help"};
	
	int trouverCommande(const std::string& entree);
	void look(const std::string& entree,std::shared_ptr<Salle> salleActuelle);
	void use(const std::string& entree, std::shared_ptr<Salle> salleActuelle,Carte& carte);
	void help(const std::string& entree);
};
