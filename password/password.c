// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int lcase = 0;
    int hcase = 0;
    int symp = 0;
    int num = 0;
    for (int i = 0; i <= strlen(password); i++)
    {
        if(password[i] >= 'A'  && password[i] <= 'Z'){
            hcase++;
        }
        else if(password[i] >= 'a'  && password[i] <= 'z'){
            lcase++;
        }
        else if(password[i] == '!' || password[i] == '#' || password[i] == '$'){
            symp++;
        }
        else if(password[i] >= '0' && password[i] <= '9'){
            num++;
        }
    }
    if(lcase >= 1 && hcase >= 1 && symp >=1 && num >= 1){
        return true;
    }
    else{
        return false;
    }
}
