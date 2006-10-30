/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regcomp.pl from regcomp.sym.
   Any changes made here will be lost!
*/

/* Regops and State definitions */

#define REGNODE_MAX           	75
#define REGMATCH_STATE_MAX    	105

#define	END                   	0	/* 0000 End of program. */
#define	SUCCEED               	1	/* 0x01 Return from a subroutine, basically. */
#define	BOL                   	2	/* 0x02 Match "" at beginning of line. */
#define	MBOL                  	3	/* 0x03 Same, assuming multiline. */
#define	SBOL                  	4	/* 0x04 Same, assuming singleline. */
#define	EOS                   	5	/* 0x05 Match "" at end of string. */
#define	EOL                   	6	/* 0x06 Match "" at end of line. */
#define	MEOL                  	7	/* 0x07 Same, assuming multiline. */
#define	SEOL                  	8	/* 0x08 Same, assuming singleline. */
#define	BOUND                 	9	/* 0x09 Match "" at any word boundary */
#define	BOUNDL                	10	/* 0x0a Match "" at any word boundary */
#define	NBOUND                	11	/* 0x0b Match "" at any word non-boundary */
#define	NBOUNDL               	12	/* 0x0c Match "" at any word non-boundary */
#define	GPOS                  	13	/* 0x0d Matches where last m//g left off. */
#define	REG_ANY               	14	/* 0x0e Match any one character (except newline). */
#define	SANY                  	15	/* 0x0f Match any one character. */
#define	CANY                  	16	/* 0x10 Match any one byte. */
#define	ANYOF                 	17	/* 0x11 Match character in (or not in) this class. */
#define	ALNUM                 	18	/* 0x12 Match any alphanumeric character */
#define	ALNUML                	19	/* 0x13 Match any alphanumeric char in locale */
#define	NALNUM                	20	/* 0x14 Match any non-alphanumeric character */
#define	NALNUML               	21	/* 0x15 Match any non-alphanumeric char in locale */
#define	SPACE                 	22	/* 0x16 Match any whitespace character */
#define	SPACEL                	23	/* 0x17 Match any whitespace char in locale */
#define	NSPACE                	24	/* 0x18 Match any non-whitespace character */
#define	NSPACEL               	25	/* 0x19 Match any non-whitespace char in locale */
#define	DIGIT                 	26	/* 0x1a Match any numeric character */
#define	DIGITL                	27	/* 0x1b Match any numeric character in locale */
#define	NDIGIT                	28	/* 0x1c Match any non-numeric character */
#define	NDIGITL               	29	/* 0x1d Match any non-numeric character in locale */
#define	CLUMP                 	30	/* 0x1e Match any combining character sequence */
#define	BRANCH                	31	/* 0x1f Match this alternative, or the next... */
#define	BACK                  	32	/* 0x20 Match "", "next" ptr points backward. */
#define	EXACT                 	33	/* 0x21 Match this string (preceded by length). */
#define	EXACTF                	34	/* 0x22 Match this string, folded (prec. by length). */
#define	EXACTFL               	35	/* 0x23 Match this string, folded in locale (w/len). */
#define	NOTHING               	36	/* 0x24 Match empty string. */
#define	TAIL                  	37	/* 0x25 Match empty string. Can jump here from outside. */
#define	STAR                  	38	/* 0x26 Match this (simple) thing 0 or more times. */
#define	PLUS                  	39	/* 0x27 Match this (simple) thing 1 or more times. */
#define	CURLY                 	40	/* 0x28 Match this simple thing {n,m} times. */
#define	CURLYN                	41	/* 0x29 Capture next-after-this simple thing */
#define	CURLYM                	42	/* 0x2a Capture this medium-complex thing {n,m} times. */
#define	CURLYX                	43	/* 0x2b Match this complex thing {n,m} times. */
#define	WHILEM                	44	/* 0x2c Do curly processing and see if rest matches. */
#define	OPEN                  	45	/* 0x2d Mark this point in input as start of */
#define	CLOSE                 	46	/* 0x2e Analogous to OPEN. */
#define	REF                   	47	/* 0x2f Match some already matched string */
#define	REFF                  	48	/* 0x30 Match already matched string, folded */
#define	REFFL                 	49	/* 0x31 Match already matched string, folded in loc. */
#define	IFMATCH               	50	/* 0x32 Succeeds if the following matches. */
#define	UNLESSM               	51	/* 0x33 Fails if the following matches. */
#define	SUSPEND               	52	/* 0x34 "Independent" sub-RE. */
#define	IFTHEN                	53	/* 0x35 Switch, should be preceeded by switcher . */
#define	GROUPP                	54	/* 0x36 Whether the group matched. */
#define	LONGJMP               	55	/* 0x37 Jump far away. */
#define	BRANCHJ               	56	/* 0x38 BRANCH with long offset. */
#define	EVAL                  	57	/* 0x39 Execute some Perl code. */
#define	MINMOD                	58	/* 0x3a Next operator is not greedy. */
#define	LOGICAL               	59	/* 0x3b Next opcode should set the flag only. */
#define	RENUM                 	60	/* 0x3c Group with independently numbered parens. */
#define	TRIE                  	61	/* 0x3d Match many EXACT(FL?)? at once. flags==type */
#define	TRIEC                 	62	/* 0x3e Same as TRIE, but with embedded charclass data */
#define	AHOCORASICK           	63	/* 0x3f Aho Corasick stclass. flags==type */
#define	AHOCORASICKC          	64	/* 0x40 Same as AHOCORASICK, but with embedded charclass data */
#define	RECURSE               	65	/* 0x41 recurse to paren arg1 at (signed) ofs arg2 */
#define	SRECURSE              	66	/* 0x42 recurse to start of pattern */
#define	NREF                  	67	/* 0x43 Match some already matched string */
#define	NREFF                 	68	/* 0x44 Match already matched string, folded */
#define	NREFFL                	69	/* 0x45 Match already matched string, folded in loc. */
#define	NGROUPP               	70	/* 0x46 Whether the group matched. */
#define	RECURSEP              	71	/* 0x47 Whether we are in a specific recurse. */
#define	DEFINEP               	72	/* 0x48 Never execute directly. */
#define	OPFAIL                	73	/* 0x49 Same as (?!) */
#define	OPTIMIZED             	74	/* 0x4a Placeholder for dump. */
#define	PSEUDO                	75	/* 0x4b Pseudo opcode for internal use. */

	/* ------------ States ------------- */

#define	TRIE_next             	76	/* 0x4c Regmatch state for TRIE */
#define	TRIE_next_fail        	77	/* 0x4d Regmatch state for TRIE */
#define	EVAL_AB               	78	/* 0x4e Regmatch state for EVAL */
#define	EVAL_AB_fail          	79	/* 0x4f Regmatch state for EVAL */
#define	CURLYX_end            	80	/* 0x50 Regmatch state for CURLYX */
#define	CURLYX_end_fail       	81	/* 0x51 Regmatch state for CURLYX */
#define	WHILEM_A_pre          	82	/* 0x52 Regmatch state for WHILEM */
#define	WHILEM_A_pre_fail     	83	/* 0x53 Regmatch state for WHILEM */
#define	WHILEM_A_min          	84	/* 0x54 Regmatch state for WHILEM */
#define	WHILEM_A_min_fail     	85	/* 0x55 Regmatch state for WHILEM */
#define	WHILEM_A_max          	86	/* 0x56 Regmatch state for WHILEM */
#define	WHILEM_A_max_fail     	87	/* 0x57 Regmatch state for WHILEM */
#define	WHILEM_B_min          	88	/* 0x58 Regmatch state for WHILEM */
#define	WHILEM_B_min_fail     	89	/* 0x59 Regmatch state for WHILEM */
#define	WHILEM_B_max          	90	/* 0x5a Regmatch state for WHILEM */
#define	WHILEM_B_max_fail     	91	/* 0x5b Regmatch state for WHILEM */
#define	BRANCH_next           	92	/* 0x5c Regmatch state for BRANCH */
#define	BRANCH_next_fail      	93	/* 0x5d Regmatch state for BRANCH */
#define	CURLYM_A              	94	/* 0x5e Regmatch state for CURLYM */
#define	CURLYM_A_fail         	95	/* 0x5f Regmatch state for CURLYM */
#define	CURLYM_B              	96	/* 0x60 Regmatch state for CURLYM */
#define	CURLYM_B_fail         	97	/* 0x61 Regmatch state for CURLYM */
#define	IFMATCH_A             	98	/* 0x62 Regmatch state for IFMATCH */
#define	IFMATCH_A_fail        	99	/* 0x63 Regmatch state for IFMATCH */
#define	CURLY_B_min_known     	100	/* 0x64 Regmatch state for CURLY */
#define	CURLY_B_min_known_fail	101	/* 0x65 Regmatch state for CURLY */
#define	CURLY_B_min           	102	/* 0x66 Regmatch state for CURLY */
#define	CURLY_B_min_fail      	103	/* 0x67 Regmatch state for CURLY */
#define	CURLY_B_max           	104	/* 0x68 Regmatch state for CURLY */
#define	CURLY_B_max_fail      	105	/* 0x69 Regmatch state for CURLY */

/* PL_regkind[] What type of regop or state is this. */

#ifndef DOINIT
EXTCONST U8 PL_regkind[];
#else
EXTCONST U8 PL_regkind[] = {
	END,     	/* END                    */
	END,     	/* SUCCEED                */
	BOL,     	/* BOL                    */
	BOL,     	/* MBOL                   */
	BOL,     	/* SBOL                   */
	EOL,     	/* EOS                    */
	EOL,     	/* EOL                    */
	EOL,     	/* MEOL                   */
	EOL,     	/* SEOL                   */
	BOUND,   	/* BOUND                  */
	BOUND,   	/* BOUNDL                 */
	NBOUND,  	/* NBOUND                 */
	NBOUND,  	/* NBOUNDL                */
	GPOS,    	/* GPOS                   */
	REG_ANY, 	/* REG_ANY                */
	REG_ANY, 	/* SANY                   */
	REG_ANY, 	/* CANY                   */
	ANYOF,   	/* ANYOF                  */
	ALNUM,   	/* ALNUM                  */
	ALNUM,   	/* ALNUML                 */
	NALNUM,  	/* NALNUM                 */
	NALNUM,  	/* NALNUML                */
	SPACE,   	/* SPACE                  */
	SPACE,   	/* SPACEL                 */
	NSPACE,  	/* NSPACE                 */
	NSPACE,  	/* NSPACEL                */
	DIGIT,   	/* DIGIT                  */
	DIGIT,   	/* DIGITL                 */
	NDIGIT,  	/* NDIGIT                 */
	NDIGIT,  	/* NDIGITL                */
	CLUMP,   	/* CLUMP                  */
	BRANCH,  	/* BRANCH                 */
	BACK,    	/* BACK                   */
	EXACT,   	/* EXACT                  */
	EXACT,   	/* EXACTF                 */
	EXACT,   	/* EXACTFL                */
	NOTHING, 	/* NOTHING                */
	NOTHING, 	/* TAIL                   */
	STAR,    	/* STAR                   */
	PLUS,    	/* PLUS                   */
	CURLY,   	/* CURLY                  */
	CURLY,   	/* CURLYN                 */
	CURLY,   	/* CURLYM                 */
	CURLY,   	/* CURLYX                 */
	WHILEM,  	/* WHILEM                 */
	OPEN,    	/* OPEN                   */
	CLOSE,   	/* CLOSE                  */
	REF,     	/* REF                    */
	REF,     	/* REFF                   */
	REF,     	/* REFFL                  */
	BRANCHJ, 	/* IFMATCH                */
	BRANCHJ, 	/* UNLESSM                */
	BRANCHJ, 	/* SUSPEND                */
	BRANCHJ, 	/* IFTHEN                 */
	GROUPP,  	/* GROUPP                 */
	LONGJMP, 	/* LONGJMP                */
	BRANCHJ, 	/* BRANCHJ                */
	EVAL,    	/* EVAL                   */
	MINMOD,  	/* MINMOD                 */
	LOGICAL, 	/* LOGICAL                */
	BRANCHJ, 	/* RENUM                  */
	TRIE,    	/* TRIE                   */
	TRIE,    	/* TRIEC                  */
	TRIE,    	/* AHOCORASICK            */
	TRIE,    	/* AHOCORASICKC           */
	RECURSE, 	/* RECURSE                */
	SRECURSE,	/* SRECURSE               */
	NREF,    	/* NREF                   */
	NREF,    	/* NREFF                  */
	NREF,    	/* NREFFL                 */
	NGROUPP, 	/* NGROUPP                */
	RECURSEP,	/* RECURSEP               */
	DEFINEP, 	/* DEFINEP                */
	OPFAIL,  	/* OPFAIL                 */
	NOTHING, 	/* OPTIMIZED              */
	PSEUDO,  	/* PSEUDO                 */
	/* ------------ States ------------- */
	TRIE,    	/* TRIE_next              */
	TRIE,    	/* TRIE_next_fail         */
	EVAL,    	/* EVAL_AB                */
	EVAL,    	/* EVAL_AB_fail           */
	CURLYX,  	/* CURLYX_end             */
	CURLYX,  	/* CURLYX_end_fail        */
	WHILEM,  	/* WHILEM_A_pre           */
	WHILEM,  	/* WHILEM_A_pre_fail      */
	WHILEM,  	/* WHILEM_A_min           */
	WHILEM,  	/* WHILEM_A_min_fail      */
	WHILEM,  	/* WHILEM_A_max           */
	WHILEM,  	/* WHILEM_A_max_fail      */
	WHILEM,  	/* WHILEM_B_min           */
	WHILEM,  	/* WHILEM_B_min_fail      */
	WHILEM,  	/* WHILEM_B_max           */
	WHILEM,  	/* WHILEM_B_max_fail      */
	BRANCH,  	/* BRANCH_next            */
	BRANCH,  	/* BRANCH_next_fail       */
	CURLYM,  	/* CURLYM_A               */
	CURLYM,  	/* CURLYM_A_fail          */
	CURLYM,  	/* CURLYM_B               */
	CURLYM,  	/* CURLYM_B_fail          */
	IFMATCH, 	/* IFMATCH_A              */
	IFMATCH, 	/* IFMATCH_A_fail         */
	CURLY,   	/* CURLY_B_min_known      */
	CURLY,   	/* CURLY_B_min_known_fail */
	CURLY,   	/* CURLY_B_min            */
	CURLY,   	/* CURLY_B_min_fail       */
	CURLY,   	/* CURLY_B_max            */
	CURLY,   	/* CURLY_B_max_fail       */
};
#endif

/* regarglen[] - How large is the argument part of the node (in regnodes) */

#ifdef REG_COMP_C
static const U8 regarglen[] = {
	0,                                   	/* END          */
	0,                                   	/* SUCCEED      */
	0,                                   	/* BOL          */
	0,                                   	/* MBOL         */
	0,                                   	/* SBOL         */
	0,                                   	/* EOS          */
	0,                                   	/* EOL          */
	0,                                   	/* MEOL         */
	0,                                   	/* SEOL         */
	0,                                   	/* BOUND        */
	0,                                   	/* BOUNDL       */
	0,                                   	/* NBOUND       */
	0,                                   	/* NBOUNDL      */
	0,                                   	/* GPOS         */
	0,                                   	/* REG_ANY      */
	0,                                   	/* SANY         */
	0,                                   	/* CANY         */
	0,                                   	/* ANYOF        */
	0,                                   	/* ALNUM        */
	0,                                   	/* ALNUML       */
	0,                                   	/* NALNUM       */
	0,                                   	/* NALNUML      */
	0,                                   	/* SPACE        */
	0,                                   	/* SPACEL       */
	0,                                   	/* NSPACE       */
	0,                                   	/* NSPACEL      */
	0,                                   	/* DIGIT        */
	0,                                   	/* DIGITL       */
	0,                                   	/* NDIGIT       */
	0,                                   	/* NDIGITL      */
	0,                                   	/* CLUMP        */
	0,                                   	/* BRANCH       */
	0,                                   	/* BACK         */
	0,                                   	/* EXACT        */
	0,                                   	/* EXACTF       */
	0,                                   	/* EXACTFL      */
	0,                                   	/* NOTHING      */
	0,                                   	/* TAIL         */
	0,                                   	/* STAR         */
	0,                                   	/* PLUS         */
	EXTRA_SIZE(struct regnode_2),        	/* CURLY        */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYN       */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYM       */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYX       */
	0,                                   	/* WHILEM       */
	EXTRA_SIZE(struct regnode_1),        	/* OPEN         */
	EXTRA_SIZE(struct regnode_1),        	/* CLOSE        */
	EXTRA_SIZE(struct regnode_1),        	/* REF          */
	EXTRA_SIZE(struct regnode_1),        	/* REFF         */
	EXTRA_SIZE(struct regnode_1),        	/* REFFL        */
	EXTRA_SIZE(struct regnode_1),        	/* IFMATCH      */
	EXTRA_SIZE(struct regnode_1),        	/* UNLESSM      */
	EXTRA_SIZE(struct regnode_1),        	/* SUSPEND      */
	EXTRA_SIZE(struct regnode_1),        	/* IFTHEN       */
	EXTRA_SIZE(struct regnode_1),        	/* GROUPP       */
	EXTRA_SIZE(struct regnode_1),        	/* LONGJMP      */
	EXTRA_SIZE(struct regnode_1),        	/* BRANCHJ      */
	EXTRA_SIZE(struct regnode_1),        	/* EVAL         */
	0,                                   	/* MINMOD       */
	0,                                   	/* LOGICAL      */
	EXTRA_SIZE(struct regnode_1),        	/* RENUM        */
	EXTRA_SIZE(struct regnode_1),        	/* TRIE         */
	EXTRA_SIZE(struct regnode_charclass),	/* TRIEC        */
	EXTRA_SIZE(struct regnode_1),        	/* AHOCORASICK  */
	EXTRA_SIZE(struct regnode_charclass),	/* AHOCORASICKC */
	EXTRA_SIZE(struct regnode_2L),       	/* RECURSE      */
	0,                                   	/* SRECURSE     */
	EXTRA_SIZE(struct regnode_1),        	/* NREF         */
	EXTRA_SIZE(struct regnode_1),        	/* NREFF        */
	EXTRA_SIZE(struct regnode_1),        	/* NREFFL       */
	EXTRA_SIZE(struct regnode_1),        	/* NGROUPP      */
	EXTRA_SIZE(struct regnode_1),        	/* RECURSEP     */
	EXTRA_SIZE(struct regnode_1),        	/* DEFINEP      */
	0,                                   	/* OPFAIL       */
	0,                                   	/* OPTIMIZED    */
	0,                                   	/* PSEUDO       */
};

/* reg_off_by_arg[] - Which argument holds the offset to the next node */

static const char reg_off_by_arg[] = {
	0,	/* END          */
	0,	/* SUCCEED      */
	0,	/* BOL          */
	0,	/* MBOL         */
	0,	/* SBOL         */
	0,	/* EOS          */
	0,	/* EOL          */
	0,	/* MEOL         */
	0,	/* SEOL         */
	0,	/* BOUND        */
	0,	/* BOUNDL       */
	0,	/* NBOUND       */
	0,	/* NBOUNDL      */
	0,	/* GPOS         */
	0,	/* REG_ANY      */
	0,	/* SANY         */
	0,	/* CANY         */
	0,	/* ANYOF        */
	0,	/* ALNUM        */
	0,	/* ALNUML       */
	0,	/* NALNUM       */
	0,	/* NALNUML      */
	0,	/* SPACE        */
	0,	/* SPACEL       */
	0,	/* NSPACE       */
	0,	/* NSPACEL      */
	0,	/* DIGIT        */
	0,	/* DIGITL       */
	0,	/* NDIGIT       */
	0,	/* NDIGITL      */
	0,	/* CLUMP        */
	0,	/* BRANCH       */
	0,	/* BACK         */
	0,	/* EXACT        */
	0,	/* EXACTF       */
	0,	/* EXACTFL      */
	0,	/* NOTHING      */
	0,	/* TAIL         */
	0,	/* STAR         */
	0,	/* PLUS         */
	0,	/* CURLY        */
	0,	/* CURLYN       */
	0,	/* CURLYM       */
	0,	/* CURLYX       */
	0,	/* WHILEM       */
	0,	/* OPEN         */
	0,	/* CLOSE        */
	0,	/* REF          */
	0,	/* REFF         */
	0,	/* REFFL        */
	2,	/* IFMATCH      */
	2,	/* UNLESSM      */
	1,	/* SUSPEND      */
	1,	/* IFTHEN       */
	0,	/* GROUPP       */
	1,	/* LONGJMP      */
	1,	/* BRANCHJ      */
	0,	/* EVAL         */
	0,	/* MINMOD       */
	0,	/* LOGICAL      */
	1,	/* RENUM        */
	0,	/* TRIE         */
	0,	/* TRIEC        */
	0,	/* AHOCORASICK  */
	0,	/* AHOCORASICKC */
	0,	/* RECURSE      */
	0,	/* SRECURSE     */
	0,	/* NREF         */
	0,	/* NREFF        */
	0,	/* NREFFL       */
	0,	/* NGROUPP      */
	0,	/* RECURSEP     */
	0,	/* DEFINEP      */
	0,	/* OPFAIL       */
	0,	/* OPTIMIZED    */
	0,	/* PSEUDO       */
};

/* reg_name[] - Opcode/state names in string form, for debugging */

#ifdef DEBUGGING
const char * reg_name[] = {
	"END",                   	/* 0000 */
	"SUCCEED",               	/* 0x01 */
	"BOL",                   	/* 0x02 */
	"MBOL",                  	/* 0x03 */
	"SBOL",                  	/* 0x04 */
	"EOS",                   	/* 0x05 */
	"EOL",                   	/* 0x06 */
	"MEOL",                  	/* 0x07 */
	"SEOL",                  	/* 0x08 */
	"BOUND",                 	/* 0x09 */
	"BOUNDL",                	/* 0x0a */
	"NBOUND",                	/* 0x0b */
	"NBOUNDL",               	/* 0x0c */
	"GPOS",                  	/* 0x0d */
	"REG_ANY",               	/* 0x0e */
	"SANY",                  	/* 0x0f */
	"CANY",                  	/* 0x10 */
	"ANYOF",                 	/* 0x11 */
	"ALNUM",                 	/* 0x12 */
	"ALNUML",                	/* 0x13 */
	"NALNUM",                	/* 0x14 */
	"NALNUML",               	/* 0x15 */
	"SPACE",                 	/* 0x16 */
	"SPACEL",                	/* 0x17 */
	"NSPACE",                	/* 0x18 */
	"NSPACEL",               	/* 0x19 */
	"DIGIT",                 	/* 0x1a */
	"DIGITL",                	/* 0x1b */
	"NDIGIT",                	/* 0x1c */
	"NDIGITL",               	/* 0x1d */
	"CLUMP",                 	/* 0x1e */
	"BRANCH",                	/* 0x1f */
	"BACK",                  	/* 0x20 */
	"EXACT",                 	/* 0x21 */
	"EXACTF",                	/* 0x22 */
	"EXACTFL",               	/* 0x23 */
	"NOTHING",               	/* 0x24 */
	"TAIL",                  	/* 0x25 */
	"STAR",                  	/* 0x26 */
	"PLUS",                  	/* 0x27 */
	"CURLY",                 	/* 0x28 */
	"CURLYN",                	/* 0x29 */
	"CURLYM",                	/* 0x2a */
	"CURLYX",                	/* 0x2b */
	"WHILEM",                	/* 0x2c */
	"OPEN",                  	/* 0x2d */
	"CLOSE",                 	/* 0x2e */
	"REF",                   	/* 0x2f */
	"REFF",                  	/* 0x30 */
	"REFFL",                 	/* 0x31 */
	"IFMATCH",               	/* 0x32 */
	"UNLESSM",               	/* 0x33 */
	"SUSPEND",               	/* 0x34 */
	"IFTHEN",                	/* 0x35 */
	"GROUPP",                	/* 0x36 */
	"LONGJMP",               	/* 0x37 */
	"BRANCHJ",               	/* 0x38 */
	"EVAL",                  	/* 0x39 */
	"MINMOD",                	/* 0x3a */
	"LOGICAL",               	/* 0x3b */
	"RENUM",                 	/* 0x3c */
	"TRIE",                  	/* 0x3d */
	"TRIEC",                 	/* 0x3e */
	"AHOCORASICK",           	/* 0x3f */
	"AHOCORASICKC",          	/* 0x40 */
	"RECURSE",               	/* 0x41 */
	"SRECURSE",              	/* 0x42 */
	"NREF",                  	/* 0x43 */
	"NREFF",                 	/* 0x44 */
	"NREFFL",                	/* 0x45 */
	"NGROUPP",               	/* 0x46 */
	"RECURSEP",              	/* 0x47 */
	"DEFINEP",               	/* 0x48 */
	"OPFAIL",                	/* 0x49 */
	"OPTIMIZED",             	/* 0x4a */
	"PSEUDO",                	/* 0x4b */
	/* ------------ States ------------- */
	"TRIE_next",             	/* 0x4c */
	"TRIE_next_fail",        	/* 0x4d */
	"EVAL_AB",               	/* 0x4e */
	"EVAL_AB_fail",          	/* 0x4f */
	"CURLYX_end",            	/* 0x50 */
	"CURLYX_end_fail",       	/* 0x51 */
	"WHILEM_A_pre",          	/* 0x52 */
	"WHILEM_A_pre_fail",     	/* 0x53 */
	"WHILEM_A_min",          	/* 0x54 */
	"WHILEM_A_min_fail",     	/* 0x55 */
	"WHILEM_A_max",          	/* 0x56 */
	"WHILEM_A_max_fail",     	/* 0x57 */
	"WHILEM_B_min",          	/* 0x58 */
	"WHILEM_B_min_fail",     	/* 0x59 */
	"WHILEM_B_max",          	/* 0x5a */
	"WHILEM_B_max_fail",     	/* 0x5b */
	"BRANCH_next",           	/* 0x5c */
	"BRANCH_next_fail",      	/* 0x5d */
	"CURLYM_A",              	/* 0x5e */
	"CURLYM_A_fail",         	/* 0x5f */
	"CURLYM_B",              	/* 0x60 */
	"CURLYM_B_fail",         	/* 0x61 */
	"IFMATCH_A",             	/* 0x62 */
	"IFMATCH_A_fail",        	/* 0x63 */
	"CURLY_B_min_known",     	/* 0x64 */
	"CURLY_B_min_known_fail",	/* 0x65 */
	"CURLY_B_min",           	/* 0x66 */
	"CURLY_B_min_fail",      	/* 0x67 */
	"CURLY_B_max",           	/* 0x68 */
	"CURLY_B_max_fail",      	/* 0x69 */
};
#endif /* DEBUGGING */
#else
#ifdef DEBUGGING
extern const char * reg_name[];
#endif
#endif /* REG_COMP_C */

/* ex: set ro: */
