/*
 * config.c
 *
 *  Created on: 15 févr. 2018
 *      Author: louis
 */

#include "config.h"

// Génération du fichier config
void createConfigFile(Data * data){
		xmlDocPtr doc = NULL;
		xmlNodePtr root_node = NULL, node = NULL;

		doc = xmlNewDoc(BAD_CAST "1.0");
		root_node = xmlNewNode(NULL, BAD_CAST "Config");

		xmlDocSetRootElement(doc, root_node);

		node = xmlNewChild(root_node, NULL, BAD_CAST "CenterName", NULL);
		xmlNewProp(node, BAD_CAST "Value", BAD_CAST data->name);
		node = xmlNewChild(root_node, NULL, BAD_CAST "ipServer", NULL);
		xmlNewProp(node, BAD_CAST "Value", BAD_CAST data->ip);

		xmlSaveFormatFileEnc(CONFIG, doc, "UTF-8", 1);

		xmlFreeDoc(doc);
		xmlCleanupParser();
		xmlMemoryDump();
}

// Initialisation de Data
Data * initData(){
	Data * data = NULL;

	data = malloc(sizeof(Data) * 1);
	if(data == NULL){
		printf("Erreur allocation structure ! \n");
		return NULL;
	}
	data->name = malloc(sizeof(char) * 100);
	if(data->name == NULL){
		printf("Erreur allocation name ! \n");
		free(data);
		return NULL;
	}
	data->ip = malloc(sizeof(char) * 17);
	if(data->ip == NULL){
		printf("Erreur allocation ip ! \n");
		free(data->name);
		free(data);
		return NULL;
	}
	return data;
}

// Libération de data
void freeData(Data * data){
	if(data->name != NULL)
		free(data->name);
	if(data->ip != NULL)
		free(data->ip);

}

// Fonction d'attribution des données du parsing
Data * parseFileConfig(char * filename){
	xmlDocPtr doc = NULL;
	xmlNode * root_node = NULL;
	xmlNode * cur_node = NULL;
	Data * data = NULL;
	char * value = NULL;

	data = initData();
	value = malloc(sizeof(char) * (strlen("Value") + 1));
	strcpy(value, "Value");

	doc = xmlReadFile(filename, NULL, 0);
	if(doc == NULL){
		printf("Erreur à l'ouverture du fichier ! \n");
		freeData(data);
		free(data);
		free(value);
		return NULL;
	}
	root_node = xmlDocGetRootElement(doc);
	if(root_node == NULL){
		printf("Le document est vierge ! \n");
		freeData(data);
		free(data);
		free(value);
		xmlFreeDoc(doc);
		return NULL;
	}
	cur_node = root_node;

	// Pour sauter l'espace blanc
	cur_node = cur_node->children;

	cur_node = cur_node->next;
	while(cur_node != NULL){
		if(!strcmp((char*)cur_node->name, "CenterName")){
			data->name = (char*)xmlGetProp(cur_node, (xmlChar*)value);
		}
		else if(!strcmp((char*)cur_node->name, "ipServer")){
			data->ip = (char*)xmlGetProp(cur_node, (xmlChar*)value);
		}
		cur_node = cur_node->next;
	}
	free(value);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();

	return data;
}
