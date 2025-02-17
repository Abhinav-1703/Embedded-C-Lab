#include <stdio.h>
#include <string.h>
#include <ctype.h>

// **Swap Functions**
void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", x, y);
}
void swapByReference(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// **Factorial (Recursion)**
long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// **Reverse String Using Pointer**
void printReverse(const char *str) {
    const char *ptr = str + strlen(str) - 1;
    while (ptr >= str) {
        printf("%c", *ptr);
        ptr--;
    }
}

// **Reverse String (Recursion)**
void reverseStringRec(char str[], int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStringRec(str, start + 1, end - 1);
}

// **Palindrome Check**
int isPalindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return (original == reversed);
}

// **Prime Check (Iterative)**
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// **Prime Check (Recursive)**
int isPrimeRecursiveHelper(int n, int i) {
    if (n < 2) return 0;
    if (i * i > n) return 1;
    if (n % i == 0) return 0;
    return isPrimeRecursiveHelper(n, i + 1);
}
int isPrimeRecursive(int n) {
    return isPrimeRecursiveHelper(n, 2);
}

// **Count Words in a Sentence**
int countWords(const char *str) {
    int count = 0, inWord = 0;
    while (*str) {
        if (!isspace((unsigned char)*str) && inWord == 0) {
            inWord = 1;
            count++;
        } else if (isspace((unsigned char)*str)) {
            inWord = 0;
        }
        str++;
    }
    return count;
}

// **Matrix Multiplication**
void multiplyMatrices(int A[][10], int B[][10], int C[][10], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
}

// **GCD (Recursion)**
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// **Main Program with Menu**
int main() {
    int choice;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Swap Numbers\n");
        printf("2. Factorial\n");
        printf("3. Reverse String (Pointer)\n");
        printf("4. Reverse String (Recursion)\n");
        printf("5. Check Palindrome\n");
        printf("6. Check Prime (Iterative)\n");
        printf("7. Check Prime (Recursive)\n");
        printf("8. Count Words in Sentence\n");
        printf("9. Matrix Multiplication\n");
        printf("10. GCD\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline after number input

        switch (choice) {
            case 1: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                swapByValue(a, b);
                swapByReference(&a, &b);
                printf("After swapByReference: a = %d, b = %d\n", a, b);
                break;
            }
            case 2: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Factorial: %ld\n", factorial(num));
                break;
            }
            case 3: {
                char str[100];
                printf("Enter a string: ");
                scanf("%99[^\n]", str);
                printf("Reversed string: ");
                printReverse(str);
                printf("\n");
                break;
            }
            case 4: {
                char str[100];
                printf("Enter a string: ");
                scanf("%99[^\n]", str);
                reverseStringRec(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;
            }
            case 5: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf(isPalindrome(num) ? "Palindrome\n" : "Not a palindrome\n");
                break;
            }
            case 6: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf(isPrime(num) ? "Prime\n" : "Not Prime\n");
                break;
            }
            case 7: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf(isPrimeRecursive(num) ? "Prime\n" : "Not Prime\n");
                break;
            }
            case 8: {
                char sentence[200];
                printf("Enter a sentence: ");
                scanf("%199[^\n]", sentence);
                printf("Word count: %d\n", countWords(sentence));
                break;
            }
            case 9: {
                int r1, c1, r2, c2, A[10][10], B[10][10], C[10][10] = {0};
                printf("Enter rows and columns for matrix 1: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for matrix 2: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("Matrix multiplication not possible!\n");
                    break;
                }

                printf("Enter elements of first matrix:\n");
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        scanf("%d", &A[i][j]);

                printf("Enter elements of second matrix:\n");
                for (int i = 0; i < r2; i++)
                    for (int j = 0; j < c2; j++)
                        scanf("%d", &B[i][j]);

                multiplyMatrices(A, B, C, r1, c1, r2, c2);

                printf("Resultant Matrix:\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++)
                        printf("%d ", C[i][j]);
                    printf("\n");
                }
                break;
            }
            case 10: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD: %d\n", gcd(a, b));
                break;
            }
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
