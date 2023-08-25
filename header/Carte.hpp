/**
* Classe Carte contenant des pointeurs vers les différentes salles du jeu.
* \file   Carte.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/
#pragma once



#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<memory>
#include<unordered_set>
#include"Salle.hpp"
#include"Objet.hpp"
#include"ObjetDebloquantObjet.hpp"
#include"ObjetDebloquantSalle.hpp"

#ifndef DEF_CARTE
#define DEF_CARTE

class Carte {
public:
	Carte();
	std::vector<std::shared_ptr<Salle>> getSalles() const;
	std::shared_ptr<Salle> trouverSalle(const std::string& nomSalle);

private:
	std::vector<std::shared_ptr<Salle>> salles_;

	std::shared_ptr<Salle> creerSalle(const std::string& nom, const std::string& description, std::vector<std::string> directions);
	std::shared_ptr<Objet> creerObjet(const std::string& nom, const std::string& description, const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles);
	std::shared_ptr<Objet> creerObjet(const std::string& nom, const std::string& description, const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles, const std::string& nouvelleConnexion, const std::pair<std::string, std::shared_ptr<Salle>>& nouvelleSalle, const std::string& nouveauMessage);
	std::shared_ptr<Objet> creerObjet(const std::string& nom, const std::string& description, const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles, const std::string& salleAvecNouvelObjet, std::shared_ptr<Objet> nouvelObjet, const std::string& nouveauMessage);
};

#endif
