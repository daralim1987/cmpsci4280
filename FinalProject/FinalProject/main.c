//  main.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testTree.h"
#include "codeCreator.h"
#include "createNode.h"
#include "parser.h"
int main(int argc, const char * argv[]) {
    if (argc > 2) {
        printf("There is an unexpected argument given\n");
        return 1;
    }
    FILE *pOut = NULL;
    char *fIn = NULL;
    char *nFile = NULL;
    const char exOutFile[] = ".asm";
    FILE *pIn = NULL;
    
    if (argc == 2) {
        const char exIn[] = ".input1";
        
        nFile = (char *) malloc(sizeof(argv[1]));
        strcpy(nFile, argv[1]);
        fIn = (char *) malloc(sizeof(nFile) + sizeof(exIn));
        strcpy(fIn, nFile);
        strcat(fIn, exIn);
        pIn = fopen(fIn, "r");
        
        if (!pIn) {
            printf("File '%s' could not be opened\n", fIn);
            return 1;
        }
    }
    else {
        const char fOutName[] = "out";
        nFile = (char *) malloc(sizeof(fOutName));
        strcpy(nFile, fOutName);
        pIn = stdin;
    }
    
    node *root = parser(pIn);
    fclose(pIn);
    
    char fOut[strlen(nFile) + strlen(exOutFile)];
    strcpy(fOut, nFile);
    strcat(fOut, exOutFile);
    free(nFile);
    pOut = fopen(fOut, "w");
    
    if (!pOut) {
        printf("File '%s' error to open\n", fOut);
        return 1;
    }
    
    generator(root, pOut);
    fclose(pOut);
    
    if (fIn != NULL) {
        printf("comp %s\n", fIn);
    }
    printf("comp %s\n", fOut);
    free(fIn);
    return ( 0 );
}
