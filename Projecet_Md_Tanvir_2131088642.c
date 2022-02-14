
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int ID;
    char name[30];
    int age, number;
    char address[1000];
    char email[100];
    char book[100];
    char takingDate[15];
    char backedDate[15];
    char crime[50];
    char crimeAttemtedDate[15];
    char Punishment[50];
    char crimeDetails[1000];
}Students;


FILE *fp;
char a;
int idHolder;

void libraryManagement(void);
void studentCrime(void);
void infoUpdate(void);
void CreateNew(void);
void add(void);
void delete(void);
void display(void);
void updateLibrary(void);
void addLibrary(int);
void updateCrime(void);
void addCrime(void);

//-----------------------------------------------------Main funcion();

int main(){
    int n = -1;
    while(1){
        puts(""); puts(""); puts("");puts("");
        puts("\t\t\t1. Library info update.");
        puts("\t\t\t2. Crime info update.");
        puts("\t\t\t3. Update personal info (i.g: Name, age, number, .......");
        puts("\t\t\t4. Create new file overriding the existed information.");
        puts("\t\t\t5. Add new student to the file.");
        puts("\t\t\t6. Delete a student from the file.");
        puts("\t\t\t7. Display all the information of students.");
        puts("\t\t\t0. EXIT............");
        printf("\t\t\tWhat do you wish to do: ");
        scanf("%d", &n);
        
        switch(n){
            case 1: libraryManagement();
                break;
            case 2: studentCrime();
                break;
            case 3: infoUpdate();
                break;
            case 4: CreateNew();
                break;
            case 5: add();
                break;
            case 6: delete();
                break;
            case 7: display();
                break;
            case 0: {puts("\nExiting.....\n\n"); exit(1);}
                break;
        } // end switch
    } // end while
} // end main











void CreateNew (void){
    system ("clear");
    
    char decition;
    int n;
    
    puts("\n\n\n");
    puts("\t\t\tNew file will \"OVERRIDE\" the existed file.");
    printf("\t\t\tDo you want to continue(Y/N): ");
    scanf(" %c", &decition);
    
    if(decition == 'y' || decition == 'Y'){
        puts("\n");
        fp = fopen("Student.txt", "w");
        if (fp == NULL){
            system("clear");
            printf("\n\n\nFile error......\n\n\n");
            exit(1);
        }//end if
        puts("\t\t\tNew \"Student.txt\" file created");
        fclose(fp);
        add();                                              // CALLING ADD
    }// if
    else if(decition == 'N' || decition == 'n'){
        puts("\n\n\t\t\tWhat do you want if you don't want to create new file.");
        puts("\t\t\t1. Add student.");
        puts("\t\t\t2. Home page.");
        printf("\t\t\tYour choice: ");
        scanf("%d", &n);
        if(n == 1)
            add();                  // calling add
        else {
            system("clear");
            main();                 //calling main
        }// end else
    }// end else if
    else{
        system("clear");
        main();                     //  calling main
    }// end else
}// end function














void add (void){
    system("clear");
    Students s[100];
    int n;
    
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }   // end if
    
    puts(""); puts(""); puts("");puts("");
    printf("\t\t\tHow many student do you want to add: ");
    scanf("%d", &n);
    
    fp = fopen("Student.txt", "a");
    for(int i = 0; i<n; i++){
        printf("\n\t\t\t%d.Input ID: ", i+1);
        scanf("%d", &s[i].ID);
        fflush(stdin);
        printf("\t\t\t\tInput Name: ");
        scanf("%[^\n]s", s[i].name);
        fflush(stdin);
        printf("\t\t\t\tage: ");
        scanf("%d", &s[i].age);
        printf("\t\t\t\tInput personal number: ");
        scanf("%d", &s[i].number);
        fflush(stdin);
        printf("\t\t\t\tInput address: ");
        scanf("%[^\n]d", s[i].address);
        fflush(stdin);
        printf("\t\t\t\tInput the email: ");
        scanf("%[^\n]d", s[i].email);
        strcpy(s[i].book, "N/A");
        strcpy(s[i].takingDate, "N/A");
        strcpy(s[i].backedDate, "N/A");
        strcpy(s[i].crime, "N/A");
        strcpy(s[i].crimeAttemtedDate, "N/A");
        strcpy(s[i].Punishment, "N/A");
        strcpy(s[i].crimeDetails, "N/A");
        fwrite(&s[i], sizeof(Students), 1, fp);
    } // end for
    fclose(fp);
} // end main










void display(void){
    system("clear");
    puts(""); puts(""); puts("");puts("");
    Students s;
    fp = fopen("Student.txt", "r");
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }
    while(fread(&s, sizeof(Students), 1, fp)){
        printf("\t\t\tID: %d\n", s.ID);
        printf("\t\t\t\tName: %s\n", s.name);
        printf("\t\t\t\tage: %d\n", s.age);
        printf("\t\t\t\tNumber: %d\n", s.number);
        printf("\t\t\t\tEmail: %s\n", s.email);
        printf("\t\t\t\tAddress: %s\n", s.address);
        printf("\t\t\t\tBorrowed Book: %s\n", s.book);
        printf("\t\t\t\tDate of taking: %s\n", s.takingDate);
        printf("\t\t\t\tDate of giving back: %s\n", s.backedDate);
        printf("\t\t\t\tCommitated crime: %s\n", s.crime);
        printf("\t\t\t\tCommiting Date: %s\n", s.crimeAttemtedDate);
        printf("\t\t\t\tCrime punishment: %s\n", s.Punishment);
        printf("\t\t\t\tCrime Details: %s\n", s.crimeDetails);
    }
    fclose(fp);
}



void infoUpdate (void){
    system("clear");
    puts(""); puts(""); puts("");puts("");
    Students s;;
    int id,found = 0;
    FILE *fp1;
    fp = fopen("Student.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }
    printf("\t\t\tInput ID To update: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(Students), 1, fp)){
        if(s.ID == id){
            found = 1;
            printf("\t\t\tID: %d\n", s.ID);
            printf("\t\t\t\tName: %s\n", s.name);
            printf("\t\t\t\tage: %d\n", s.age);
            printf("\t\t\t\tNumber: %d\n", s.number);
            printf("\t\t\t\tEmail: %s\n", s.email);
            printf("\t\t\t\tAddress: %s\n", s.address);
            printf("\t\t\t\tBorrowed Book: %s\n", s.book);
            printf("\t\t\t\tDate of taking: %s\n", s.takingDate);
            printf("\t\t\t\tDate of giving back: %s\n", s.backedDate);
            printf("\t\t\t\tCommitated crime: %s\n", s.crime);
            printf("\t\t\t\tCommiting Date: %s\n", s.crimeAttemtedDate);
            printf("\t\t\t\tCrime punishment: %s\n", s.Punishment);
            printf("\t\t\t\tCrime Details: %s\n", s.crimeDetails);
            
            
            
            
            fflush(stdin);
            printf("\t\t\t\tInput Name: ");
            scanf("%[^\n]s", s.name);
            fflush(stdin);
            printf("\t\t\t\tage: ");
            scanf("%d", &s.age);
            printf("\t\t\t\tInput personal number: ");
            scanf("%d", &s.number);
            fflush(stdin);
            printf("\t\t\t\tInput address: ");
            scanf("%[^\n]d", s.address);
            fflush(stdin);
            printf("\t\t\t\tInput the email: ");
            scanf("%[^\n]d", s.email);
        }
            
        fwrite(&s, sizeof(Students), 1, fp1);
        }
    fclose(fp);
    fclose(fp1);
    if(!found)
        printf("\t\t\tInformation not found");
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("Student.txt","w");
        while(fread(&s, sizeof(Students), 1, fp1)){
            fwrite(&s, sizeof(Students), 1, fp);
        }
    }
    fclose(fp);
}


void delete (void){
    system("clear");
    puts(""); puts(""); puts("");puts("");
    Students s;;
    int id,found = 0;
    FILE *fp1;
    fp = fopen("Student.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }
    printf("\t\t\tInput ID To Delete: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(Students), 1, fp)){
        if(s.ID == id){
            found = 1;
        } else
            fwrite(&s, sizeof(Students), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(!found)
        printf("\t\t\tInformation not found");
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("Student.txt","w");
        while(fread(&s, sizeof(Students), 1, fp1)){
            fwrite(&s, sizeof(Students), 1, fp);
        }
    }
    fclose(fp);
}




void libraryManagement(void){
    
    system("clear");
    puts(""); puts(""); puts("");puts("");
    Students s;;
    int id,found = 0;
    FILE *fp1;
    fp = fopen("Student.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }
    printf("\t\t\tInput ID To update library info: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(Students), 1, fp)){
        if(s.ID == id){
            found = 1;
            printf("\t\t\tID: %d\n", s.ID);
            printf("\t\t\t\tName: %s\n", s.name);
            printf("\t\t\t\tage: %d\n", s.age);
            printf("\t\t\t\tNumber: %d\n", s.number);
            printf("\t\t\t\tEmail: %s\n", s.email);
            printf("\t\t\t\tAddress: %s\n", s.address);
            printf("\t\t\t\tBorrowed Book: %s\n", s.book);
            printf("\t\t\t\tDate of taking: %s\n", s.takingDate);
            printf("\t\t\t\tDate of giving back: %s\n", s.backedDate);
            printf("\t\t\t\tCommitated crime: %s\n", s.crime);
            printf("\t\t\t\tCommiting Date: %s\n", s.crimeAttemtedDate);
            printf("\t\t\t\tCrime punishment: %s\n", s.Punishment);
            printf("\t\t\t\tCrime Details: %s\n", s.crimeDetails);
            
            
            
            
            puts("");
            fflush(stdin);
            printf("\t\t\t\tInput borrowed book name(N for N/A): ");
            scanf("%[^\n]d", s.book);
            if(strcmp(s.book, "n") == 0 || strcmp(s.book, "N") == 0){
                strcpy(s.book, "N/A");
                strcpy(s.takingDate, "N/A");
                strcpy(s.backedDate, "N/A");
            }
            else{
                fflush(stdin);
                printf("\t\t\t\t\tInput book taking date (DD/MM/YY): ");
                scanf("%[^\n]d", s.takingDate);
                fflush(stdin);
                printf("\t\t\t\t\tInput the date of giving date (DD/MM/YY): ");
                scanf("%[^\n]d", s.backedDate);
            }
        }
        fwrite(&s, sizeof(Students), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(!found)
        printf("\t\t\tInformation not found");
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("Student.txt","w");
        while(fread(&s, sizeof(Students), 1, fp1)){
            fwrite(&s, sizeof(Students), 1, fp);
        }
    }
    fclose(fp);
}







void studentCrime(void){
    
    system("clear");
    puts(""); puts(""); puts("");puts("");
    Students s;;
    int id,found = 0;
    FILE *fp1;
    fp = fopen("Student.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if(fp == NULL){
        printf("\n\nFile error.....\n\n\n");
        exit(1);
    }
    printf("\t\t\tInput ID update student crime info: ");
    scanf("%d", &id);
    while(fread(&s, sizeof(Students), 1, fp)){
        if(s.ID == id){
            found = 1;
            printf("\t\t\tID: %d\n", s.ID);
            printf("\t\t\t\tName: %s\n", s.name);
            printf("\t\t\t\tage: %d\n", s.age);
            printf("\t\t\t\tNumber: %d\n", s.number);
            printf("\t\t\t\tEmail: %s\n", s.email);
            printf("\t\t\t\tAddress: %s\n", s.address);
            printf("\t\t\t\tBorrowed Book: %s\n", s.book);
            printf("\t\t\t\tDate of taking: %s\n", s.takingDate);
            printf("\t\t\t\tDate of giving back: %s\n", s.backedDate);
            printf("\t\t\t\tCommitated crime: %s\n", s.crime);
            printf("\t\t\t\tCommiting Date: %s\n", s.crimeAttemtedDate);
            printf("\t\t\t\tCrime punishment: %s\n", s.Punishment);
            printf("\t\t\t\tCrime Details: %s\n", s.crimeDetails);
            
            
            
            puts("");
            fflush(stdin);
            printf("\t\t\t\tInput attemted crime name (N for N/A): ");
            scanf("%[^\n]s", s.crime);
            if(strcmp(s.crime, "n") == 0 || strcmp(s.crime,"N") == 0){
                strcpy(s.crime, "N/A");
                strcpy(s.crimeAttemtedDate, "N/A");
                strcpy(s.Punishment, "N/A");
                strcpy(s.crimeDetails, "N/A");
            }
            else{
                fflush(stdin);
                printf("\t\t\t\tAttemted Date: ");
                scanf("%[^\n]s", s.crimeAttemtedDate);
                fflush(stdin);
                printf("\t\t\t\tpunishment: ");
                scanf("%[^\n]s", s.Punishment);
                fflush(stdin);
                printf("\t\t\t\tCrime details (N for N/A): ");
                scanf("%[^\n]s", s.crimeDetails);
            }
            
        }
        fwrite(&s, sizeof(Students), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(!found)
        printf("\t\t\tInformation not found");
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("Student.txt","w");
        while(fread(&s, sizeof(Students), 1, fp1)){
            fwrite(&s, sizeof(Students), 1, fp);
        }
    }
    fclose(fp);
    
}
