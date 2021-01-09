#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void Convert(int type,void* param);
void Number(void* param);
void String(void* param);

void Convert(int type,void* param){
    switch(type){
    case 0:
        Number(param);
        break;
    case 1:
        String(param);
        break;
    default:
        break;
    }
}

void Number(void* param){
    int num;
    // num = int*(param);        //mark
    num = *((int*)param);
    printf("Number:%d\n",*((int*)param));

}

void String(void* param){
    char* str;
    str = (char*)param;
    printf("String:%s\n",str);
}



int main(int argc, char* argv[]){
    Convert(0,(void*)(int*)(2));
    Convert(1,(void*)"hello");
    return 0;
}

