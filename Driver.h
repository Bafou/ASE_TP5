/*
 * Driver.h
 * Authors : Honoré NINTUNZE & Antoine PETIT
 */
#ifndef DRIVER_H
#define DRIVER_H

void read_sector(unsigned int, unsigned int, unsigned char *);

void read_sectorn(unsigned int, unsigned int, unsigned char *, unsigned int);

void write_sector(unsigned int, unsigned int, const unsigned char *);

void write_sectorn(unsigned int, unsigned int, const unsigned char *, unsigned int);

void format_sector(unsigned int,unsigned int, unsigned int, unsigned int);

#endif
