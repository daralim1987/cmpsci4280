//  token.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.


#ifndef token_h
#define token_h

#define SIZE 9
typedef enum {
    Ntk = -1,
    
    Begin_token=0, End_token, Loop_token, Void_token, Int_token,
    Return_token, Read_token, Output_token, Program_token,
    Iff_token, Then_token, Let_token,
    
    Eof_token, Id_token, Integer_token,
    Eq_token, Less_token, Greater_token, Col_token, Plus_token, Minus_token, Mul_token, Di_token, Mod_token, Dot_token, Lpar_token,
    Rpar_token, Comm_token, Lbrac_token, Rbrac_token, Semi_token, Lbrack_token, Rbrack_token, 
} instanceToken;


typedef struct {
    instanceToken kindOf;
    char ofType[9];
    int numOfLine;
} token;

#endif /* token_h */
