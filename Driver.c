#include <stdlib.h>
#include <stdio.h>
#include "include/hardware.h"
#include "hw_config.h"

void seek (unsigned int cylinder, unsigned int sector) {
  _out(HDA_DATAREGS, (cylinder >> 8) & 0xFF);
  _out(HDA_DATAREGS + 1, (cylinder) & 0xFF);
  _out(HDA_DATAREGS + 2, (sector >> 8) & 0xFF);
  _out(HDA_DATAREGS + 3, (sector) & 0xFF);
  _out(CMD_REG,CMD_SEEK);
  return;
}

void read_sector(unsigned int cylinder,unsigned int sector, unsigned char *buffer) {
  int i;
  seek(cylinder, sector);
  _sleep(HDA_IRQ);
  _out(HDA_DATAREGS,0);
  _out(HDA_DATAREGS + 1,1);
  _out(CMD_REG,CMD_READ);
  _sleep(HDA_IRQ);
  for (i=0; i<HDA_SECTORSIZE ;i++) 
    buffer[i]=MASTERBUFFER[i];
  return;
}

void read_sectorn(unsigned int cylinder,unsigned int sector, unsigned char *buffer, unsigned int bufsize) {
  int i;
  seek(cylinder, sector);
  _sleep(HDA_IRQ);
  _out(HDA_DATAREGS,0);
  _out(HDA_DATAREGS + 1,1);
  _out(CMD_REG,CMD_READ);
  _sleep(HDA_IRQ);
  for (i=0; i<bufsize ;i++) 
    buffer[i]=MASTERBUFFER[i];
  return;
}

void write_sector(unsigned int cylinder, unsigned int sector, const unsigned char *buffer) {
  int i;
  seek(cylinder, sector);
  _sleep(HDA_IRQ);
  for (i=0; i<HDA_SECTORSIZE ; i++) {
    MASTERBUFFER[i] = buffer[i];
  }
  _out(HDA_DATAREGS,0);
  _out(HDA_DATAREGS + 1,1);
  _out(CMD_REG, CMD_WRITE);
  _sleep(HDA_IRQ);
  return;
}

void write_sectorn(unsigned int cylinder, unsigned int sector, const unsigned char *buffer, unsigned int bufsize) {
  int i;
  seek(cylinder, sector);
  _sleep(HDA_IRQ);
  for (i=0; i<bufsize ; i++) {
    MASTERBUFFER[i] = buffer[i];
  }
  _out(HDA_DATAREGS,0);
  _out(HDA_DATAREGS + 1,1);
  _out(CMD_REG, CMD_WRITE);
  _sleep(HDA_IRQ);
  return;
}

void format_sector(unsigned int cylinder,unsigned int sector, unsigned int nsector, unsigned int value) {
  seek(cylinder, sector);
  _sleep(HDA_IRQ);
  _out(HDA_DATAREGS, 0);
  _out(HDA_DATAREGS + 1, 1);
  _out(HDA_DATAREGS + 2, 0);
  _out(HDA_DATAREGS + 3, 0);
  _out(HDA_DATAREGS + 4, 0);
  _out(HDA_DATAREGS + 5, 0);
  _out(CMD_REG, CMD_FORMAT);
  _sleep(HDA_IRQ);
  return;
}
