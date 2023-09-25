#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <colors.h>
#include <signal.h>
#define namesize 10
int shop(int dollar, int euro, int toman);
void warning();
void member();
int menu(int dollar, int euro, int toman);
int Dollar(int dollar, int euro, int toman);
int Euro(int dollar, int euro, int toman);
int Toman(int dollar, int euro, int toman);
void delay(int number_of_seconds);
int error(int error_number);
void welcome();
char licnes[100][100];
int c = 0;
int f_dollar;
int f_euro;
int f_toman;
bool register_check;
char username[namesize];
void handle(int signo);
void bye(int dollar, int euro, int toman);

int main(int argc, char **argv)
{
    signal(SIGINT, handle);
    signal(SIGQUIT, handle);
    signal(SIGTERM, handle);
    signal(SIGTSTP, handle);
    welcome();
    for (;;)
    {
        menu(0, 0, 500);
    }
    return 0;
}
int menu(int dollar, int euro, int toman)
{
    // bool register_check;
    int pass;
    int verify;
    int verify_pass;
    int select;
    int i = 0;
    char fermet[20];
    printf(BYEL "\n(1)shop\n");
    printf("(2)register\n");
    printf("(3)about\n");
    printf("(4)exit\n" reset);
    fflush(stdout);
    scanf("%2d", &select);
    getchar();
    if (select == 4)
    {
        bye(dollar, euro, toman);
    }

    else if (select == 2)
    {
        if (register_check == true)
        {
            printf(REDB "you was registered" reset);
            printf("\n");
            fflush(stdout);
            return 0;
        }
        printf(MAG "create an account\n");
        printf("enter your username : ");
        fflush(stdout);
        fgets(username, namesize, stdin);
        if (strlen(username) < 4)
        {
            error(406);
            return menu(dollar, euro, toman);
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
            return 0;
        }
        else if (verify == pass)
        {
            register_check = true;
        }
        printf(GRN "Registration was successful\n" reset);
        fflush(stdout);
    }
    else if (select == 1 && register_check == true)
    {
        shop(dollar, euro, toman);
    }
    else if (select == 1 && register_check != true)
    {
        error(401);
        return 0;
    }
    else if (select == 3)
    {
        system("clear");
        FILE *readme;
        readme = fopen("README.md", "r");
        if (readme == NULL)
        {
            error(503);
            bye(dollar, euro, toman);
        }
        while (feof(readme) == 0)
        {
            fgets(licnes[i], 256, readme);
            printf(CYN "%s" reset, licnes[i]);
            fflush(stdout);
            i++;
        }
        fclose(readme);
    }
    else
    {
        bye(dollar, euro, toman);
    }
}
int shop(int dollar, int euro, int toman)
{
    int option;
    int num1 = 3;
    int num2 = 2;
    f_dollar = dollar;
    f_euro = euro;
    f_toman = toman;
    system("clear");
    printf(BYEL "            ***______Welcome to shop______***\n\n" reset);
    printf(GRN "your dollar is %d\n", dollar);
    printf("your euro is %d\n", euro);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "(1)dollar conversions\n");
    printf("(2)euro conversions\n");
    printf("(3)Toman conversions\n");
    printf("(4)Go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option);
    if (option == 4)
    {
        return menu(dollar, euro, toman);
    }
    else if (option == 1)
    {
        Dollar(dollar, euro, toman);
    }
    else if (option == 3)
    {
        Toman(dollar, euro, toman);
    }
    else if (option == 2)
    {
        Euro(dollar, euro, toman);
    }
    else
    {
        return menu(dollar, euro, toman);
    }
    return shop(dollar, euro, toman);
}
int Toman(int dollar, int euro, int toman)
{
    int option3;
    int dollar_value;
    int euro_value;
    int dollar_point = 50;
    int euro_point = 60;
    int check_t_1 = toman / dollar_point;
    int check_t_2 = toman / euro_point;
    system("clear");
    // delay(2000);
    if (toman <= 0)
    {
        error(403);
        delay(2000);
        return shop(dollar, euro, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your euro is %d\n", euro);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<Toman>>>>>>> :\n");
    fflush(stdout);
    // printf(__DATE__);
    printf("(1)toman to dollar\n");
    printf("(2)tomn to euro\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option3);
    if (option3 == 3)
    {
        return shop(dollar, euro, toman);
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
            return Toman(dollar, euro, toman);
        }
        else if (toman < 0)
        {
            error(405);
            delay(2000);
            return Toman(dollar, euro, toman);
        }
        else if (dollar_value > check_t_1)
        {
            error(500);
            delay(2000);
            return Toman(dollar, euro, toman);
        }
        dollar = dollar + dollar_value;
        dollar_value = dollar_value * dollar_point;
        toman = toman - dollar_value;
        printf(BGRN "convert was successfully\n" reset);
        fflush(stdout);
        delay(2000);

        // printf(GRN "your dollar is %d\n", dollar);
        // printf("your euro is %d\n", euro);
        // printf("your tomsn is %d\n" reset, toman);
    }
    else if (option3 == 2)
    {
        printf(CYN "ok once euro is %d toman\n", euro_point);
        printf("enter your euro to want : " reset);
        fflush(stdout);
        scanf("%3d", &euro_value);
        if (euro_value <= 0 | euro_value > 500)
        {
            error(404);
            delay(2000);
            return Toman(dollar, euro, toman);
        }
        else if (toman < 0)
        {
            error(405);
            delay(2000);
            return Toman(dollar, euro, toman);
        }
        else if (euro_value > check_t_2)
        {
            error(500);
            delay(2000);
            return Toman(dollar, euro, toman);
        }
        euro = euro + euro_value;
        euro_value = euro_value * euro_point;
        toman = toman - euro_value;
        printf(BGRN "convert was successfully\n" reset);
        fflush(stdout);
        delay(2000);
        // printf(GRN "your dollar is %d\n", dollar);
        // printf("your euro is %d\n", euro);
        // printf("your tomsn is %d\n" reset, toman);
    }
    else
    {
        bye(dollar, euro, toman);
    }
    f_dollar = dollar;
    f_euro = euro;
    f_toman = toman;
    return Toman(dollar, euro, toman);
}
int Dollar(int dollar, int euro, int toman)
{
    int option2;
    int toman_value;
    int euro_value;
    int toman_point = 50;
    float euro_point = 1.079;
    int check_d_1 = toman_point * dollar;
    int check_d_2 = euro_point * dollar;
    // bool ask = true;
    // bool ans = false;
    // delay(2000);
    system("clear");
    if (dollar <= 0)
    {
        error(402);
        delay(2000);
        return shop(dollar, euro, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your euro is %d\n", euro);
    printf("your toman is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<Dollar>>>>>>> :\n");
    fflush(stdout);
    printf("(1)dollar to euro\n");
    printf("(2)dollar to toman\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option2);
    if (option2 == 3)
    {
        return shop(dollar, euro, toman);
    }
    else if (option2 == 1)
    {
        printf(CYN "ok %d dollar is once euro\n", euro_point);
        printf("enter your euro to want : " reset);
        fflush(stdout);
        scanf("%3d", &euro_value);
        if (euro_value <= 0 | euro_value > 500)
        {
            error(404);
            delay(2000);
            return Dollar(dollar, euro, toman);
        }
        else if (dollar < 0)
        {
            error(407);
            delay(2000);
            return Dollar(dollar, euro, toman);
        }
        else if (euro_value > check_d_2)
        {
            error(500);
            delay(2000);
            return Dollar(dollar, euro, toman);
        }
        euro = euro + euro_value;
        euro_value = euro_value * euro_point;
        dollar = dollar - euro_value;
        printf(BGRN "convert was successfully\n" reset);
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
            return Dollar(dollar, euro, toman);
        }
        else if (dollar < 0)
        {
            error(407);
            delay(2000);
            return Dollar(dollar, euro, toman);
        }
        else if (toman_value > check_d_1)
        {
            error(500);
            delay(2000);
            return Dollar(dollar, euro, toman);
        }
        toman = toman + toman_value;
        toman_value = toman_value / toman_point;
        dollar = dollar - toman_value;
        printf(BGRN "convert was successfully\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else
    {
        bye(dollar, euro, toman);
    }
    f_dollar = dollar;
    f_euro = euro;
    f_toman = toman;
    return Dollar(dollar, euro, toman);
}
int Euro(int dollar, int euro, int toman)
{
    int option4;
    int toman_value;
    int dollar_value;
    int toman_point = 60;
    float dollar_point = 1.9;
    int check_e_1 = toman_point * euro;
    int check_e_2 = dollar_point * euro;
    system("clear");
    // delay(2000);
    if (euro <= 0)
    {
        error(409);
        delay(2000);
        return shop(dollar, euro, toman);
    }
    printf(GRN "your dollar is %d\n", dollar);
    printf("your euro is %d\n", euro);
    printf("your tomsn is %d\n" reset, toman);
    printf(BYEL "\n          <<<<<<<Euro>>>>>>> :\n");
    fflush(stdout);
    printf("(1)euro to toman\n");
    printf("(2)euro to dollar\n");
    printf("(3)go back\n" reset);
    fflush(stdout);
    scanf("%2d", &option4);
    if (option4 == 3)
    {
        return shop(dollar, euro, toman);
    }
    else if (option4 == 1)
    {
        printf(CYN "ok %d is once euro\n", toman_point);
        printf("enter your toman to want : " reset);
        fflush(stdout);
        scanf("%3d", &toman_value);
        if (toman_value <= 0 | toman_value > 500 | toman_value < toman_point)
        {
            error(404);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        else if (euro < 0)
        {
            error(408);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        else if (toman_value > check_e_1)
        {
            error(500);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        toman = toman + toman_value;
        toman_value = toman_value / toman_point;
        euro = euro - toman_value;
        printf(BGRN "convert was successfully\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else if (option4 == 2)
    {
        printf(CYN "ok %d euro is once dollar\n", dollar_point);
        printf("enter your euro to want : " reset);
        fflush(stdout);
        scanf("%d", &dollar_value);
        if (dollar_value <= 0 | dollar_value > 500)
        {
            error(404);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        else if (dollar < 0)
        {
            error(408);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        else if (dollar_value > check_e_2)
        {
            error(500);
            delay(2000);
            return Euro(dollar, euro, toman);
        }
        dollar = dollar + dollar_value;
        dollar_value = dollar_value * dollar_point;
        euro = euro - dollar_value;
        printf(BGRN "convert was successfully\n" reset);
        fflush(stdout);
        delay(2000);
    }
    else
    {
        bye(dollar, euro, toman);
    }
    f_dollar = dollar;
    f_euro = euro;
    f_toman = toman;
    return Euro(dollar, euro, toman);
}

void warning()
{
}
void member()
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
    char y_n[20];
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
        printf(REDB "ERROR: euro is very low" reset);
        printf("\n");
        fflush(stdout);
    }
    else if (error_number == 409)
    {
        printf(REDB "ERROR: you dont have any euro please first buy euro" reset);
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
    else if (error_number == 503)
    {
        printf(REDB "ERROR: README file not found" reset);
        printf("\n");
        fflush(stdout);
    }
}
void welcome()
{
    printf(BBLU "Hello and welcome to the exchange\n\n");
    printf("thank you for using\n");
    system("date");
    printf("\e[1;31m[\e[1;32m*\e[1;31m]\e[1;32m for report the bugs select ");
    printf(UCYN "(3)" reset);
    fflush(stdout);
    printf(reset "\n");
    fflush(stdout);
}
void handle(int signo)
{

    char check[3];
    if (signo == SIGQUIT)
    {
        printf(BRED "Are you sure to exit program(y or n)\n" reset);
        fflush(stdout);
        fgets(check, 1, stdin);
        if (check == "y")
        {
            bye(f_dollar, f_euro, f_toman);
        }
        else
        {
            printf(BWHT "ok" reset);
        }
    }
    else if (signo == SIGINT)
    {
        printf(BRED "Are you sure to exit program (y or n)\n" reset);
        fflush(stdout);
        fgets(check, 1, stdin);
        if (check == "y")
        {
            bye(f_dollar, f_euro, f_toman);
        }
        else
        {
            printf(BWHT "ok" reset);
        }
    }
    else if (signo == SIGTSTP)
    {
        printf(BRED "Are you sure to exit program (y or n)\n" reset);
        fflush(stdout);
        fgets(check, 1, stdin);
        if (check == "y")
        {
            bye(f_dollar, f_euro, f_toman);
        }
        else
        {
            printf(BWHT "ok" reset);
        }
    }
    else if (signo == SIGTERM)
    {
        printf(BRED "Are you sure to exit program (y or n)\n" reset);
        fflush(stdout);
        fgets(check, 1, stdin);
        if (check == "y")
        {
            bye(f_dollar, f_euro, f_toman);
        }
        else
        {
            printf(BWHT "ok" reset);
        }
    }
}
void bye(int dollar, int euro, int toman)
{
    FILE *output;
    output = fopen("outputs.txt", "a-w-r");
    fprintf(output, "username :%s{\n", username);
    fprintf(output, "\tDollars is %d\n", dollar);
    fprintf(output, "\teuro is %d\n", euro);
    fprintf(output, "\ttoman is %d\n", toman);
    fprintf(output, "}\n\n");
    fclose(output);
    printf(BCYN "Good bye\n");
    fflush(stdout);
    exit(0);
}
