#include <stdio.h>
#include <stdlib.h>

int days;
int get_dayofweek();
int get_year();
int get_month(int);

int get_dayofweek()
{
    int dayofweek;
    dayofweek = days % 7;
    return dayofweek;
}

int get_year()
{
    int i = 2000, leap_year;

    while(1){
        leap_year = (i%4==0&&i%100!=0||i%400==0);
        if(leap_year==1 && days>=366){
            days=days-366;
            i++;
            continue;
        }else if(leap_year==0&&days>=365){
            days=days-365;
            i++;
            continue;
        }else
            break;
    }
    return i;
}

int get_month(int leap_year)
{
    int pmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};  //365 days
    int rmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};  //366 days
    int j = 0;
    while(1){
        if(leap_year==1 && days>=rmonth[j]){
            days=days-rmonth[j];
            j++;
        }else if(leap_year==0 && days>=pmonth[j]){
            days=days-pmonth[j];
            j++;
        }else
            break;
    }
    return ++j;
}

int main()
{
    int year, month, dayofweek;
    int leap_year;
    char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday",
            "Wednesday", "Thursday", "Friday"};

    while(scanf("%d", &days) && days != -1){
//        printf("%d\n", days);
        dayofweek = get_dayofweek();
        year = get_year();
        leap_year = (year%4==0 && year%100!=0 || year%400==0);
        month = get_month(leap_year);
        printf("dayofweek:%d year:%d, month:%d\n", dayofweek, year, month);
        printf("%d-%d-%d %s\n", year, month, days, week[dayofweek]);
    }


    return 0;
}
