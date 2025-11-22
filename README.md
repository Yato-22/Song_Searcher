Activity 3 EEL

Telephone Directory
Develop a C program to search for the location or the area of a person based on their phone number in the telephone directory. The program should utilize an array to store the phone numbers along with their corresponding locations or areas. Upon receiving a specific phone number as an input from the user, the program should search the array and display the corresponding location or area if the phone number is found. If the phone number is not found, the program should output a message indicating that the number is not in the directory. Additionally the program should handle invalid input and provide appropriate error messages.

Research:

A telephone directory or also known as a telephone book, telephone address book or phonebook is a listing of telephone subscribers in a geographical area provided by the organization that publishes the directory. Its purpose is to allow the telephone number of a subscriber identified by name and address to be found. The invention of the Internet, search engines and smart phones has reduced the need for paper telephone directories.
A telephone directory may also provide instructions on how to use the telephone service, how to dial a particular number. It also provides the numbers for emergency services, utilities, hospitals, doctors and such.  

References: 
https://en.wikipedia.org/wiki/Telephone_directory
https://www.geeksforgeeks.org/c/strcmp-in-c/

Analyse:

For this program, the following commands will be needed: 
Using Scanf for multiple word input:
This reads the entire line including spaces and stops at newline, when the user presses enter
Syntax: scanf(" %[^\n]", str);
Here,
%[] starts a scanset.
^ means ‘not these characters’
\n means stop reading at newline
The space before % is to clear if anything is in the buffer from a previous scanf function.
String Comparison:
In C, strcmp() is a built-in function included in the string.h header file. It is used to compare two strings lexicographically. It takes two strings as arguments, compares these two strings lexicographically and then returns some value as a result. 
Syntax: strcmp(s1,s2);
How strcmp() works:
It starts with comparing the ASCII values of the first characters of both strings.
If the first characters in both strings are equal, then this function will check the second character. If they are also equal, then it will check the third and so on till the first unmatched character is found or the NULL character is found.
If a NULL character is found, the function returns 0 as both strings will be the same.
The strcmp() returns three different values after comparison of two strings as follows:
Zero (0): It returns 0 when all the characters at given indexes in both strings are the same.
Greater than zero (>0): A value greater than zero is returned when the first not-matching character in s1 has a greater ASCII value than the corresponding character in s2.
Lesser than zero (>0): A value lesser than zero is returned when the first not-matching character in s1 has a lesser ASCII value than the corresponding character in s2.




Ideate:

Develop a C program to search for the details of a song from a database. The program should utilize an array to store the song name, its artist name, its duration and the number of likes of that song. Upon receiving a song name or a arist name as an input from the user, the program should search the database and display all the songs in the database that match with the given search result with their details. If the song name or artist name is not found, the program should output a message indicating that there are no results. Additionally the program should handle invalid input and provide appropriate error messages.


Build:


#include <stdio.h>
#include <string.h>

struct song{
    char name[50], artist[50];
    int duration, likes;
};

void search_songname(struct song list[], char search[], char temp[]);
void search_artistname(struct song list[], char search[], char temp[]);

int main() {
    int n;
    char search[50], temp[50];
    struct song list[20] = {{"perfect", "ed sheeran", 120, 3400},
                            {"castle on the hill", "ed sheeran", 120, 3400},
                            {"love story", "taylor swift", 120, 3400},
                            {"perfect", "one direction", 120, 3400},
                            {"photograph", "ed sheeran", 120, 3400},
                            {"night changes", "one direction", 120, 3400},
                            {"you belong with me", "taylor swift", 120, 3400},
                            {"movies", "conan gray", 120, 3400},
                            {"those eyes", "new west", 120, 3400},
                            {"a thousand years", "christina perri", 120, 3400},
                            {"until i found you", "stephan sanchez", 120, 3400},
                            {"what makes you beautiful", "one direction", 120, 3400},
                            {"you", "armaan malik", 120, 3400},
                            {"anyone", "justin bieber", 120, 3400},
                            {"daylight", "taylor swift", 120, 3400},
                            {"when you're gone", "shawn mendes", 120, 3400},
                            {"wolves", "selena gomez", 120, 3400},
                            {"story of my life", "one direction", 120, 3400},
                            {"imagination", "shawn mendes", 120, 3400},
                            {"all of me", "john legend", 120, 3400}
                        };
    
    invalid:
    printf("Choose a search option: \n");
    printf("1 - Song name \n");
    printf("2 - Artist name \n");
    printf("Enter choice: ");
    scanf("%d", &n);
    
    printf("Enter the search: ");
    scanf(" %[^\n]", search);
    int i = 0;
    while(search[i] != '\0'){
        if(search[i] >= 65 && search[i] <= 90){
            temp[i] = search[i] + 32;
        }
        else{
            temp[i] = search[i];
        }
        i++;
    }
    
    switch(n){
        case 1: 
                search_songname(list, search, temp);
                break;
        case 2: 
                search_artistname(list, search, temp);
                break;
        default:
            printf("Invalid choice.");
            goto invalid;
    }
    

    return 0;
}

void search_songname(struct song list[], char search[], char temp[]){
    int count = 0, temp1[20], n = 1;
    for(int i = 0; i < 20; i++){
        if(strcmp(list[i].name, temp) == 0){
            temp1[count] = i;
            count++;
        }
    }
    if(count == 0){
        printf("There are no matching results!");
    }
    else{
        printf("The search results for '%s' are: \n", temp);
    }
    for(int i = 0; i < count; i++){
        printf("%d. Song name: %s \n", n, list[temp1[i]].name);
        printf("   Artist name: %s \n", list[temp1[i]].artist);
        printf("   Duration (seconds): %d \n", list[temp1[i]].duration);
        printf("   Likes: %d \n", list[temp1[i]].likes);
        n++;
    }
}

void search_artistname(struct song list[], char search[], char temp[]){
    int count = 0, temp1[20], n = 1;
    for(int i = 0; i < 20; i++){
        if(strcmp(list[i].artist, temp) == 0){
            temp1[count] = i;
            count++;
        }
    }
    if(count == 0){
        printf("There are no matching results!");
    }
    else{
        printf("The search results for '%s' are: \n", temp);
    }
    for(int i = 0; i < count; i++){
        printf("%d. Song name: %s \n", n, list[temp1[i]].name);
        printf("   Artist name: %s \n", list[temp1[i]].artist);
        printf("   Duration (seconds): %d \n", list[temp1[i]].duration);
        printf("   Likes: %d \n", list[temp1[i]].likes);
        n++;
    }
}


Test:

Test Case 1:
Choose a search option: 
1 - Song name 
2 - Artist name 
Enter choice: 1
Enter the search: Perfect
The search results for 'perfect' are: 
1. Song name: perfect 
   Artist name: ed sheeran 
   Duration (seconds): 120 
   Likes: 3400 
2. Song name: perfect 
   Artist name: one direction 
   Duration (seconds): 120 
   Likes: 3400 

Test Case 2:
Choose a search option: 
1 - Song name 
2 - Artist name 
Enter choice: 2
Enter the search: One Direction
The search results for 'one direction' are: 
1. Song name: perfect 
   Artist name: one direction 
   Duration (seconds): 120 
   Likes: 3400 
2. Song name: night changes 
   Artist name: one direction 
   Duration (seconds): 120 
   Likes: 3400 
3. Song name: what makes you beautiful 
   Artist name: one direction 
   Duration (seconds): 120 
   Likes: 3400 
4. Song name: story of my life 
   Artist name: one direction 
   Duration (seconds): 120 
   Likes: 3400 

