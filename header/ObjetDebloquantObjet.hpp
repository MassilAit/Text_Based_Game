/**
* Objet permetant de débloquer un objet contenant en plus des attributs d'un objet, la salle avec le nouvel objet, le nouvel objet et le nouveau message après utilisationd de l'objet 
* \file   ObjetDebloquantObjet.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#pragma once

#include"Objet.hpp"
#include"Carte.hpp"

class ObjetDebloquantObjet :public Objet {
public:
	ObjetDebloquantObjet(const std::string& nom, const std::string& description, const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles, const std::string& salleAvecNouvelObjet, std::shared_ptr<Objet> nouvelObjet, const std::string& nouveauMessage);
	void utiliserObjet(Carte& carte)  override;
private:
	std::string salleAvecNouvelObjet_;
	std::shared_ptr<Objet> nouvelObjet_;
	std::string nouveauMessage_;
};

