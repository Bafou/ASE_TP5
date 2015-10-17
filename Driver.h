/*
 * Driver.h
 * Authors : Honoré NINTUNZE & Antoine PETIT
 */
#ifndef DRIVER_H
#define DRIVER_H

/*
 * Lit les données de la piste cylinder, secteur sector
 * @param cylinder le numéro de piste
 * @param sector le numéro de secteur
 * @param buffer où seront stockées les données lues
 */
void read_sector(unsigned int, unsigned int, unsigned char *);
/*
 * Lit au maximum n octets des données de la piste cylinder, secteur sector
 * @param cylinder le numéro de piste
 * @param sector le numéro de secteur
 * @param buffer où seront stockées les données lues
 * @param bufsize la taille des données à lire
 */
void read_sectorn(unsigned int, unsigned int, unsigned char *, unsigned int);
/*
 * Ecrit des données sur la piste cylinder, secteur sector
 * @param cylinder le numéro de piste
 * @param sector le numéro de secteur
 * @param buffer les données à écrire
 */
void write_sector(unsigned int, unsigned int, const unsigned char *);
/*
 * Ecrit au maximum n octets sur la piste cylinder, secteur sector
 * @param cylinder le numéro de piste
 * @param sector le numéro de secteur
 * @param buffer les données à écrire
 * @param bufsize la taille des données à écrire
 */
void write_sectorn(unsigned int, unsigned int, const unsigned char *, unsigned int);
/*
 * Formate les données de la piste cylinder, secteur sector
 * @param cylinder le numéro de piste
 * @param sector le numéro de secteur
 * @param nsector le nombre de secteur à formater
 * @param value la valeur à initialiser
 */
void format_sector(unsigned int,unsigned int, unsigned int, unsigned int);

#endif
