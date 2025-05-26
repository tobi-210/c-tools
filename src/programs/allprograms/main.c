#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <test_c_lib.h>

//                                                           !EXPLANATION!
//
// C-Tools is a collection of programs that can be used to test and demonstrate various functionalities.
// The programs are designed to be simple and easy to use, with a focus on demonstrating specific features.
// The main program serves as a menu for the user to choose which program they want to run.
// The programs are implemented in separate files and are included in the main program.
// If the program doesnt compile correctly, then try again

//                                                            !IMPORTANT!

// run /src/programs/compiler/main.c if the program does not compile correctly.

int main(int argc, char **argv)
{

    srand(time(NULL));

    char decision[100];
    int32_t running = 0;

    printf("\n\033[1mWelcome to C-Tools! 🔧\033[0m\n");
    printf("\nhelpful programs:\n");
    printf("• readtext: Read text and count characters\n• calculator: A simple calculator with integers\n");
    printf("\ngames:\n");
    printf("• guessthenumber: guessing game with numbers between 1 and 100\n");
    printf("\nPlease choose your program from above: ");
    scanf("%s", decision);
    while (getchar() != '\n')
        ; // Clear the input buffer for other programs

    running = 1;

    while (running)
    {

        if (strcmp(decision, "readtext") == 0)
        {

            char text[500];
            int32_t count = 0;

            printf("\nWelcome to the read text program!👋\n");

            printf("Insert your text here: ");
            fgets(text, sizeof(text), stdin);

            readtext(text, &count);

            printf("Your text has %d characters.\n", count);

            printf("Goodbye! 👋\n");

            running = 0; // exit the loop after running the readtext program correctly
        }
        else if (strcmp(decision, "calculator") == 0)
        {

            char decisioncalculator[20];
            int32_t numbers[2];
            float result = 0;

            printf("\nWelcome to the c-tools calculator!👋");

            printf("\nWould you like to add, subtract, divide or multiply two numbers?: ");
            scanf("%s", decisioncalculator);

            if (strcmp(decisioncalculator, "add") == 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                }
                result = add(numbers[0], numbers[1]);

                printf("The result of that is: %.2f\n", result);
                printf("Goodbye! 👋\n");

                running = 0;
            }

            if (strcmp(decisioncalculator, "subtract") == 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                }
                result = subtract(numbers[0], numbers[1]);

                printf("The result of that is: %.2f\n", result);
                printf("Goodbye! 👋\n");

                running = 0;
            }

            if (strcmp(decisioncalculator, "divide") == 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                }
                result = divide((float)numbers[0], (float)numbers[1]);

                printf("The result of that is: %.2f\n", result);
                printf("Goodbye! 👋\n");

                running = 0;
            }

            if (strcmp(decisioncalculator, "multiply") == 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Enter number %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                }
                result = multiply(numbers[0], numbers[1]);

                printf("The result of that is: %.2f\n", result);
                printf("Goodbye! 👋\n");

                running = 0;
            }
        }
        else if (strcmp(decision, "guessthenumber") == 0)
        {

            int32_t guess = 0;
            int32_t target = 0;

            target = random_number();

            printf("\nWelcome to the guessthenumber game! 👋");

            while (guess != target)
            {
                printf("\nYour guess: ");
                scanf("%d", &guess);

                if (guess < target)
                {
                    printf("too small!\n");
                }
                else if (guess > target)
                {
                    printf("too big!\n");
                }
                else
                {
                    printf("Bingo! The number was %d.\n", target);
                }

                if (guess > 100)
                {
                    printf("Only numbers between 1 and 100!\n");
                }
            }

            printf("Goodbye! 👋\n");
            running = 0;
            clear_terminal();
        }
        else
        {
            printf("\nInvalid program choice. Please try again.\n");
            printf("Would you like to do something else? [Enter program name]: ");
            scanf("%s", decision);
            while (getchar() != '\n')
                ; // Clear the input buffer for other programs
            running = 1;
        }

        clear_terminal();
    }
}
