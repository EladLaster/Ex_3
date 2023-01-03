#include <stdio.h>
#include <string.h>

#define NUM_OF_LINES 250
#define LINE_SIZE 256
#define WORD_SIZE 30

int getLine(char s[]){
    scanf("%c",&s[0]);
    int counter=0;
    while(counter<LINE_SIZE && s[counter] != '\n'){
        counter++;
        if(scanf("%c",&s[counter])==EOF) 
        return 0;
        }
        s[counter]='\0';
        return (counter+1);
    }


int getWord(char w[]){
    scanf("%c",&w[0]);
    int counter=0;
    while(counter<WORD_SIZE && w[counter] != '\n' && w[counter] != '\t' && w[counter] != ' '){
        counter++;
        if(scanf("%c",&w[counter])==EOF) 
        return 0;
        }
        w[counter]='\0';
        return (counter+1);
    }


int substring( char * str1, char * str2){

    int len1=strlen(str1);
    int len2=strlen(str2); 
    if(len2>len1){
        return 0;
    }
    int i=0;
    int j=0;
   
    while(i<len1 && j<len2){
        if(str1[i]==str2[j]){
            i++;
            j++;
            // printf("i is %d . j is %d\n",i,j);
        }
        else {
            i++;
            j=0;
            // printf("i is %d . j is %d\n",i,j);
        }
    }
    if(j==len2){
        return 1;
    }
    else{
        return 0;
    }

}


int similar (char *s, char *t, int n){

    int len1=strlen(s);
    int len2=strlen(t); 
    if(len2>len1){
        return 0;
    }
    if(n==0){
        if(strcmp(s,t)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int i=0;
    int j=0;
    int counter=0;
    while(i<len1 || j<len2){
        if(s[i]==t[j]){
            i++;
            j++;
            // printf("i is %d . j is %d\n",i,j);
        }
        else if(i<len1){
            i++;
            counter++;
            // printf("i is %d . counter is %d\n",i,counter);
        }
        else if(j<len2){
            return 0;
        }
        else{
            i++;
            counter++;
            // printf("i is %d . j is %d . count is %d\n",i,j,counter);
        }
    }
    if(counter!=n){
        return 0;
    }
    else{
        return 1;
    }
}


void print_lines(char * str){

char l[LINE_SIZE]={0};
int size;

    for (int i = 0; i < NUM_OF_LINES; i++){
        size=getLine(l);
        if(size==0)
        break;

        if(substring(l,str)==1)
             printf("%s\n", l);
}

}


void print_similar_words(char * str){

char c[WORD_SIZE]={0};
    int size;
    for (int i = 0; i < NUM_OF_LINES; i++){
        size=getWord(c);
        if(size==0)
        break;

        if(similar(c,str,1)==1 || strcmp(c,str)==0)
                printf("%s\n", c);
    }
}

int main(){
    char ward[WORD_SIZE];
    char options;
    getWord(ward);
    scanf("%c\n", &options);
    switch (options)
    {
    case 'a':
        print_lines(ward);
        break;
    
    case 'b':
        print_similar_words(ward);
        break;
    }
    return 0;
}
