/*
 * config.h
 *
 *  Created on: 15 févr. 2018
 *      Author: louis
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include "library.h"
#define CONFIG "config.xml"

typedef struct Data{
	char * name;
	char * ip;
}Data;

void createConfigFile(Data *);
Data * initData();
void freeData(Data *);
void get_attribute(xmlNode *, char **);
Data * parseFileConfig(char *);

#endif /* CONFIG_H_ */
