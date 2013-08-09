#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DICT "words.txt"
#define EDICT "/crp/dict/web2"
#define MAXERR 7
#define MINSCORE 0
#define MINLEN 7

char *dictfile;
int alive, lost;
FILE *dict;
long int dictlen;
float errors = 0, words = 0;

void setup();
double frand(void);
void startnew();
void stateout();
void getguess();
void wordout();
void youwon();
void fatal(char *s);
void getword();
void pscore();

int main(int argc, char **argv)
{
        if (argc == 1)
                dictfile = DICT;
        else if (*argv[1] == '-')
                dictfile = EDICT;
        else
                ditcfile = argv[1];

        setup();
        for(;;)
        {
                startnew();
                while (alive > 0)
                {
                        stateout();
                        getguess();
                }
                words = words + 1;
                if (lost)
                        wordout();
                else
                        youwon();
                
        }
}  

void setup()
{
        int tvec[2];
        struct stat statb;
        time(tvec);
        srand(tvec[1] + tvec[2]);
        if ((dict = fopen(dictfile, "r")) == NULL)
                fatal("no dictionary");
        if (stat(dictfile, &statb) < 0)
                fatal("can't stat");
                
        dictlen = statb.st_size;
        
}

double frand(void)
{
        return (rand()/32768.);

}

char word[26], laph[26], realword[26];

void startnew()
{
        
        
}
