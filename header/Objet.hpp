/**
* Classe polymorphique Objet contenant le nom de l'objet, sa description, un message d'utilisation ainsi qu'un ensemble de noms possibles pour le nommer.
* \file   Objet.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

class Carte;

#ifndef DEF_OBJET
#define DEF_OBJET

class Objet {
public:
	Objet();
	Objet(const std::string& nom, const std::string& description,const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles);
	virtual ~Objet() = default;
	virtual void utiliserObjet(Carte& carte) ;
	std::string getNom() const;
	std::string getDescription() const;
	std::unordered_set<std::string> getNomsPossibles() const;

protected:
	bool isUsed_ = false;
private:
	std::string nom_;
	std::string description_;
	std::string messageUtilisation_;
	std::unordered_set<std::string> nomsPossibles_;
};

#endif






