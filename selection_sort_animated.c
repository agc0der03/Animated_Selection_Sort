#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printminarr1(int[], int, int,int);
void printminarr2(int[], int, int, int,int);
void printcursorarr(int[], int, int, int, int,int);
void display_swap(int[], int, int,int,int);

int main() {
    printf("enter the number of elements:");
    int n;
    float sp;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("enter unsorted array:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i]=x;
    }
    printf("enter the speed of animation any float between 0 to 1 \n");
    scanf("%f",&sp);

    float speed = sp * 1000000.0; 
    int duration = 1000000-(int)speed;

    printf("\n");
    printf("\n");
    printf("\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        printminarr1(arr, n, i,duration);

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
                printminarr2(arr, n, min, i,duration);
            } else {
                printcursorarr(arr, n, j, min, i,duration);
            }
        }

        display_swap(arr, i, min,n,duration);

    }
    printf("\r");
    printf("\x1b[K");
    printf("\x1b[1A\x1b[0G");
    usleep(duration);
    printf("\r");
    for(int i=0;i<n;i++){
        printf("\x1b[32;40m%03d \x1b[0m", arr[i]);
    }


    free(arr);
    printf("\n");
    printf("\n");


    return 0;
}

void printminarr1(int arr[], int n, int i,int duration) {
    usleep(duration);
    printf("\r");

    // Print the array elements
    for (int x = 0; x < n; x++) {
        if (x < i) {
            printf("\x1b[32;40m%03d \x1b[0m", arr[x]);
        } else if (x == i) {
            printf("\x1b[31m%03d \x1b[0m", arr[x]);
        } else {
            printf("%03d ", arr[x]);
        }
    }

    printf("\n");

    // Calculate the number of spaces needed for cursor alignment
    int spaces = i * 4;

    // Print spaces before the cursor based on the current element's position
    for (int x = 0; x <= spaces; x++) {
        printf(" ");
    }
    printf("^");

    fflush(stdout);

    // Move the cursor to the beginning of the previous line using ANSI escape codes
    printf("\r");
    printf("\x1b[K");
    printf("\x1b[1A\x1b[0G");
}

void printminarr2(int arr[], int n, int m, int i,int duration) {
    usleep(duration);
    printf("\r");

    // Print the array elements
    for (int x = 0; x < n; x++) {
        if (x < i) {
            printf("\x1b[32;40m%03d \x1b[0m", arr[x]);
        } else if (x == m) {
            printf("\x1b[31m%03d \x1b[0m", arr[x]);
        } else {
            printf("%03d ", arr[x]);
        }
    }

    printf("\n");

    // Calculate the number of spaces needed for cursor alignment
    int spaces = m * 4;

    // Print spaces before the cursor based on the current element's position
    for (int x = 0; x <= spaces; x++) {
        printf(" ");
    }
    printf("^");

    fflush(stdout);

    // Move the cursor to the beginning of the previous line using ANSI escape codes
    printf("\r");
    printf("\x1b[K");
    printf("\x1b[1A\x1b[0G");
}


void printcursorarr(int arr[], int n, int j, int m, int i,int duration) {
    // i has cursor, m has min
    usleep(duration);
    printf("\r");
    for (int x = 0; x < n; x++) {
        if (x < i) {
            printf("\x1b[32;40m%03d \x1b[0m", arr[x]);
        } else if (x == m) {
            printf("\x1b[31m%03d \x1b[0m", arr[x]);
        } else {
            printf("%03d ", arr[x]);
        }
    }

    printf("\n");

    // Calculate the number of spaces needed for cursor alignment
    int spaces = j * 4;

    // Print spaces before the cursor based on the current element's position
    for (int x = 0; x <= spaces; x++) {
        printf(" ");
    }
    printf("^");

    fflush(stdout);

    // Move the cursor to the beginning of the previous line using ANSI escape codes
    printf("\r");
    printf("\x1b[K");
    printf("\x1b[1A\x1b[0G");
}


void display_swap(int arr[], int i, int min, int n,int duration) {
    int steps = abs(min - i);
    int temp = min;
    int temp2 = i;
    printf("\r");
    printf("\033[2K");
    for (int x = 0; x < n; x++) {
        if (x < i) {
            printf("\x1b[32;40m%03d\x1b[0m ", arr[x]);
            continue;
        }

        if (x == min || x == i) {
            printf("   ");
        } else {
            printf("%03d ", arr[x]);
        }
    }

    // Move cursor to the beginning of the current line
    printf("\r");

    // Move cursor to the previous line (1 line up)
    printf("\033[F");
    while (steps+1) {
        printf("\033[2K");
        usleep(duration/2);
        for (int x = 0; x < temp; x++) {
            printf("    ");
        }
        printf("%03d", arr[min]);
        printf("\r");
        printf("\033[2E");
        printf("\033[2K");
        for (int x = 0; x < temp2; x++) {
            printf("    ");
        }
        printf("%03d", arr[i]);
        usleep(duration/2);
        printf("\r");
        printf("\033[2F");

        temp--;
        temp2++;
        steps--;
        fflush(stdout);
    }

    // Swap the elements
    int c = arr[i];
    arr[i] = arr[min];
    arr[min] = c;
    usleep(duration/2);
    printf("\r");
    printf("\033[2K");
    printf("\033[2E");
    printf("\033[2K");
    printf("\033[F");

    // printf("\n");
    for (int x = 0; x < n; x++) {
        if (x <= i) {
            printf("\x1b[32;40m%03d\x1b[0m ", arr[x]);
        } else {
            printf("%03d ", arr[x]);
        }
    }
}


