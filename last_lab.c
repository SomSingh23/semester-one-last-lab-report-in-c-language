#include <stdio.h>
#include <stdlib.h>


struct product{
    char name[20];
    float price;
    int quantity;       
};

int main(int argc, char *argv[]) {
    
    printf("------------------------Please enter the required details of your products----------------------.");
    int i;
    struct product p[10];
    
    for(i = 0; i < 10; ++i){
        printf("\nEnter the details of product %d",i+1);
        printf("\nName: ");
        scanf("%s",p[i].name);
        printf("\nPrice: ");
        scanf("%f",&p[i].price);
        printf("\nQuantity: ");
        scanf("%d",&p[i].quantity);     
    }
//STORING DATA IN A FILE.   
    FILE *fptr = NULL;
    fptr = fopen("storing_data.txt","w"); 
    
//printf("---------- Storing Data with respect to PRICE in ascending order ----------\n\n");
// sorting data wrt to price in ascending order !!
int swap ; int lol , lol2 ;
for(int i = 0 ; i<10  ; i++){
  swap = 0 ; // become 1 when swaping happen
  for(int j = i ; j<10 ; j++){
    if(p[j].price<=p[i].price){
struct product new = p[j] ;
p[j] = p[i] ;
p[i] = new ;
swap = 1 ;
    }
  }
  if(swap==0) {break;}
} fprintf(fptr , "---------- Storing Data with respect to PRICE in ascending order ----------\n\n");
    for(i = 0; i < 10; ++i){
     
        fprintf(fptr,"The details of product %d are:\n",i+1);
        fprintf(fptr,"Name -> %s\n",p[i].name);
        fprintf(fptr,"Price -> %.2f\n",p[i].price);
        fprintf(fptr,"Quantity -> %d\n\n",p[i].quantity);
        
    }
    fclose(fptr);
    
//READING DATA FROM FILE;
    printf("\n\n\n------------------------------This is the dispaly by reading the file------------------------------\n\n\n.");
    
    fptr = fopen("storing_data.txt","r");     
    char ch;
    ch = fgetc(fptr);
    while(ch != EOF){
        printf("%c",ch) ;
        ch = fgetc(fptr);       
    }
    fclose(fptr);
    //DISPLAY 
    
    
    
    
    return 0;
}