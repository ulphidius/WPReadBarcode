/*
 * library.h
 *
 *  Created on: 12 févr. 2018
 *      Author: louis
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Resources pour libxml2
#include <libxml/parser.h>
#include <libxml/tree.h>

// Resource pour manipulation des dossiers et des fichiers
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#if defined(_WIN32)
#include <direct.h>
#endif

#define CLEAR_STDIN { int c; while((c = getchar()) && (c != '\n')); }

#endif /* LIBRARY_H_ */
