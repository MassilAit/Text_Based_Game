/**
* Classe Jeu permettant de jouer au jeu, elle contient un joueur,des commandes et une carte.
* \file   Jeu.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/
#pragma once
#include<iostream>
#include<string>
#include"Joueur.hpp"
#include"Carte.hpp"
#include"Commandes.hpp"

class Jeu {
public:
	Jeu();
	void jouer();
	

private:
	const std::string nomJeu_ = "PROJET 1, UN JEU TEXTUEL";
	Joueur joueur_;
	Carte  carte_;
	Commandes commandes_;
	
	

	std::string convertirDirection(const std::string& directionAConvertir);
	void afficherSalleActuelle();
	std::shared_ptr<Salle> LireEntree();
	std::string toLowerCase(const std::string& texte) const;
	void retirerEspace(std::string& texte) const;
	
	


};
