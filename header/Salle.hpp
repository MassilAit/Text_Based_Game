/**
* Classe Salle contenant le nom de la salle, sa déscription, un vecteur des objets qu'elle contient ainsi qu'un tableau des directions possibles ainsi que la salle à cette direction.
* \file   Salle.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 30 mai 2022
*/
#pragma once



#include<iostream>
#include<string>
#include<vector>
#include<memory>

class Objet;



class Salle {
public:
	Salle();
	Salle(const std::string& nomSalle, const std::string& descriptionSalle, std::vector<std::string> direcitionPossible);
	void setDirectionSalle(const std::string& direction, std::shared_ptr<Salle> salle);
	void setObjets(std::vector<std::shared_ptr<Objet>> objets);
	void ajouterNouvelleDirection(std::pair<std::string, std::shared_ptr<Salle>> nouvelleDirection);
	void ajouterObjet(std::shared_ptr<Objet> nouvelObjet);
	const std::string& getNom() const;
	const std::string& getDescription() const;
	std::vector<std::pair<std::string, std::shared_ptr<Salle>>> getDirections() const;
	std::shared_ptr<Salle> verifierDirection(const std::string& directionAVerifier);
	void afficherSalle() const;
	std::vector<std::shared_ptr<Objet>> getObjets() const;

private:
	std::string nomSalle_;
	std::string descriptionSalle_;
	std::vector<std::pair<std::string, std::shared_ptr<Salle>>> directions_;
	std::vector<std::shared_ptr<Objet>> objets_;
	
	std::string convertirDirection(const std::string& directionAConvertir) const;
};

