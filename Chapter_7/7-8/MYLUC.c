#INCLUDE <STDIO.H>
#INCLUDE <CTYPE.H>     /* FOR TOUPPER() & TOLOWER() */
#INCLUDE <STDLIB.H>    /* FOR EXIT */
#INCLUDE <UNISTD.H>    /* FOR GETOPT */
#INCLUDE <STRING.H>    /* FOR MEMSET */
#DEFINE  OPTSTRING   "UL"
#DEFINE  MAXSIZE     100

/* CONVERT CONTENT OF FILE ALL TO UPPER OR LOWER */
VOID FILECONVERSION(FILE *IFP, FILE *OFP, INT U2L, INT L2U);

INT MAIN(INT ARGC, CHAR *ARGV[])
{
    INT C;
    INT U2L, L2U;
    FILE *FP;

    U2L = L2U = 0;

    /* COMMAND OPTION PROCESS */
    WHILE ((C = GETOPT(ARGC, ARGV, OPTSTRING)) != -1) {
        SWITCH (C) {
            CASE 'U':
                L2U = 1;
                BREAK;

            CASE 'L':
                U2L = 1;
                BREAK;

            DEFAULT:
                FPRINTF(STDERR, "USAGE: %S [-U] [-L] [FILES] ...\N", ARGV[0]);
                EXIT(EXIT_FAILURE);
        }
        ARGC--;
    }

     
    IF (ARGC == 1)    /* READ FROM STDIN */
        FILECONVERSION(STDIN, STDOUT, U2L, L2U);
    ELSE
        WHILE (--ARGC > 0)  /* READ FROM FILES */
            IF ((FP = FOPEN(ARGV[OPTIND], "R")) == NULL) {
                FPRINTF(STDERR, "%S CAN'T OPEN %S\N", ARGV[0], ARGV[OPTIND]);
                EXIT(EXIT_FAILURE);
            }
            ELSE {
                FILECONVERSION(FP, STDOUT, U2L, L2U);
                FCLOSE(FP);
                OPTIND++;
            }

    
    EXIT(EXIT_SUCCESS);
}

/* FILECONVERSION:  CONVERT FILE IFP TO FILE OFP, DIRECTION IS UP TO FLAG
 * 'U2L' AND 'L2U' */
VOID FILECONVERSION(FILE *IFP, FILE *OFP, INT U2L, INT L2U)
{
    INT I;
    CHAR SBUF[MAXSIZE] = "";
    CHAR DBUF[MAXSIZE] = "";

    WHILE (FGETS(SBUF, MAXSIZE, IFP) != NULL) {
        MEMSET(DBUF, 0, MAXSIZE);
        FOR (I = 0; *(SBUF+I) != '\0'; ++I)
            IF (U2L == 1)
                *(DBUF+I) = TOLOWER(*(SBUF+I));
            ELSE IF (L2U == 1)
                *(DBUF+I) = TOUPPER(*(SBUF+I));
        FPUTS(DBUF, OFP);
    }
}
