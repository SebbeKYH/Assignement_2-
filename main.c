#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

typedef struct currency_table
    {
    char *country;
    int value;
    }CT;
    CT currency_arr[ARRAY_SIZE];

void read_file(char *in_file){
    int i=0;


    FILE *file_pointer;
    file_pointer = fopen(in_file,"r");


    // Removing *c%d will give us correct spacing but not value...
    while(fscanf(file_pointer, "%s,*c%d", &currency_arr[i].country, &currency_arr[i].value)!=EOF){
    i++;
    }
    fclose(file_pointer);
}

int main()
{
    char* in_file = "currency.txt";
    read_file(in_file);
    int i = 0;


    //size_t array_elements = SIZEOF(CT);

    for(i; i< ARRAY_SIZE; i++){
        printf("%s\t%d\n", &currency_arr[i].country, currency_arr[i].value);

    }
    return 0;
}


