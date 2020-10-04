/*
    Author: Mohammad Karimi
    Date: 3 November 2019
    Purpose: This program is to show the weekly NET pay, TAX and GROSS pay.
*/
#include<stdio.h>
#include<conio.h>

void main()
{
    float hours,gross,tax,net,overtime;
    float remain;
    printf("Enter the hours you worked in this week\n");
    scanf("%f",&hours);
    gross = 12*hours;
    if(hours>40)      //It will calculate the Overtime
    {
        remain = hours - 40;  //For each hour after 40 hours will add 18$
        overtime = remain * 18;
        printf("Your Over Time Pay is: %.2f $\n",overtime);
    }
    else
    {
        overtime = 0;
        printf("You do not have any Over Time Pay\n");
    }

    gross += overtime;
    printf("Your Gross Pay is: %.2f $\n",gross);

                     /*Calculating TAX*/
    if(gross<=300)
    {
        tax = gross*0.15;
        net = gross-tax;
    }
    else if(gross>300 && gross<=450)
    {
        tax = 300*0.15;
        tax += (gross-300) * 0.20;
        net = gross-tax;
    }
    else if(gross>450)
    {
        tax = 300*0.15;               //TAX for first 300$
        tax += 150*0.20;              //TAX for 150$ more except first 300$
        tax += (gross-450) * 0.25;    //TAX for remain except first 450$
        net = gross-tax;
    }
    printf("You should pay %.2f $ as TAX\n",tax);
    printf("Your Net pay is: %.2f $\n",net);
}
