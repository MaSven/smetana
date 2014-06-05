#line 1 "graphviz-2.38.0\\lib\\gvpr\\trie.c" 1


#line 1 "graphviz-2.38.0\\lib\\gvpr\\trieFA.h" 1
/* File - trieFA.h
 *
 *    This file contains code to be included in the scanner file using a
 * generated trie-based FA.
 */

typedef struct {				/* An entry in the FA state table			*/
	short			def;		/* 	If this state is an accepting state then*/
								/*	this is the definition, otherwise -1.	*/
	short			trans_base;	/* The base index into the transition table.*/
	long			mask;		/* The transition mask. 					*/
}TrieState ;

typedef struct {				/* An entry in the FA transition table.		*/
	short			c;				/* The transition character (lowercase).*/
	short			next_state;		/* The next state.						*/
}TrieTrans ;


static long CharMask[28] = {
	0x0000001,	0x0000000,	0x0000004,	0x0000008,	
	0x0000010,	0x0000020,	0x0000040,	0x0000080,
	0x0000100,	0x0000200,	0x0000400,	0x0000800,
	0x0001000,	0x0002000,	0x0004000,	0x0008000,
	0x0010000,	0x0020000,	0x0040000,	0x0080000,
	0x0100000,	0x0200000,	0x0400000,	0x0800000,
	0x1000000,	0x2000000,  0x4000000,  0x8000000,
};






	
	
	
	
	
	
	







static short		TFA_State;

/* TFA_Init:
 *
 *    Initialize the trie FA.
 */


/* TFA_Advance:
 *
 *    Advance to the next state (or -1) on the lowercase letter c. 
 */





















/* TFA_Definition:
 *
 *    Return the definition (if any) associated with the current state.
 */


#line 4 "graphviz-2.38.0\\lib\\gvpr\\trie.c" 2

TrieState           TrieStateTbl[70] = {
    { -1, 0, 0x3b8620 },
    { -1, 9, 0x440 },
    { -1, 11, 0x100 },
    { -1, 12, 0x80000 },
    { -1, 13, 0x40 },
    { -1, 14, 0x40 },
    { Y(V), 15, 0x0 },
    { -1, 15, 0x80000 },
    { -1, 16, 0x40 },
    { -1, 17, 0x10 },
    { -1, 18, 0x200000 },
    { -1, 19, 0x40 },
    { -1, 20, 0x20 },
    { Y(G), 21, 0x0 },
    { -1, 21, 0x40 },
    { -1, 22, 0x4 },
    { -1, 23, 0x20 },
    { Y(E), 24, 0x0 },
    { -1, 24, 0x8000 },
    { -1, 25, 0x20 },
    { -1, 26, 0x40 },
    { -1, 27, 0x100 },
    { -1, 28, 0x80000 },
    { -1, 29, 0x40 },
    { -1, 30, 0x40 },
    { Y(V), 31, 0x0 },
    { -1, 31, 0x5 },
    { -1, 33, 0x8040 },
    { -1, 35, 0x20 },
    { -1, 36, 0x100 },
    { -1, 37, 0x40 },
    { -1, 38, 0x100000 },
    { Y(G), 39, 0x0 },
    { -1, 39, 0x10000 },
    { -1, 40, 0x20 },
    { -1, 41, 0x40 },
    { -1, 42, 0x100000 },
    { Y(G), 43, 0x0 },
    { -1, 43, 0x4000 },
    { -1, 44, 0x40 },
    { YALL, 45, 0x0 },
    { -1, 45, 0x400000 },
    { -1, 46, 0x200000 },
    { -1, 47, 0x20 },
    { -1, 48, 0x40 },
    { -1, 49, 0x100 },
    { -1, 50, 0x80000 },
    { -1, 51, 0x40 },
    { -1, 52, 0x40 },
    { Y(V), 53, 0x0 },
    { -1, 53, 0x4 },
    { -1, 54, 0x80000 },
    { -1, 55, 0x40 },
    { -1, 56, 0x8000 },
    { -1, 57, 0x200000 },
    { Y(G), 58, 0x0 },
    { -1, 58, 0x10000 },
    { -1, 59, 0x10000 },
    { -1, 60, 0x200000 },
    { YALL, 61, 0x0 },
    { -1, 61, 0x200000 },
    { -1, 62, 0x80000 },
    { -1, 63, 0x400 },
    { -1, 64, 0x10 },
    { -1, 65, 0x200000 },
    { Y(G), 66, 0x0 },
    { -1, 66, 0x4 },
    { -1, 67, 0x400 },
    { -1, 68, 0x2000 },
    { Y(E), 69, 0x0 },
};
TrieTrans           TrieTransTbl[69] = {
    /* State   0 */  { 'd',   1 }, { 'h',  14 }, { 'i',  18 }, { 'n',  26 }, { 'o',  41 }, { 'p',  50 }, { 'r',  56 }, { 's',  60 }, { 't',  66 },
    /* State   1 */  { 'e',   2 }, { 'i',   7 },
    /* State   2 */  { 'g',   3 },
    /* State   3 */  { 'r',   4 },
    /* State   4 */  { 'e',   5 },
    /* State   5 */  { 'e',   6 },
    /* State   7 */  { 'r',   8 },
    /* State   8 */  { 'e',   9 },
    /* State   9 */  { 'c',  10 },
    /* State  10 */  { 't',  11 },
    /* State  11 */  { 'e',  12 },
    /* State  12 */  { 'd',  13 },
    /* State  14 */  { 'e',  15 },
    /* State  15 */  { 'a',  16 },
    /* State  16 */  { 'd',  17 },
    /* State  18 */  { 'n',  19 },
    /* State  19 */  { 'd',  20 },
    /* State  20 */  { 'e',  21 },
    /* State  21 */  { 'g',  22 },
    /* State  22 */  { 'r',  23 },
    /* State  23 */  { 'e',  24 },
    /* State  24 */  { 'e',  25 },
    /* State  26 */  { '_',  27 }, { 'a',  38 },
    /* State  27 */  { 'e',  28 }, { 'n',  33 },
    /* State  28 */  { 'd',  29 },
    /* State  29 */  { 'g',  30 },
    /* State  30 */  { 'e',  31 },
    /* State  31 */  { 's',  32 },
    /* State  33 */  { 'o',  34 },
    /* State  34 */  { 'd',  35 },
    /* State  35 */  { 'e',  36 },
    /* State  36 */  { 's',  37 },
    /* State  38 */  { 'm',  39 },
    /* State  39 */  { 'e',  40 },
    /* State  41 */  { 'u',  42 },
    /* State  42 */  { 't',  43 },
    /* State  43 */  { 'd',  44 },
    /* State  44 */  { 'e',  45 },
    /* State  45 */  { 'g',  46 },
    /* State  46 */  { 'r',  47 },
    /* State  47 */  { 'e',  48 },
    /* State  48 */  { 'e',  49 },
    /* State  50 */  { 'a',  51 },
    /* State  51 */  { 'r',  52 },
    /* State  52 */  { 'e',  53 },
    /* State  53 */  { 'n',  54 },
    /* State  54 */  { 't',  55 },
    /* State  56 */  { 'o',  57 },
    /* State  57 */  { 'o',  58 },
    /* State  58 */  { 't',  59 },
    /* State  60 */  { 't',  61 },
    /* State  61 */  { 'r',  62 },
    /* State  62 */  { 'i',  63 },
    /* State  63 */  { 'c',  64 },
    /* State  64 */  { 't',  65 },
    /* State  66 */  { 'a',  67 },
    /* State  67 */  { 'i',  68 },
    /* State  68 */  { 'l',  69 },
};
