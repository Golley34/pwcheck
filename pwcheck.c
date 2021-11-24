#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// Algoritmus pro určení délky řetězce.
int mystrlen(char *str){
    int i = 0;
 
    while (*str++ != '\n')
    i++;
    return i;
}

// Algoritmus mystrncpy je nutný k implementaci mysubstr. 
//Tyto dva algoritmy spolupracují, aby umožnily implementaci „4 level“ extrahovat podřetězce požadované délky.
char* mystrncpy( char* _dst, const char* _src, size_t _n )
{
   size_t i = 0;
   while(i++ != _n && (*_dst++ = *_src++));
}



char* mysubstr(char* s, size_t pos, size_t count)
{
   static char buf[BUFSIZ];
   buf[sizeof buf - 1] = '\0';
   if ( count >= BUFSIZ )
      return NULL;
   else
      return mystrncpy(buf, s + pos, count);
}

int mystrcmp(const char *s1, const char *s2) {
    unsigned char c1, c2;
    while ((c1 = *s1++) == (c2 = *s2++)) {
        if (c1 == '\0')
            return 0;
    }
    return c1 - c2;
}


void computeLPSarray(char *pat, int M, int *lps)
{
	int len = 0;	//lenght of previous longest prefix suffix
	int i ;
	
	lps[0] = 0 ;	//lps[0] is always 0
	i = 1;

	while(i <  M)	//loop calculates lps[i] for i = 1 to M-1
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else	//pat[i] != pat[len]
		{
			if(len != 0)
			{
				//this is tricky
				//consider the example AAACAAAA and i =7
				len = lps[len - 1];
				//we donot increment i here
			}
			else	//if len == 0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int KMPSearch(char *pat, char *txt)
{
	int M = mystrlen(pat);
	int N = mystrlen(txt);

	int *lps = (int*)malloc(M*sizeof(int));
	int j = 0;
    int sec = 0;

	computeLPSarray(pat, M, lps);
	
	int i = 0;
	while(i < N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if(j == M)
		{
			j = lps[j-1];
            sec++;
		}
		else if(pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
	free(lps);
    return sec;
}


int main(int argc, char* argv[]){
    char heslo[102];
    bool flag1 = true;
    bool flag2 = true;
    bool flag3 = true;
    bool flag4 = true;
    bool flag5 = true;
    bool flag6 = true;
    float AVG;
    int min = 100;
    int NCHARS = 0;
    int meter = 0;
    int totallenth = 0;
    if (argc < 3 || argc > 4){
        printf("Erorr 1\n");
        return 1;
    }

    if (atoi(argv[1]) >= 1 && atoi(argv[1]) <= 4){
        while (fgets(heslo, 102, stdin) != NULL){
            if (argc == 4 && !mystrcmp(argv[3], "--stats")){
                if (heslo != '\0'){
                    int len = mystrlen(heslo);
                    int lenth = mystrlen(heslo);
                    meter++;
                    totallenth += lenth;
                    if (len < min){
                    min = len;
                    }
                    // char* asc [127];
                    // int NCHARS = 0;
                    // for (int i = 0; heslo[i] != '\n'; i++){
                    //     char* hes = getchar(heslo[i]);
                    //     int a = KMPSearch(hes, asc);
                    //     if (a = 0){
                    //         asc[NCHARS] = hes;
                    //         NCHARS++;
                    //     }
                    // }
                }  
            }

            for (int i = 0; heslo[i] != '\n'; i++){ 
                if ('A' <= heslo[i] && heslo[i] <= 'Z'){
                    flag1 = true;
                    break;
                }
                else{
                    flag1 = false;
                }
            }
            for (int i = 0; heslo[i] != '\n'; i++){ 
                if ('a' <= heslo[i] && heslo[i] <= 'z'){
                    flag2 = true;
                    break;
                }
                else{
                    flag2 = false;
                }
            }
            if (atoi(argv[1]) == 1){
                if (flag1 && flag2 == true){
                    printf ("%s", heslo);
                }
            }

            if (atoi(argv[1]) >= 2 && atoi(argv[1]) <= 4){
                if (atoi(argv[1]) == 2 && atoi(argv[2]) == 1){
                    if (flag1 && flag2 == true){
                        printf ("%s", heslo);
                    }
                }
                if (atoi(argv[1]) == 2 && atoi(argv[2]) == 2){
                    if (flag1 && flag2 == true){
                        printf ("%s", heslo);
                    }
                }
                if (atoi(argv[2]) >= 3){
                    for (int i = 0; heslo[i] != '\n'; i++){ 
                        if (heslo[i] >= '0' && heslo[i] <= '9'){
                        flag3 = true;
                        break;
                        }
                        else{
                            flag3 = false;
                        }
                    }
                    if (atoi(argv[1]) == 2 && atoi(argv[2]) == 3){
                        if (flag1 && flag2 && flag3 == true){
                        printf ("%s", heslo);
                        }
                    }
                
                    if (atoi(argv[2]) >= 4){
                        for (int i = 0; heslo[i] != '\n'; i++){ 
                            if ((heslo[i] >= '!' && heslo[i] <= '/') || 
                                (heslo[i] >= ':' && heslo[i] <= '@') ||
                                (heslo[i] >= '[' && heslo[i] <= '`') ||
                                (heslo[i] >= '{' && heslo[i] <= '~') || heslo[i] == ' '){
                            flag4 = true;
                            break;
                            }
                            else{
                                flag4 = false;
                            }
                        }
                        if (atoi(argv[1]) == 2 && atoi(argv[2]) >= 4){
                            if (flag1 && flag2 && flag3 && flag4 == true){
                            printf ("%s", heslo);
                            }
                        }
                    }
                }
                
                if (atoi(argv[1]) >= 3 && atoi(argv[1]) <= 4){
                int buffer = 1;
                    for (int i = 1; heslo[i] != '\n'; i++){
                        if (heslo[i] == heslo[i - 1]){
                            buffer++;
                            if (buffer == atoi(argv[2])){
                                break;
                            }
                        }
                        else{
                            buffer = 1;
                        }
                    }
                    if (atoi(argv[2]) > buffer){
                        flag5 = true;
                    }
                    else{
                        flag5 = false;
                    }
                    if (atoi(argv[1]) == 3 && atoi(argv[2]) >= 1 ){
                        if (flag1 && flag2 && flag3 && flag4 && flag5  == true){
                            printf ("%s", heslo);
                        }
                    }
                
                    if (atoi(argv[1]) >= 4){
                        int a;
                        for (int i = 0; i < ((mystrlen(heslo)) - (atoi(argv[2]))); i++){
	                        char *txt = heslo;
	                        char *pat = mysubstr(heslo, i, atoi(argv[2]));
                            int a = KMPSearch(pat, txt);
                            if (a > 1){
                                flag6 = false;
                                break;
                            }
                            else{
                                flag6 = true;
                            }
                        }
                        if (atoi(argv[1]) >= 4 && atoi(argv[2]) >= 1 ){
                            if (flag1 && flag2 && flag3 && flag4 && flag5 && flag6 == true){
                                printf ("%s", heslo);
                            }
                        }
                    } 
                }
            }
        }
    }    
    else {
        printf("Erorr: wrong data\n");
        return 6;
    }
    if (argc == 4 && !mystrcmp(argv[3], "--stats")){
        AVG = (float)totallenth / meter;
        printf ("\n\nStatistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f\n", NCHARS, min, AVG);
    }
}

