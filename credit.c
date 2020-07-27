#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card = get_long("Whats the credit card number?");

    long firstTwoDigits = card;

    while (firstTwoDigits > 100)
    {
        firstTwoDigits /= 10;
    }


    int numberLength = 0;
    long newCard = card;


    for (int a = 0; newCard > 0; a++)
    {
        newCard /= 10;
        numberLength ++;
    }

    long completeCard = card;

    long firstNumbers = 0;
    long secondNumbers = 0;

    for (int b = 0; completeCard > 0; b++)
    {

        // Take the last number
        firstNumbers += completeCard % 10;
        completeCard /= 10;

        long sec = completeCard % 10;
        long secM = sec * 2;
        if (secM > 9)
        {
            if (secM == 10)
            {
                secM = 1;
            }
            else
            {
                int one = secM % 10;
                int two = secM / 10;
                secM = one + two;
            }
        }
        secondNumbers += secM;
        completeCard /= 10;
    }

    long totalSum = firstNumbers + secondNumbers;

    if (totalSum % 10 == 0)
    {
        if ((firstTwoDigits == 34 || firstTwoDigits == 37) && (numberLength == 15))
        {
            printf("AMEX\n");
        }
        else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && (numberLength == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((firstTwoDigits / 10 == 4) && (numberLength == 13 || numberLength == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
