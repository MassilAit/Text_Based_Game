/**
* Objet permetant de débloquer une nouevelle salle, contenant en plus des attributs d'un objet, la salle avec la nouvelle connexion,la nouvelle salle associé à une direction et le nouveau message après utilisationd de l'objet
* \file   ObjetDebloquantSalle.hpp
* \author Massil Ait Abdeslam (2153204)
* \date le 15 juin 2022
* Créé le 12 juin 2022
*/

#pragma once


#include"Objet.hpp"
#include"Carte.hpp"


class ObjetDebloquantSalle :public Objet {
public:
	ObjetDebloquantSalle(const std::string& nom, const std::string& description, const std::string& messageUtilisation, const std::unordered_set<std::string>& nomPossibles, const std::string& nouvelleConnexion, const std::pair<std::string, std::shared_ptr<Salle>>& nouvelleSalle, const std::string& nouveauMessage);
	void utiliserObjet(Carte& carte)  override;
private:
	std::string salleAvecNouvelleConnexion_;
	std::pair<std::string, std::shared_ptr<Salle>> nouvelleSalle_;
	std::string nouveauMessage_;
};