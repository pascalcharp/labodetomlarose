/**
 * \file Temps.h
 * \brief Fichier qui contient l'interface de la classe Temps qui sert à la manipulation de l'heure.
 * \author Tom Garneau-Larose
 * \date 28 septembre 2021
 * \version 1.0
 */

#ifndef TEMPS_H
#define TEMPS_H
#include<string>

/**
 * \class Temps
 * \brief Cette classe sert à la manipulation de l'heure.
 *          
 *          Permet de faire la création d'une heure précise selon l'heure actuel
 *          du système ou de créer selon une heure spécifique.
 *          Il est possibe de faire des modifications sur le temps inscrit.
 *          Les valeurs passées en paramètres sont validés par la classe.
 *          
 * Attributs :  int m_heure - Nombre d'heures écoulé depuis le début de la journée.
 *              int m_minute - Nombre de minutes écoulées depuis le début de l'heure.
 *              int m_seconde - Nombre de secondes écoulées depuis le début de la minute.
 * 
 * \invariant m_heure >= 0 et <= 24.
 * \invariant m_minute >= 0 et <= 60.
 * \invariant m_seconde >= 0 et <= 60.
 */
class Temps
{
public:
  Temps ();
  Temps (int p_heure, int p_minute, int p_seconde);
  
  void asgValeurs (int p_heure, int p_minute, int p_seconde);
  void asgHeure (int p_heure);
  void asgMinute (int p_minute);
  void asgSeconde (int p_seconde);
  
  void tic ();
  
  int reqHeure () const;
  int reqMinute () const;
  int reqSeconde () const;
  std::string reqTemps () const;
  
  static int reqNbInstances();
  static bool validerHeure(int p_heure);
  static bool validerMinuteOuSeconde(int p_min_ou_sec);
  
  friend std::ostream& operator <<(std::ostream& p_os, const Temps& p_temps); //Permet d'écrire directement objet ostream << objet Temps
  
  virtual ~Temps ();
  
private:
  int m_heure;
  int m_minute;
  int m_seconde;
  
  static int m_nb_instances; //Attribut commun a toute les classes. Permet de savoir le nombre d'objets crée dans ce cas présent.
};

#endif /* TEMPS_H */

