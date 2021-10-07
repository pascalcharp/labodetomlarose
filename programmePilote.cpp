/**
 * \file programmePilote.cpp
 * \breif Programme simple pour l'utilisation de la classe Temps
 * \author Tom Garneau-Larose
 * \date 29 septembre 2021
 * \version 1.0
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "Temps.h"

using namespace std;

void sauvegarde(vector<Temps>& p_tableau_temps)
{
    ofstream fichier("sauvegarde.txt", ios::out);
    
    if(!fichier)
    {
        cerr << "Ouverture impossible" << endl;
    }
    else
    {
        for(int i=0; i < p_tableau_temps.size(); i++)
        {
            fichier << p_tableau_temps.at(i) << endl;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv)
{   
    cout << "Test du nombre d'instances" << endl;
    {
        Temps t1, t2, t3;
        cout << Temps::reqNbInstances() << endl;
    }
    cout << Temps::reqNbInstances() << endl;
    
    cout << endl << "Création d'un vecteur de 5 objets temps" << endl;
    
    vector<Temps> tableau_temps;
    
    cout << Temps::reqNbInstances() << endl;
    
    for (int i=0; i<5; i++)
    {
        tableau_temps.push_back(Temps());
        cout << "indice : " << i << " - Nombre Inst : " << Temps::reqNbInstances() << endl;
    }
    
    cout << endl << "Modification de l'objet 1 et 5" << endl;
    
    tableau_temps[0].asgValeurs(100, 100, 100);
    tableau_temps[4].asgValeurs(24, 30, 30);
    
    cout << endl << "Affichage des 5 objets temps suite à la modification" << endl;
    for (int i=0; i<tableau_temps.size() ; i++)
    {
        cout << tableau_temps[i] << endl;
    }
    
    cout << endl << "Test de la méthode tic pour l'incémentation du temps." << endl;
    Temps temps_incrementation(23, 59, 59);
    for (int i = 0; i < 30; i++)
    {
        cout << "[" << i << "] " << temps_incrementation << endl;
        temps_incrementation.tic();
    }
    
    sauvegarde(tableau_temps);
    return 0;
}

