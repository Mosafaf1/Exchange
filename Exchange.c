#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <colors.h>
// #include <mysql/mysql.h>
#define namesize 10
int shop(int dollar, int erue, int toman);
void warning();
void member();
int menu(int dollar, int erue, int toman);
void admin();
int Dollar(int dollar, int erue, int toman);
int Erue(int dollar, int erue, int toman);
int Toman(int dollar, int erue, int toman);
void delay(int number_of_seconds);
int error(int error_number);
char licnes[100][100];
int c = 0;
bool register_check;
// char welcome[35] = {'h', 'e', 'l', 'l', 'o', 'a', 'n', 'd', 'w', 'e', 'l', 'c', 'o', 'm', 'e', 't', 'o', 't', 'h', 'e', 'e', 'x', 'c', 'h', 'a', 'n', 'g', 'e', '\0'};
// user = fopen("username.txt", "r");
int main(char username, int password)
{
    printf(BBLU "hello and welcome to the exchange\n\n");
    fflush(stdout);
    printf(__DATE__);
    printf("\n" reset);
    fflush(stdout);
    for (;;)
    {
        menu(0, 0, 500);
    }
    return 0;
}
int menu(int dollar, int erue, int toman)
{
    // bool register_check;
    char username[namesize];
    int pass;
    int verify;
    int verify_pass;
    char verify_username[namesize];
    int select;
    int i = 0;
    printf(BYEL "\n(1)shop\n");
    printf("(2)register\n");
    printf("(3)about\n");
    printf("(4)exit\n" reset);
    fflush(stdout);
    scanf("%2d", &select);
    getchar();
    if (select == 4)
    {
        printf(CYN "good bye\n" reset);
        fflush(stdout);
        // remove("username.txt");
        exit(0);
    }
    else if (select == 2)
    {
        if (register_check == true)
        {
            printf(REDB "you was registered" reset);
            printf("\n");
            return 0;
        }
        printf(MAG "creat an acount\n");
        printf("enter your username : ");
        fflush(stdout);
        fgets(username, namesize, stdin);
        if (strlen(username) < 4)
        {
            error(406);
            return menu(dollar, erue, toman);
        }
        printf("\nyour username is = %s\n", username);
        printf("Enter your password : ");
        fflush(stdout);
        scanf("%8d", &pass);
        if (pass < 9999999)
        {
            error(501);
            return 0;
        }
        printf("\nconfirm your password : ");
        fflush(stdout);
        scanf("%8d", &verify);
        printf("\n" reset);
        fflush(stdout);
        if (verify != pass)
        {
            error(400);
        }
        else if (verify == pass)
        {
            register_check = true;
        }
        printf(GRN "register success\n" reset);
        // printf("%d", register_check);
        fflush(stdout);
    }
    else if (select == 1 && register_check == true)
    {
        shop(dollar, erue, toman);
    }
    else if (select == 1 && register_check != true)
    {
        error(401);
        return 0;
    }
    else if (select == 3)
    {
        FILE *readme;
        readme = fopen("readme.md", "r");
        while (feof(readme) == 0)
        {
            fgets(licnes[i], 256, readme);
            printf(CYN "%s" reset, licnes[i]);
            i++;
        }
    }
    else
    {
        exit(0);
    }
}
int shop(int dollar, int erue, int toman)
{
    int option;
    // system("clear");
    printf(BYEL "            ***______welcome to shop______***\n\n" reset);
    printf(GRN "your dollar is %d\n", dollar);
    printf("your erue is %d\n", erue);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "(1)Conversions dollar\n");
    printf("(2)Conversions euro\n");
    printf("(3)Conversions toman\n");
    printf("(4)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option);
    if (option == 4)
    {
        return menu(dollar, erue, toman);
    }
    else if (option == 1)
    {
        Dollar(dollar, erue, toman);
    }
    else if (option == 3)
    {
        Toman(dollar, erue, toman);
    }
    else if (option == 2)
    {
        Erue(dollar, erue, toman);
    }
    else
    {
        return menu(dollar, erue, toman);
    }
    return shop(dollar, erue, toman);
}
int Toman(int dollar, int erue, int toman)
{
    int option3;
    int dollar_value;
    int erue_value;
    int dollar_point = 50;
    int erue_point = 60;
    int check_t_1 = toman / dollar_point;
    int check_t_2 = toman / erue_point;
    system("clear");
    // delay(2000);
    if (toman <= 0)
    {
        error(403);
        return shop(dollar, erue, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your erue is %d\n", erue);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<the conversions for toman >>>>>>> :\n");
    fflush(stdout);
    // printf(__DATE__);
    printf("(1)toman to dollar\n");
    printf("(2)tomn to erue\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option3);
    if (option3 == 3)
    {
        return shop(dollar, erue, toman);
    }
    else if (option3 == 1)
    {
        printf(CYN "ok once dollar is %d toman\n", dollar_point);
        printf("enter your dollar to want : " reset);
        fflush(stdout);
        scanf("%3d", &dollar_value);
        if (dollar_value <= 0 | dollar_value > 500)
        {
            error(404);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        else if (toman < 0)
        {
            error(405);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        else if (dollar_value > check_t_1)
        {
            error(500);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        dollar = dollar + dollar_value;
        dollar_value = dollar_value * dollar_point;
        toman = toman - dollar_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);

        // printf(GRN "your dollar is %d\n", dollar);
        // printf("your erue is %d\n", erue);
        // printf("your tomsn is %d\n" reset, toman);
    }
    else if (option3 == 2)
    {
        printf(CYN "ok once erue is %d toman\n", erue_point);
        printf("enter your erue to want : " reset);
        fflush(stdout);
        scanf("%3d", &erue_value);
        if (erue_value <= 0 | erue_value > 500)
        {
            error(404);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        else if (toman < 0)
        {
            error(405);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        else if (erue_value > check_t_2)
        {
            error(500);
            delay(2000);
            return Toman(dollar, erue, toman);
        }
        erue = erue + erue_value;
        erue_value = erue_value * erue_point;
        toman = toman - erue_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);
        // printf(GRN "your dollar is %d\n", dollar);
        // printf("your erue is %d\n", erue);
        // printf("your tomsn is %d\n" reset, toman);
    }
    else
    {
        exit(0);
    }
    return Toman(dollar, erue, toman);
}
int Dollar(int dollar, int erue, int toman)
{
    int option2;
    int toman_value;
    int erue_value;
    int toman_point = 50;
    float erue_point = 1.079;
    int check_d_1 = toman_point * dollar;
    int check_d_2 = erue_point * dollar;
    system("clear");
    // delay(2000);
    if (dollar <= 0)
    {
        error(402);
        return shop(dollar, erue, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your erue is %d\n", erue);
    printf("your toman is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<the conversions for dollar>>>>>>> :\n");
    fflush(stdout);
    printf("(1)dollar to euro\n");
    printf("(2)dollar to toman\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option2);
    if (option2 == 3)
    {
        return shop(dollar, erue, toman);
    }
    else if (option2 == 1)
    {
        printf(CYN "ok %d dollar is once erue\n", erue_point);
        printf("enter your erue to want : " reset);
        fflush(stdout);
        scanf("%3d", &erue_value);
        if (erue_value <= 0 | erue_value > 500)
        {
            error(404);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        else if (dollar < 0)
        {
            error(407);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        else if (erue_value > check_d_2)
        {
            error(500);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        erue = erue + erue_value;
        erue_value = erue_value * erue_point;
        dollar = dollar - erue_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else if (option2 == 2)
    {
        printf(CYN "ok %d is once dollar\n", toman_point);
        printf("enter your toman to want : " reset);
        fflush(stdout);
        scanf("%3d", &toman_value);
        if (toman_value <= 0 | toman_value > 500 | toman_value < toman_point)
        {
            error(404);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        else if (dollar < 0)
        {
            error(407);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        else if (toman_value > check_d_1)
        {
            error(500);
            delay(2000);
            return Dollar(dollar, erue, toman);
        }
        toman = toman + toman_value;
        toman_value = toman_value / toman_point;
        dollar = dollar - toman_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else
    {
        exit(0);
    }
    return Dollar(dollar, erue, toman);
}
int Erue(int dollar, int erue, int toman)
{
    int option4;
    int toman_value;
    int dollar_value;
    int toman_point = 60;
    float dollar_point = 1.9;
    int check_e_1 = toman_point * erue;
    int check_e_2 = dollar_point * erue;
    system("clear");
    // delay(2000);
    if (erue <= 0)
    {
        error(409);
        return shop(dollar, erue, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your erue is %d\n", erue);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<the conversions for erue>>>>>>> :\n");
    fflush(stdout);
    printf("(1)erue to toman\n");
    printf("(2)erue to dollar\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option4);
    if (option4 == 3)
    {
        return shop(dollar, erue, toman);
    }
    else if (option4 == 1)
    {
        printf(CYN "ok %d is once erue\n", toman_point);
        printf("enter your toman to want : " reset);
        fflush(stdout);
        scanf("%3d", &toman_value);
        if (toman_value <= 0 | toman_value > 500 | toman_value < toman_point)
        {
            error(404);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        else if (erue < 0)
        {
            error(408);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        else if (toman_value > check_e_1)
        {
            error(500);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        toman = toman + toman_value;
        toman_value = toman_value / toman_point;
        erue = erue - toman_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else if (option4 == 2)
    {
        printf(CYN "ok %d erue is once dollar\n", dollar_point);
        printf("enter your erue to want : " reset);
        fflush(stdout);
        scanf("%3d", &dollar_value);
        if (dollar_value <= 0 | dollar_value > 500)
        {
            error(404);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        else if (dollar < 0)
        {
            error(408);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        else if (dollar_value > check_e_2)
        {
            error(500);
            delay(2000);
            return Erue(dollar, erue, toman);
        }
        dollar = dollar + dollar_value;
        dollar_value = dollar_value * dollar_point;
        erue = erue - dollar_value;
        printf(BGRN "convert success\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else
    {
        exit(0);
    }
    return Erue(dollar, erue, toman);
}

void warning()
{
}
void member()
{
}
void admin()
{
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 2000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int error(int error_number)
{
    if (error_number == 400)
    {
        printf(REDB "ERROR: you are bot?\n");
        printf("ERROR: your password not match" reset);
        printf("\n");
        fflush(stdout);
        return 0;
    }
    else if (error_number == 401)
    {
        printf(REDB "ERROR: firs register please" reset);
        printf("\n");
        fflush(stdout);
        return 0;
    }
    else if (error_number == 402)
    {
        printf(REDB "ERROR: you dont have any dollar please first buy dollar!!!!" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 403)
    {
        printf(REDB "ERROR: you dont have any toman please first buy toman!!!!" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 404)
    {
        printf(REDB "ERROR: value can not be zero or more than 500 or fewer point " reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 405)
    {
        printf(REDB "ERROR: toman is very low" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 406)
    {
        printf(RED "Error: username very small" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 407)
    {
        printf(REDB "ERROR: dollar is very low" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 408)
    {
        printf(REDB "ERROR: erue is very low" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 409)
    {
        printf(REDB "ERROR: you dont have any erue please first buy erue" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 500)
    {
        printf(REDB "ERROR: you dont have more than many to convert" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 501)
    {
        printf(REDB "ERROR: password is small" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 502)
    {
        printf(REDB "ERROR: username or password is not correct" reset);
        printf("\n");
        fflush(stdout);
    }
}
