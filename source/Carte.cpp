/**
* Definition des méthodes/constructeurs de la classe Carte.
* \file   Carte.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/

#include"Carte.hpp"
using namespace std;

shared_ptr<Salle> Carte::creerSalle(const string& nom, const string& description, vector<string> directions) {
	Salle salle{ nom,description,directions };
	return  make_shared<Salle>(salle);
}

shared_ptr<Objet> Carte::creerObjet(const string& nom, const string& description, const string& messageUtilisation, const unordered_set<string>& nomPossibles) {
	Objet objet(nom, description, messageUtilisation, nomPossibles);
	return  make_shared<Objet>(objet);
}

shared_ptr<Objet> Carte::creerObjet(const string& nom, const string& description, const string& messageUtilisation, const unordered_set<string>& nomPossibles, const string& nouvelleConnexion, const pair<string, shared_ptr<Salle>>& nouvelleSalle, const string& nouveauMessage) {
	ObjetDebloquantSalle objet(nom, description, messageUtilisation, nomPossibles,nouvelleConnexion,nouvelleSalle,nouveauMessage);
	return  make_shared<ObjetDebloquantSalle>(objet);
}

shared_ptr<Objet> Carte::creerObjet(const string& nom, const string& descritpion, const string& messageUtilisation, const unordered_set<string>& nomPossibles, const string& salleAvecNouvelObjet, shared_ptr<Objet> nouvelObjet, const string& nouveauMessage) {
	ObjetDebloquantObjet objet(nom, descritpion, messageUtilisation, nomPossibles, salleAvecNouvelObjet, nouvelObjet, nouveauMessage);
	return  make_shared<ObjetDebloquantObjet>(objet);
}

Carte::Carte() {
	
	auto ptrChambre = creerSalle("Chambre", "Il s'agit d'une chambre tout ce qu'il y a de plus normal", { "N","E" });
	auto ptrCouloir = creerSalle("Couloir", "Il s'agit d'un couloir tout ce qu'il y a de plus normal", { "N","E","S","O" });
	auto ptrToilette = creerSalle("Toilette", "Il s'agit d'une toilette tout ce qu'il y a de plus normal", { "S","O" });
	auto ptrCuisine = creerSalle("Cuisine", "Il s'agit d'une superbe cuisine!", { "S" });
	auto ptrSalon = creerSalle("Salon", "Il s'agit d'un beau salon avec une tele.", { "E" });
	auto ptrBunker = creerSalle("Bunker", "Il s'agit d'un bunker.", { "E" });

	ptrChambre->setDirectionSalle("N", ptrCouloir);
	ptrChambre->setDirectionSalle("E", ptrToilette);

	ptrCouloir->setDirectionSalle("S", ptrChambre);
	ptrCouloir->setDirectionSalle("E", ptrToilette);
	ptrCouloir->setDirectionSalle("N", ptrCuisine);
	ptrCouloir->setDirectionSalle("O", ptrSalon);

	ptrToilette->setDirectionSalle("S", ptrChambre);
	ptrToilette->setDirectionSalle("O", ptrCouloir);

	ptrCuisine->setDirectionSalle("S", ptrCouloir);

	ptrSalon->setDirectionSalle("E", ptrCouloir);

	ptrBunker->setDirectionSalle("E", ptrSalon);

	//Objets de la chambre
	auto ptrLit = creerObjet("Un grand lit king-size", "Il s'agit d'un lit king-size confortable", "Vous vous couchez un peu pour vous reposer", { "lit","grandlitking-size","litking-size","king-size","grandlit"});
	auto ptrInterupteur = creerObjet("Un interupteur Rouge", "Un interrupteur rouge sous ", "Vous appuyez sur l'interupteur, la salle bunker est maintenant connecte au salon", { "interupteur","rouge","interupteurrouge" }, "Salon", make_pair("O", ptrBunker), "Vous appuyez, il ne se pas rien de particulier");
	ptrChambre->setObjets({ ptrLit,ptrInterupteur });

	//Objets toilette
	auto ptrCle = creerObjet("Une cle", "Cette cle pourait être utile plus tard", "Je ne sais pas ou je pourais utiliser cette cle", { "cle","clef","une cle","une clef" });
	auto ptrChasseDEau = creerObjet("Une chasse d'eau", "Les toilettes semblent bouchées", "Vous tirer la chasse d'eau, vous voyez une cle qui flotte...", { "chasse","eau","d'eau","chassed'eau" },"Toilette",ptrCle, "la toilette est debouche");
	ptrToilette->setObjets({ ptrChasseDEau });

	//Objets couloir
	auto ptrCadre = creerObjet("Un cadre", "Un jole cadre d'une montagne, peut-etre une replique d'un tableau connue?", "Vous regarder le cadre, vous a t-il regarde?", { "cadre","uncadre"});
	ptrCouloir->setObjets({ ptrCadre });
	
	//Objets Cuisine
	auto ptrMicroOnde = creerObjet("Un micro-onde", "Un micro-onde tout ce qu'il y a de plus normal", "Vous allumez le micro-onde, rien ne semble se passer.", { "unmicro-onde","micro","onde","microonde","micro-onde" });
	ptrCuisine->setObjets({ ptrMicroOnde });

	//Objets Salon
	auto ptrMusique = creerObjet("Un gramophone", "Un ancine gramophone avec un vinyle dont on ne peut psa lire le nom", "Une ancienne musique qui vous fit quelque chose joue...", { "gramophone","ungramophone","vinyle","unvinyle" });
	ptrSalon->setObjets({ ptrMusique });
	
	//Objets Bunker
	auto ptrBouton = creerObjet("Un bouton rouge", "Il s'agit d'un gros bouton rouge", "Vous appuyez mais rien ne semble se produire...", { "bouton","rouge","boutonrouge" });
	ptrBunker->setObjets({ ptrBouton });

	salles_ = { ptrChambre,ptrCouloir,ptrToilette,ptrCuisine,ptrSalon,ptrBunker };
}

vector<shared_ptr<Salle>> Carte::getSalles() const {
	return salles_;
}

shared_ptr<Salle> Carte::trouverSalle(const string& nomSalle) {
	for (int i = 0; i < salles_.size(); i++) {
		if (salles_[i]->getNom() == nomSalle) {
			return salles_[i];
		}
	}
	return nullptr;
}

