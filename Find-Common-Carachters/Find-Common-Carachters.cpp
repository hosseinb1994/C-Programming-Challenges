extern "C" {
	#include "Find-Common-Carachters.h"
}

void Find_Common_Characters(const char* Words[], int Number_Of_Words);

int main()
{
    const char* Words[] = { "bella", "label", "roller" };
    int Number_Of_Words = sizeof(Words) / sizeof(Words[0]);

    Find_Common_Characters(Words, Number_Of_Words);
	return 0;
}

//Find and print common characters in Words
void Find_Common_Characters(const char* Words[], int Number_Of_Words) {
    
    int c_count[A_SIZE];
    // set a block of memory to 0
    memset(c_count, 0, sizeof(c_count));

    // Count the occurrences of each character in the first word
    for (const char* p = Words[0]; *p != '\0'; p++) {
        c_count[*p - 'a']++;
    }

    // Process each subsequent word
    for (int i = 1; i < Number_Of_Words; i++) {
        int t_count[A_SIZE] = { 0 };

        // Count the occurrences of each character in the current word
        for (const char* p = Words[i]; *p != '\0'; p++) {
            t_count[*p - 'a']++;
        }

        // Update the c_count array to hold the minimum count across words
        for (int j = 0; j < A_SIZE; j++) {
            if (t_count[j] < c_count[j]) {
                c_count[j] = t_count[j];
            }
        }
    }

    // Print the common characters
    for (int i = 0; i < A_SIZE; i++) {
        for (int j = 0; j < c_count[i]; j++) {
            printf("%c", i + 'a');
        }
    }
    printf("\n");
}