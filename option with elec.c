#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "option.h"
#include "reg.h"
#include "mystruct.h"
#define MAX 9
FILE *fp;
int options(char *fid)
{
    system("color 0B");
    system("cls");
    int opt;
    printf("\t\t1. View your information\n\t\t2. Edit your information\n\t\t3. Delete your account\n");
    printf("\t\t4. Course Registration\n\t\t5. Logout\n");
    printf("\n\t\tEnter your choice: ");
    scanf("%d", &opt);
    getchar();
    switch (opt)
    {
    case 1:
        printf("\t\t\t---Your information---\n");
        fp = fopen("stdinfo.txt", "r");
        while (fscanf(fp, "%s %s %s %s", s.roll, s.name, s.email, s.phone) != EOF)
        {
            if (strcmp(s.roll, fid) == 0)
            {
                printf("\t\tName: %s\n\t\tEmail: %s\n\t\tPhone: %s\n\t\tRoll: %s\n", s.name, s.email, s.phone, s.roll);
                break;
            }
        }
        options(fid);
        break;
    case 2:
        options(fid);
        break;
    case 3:
        options(fid);
        break;
    case 4:
        course_reg(fid);
        options(fid);
        break;
    case 5:
        printf("\n\t\tLogging out");
        for(int i=0;i<3;i++)
        {
            printf(".");
            fflush(stdin);
            Sleep(500);
        }
        login();
        break;
    default:
        printf("\t\t---Invalid choice---");
        Sleep(1000);
        options(fid);
        return 0;
    }
}

int optiont(char *femail)
{
    system("color 0B");
    system("cls");
    int opt;
    printf("\t\t1. View your information\n\t\t2. Edit your information\n\t\t3. Calculate GPA\n");
    printf("\t\t4. CGPA Calculator\n\t\t5. Elect CR\n\t\t6. Logout\n");
    printf("\n\t\tEnter your choice: ");
    scanf("%d", &opt);
    getchar();
    switch (opt)
    {
    case 1:
        printf("\n\n");
        printf("\t\t\t---Your information---\n");
        fp = fopen("teacherinfo.txt", "r");
        while (fscanf(fp, "%s %s %s", t.email, t.name, t.phone) != EOF)
        {
            if (strcmp(t.email, femail) == 0)
            {
                printf("\t\tName: %s\n\t\tEmail: %s\n\t\tPhone: %s\n", t.name, t.email, t.phone);
                break;
            }
        }
        printf("\n\t\tPress any key to continue...");
        getchar();
        optiont(femail);
        break;
    case 2:
        break;
    case 3:
        gpcal();
        optiont(femail);
        break;
    case 4:
        cgpcal();
        optiont(femail);
        break;
    case 5:
        elect_cr();
        optiont(femail);
        break;
    case 6:
        printf("\n\t\tLogging out");
        for(int i=0;i<3;i++)
        {
            printf(".");
            Sleep(500);
        }
        login();
        break;
    default:
        printf("\n\n\t\t---Invalid choice---\n\n");
        printf("\t\tPress any key to continue...");
        getchar();
        optiont(femail);
    }
}

int gpcal()
{
    printf("\t\tGPA Calculator\n\n");
    int courses;
    printf("Enter the total number of courses: ");
    scanf("%d", &courses);
    float gp[courses][2];
    printf("Enter Grade point and CREDIT for each course: \n");
    printf("READ CARFULLY : GP and Credit have to be space separated. Otherwise it'll produce error.\n");
    printf("\n\t\tGP- Credit\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < courses; i++)
    {
        printf("\t\t");
        scanf("%f %f", &gp[i][0], &gp[i][1]);
        getchar();
        if (gp[i][0] > 4)
        {
            printf("Invalid input\n");
            printf("Press any key to continue...");
            getchar();
            return 0;
        }
    }
    float total_credit = 0;
    for (int i = 0; i < courses; i++)
    {
        total_credit += gp[i][1];
    }
    float score = 0;
    for (int i = 0; i < courses; i++)
    {
        score += gp[i][0] * gp[i][1];
    }
    float cg;
    cg = (float)score / (float)total_credit;
    if (cg > 4)
    {
        printf("Please give input carefully.\n");
    }
    else
        printf("THE GPA IS %.2f\n\n", cg);

    printf("Press any key to continue...");
    getchar();
    return 0;
}

int cgpcal()
{
    int n;
    printf("How many semesters?");
    scanf("%d", &n);
    getchar();
    float gp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &gp[i]);
        getchar();
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += gp[i];
    printf("The CGPA is : %.2f\n", sum / n);
    printf("\n\t\tPress any key to continue...");
    getchar();
    return 0;
}



int course_reg(char *fid)
{
    system("cls");
    system("color 0B");
    char sem[8], fsem[8];
    printf("\t\tCourse Registration for ID : %s\n\n", fid);
    printf("Enter the semester (Example: CSE 1-1): ");
    fgets(sem, sizeof(sem), stdin);
    sem[strcspn(sem, "\n")] = 0; // Remove the newline character
    getchar();

    //now add id and sem with a space between them
    char check[20];
    int j=0;
    for(int i=0;i<strlen(fid);i++)
    {
        check[j++]=fid[i];
    }
    check[j++]=' ';
    for(int i=0;i<strlen(sem);i++)
    {
        check[j++]=sem[i];
    }
    check[j++]='\n';
    check[j]='\0';

    fp=fopen("reginfo.txt","r");//check if it is already registered or not
    char fcheck[20];
    while (fgets(fcheck,sizeof(fcheck),fp) != NULL)
    {
        if (strcmp(check,fcheck)==0)
        {
            printf("\n\t\tYou are already registered for this semester.\n");
            printf("\n\t\tPress any key to continue...");
            getchar();
            fclose(fp);
            return 0;
        }

    }
    fclose(fp);

    fp = fopen("semester.txt", "r");
    while (fgets(fsem, sizeof(fsem), fp) != NULL)
    {
        fsem[strcspn(fsem, "\n")] = 0; // Remove the newline character
        if (strcmp(sem, fsem) == 0)
        {
            fclose(fp);
            fp = fopen("reginfo.txt","a");
            fprintf(fp,"%s %s\n",fid,sem);
            fclose(fp);
            printf("\n\t\tID %s is registered for %s\n", fid, fsem);
            printf("\n\t\tPress any key to continue...");
            getchar();
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    printf("\n\t\tSomething went wrong\n");
    printf("\n\t\tPress any key to continue...");
    getchar();

    return 0;
}


typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[MAX];
int candidates_count;

// Function prototypes
bool vote(char name[]);
void print_winner(void);
bool check_tie(int most_votes);
void reset_votes(void);

int elect_cr() {
    printf("Enter the number of candidates (max %d): ", MAX);
    scanf("%d", &candidates_count);

    if (candidates_count < 1 || candidates_count > MAX) {
        printf("Invalid number of candidates. Maximum is %d.\n", MAX);
       // Wait for user input to keep the console open
    printf("\nPress ENTER to continue...");
    getchar(); // Consume the newline left by the last input
    getchar(); // Wait for Enter key

        return 1;
    }

    for (int i = 0; i < candidates_count; i++) {
        printf("Enter name for candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    while (true) {
        int voters_count;
        printf("\nEnter the number of voters: ");
        scanf("%d", &voters_count);

        for (int i = 0; i < voters_count; i++) {
            char name[50];
            printf("Vote %d: ", i + 1);
            scanf("%s", name);

            if (!vote(name)) {
                printf("Invalid vote.\n");
            }
        }

        // Determine the highest votes
        int most_votes = 0;
        for (int i = 0; i < candidates_count; i++) {
            if (candidates[i].votes > most_votes) {
                most_votes = candidates[i].votes;
            }
        }

        // Check if there is a tie
        if (check_tie(most_votes)) {
            printf("\nThere is a tie. A re-election is required among the tied candidates.\n");

            // Retain only the tied candidates and reset their votes
            reset_votes();
        } else {
            // Print the winner(s) and exit the loop
            print_winner();
            break;
        }
    }

    // Wait for user input to keep the console open
    printf("\nPress ENTER to continue...");
    getchar(); // Consume the newline left by the last input
    getchar(); // Wait for Enter key

    return 0;
}

// Update vote totals given a new vote
bool vote(char name[]) {
    for (int i = 0; i < candidates_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner(s) of the election
void print_winner(void) {
    int most_votes = 0;

    for (int i = 0; i < candidates_count; i++) {
        if (candidates[i].votes > most_votes) {
            most_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidates_count; i++) {
        if (candidates[i].votes == most_votes) {
            printf("AND THE CR IS: %s\n", candidates[i].name);
        }
    }
}

// Check if there is a tie among candidates with the highest votes
bool check_tie(int most_votes) {
    int tie_count = 0;

    for (int i = 0; i < candidates_count; i++) {
        if (candidates[i].votes == most_votes) {
            tie_count++;
        }
    }

    // A tie occurs if more than one candidate has the highest votes
    return tie_count > 1;
}

// Reset the votes of all candidates for a re-election
void reset_votes(void) {
    for (int i = 0; i < candidates_count; i++) {
        candidates[i].votes = 0;
    }
}
