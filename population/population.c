#include <cs50.h>
#include <stdio.h>
int Get_StartSize(void);
int Get_EndSize(void);
int main(void)
{
    // TODO: Prompt for start size
    int start_size ;
    do{
        start_size = get_int(" Enter a start size : \n");
    }while (start_size < 9);
    // TODO: Prompt for end size
    int end_size ;
    do{
        end_size = get_int("Enter an end size : \n");
    }while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold
    int new_born ;
    int years = 0 ;
    int passed_away ;
    int yearly_increase;


    while(start_size < end_size)
    {
    new_born = start_size / 3;
    passed_away = start_size / 4;
    yearly_increase = new_born - passed_away;
    start_size = start_size + yearly_increase ;
    years+=1;
    }


    // TODO: Print number of years
    printf("Years: %i\n",years);
}



