/*
 * createXml.c
 *
 *  Created on: 12 févr. 2018
 *      Author: louis
 */

#include "createXml.h"

// Création du fichier xml
void createXmlFile(){
	xmlDocPtr doc = NULL;
	xmlNodePtr root_node = NULL;
	char * filename = NULL;

	doc = xmlNewDoc(BAD_CAST "1.0");
	if(doc == NULL){
		printf("Erreur création du fichier xml ! \n");
		return;
	}

	root_node = xmlNewNode(NULL, BAD_CAST "Passage");
	if(root_node == NULL){
		printf("Erreur création du node racine ! \n");
		xmlFreeDoc(doc);
		return;
	}

	xmlDocSetRootElement(doc, root_node);

	filename = generateFileName();
	xmlSaveFormatFileEnc(filename, doc, "UTF-8", 1);

	xmlFreeDoc(doc);
	free(filename);
	xmlCleanupParser();
	xmlMemoryDump();

}

// Ouverture du fichier xml
xmlDocPtr openXmlFile(char * filename){
	xmlDocPtr doc = NULL;
	doc = xmlReadFile(filename, "UTF-8", 1);
	if(doc == NULL){
		printf("Erreur ouverture du fichier ! \n");
		return NULL;
	}
	return doc;
}

// Obtention du noeud racine
xmlNodePtr getRootNode(xmlDocPtr doc){
	xmlNodePtr root_node = NULL;
	root_node = xmlDocGetRootElement(doc);
	if(root_node == NULL){
		printf("Erreur à l'obtention du noeud racine ! \n");
		return NULL;
	}
	return root_node;
}

// Ajout d'un node
xmlNodePtr addNode(){
	xmlNodePtr node = NULL;
	node = xmlNewNode(NULL, BAD_CAST "User");
	if(node == NULL){
		printf("Erreur à la création du node ! \n");
		return NULL;
	}
	return node;
}

// Ajout des données
void addProp(Profile * profile, xmlNodePtr node, char * value){
	if(xmlNewProp(node, BAD_CAST "id", BAD_CAST profile->id) == NULL ||
	   xmlNewProp(node, BAD_CAST "time", BAD_CAST profile->time) == NULL ||
	   xmlNewProp(node, BAD_CAST "check", BAD_CAST value) == NULL){
		printf("Erreur à l'ajout des propriétés ! \n");
		return;
	}
}

// Transformation noeud classique en noeud enfant
void addChild(xmlNodePtr root_node, xmlNodePtr node){
	if(xmlAddChild(root_node, node) == NULL){
		printf("Erreur à l'ajout de l'enfant");
		return;
	}
}

// Ajout d'un passage
void addUser(Profile * profile, int inOut){
	xmlDocPtr doc = NULL;
	xmlNodePtr root_node = NULL;
	xmlNodePtr node = NULL;
	char * filename = NULL;

	filename = generateFileName();
	doc = openXmlFile(filename);
	root_node = getRootNode(doc);
	node = addNode();
	generateTime(profile->time);

	if(inOut > 0){
		addProp(profile, node, IN);
	}else{
		addProp(profile, node, OUT);
	}
	addChild(root_node, node);

	xmlSaveFormatFileEnc(filename, doc, "UTF-8", 1);

	free(filename);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();
}

// Affichage du profil
void showProfile(Profile * profile){
	printf("%s\n", profile->id == NULL ? "(null)" : profile->id);
	printf("%s\n", profile->time == NULL ?"(null)" : profile->time);
	printf("%s\n", profile->statut == NULL ? "(null)" : profile->statut);

}

// Initialisation de la structure
Profile * initProfile(){
	Profile * profile = NULL;

	profile = malloc(sizeof(Profile) * 1);
	if(profile == NULL){
		printf("Erreur allocation structure ! \n");
		return NULL;
	}
	profile->id = malloc(50 * 1);
	if(profile->id == NULL){
		printf("Erreur allocation id ! \n");
		free(profile);
		return NULL;
	}

	profile->time = malloc(6 * 1);
	if(profile->time == NULL){
		free(profile->id);
		free(profile);
		return NULL;
	}

	profile->statut = malloc(4 * 1);
	if(profile->statut == NULL){
		printf("Erreur allocation ");
		free(profile->id);
		free(profile->time);
		free(profile);
		return NULL;
	}

	return profile;
}

// Fonction de libération la structure
void freeProfile(Profile * profile){
	if(profile == NULL){
		printf("Le profile est null \n");
		return;
	}
	if(profile->id != NULL)
		free(profile->id);
	if(profile->statut != NULL)
		free(profile->statut);
	if(profile->time != NULL)
		free(profile->time);

}

// Génération du nom du fichier
char * generateFileName(){
	Data * data = NULL;
	time_t secondes;
	struct tm instant;
	char * filename = NULL;
	char * day = NULL;
	char * month = NULL;
	char * year = NULL;

	filename = malloc(250 * 1);
	if(filename == NULL){
		printf("Erreur à l'allocation de filename ! \n");
		return NULL;
	}
	day = malloc(3 * 1);
	if(day == NULL){
		printf("Erreur à l'allocation de day ! \n");
		free(filename);
		return NULL;
	}
	month = malloc(3 * 1);
	if(month == NULL){
		printf("Erreur à l'allocation de mouth ! \n");
		free(filename);
		free(day);
		return NULL;
	}
	year = malloc(5 * 1);
	if(year == NULL){
		printf("Erreur à l'allocation de year ! \n");
		free(filename);
		free(day);
		free(month);
		return NULL;
	}

	checkProfileDirectoryExist();
	data = parseFileConfig(CONFIG);
	time(&secondes);
	instant=*localtime(&secondes);

	sprintf(day, "%d", instant.tm_mday);
	sprintf(month, "%d", (instant.tm_mon+1));
	sprintf(year, "%d", ((instant.tm_year+1900) - 2000));

	strcpy(filename, PROFILE_FILENAME_START);
	strcat(filename, data->name);
	if(strlen(day) == 1){
		strcat(filename, "0");
	}
	strcat(filename, day);
	if(strlen(month) == 1){
		strcat(filename, "0");
	}
	strcat(filename, month);
	strcat(filename, year);
	strcat(filename, FILENAME_END);

	freeData(data);
	free(data);
	free(day);
	free(month);
	free(year);

	return filename;
}

// Génération des heures d'entrés et sorties
void generateTime(char * timeFinal){
	char * hour = NULL;
	char * min = NULL;
	time_t secondes;
	struct tm instant;

	hour = malloc(3 * 1);
	if(hour == NULL){
		printf("Erreur à l'allocation de la chaine hour a échoué ! \n");
		return;
	}
	min = malloc(3 * 1);
	if(min == NULL){
		printf("Erreur à l'allocation de la chaine min a échoué ! \n");
		free(hour);
		return;
	}

	time(&secondes);
	instant=*localtime(&secondes);

	sprintf(hour, "%d", instant.tm_hour);
	sprintf(min, "%d", instant.tm_min);
	strcpy(timeFinal, hour);
	strcat(timeFinal, ":");
	strcat(timeFinal, min);

	free(hour);
	free(min);
}

// Fonction de verification de l'existance du dossier
void checkProfileDirectoryExist(){
	DIR* dir = opendir(PROFILE_FILENAME_START);

	if (dir){
		// Si oui
		closedir(dir);

	}else if (ENOENT == errno){
		// Sinon
#if defined(_WIN32)
		_mkdir(PROFILE_FILENAME_START);
#else
		mkdir(PROFILE_FILENAME_START, 0700);
#endif

	}else{
		// Erreur
		printf("Erreur à l'ouverture/creation du dossier Passage ! \n");
		exit(EXIT_FAILURE);

	}
}

// Vérification d'existance du fichier
void checkFileExist(){
	FILE * file = NULL;
	char * filename = NULL;
	filename = generateFileName();
	file = fopen(filename, "r");
	if(file == NULL){
		createXmlFile();
	}
	free(filename);
}
