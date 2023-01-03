#include <stdio.h> 
#define length 50

void shift_element(int* arr, int i){

    for(int *p=arr+i+1;p>arr;p--){
        *p=*(p-1);  
    }
    *(arr+1)=0;  //need to zero the first place we moved???
}


void insertion_sort(int* arr , int len){
        for(int *i=arr+1;i<arr+len;i++){
            int curr= *i;
            int *j=i-1;
            int counter=0;
            while (j>=arr&&*j>curr){
                *(j+1)=*j;
                j--;
            }
            *(j+1)=curr;
        }
}

int main(){
    
    int arr[length];
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,length);


    for (int i = 0; i < length-1; i++)    {
        printf("%d,",arr[i]);
        
    }
    printf("%d\n",arr[length-1]);

    return 0;
    }

