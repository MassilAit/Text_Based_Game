/**
* Definition des méthodes de la classe Jeu.
* \file   Jeu.cpp
* \author Massil Ait Abdeslam (2153204)
* \date le 02 juin 2022
* Créé le 30 mai 2022
*/

#include"Jeu.hpp"

using namespace std;


Jeu::Jeu(): 
	joueur_(),
	carte_()
{

}


string Jeu::convertirDirection(const string& directionAConvertir) {
	if (directionAConvertir == "n") return "nord";
	if (directionAConvertir == "s") return "sud";
	if (directionAConvertir == "e") return "est";
	if (directionAConvertir == "o") return "ouest";
	return "";
}

string Jeu::toLowerCase(const string& texte) const {
	string texteToLower;
	for (int i = 0; i < texte.length(); i++)
	{
		texteToLower+= tolower(texte[i]);
	}
	return texteToLower;
}

void Jeu::retirerEspace(string& texte) const {
	texte.erase(remove(texte.begin(), texte.end(), ' '), texte.end());
}

void Jeu::afficherSalleActuelle() {
	joueur_.getSalle()->afficherSalle();
	
}



shared_ptr<Salle> Jeu::LireEntree() {
	string lecture;
	cout << ">";
	getline(cin,lecture);
	auto directions = joueur_.getSalle()->getDirections();
	retirerEspace(lecture);
	lecture = toLowerCase(lecture);

	if (lecture == "exit") {
		cout << "Vous quittez le jeu.";
		return nullptr;
	}
	

	for (int i = 0; i < directions.size(); i++) {
		if (lecture == (toLowerCase(directions[i].first)) || lecture==convertirDirection(toLowerCase(directions[i].first)))
			return directions[i].second;
	}

	vector<string> toutesLesDirectionsPossibles = { "n","s","e","o" };
	for (string direction : toutesLesDirectionsPossibles) {
		if (lecture == direction|| lecture == convertirDirection(direction)) {
			cout << endl<< "Ne peut pas aller la..." << endl;
			return LireEntree();
		}
	}


	commandes_.checkCommande(lecture, joueur_.getSalle(),carte_);
	return LireEntree();
	
	


}




void Jeu::jouer() {

	cout << ">>>>" << nomJeu_ << "<<<<" << endl<<endl;
	string nomJoueur;
	cout << "Veuillez entrer le nom de votre personnage : ";
	getline(cin,nomJoueur);
	joueur_.setNomJoueur(nomJoueur);
	string nomSalleDeDepart = "Toilette";
	joueur_.setsalleActuelle(carte_.trouverSalle(nomSalleDeDepart));
	cout << "Debut du jeu, vous allez jouer a un jeu textuel..." << endl<<endl;

	while (joueur_.getSalle()!=nullptr) {
		afficherSalleActuelle();
		joueur_.setsalleActuelle(LireEntree());
	}
}