#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void extract_args(char *buf, char **args, char **commande, char **buf_tmp, int *i, int len)
{
    char *argument;

    // Initialisation de l'indice
    *i = 0;

    // Enlever le saut de ligne causé par l'entrée du clavier
    if (len > 0 && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
    }

    // Dupliquer la chaîne de commande pour la manipulation
    *buf_tmp = strdup(buf);

    // Extraire la commande
    *commande = strtok(buf, " ");
    if (*commande != NULL)
    {
        args[*i] = strdup(*commande);
        (*i)++;
    }

    // Extraire les arguments
    while ((argument = strtok(NULL, " ")) != NULL && *i < NBR_MAX_ARGUMENTS)
    {
        args[*i] = strdup(argument);
        (*i)++;
    }

    // Marquer la fin du tableau d'arguments
    args[*i] = NULL;
}