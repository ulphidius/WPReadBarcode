/*
 * menu.c
 *
 *  Created on: 21 févr. 2018
 *      Author: louis
 */

#include "menu.h"

void inputXml(Profile * profile){
	mainProccessUser(profile);
	addUser(profile, 1);
}

void inputConfig(Data * data){
	mainProccessAdmin(data);
	createConfigFile(data);
}

void outputXml(Profile * profile){
	mainProccessUser(profile);
	addUser(profile, 0);
}

void mainProccessUser(Profile * profile){
	printf("scanner votre code : ");
	fgets(profile->id, 50, stdin);
	CLEAR_STDIN;
	profile->id[strlen(profile->id) - 1] = '\0';
	strcpy(profile->id, profile->id + 3);
	printf("\n");
}

void mainProccessAdmin(Data * data){
	printf("Entrez le nom du site : ");
	fgets(data->name, 100, stdin);
	CLEAR_STDIN;
	data->name[strlen(data->name) - 1] = '\0';
	printf("\n");
	printf("Entrez l'ip du serveur central : ");
	fgets(data->ip, 17, stdin);
	CLEAR_STDIN;
	data->ip[strlen(data->ip) - 1] = '\0';
	printf("\n");
}

void menuUser(){
	Profile * profile = NULL;
	char choise = 0;
	profile = initProfile();

	checkFileExist();

	do{
		printf("Bonjour vous entrez ou sortez ? (e/s/q) :");
		scanf("%c", &choise);
		CLEAR_STDIN;
		printf("\n");
		if(choise == 'e'||choise == 'E'){
			inputXml(profile);

		}else if(choise == 's'||choise == 'S'){
			outputXml(profile);

		}else if(choise == 'q'||choise == 'Q'){
			printf("Vous quitez la phase principal du programme ! \n");
			freeProfile(profile);
			free(profile);
			return;

		}else{
			printf("Vous n'avait pas rentré la donnée attendu ! \n");
			freeProfile(profile);
			free(profile);
			return;
		}
	}while(1);

	freeProfile(profile);
	free(profile);
	return;
}

void menuAdmin(){
	Data * data = NULL;
	char choise = 0;

	data = initData();

	do{
		printf("Voulez-vous changer la configuration ? (o/n) :");
		scanf("%c", &choise);
		CLEAR_STDIN;
		printf("\n");
		if(choise == 'o'||choise == 'O'){
			inputConfig(data);

		}else if(choise == 'n'||choise == 'N'){
			printf("Retour en arrière ! \n");
			freeData(data);
			free(data);
			return;

		}else{
			printf("Erreur mauvaise entrée de donnée ! \n");
			freeData(data);
			free(data);
			return;

		}
	}while(1);
}

void mainLoop(){
	char choise = 0;

	printf("Bonjour lancemment du programme \n");
	printf("Que voulez-vous faire ? \n");
	printf("Lancer le programme de passage utilisateur ? (u) \n");
	printf("Lancer le programme de mise à jour de la configuration ? (c) \n");
	printf("Quiter le programme ? (q) \n");
	printf("Entrez votre choix : ");
	scanf("%c", &choise);
	CLEAR_STDIN;
	printf("\n");

	if(choise == 'u'||choise == 'U'){
		menuUser();

	}else if(choise == 'c'||choise == 'C'){
		menuAdmin();

	}else if(choise == 'q'||choise == 'Q'){
		exit(EXIT_SUCCESS);

	}else{
		printf("Mauvaise entrée ! \n");
		exit(EXIT_FAILURE);

	}

	return;
}
