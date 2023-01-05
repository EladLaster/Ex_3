#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 30
#define MAX_LINE_SIZE 256
#define NUM_OF_LINES 250

int getLine(char s[]){
    
    int counter=0;
    for(int i=0;i<MAX_LINE_SIZE;i++){
        scanf("%c",&s[i]);
        counter++;
        if(s[i]=='\n') {
            s[i]='\0';
            break;
        }
        }
        return counter;
    }


int getWord(char w[]){

    int counter=0;
    for(int i=0;i<MAX_WORD_SIZE;i++){
        scanf("%c",&w[i]);
        counter++;
        if(w[i]==' '||w[i]=='\t'||w[i]=='\n') {
            w[i]='\0';
            break;
        }
        }
        return counter;
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
    int i=0;
    int line_size=1;
    char text[MAX_LINE_SIZE]={0};
    while(line_size!=0 && i<MAX_LINE_SIZE){
        line_size=getLine(text);
        if(substring(text,str)==1){
            printf("%s\n",text);
        }
        i++;
    }
}


void print_similar_words(char * str){

    int i=0;
    int ward_size=1;
    char text[MAX_WORD_SIZE]={0};
    while(ward_size!=0 && i<MAX_WORD_SIZE){
        ward_size=getWord(text);
        if(similar(text,str,1)==1||similar(text,str,0)){
            printf("%s\n",text);
        }
        i++;
    }
}

int main(){
    char ward[MAX_WORD_SIZE];
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

