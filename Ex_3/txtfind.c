#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define MAXLINES 250

int getLine(char s[]){
    int i=0;
    scanf("%c",&s[i]);
    while(i<LINE && s[i] != '\n'){
        i++;
        if(scanf("%c",&s[i])==EOF) 
        return 0;
        }
        s[i]='\0';
        return (i+1);
    }


int getWord(char w[]){
    int i=0;
    scanf("%c",&w[i]);
    while(i<WORD && w[i] != '\n' && w[i] != '\t' && w[i] != ' '){
        i++;
        if(scanf("%c",&w[i])==EOF) 
        return 0;
        }
        w[i]='\0';
        return (i+1);
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

char line[LINE]={0};
    int size;

    for (int i = 0; i < MAXLINES; i++){
        size=getLine(line);

        if(size==0)
        break;

        if(substring(line,str)==1)
             printf("%s\n", line);
}

}


void print_similar_words(char * str){

char check[WORD]={0};
    int size;
    for (int i = 0; i < MAXLINES; i++){
        size=getWord(check);

        if(size==0)
        break;

        if(similar(check,str,1)==1 ||strcmp(check,str)==0)
                printf("%s\n", check);

        
    }
}

int main(){
    char word[WORD]={0};
    getWord(word);
    char function[WORD]={0};
    getWord(function);

    if(function[0]=='a')
    print_lines(word);

    if(function[0]=='b')
    print_similar_words(word);

    return 0;
}

