#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <ctype.h>


#define THE_LENGHT 1000
#define THE_LENG_OF 20

//declaration dyal c functions
void file_checker(FILE *pFile);
int user_already_ex(const char *usernams);
int user_login(const char *user , const char *passw);
int history(const char *key , char *user);


int main(){

    char user[THE_LENG_OF]; // for the users to insert thier usernames
    char passw[THE_LENG_OF];// for codes
    int checker = 0; //to see if a code is seccsefuly completed   0 = true 1 = flase
    char choice , operators , s_for_stats , key;// choice = yes or no // operators = switches
    double deposit, withdraw, transfer;


printf(" *****************************\n");
puts("******      BANKIE      *******");
printf(" *****************************\n");
Sleep(1000*4);
printf("\n********WELOME TO BABKIE************\n");
Sleep(500);
printf("\n");
puts("---THE WORST BANK IN THE PROGRAMING LAND---");
Sleep(1000*2);
printf("\nDO YOU HAVE ALREADY AN ACCOUNT BY US? IF YES PRESS Y IF NO PRESS N!\n");
scanf(" %c" , &choice);
choice = toupper(choice);
if(choice == 'N'){
    printf("\nfirst you need to enter your username!\npss no spacses\n");

    while (1)
    {
    memset(user, 0, THE_LENG_OF);
    scanf("%s" , user);
        if(checker = user_already_ex(user)!= 0)//the code is true !
         {
            puts("this username already existed");
            puts("please try again");
            continue;
         }
         else
         break;
}


printf("now we need you to enter a password for you account!\npss no scpaces\n");
scanf("%s" , passw);
FILE *pFile = fopen("secret_data.txt" , "a");
file_checker(pFile);
fprintf(pFile , "\n%s %s" , user , passw);
fclose(pFile);
checker = 0;
puts("------- BANKIE WELCOMES YOU!----------");
Sleep(1000*2);
system("cls");
}




else if(choice == 'Y'){
    puts("WE'ER GLAD TO HERE THAT YOU ARE ALREADY A CLEINT FOR BANKIE");
    while (1)
    {

    memset(user, 0, THE_LENG_OF);
    memset(passw, 0, THE_LENG_OF);

    puts("enter here your username!");
    scanf("%s" , user);
    puts("and here your password!");
    scanf("%s" , passw);

    if (user == "no")
    {
    exit(0);}

    else if(checker = user_login(user , passw) != 0)
    {
        printf("WELCOME AGAIN MR/MS : %s\n" , user);
        break;
    }
    else if(checker == 0)
    {
        printf("THER IS NO SUCH USERNAME AS \"%s\"\n" , user);
        Sleep(1000*2);
        printf("\nif you don't have an account click on \"Control+C\"\n");
        continue;
    }
    else
    printf("\nerror\n");

  }   

 }
 else{
 puts("you need to choose btween y/n");
 exit(0);}
 Sleep(1000*2);
system("cls");
strcat(user , "_bankie.txt");
FILE *pFile_clients = fopen(user, "a");
file_checker(pFile_clients);// i check files with it
fclose(pFile_clients);
 puts("HERE YOU CAN CHOOSE ONE OF OUR SERVICES");

do{
 puts("D = DEPOSIT / W = WITHDRAW / T = TRANSFER MONEY / S = SEE YOUR ACCOUNT STATS");
operators = '\0'; // to clear it i don't know if it realy works hhh


scanf(" %c" , &operators);
operators = tolower(operators);
switch(operators){
default :
puts("SORRY, INVALID OPERATOR");
break;
case 'd' : 
puts("--------YOU ARE IN THE DEPOSIT SECTION-------");
puts("how much do you wanna deposit?");

FILE *pFile_clients = fopen (user , "a");
file_checker(pFile_clients);
scanf("%lf" , &deposit);
if(deposit <= 0 )
{
    printf("\nSORRY BUT YOU CAN'T DEPOSIT A NEGATIVE NUMBER!\n");
}
else{
fprintf(pFile_clients , "$%lf\n" , deposit);}

fclose(pFile_clients);
break;
case 'w' :
puts("--------YOU ARE IN THE WITHDRAW SECTION-------");
puts("the withdraw service is still under maintenance but it's working a little/sorry i'm lazy");
puts("how much do you wanna withdraw?");
FILE *pFile_clients2 = fopen (user , "a");
file_checker(pFile_clients2);
scanf("%lf" , &withdraw);
fprintf(pFile_clients2 , "-%lf\n" , withdraw);
fclose(pFile_clients2);
break;
case 't' :
puts("--------YOU ARE IN THE TRANSFER SECTION-------");
puts("the transfer service is still under maintenance but it's working. a little/sorry i'm lazy");
puts("how much do you wanna TRANSFER?");
FILE *pFile_clients3 = fopen (user , "a");
file_checker(pFile_clients3);
scanf("%lf" , &transfer);
fprintf(pFile_clients3 , ">%lf\n" , transfer);
fclose(pFile_clients3);
break;
case 's' :
puts("CHOOSE ONE OF THE FOLLOWING OPERATORS!");
puts("D = DEPOSIT HISTORY / W = WITHDRAW HISTORY / T = TRANSFER HISTORY");
scanf(" %c" , &s_for_stats);
s_for_stats = toupper(s_for_stats);
switch(s_for_stats)
{
    default :
    perror("ERROR IN SWITCH HISTORY");
    case 'D' :
    puts("YOUR DEPOSIT HISTORY");
    key = '$';
    if(checker == history(&key , user) == 0)
    {}
    else
    // perror("\nERROR IN DEPOSIT HISTORY!\n");
    checker == 0;
    key = '\0';
    break;
    case 'W' :
    puts("YOUR WITHDRAW HISTORY");
    key = '-';
    if(checker == history(&key , user) == 0)
    {}
    else
    // perror("\nERROR IN WITHDRAW HISTORY!\n");
        checker == 0;
            key = '\0';
    break;
        case 'T' :
    puts("YOUR MONEY TRANSFERRING HISTORY");
    key = '>';
    if(checker == history(&key , user) == 0)
    {}
    else
    // perror("\nERROR IN MONEY TRANSFER HISTORY!\n");
        checker == 0;
            key = '\0';
    break;
}
}
s_for_stats = '\0';
choice = '\0';// same shit
printf("\ndo you wanna choose another service? Y/N\n");
scanf(" %c" , &choice); // space bin " o %c bach t7yd ay left overs !
choice = toupper(choice);
system("cls");
}while(choice == 'Y');
puts("-----THANK YOU FOR CHOOSING OUR SERVICES-----");
 system("pause");
 return 0;
}

/*
HNA C FUNCTIONS******************************
*/
    int history(const char *key , char *user)
{

char scanner[1000];

    FILE *pFile_clients = fopen (user, "r");
    if(pFile_clients == NULL)
    {
        perror("NO FILE FOUND!");
        exit(0);
    }
while(fgets(scanner , 1000, pFile_clients))
{
    size_t ind = strcspn(scanner , key);
    if (scanner[ind] != *key)
    {
continue;
    // if(scanner[EOF])
    // {return 0;}
    }else
    printf("%s" , scanner);
}
return 1;
}
    void file_checker(FILE *pFile)
    {
        if(pFile == NULL)
        {
        perror("SORRY");
        exit(0);
        }
    }

    int user_already_ex(const char *user)
    {
    char scanner[THE_LENGHT];

    FILE *pFile = fopen("secret_data.txt" , "r");

    if (pFile == NULL)//checking the file!!
    {
    perror("\nSORRY THE FILE CANNOT BE OPEN!!!");
    exit(0);
    }


    while (fgets(scanner, THE_LENGHT, pFile))
    {
    /* "ind" means nothing, but i used it to see 
    where the \n is so i can reolace it with '\0'*/
    size_t ind = strcspn(scanner, "\n");
    size_t ind2 = strcspn(scanner, " ");
    if (scanner[ind] == '\n' || scanner[ind2] == ' ')
        {
        scanner[ind] = '\0';
        scanner[ind2] = '\0';
        }


    if (strcmp(scanner, user) == 0)
    {  fclose(pFile);
        return 1; // you see, im using the return statment to return two values 1 and 0 
                 // basically what i wrote is int checker = 1 *look down*
                 }
    
    }
  fclose(pFile);
    return 0; // int checker = 0 
}


    int user_login(const char *user , const char *passw)
 {
        char users[THE_LENG_OF] , codes[THE_LENG_OF]; 
        char scanner [THE_LENGHT];
        FILE *pFile = fopen ("secret_data.txt" , "r");
        if (pFile == NULL)// to check if the file oppening is working fine!
        {
        perror("SORRY THE FILE CANNOT BE OPEN!!!");
        exit(0);
        }
 
 
        while (fgets(scanner, THE_LENGHT, pFile))//3gzt nchr7 hhh 
    {

        //i already explaind ind in the first c function!!!
        size_t ind = strcspn(scanner , "\n");

        if(scanner[ind] == '\n')
        {
        scanner[ind] = '\0';
        }

        sscanf(scanner, "%s %s" , users, codes);
        if (strcmp(users, user) == 0 && strcmp(codes, passw) ==0 )
        return 1;
        

    }
    fclose(pFile);
    return 0;
}