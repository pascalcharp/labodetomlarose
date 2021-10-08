/**
 * \file Temps.cpp
 * \breif Implantation de la classe Temps
 * \author Tom Garneau-Larose
 * \date 28 septembre 2021
 * \version 1.0
 */

#include "Temps.h"
#include <ostream>
#include <iomanip>
#include <iostream>

using namespace std;

int Temps::m_nb_instances = 0; //Initialisation du compteur d'instances.

/**
 * \brief Constructeur par défaut, aucun paramètre.
 * L'heure est initaialisé selon l'heure du système.
 */
Temps::Temps()
{
    time_t mon_temps = time(NULL);

    struct tm* mes_infos = localtime(&mon_temps);

    m_heure = (*mes_infos).tm_hour; //Même chose que l'oprateur ->
    m_minute = mes_infos -> tm_min;
    m_seconde = mes_infos -> tm_sec;
    
    //Une fois l'objet crée on ajoute 1 au compteur instances Temps.
    
    m_nb_instances++;
    cout << "Constructeur défaut: " << m_nb_instances << endl ; 
}

/**
 * \brief Costructeur avec paramètres.
 *          On construit un objet Temps à partir de valeur passées en paramètres.
 *          Les attributs ne sont pas validé dans la construction ici.
 * 
 * \param p_heure est un entier qui représente l'heure.
 * \param p_minute est un entier qui réprente le nombre de minutes.
 * \param p_seconde est un entier qui représente le nombre de secondes.
 */
Temps::Temps(int p_heure, int p_minute, int p_seconde) : m_heure(p_heure), m_minute(p_minute), m_seconde(p_seconde)
{
    m_nb_instances++;
    cout << "Constructeur paramétrique: " << m_nb_instances << endl ; 
}

/**
 * \brief Assigne des valeurs à un objet temps tout en validant les valeurs reçues en paramètres.
 *          Utilise les autres méthodes d'assignation pour fonctionner.
 * 
 * \param p_heure est un entier qui représente l'heure.
 * \param p_minute est un entier qui réprente le nombre de minutes.
 * \param p_seconde est un entier qui représente le nombre de secondes.
 */
void Temps::asgValeurs(int p_heure, int p_minute, int p_seconde)
{
    asgHeure(p_heure);
    asgMinute(p_minute);
    asgSeconde(p_seconde);
}

/**
 * \brief Assigne l'heure à l'objet temps après validation.
 * 
 * \param p_heure est un entier qui représente l'heure.
 */
void Temps::asgHeure(int p_heure)
{
    if (validerHeure(p_heure))
    {
        m_heure = p_heure;
    }
    else
    {
        m_heure = 0;
    }
}

/**
 * \brief Assigne les minutes à l'objet temps après validation.
 * 
 * \param p_minute est un entier qui réprente le nombre de minutes.
 */
void Temps::asgMinute(int p_minute)
{
    if (validerMinuteOuSeconde(p_minute))
    {
        m_minute = p_minute;
    }
    else
    {
        m_minute = 0;
    }
}

/**
 * \brief Assigne les secondes à l'objet temps après validation.
 * 
 * \param p_seconde est un entier qui représente le nombre de secondes.
 */
void Temps::asgSeconde(int p_seconde)
{
    if (validerMinuteOuSeconde(p_seconde))
    {
        m_seconde = p_seconde;
    }
    else
    {
        m_seconde = 0;
    }
}

/**
 * \brief Cette méthode membre de la classe Temps permet de faire l'incémentation d'une
 * seconde à l'objet temps. Si le nombre de secondes devient alors plus grand
 * que 59 on met à 0 et on bascule le nombre de minutes, puis la même vérification
 * est faite pour les minutes et les heures.
 */
void Temps::tic()
{
    int secondes = reqSeconde();
    int minutes = reqMinute();
    int heure = reqHeure();
    
    if (validerMinuteOuSeconde(++secondes))
    {
        asgSeconde(secondes);
    }
    else
    {
        asgSeconde(secondes);
        if (validerMinuteOuSeconde(++minutes))
        {
            asgMinute(minutes);
        }
        else
        {
            asgMinute(minutes);
            asgHeure(++heure);
        }
    }
}

/**
 * \brief Cette méthode étant statique n'utilisa pas d'objet Temps. Elle s'occupe
 *          de faire la validation d'un nombre d'heure pour qu'il respecte les
 *          conditions.
 * \param p_heure Le nombre d'heures à valider.
 * \return True si valide et False sinon.
 */
bool Temps::validerHeure(int p_heure)
{
    return p_heure >= 0 && p_heure < 24;
}

bool Temps::validerMinuteOuSeconde(int p_min_ou_sec)
{
    return p_min_ou_sec >= 0 && p_min_ou_sec < 60;
}

int Temps::reqHeure() const
{
    return m_heure;
}

int Temps::reqMinute() const
{
    return m_minute;
}

int Temps::reqSeconde() const
{
    return m_seconde;
}

string Temps::reqTemps() const
{
    ostringstream os;

    os << setw(2)
            << setfill('0')
            << right
            << reqHeure()
            << ":"
            << setw(2)
            << setfill('0')
            << right
            << reqMinute()
            << ":"
            << setw(2)
            << setfill('0')
            << right
            << reqSeconde();

    return os.str();
}

int Temps::reqNbInstances()
{
    return m_nb_instances;
}

/**
 * \brief Cette fonction est une surcharge de l'opérateur "<<" 
 *          Lorsque cet opérateur est utilisé l'objet temps sous la forme d'une 
 *          chaine de charactère est envoyé dans un flux de sortie ostream.
 * \param p_os      Une référence vers le flux de sortie
 * \param p_temps   L'objet temps qui doit être envoyé vers le flux de sortie
 * \return          Une référence du flux de sortie reçu en entrée et modifié.
 */
ostream& operator <<(std::ostream& p_os, const Temps& p_temps)
{
    p_os << p_temps.reqTemps();
    
    return p_os;
}

/**
 * \brief Destructeur de la classe Temps. Permet de maintenir à jour le nombre
 *          d'instances d'objet Temps. Enleve 1 au compteur à chaque destruction.
 */
Temps::~Temps()
{
    m_nb_instances--;
    cout << "Destructeur: " << m_nb_instances << endl ; 
}

