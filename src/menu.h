/*
 * menu.h
 *
 *  Created on: 21 févr. 2018
 *      Author: louis
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_
#include "createXml.h"


void inputXml(Profile *);
void inputConfig(Data *);
void outputXml(Profile *);
void mainProccessUser(Profile *);
void mainProccessAdmin(Data *);
void menuUser();
void menuAdmin();

#endif /* SRC_MENU_H_ */
