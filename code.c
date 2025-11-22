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
