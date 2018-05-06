/*
 * createXml.h
 *
 *  Created on: 12 févr. 2018
 *      Author: louis
 */

#ifndef SRC_CREATEXML_H_
#define SRC_CREATEXML_H_

#include "library.h"
#include "config.h"
#define IN "in"
#define OUT "out"

#if defined(_WIN32)
#define PROFILE_FILENAME_START "Passages\\"
#else
#define PROFILE_FILENAME_START "Passages/"
#endif

#define FILENAME_END ".xml"


typedef struct Profile{
	char * id;
	char * time;
	char * statut;
}Profile;

void showProfile(Profile *);
void addUser(Profile *, int);
void createXmlFile();
void freeProfile(Profile *);
void print_element_names(xmlNode *);
void addProp(Profile *, xmlNodePtr, char *);
void addProp(Profile *, xmlNodePtr, char *);
void checkProfileDirectoryExist();
void checkFileExist();
void generateTime(char *);
char * generateFileName();


xmlDocPtr openXmlFile(char *);
xmlNodePtr getRootNode(xmlDocPtr);
xmlNodePtr addNode();

Profile * initProfile();

#endif /* SRC_CREATEXML_H_ */
