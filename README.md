# Clean-coding
#25 color code manual

#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;  // we can use uint8_t so that it will take 1byte for that need to add stdint.h header file, int maj_u8,min_u8=0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);    //first argument is not understanding to user .for easy understandint we can add as a count in printf statement
        }
    }
    return i * j;      //return maj_u8*min_u8
}

int main() {
    int result = printColorMap();  
    assert(result == 25);   // this 25 we can take it as a macro  #define COLOR_MANUAL 25
    printf("All is well (maybe!)\n");
    return 0;
}
