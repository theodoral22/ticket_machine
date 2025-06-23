#include <stdio.h>

#define TICKET_PRICE 0.75

int main()
{
    int tickets; //number of tickets (0-5)
    float money; //how much money the user has (0.75-100€)
    float total; //the total price of the tickets
    float change; //to check if the user has enough money to buy the tickets
    
    //eu2=2€, eu1=1€, ce50=0.50€, ce20=0.20€, ce10=0.10€, ce5=0.05€
    int eu2,eu1,ce50,ce20,ce10,ce5;
    int change2; //for the change
    
    //read the number of tickets. The value must be between 1 and 5. In any other case, repeat
    do {
        printf ("Give me the number of tickets that you want to buy.\n");
        scanf ("%d",&tickets);
        if (tickets<1 || tickets>5)
            printf ("You must buy from 1 to 5 tickets.\n");
    } while (tickets<1 || tickets>5);
    
    //read how much money the user has. The value must be between 0.75 and 100. In any other case, repeat
    do {
        printf ("How much money do you have?\n");
        scanf ("%f",&money);
        if (money<0.75 || money>100)
            printf ("The money must be between 0.75€ and 100€.\n");
    } while (money<0.75 || money>100);
    
    
    total=tickets*TICKET_PRICE; //calculate the total price of the tickets 
    change=money-total; //calculate if the money is enough to buy the tickets
            
    //if the money is enough, calculate the change
    if (change>=0)  
    {
        change2=(int)(change*100+0.5);
                
        eu2=change2/200;
        change2=change2%200;
                
        eu1=change2/100;
        change2=change2%100;
                
        ce50=change2/50;
        change2=change2%50;
                
        ce20=change2/20;
        change2=change2%20;
                
        ce10=change2/10;
        change2=change2%10;
                
        ce5=change2/5;
        change2=change2%5;
                
        //print the change
        printf ("Your change is: \n");
        if (eu2!=0) 
            printf ("%d * 2 euros\n",eu2);
        if (eu1!=0) 
            printf ("%d * 1 euros\n",eu1);
        if (ce50!=0) 
            printf ("%d * 50 cents\n",ce50);
        if (ce20!=0) 
            printf ("%d * 20 cents\n",ce20);
        if (ce10!=0) 
            printf ("%d * 10 cents\n", ce10);
        if (ce5!=0) 
            printf ("%d * 5 cents\n",ce5);
        if (change2!=0) 
            printf ("%d * 1 cent\n",change2);
        printf ("Total: %.2f€\n",eu2*2+eu1*1+ce50*0.5+ce20*0.2+ce5*0.05+change2*0.01);
    } 
    else
        printf ("The money is not enough to buy the tickets.\n");
            
    return 0;
}
