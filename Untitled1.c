#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void password();
void heading();
void mainmenu();
void addDonor();
void searchByBloodType();
void recordDonation();
void viewBloodStock();
void saveDataToFile();
void loadDataFromFile();


struct Donor{
    char name[100];
    char bloodType[9];
    char contactInfo[100];
    int availability;
};
struct Donor donors[1000];
int donorCount=0;
int bloodStock[8]={0,0,0,0,0,0,0,0};

int d=1;

int main()
{
    loadDataFromFile();
    password();
}

void password()
{
    heading();
    char p1[10]="admin";
    char p2[10];
    printf("\n\n\t\t\t\t\t\tEnter Password: ");
    gets(p2);
    if(strcmp(p1,p2)==0)
        {
            printf("\n\n\t\t\t\t\t\t  \033[1;32mPassword Matched\033[0m\n");
            printf("\n\t\t\t\t\t     Press any key to continue...");
        }
    else
        {
            if(d==3)
            {
                exit(0);
            }
            printf("\n\n\t\t\t\t\t\t\033[1;31mWrong Password! %d\033[0m to 3\n",d);
            printf("\n\n\t\t\t\t\t\t      Try again");
            d++;
            getchar();
            password();
        }
    fflush(stdin);
    getchar();
    mainmenu();
}

void heading()
{
    system("cls");
    printf("\n\n\t\t\t\t    \033[1;33mWelcome to Red Crescent Blood Center, Dhaka-1212\033[0m\n");
}

void mainmenu()
{
    system("cls");
    int cn;
    printf("\n\n\t\t\t\t\t\tMain Menu\n");
    printf("\n\t\t\t\t1.Add New Donor\n");
    printf("\n\t\t\t\t2.Search Donor by Blood Type\n");
    printf("\n\t\t\t\t3.Record Blood Donation\n");
    printf("\n\t\t\t\t4.View Blood Stock\n");
    printf("\n\t\t\t\t5.Save Data to File\n");
    printf("\n\t\t\t\t6.Exit\n");
    printf("\n");
    printf("\t\t\t\t\t  Choose an option: ");
    scanf("%d",&cn);
    if(cn==1)
    {
        addDonor();
    }
    else if(cn==2)
    {
        searchByBloodType();
    }
    else if(cn==3)
    {
        recordDonation();
    }
    else if(cn==4)
    {
        viewBloodStock();
    }
    else if(cn==5)
    {
        saveDataToFile();
    }
    else if(cn==6)
    {
        printf("\t\t\t\t\t  Exiting the system...\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t\t\t    \033[1;31mWrong Choice...!\033[0m\n");
        printf("\n\t\t\t\t\t      Try again...\n");
        fflush(stdin);
        getchar();
        mainmenu();
    }
}

void addDonor()
{
    system("cls");
    if (donorCount >=1000)
    {
        printf("Donor list is full.\n");
        return;
    }
    struct Donor newDonor;

    printf("\n\n\t\t\t\t\t\tDonor Information Menu\n");

    printf("\n\t\t\tDonor's Name: ");
    fflush(stdin);
    gets(newDonor.name);

    printf("\n\t\t\tDonor's Blood type (A+,A-,B+,B-,AB+,AB-,O+,O-): ");
    fflush(stdin);
    gets(newDonor.bloodType);

    printf("\n\t\t\tContact: ");
    fflush(stdin);
    gets(newDonor.contactInfo);

    printf("\n\t\t\tIs the donor available? 1 for Yes, 0 for No: ");
    scanf("%d",&newDonor.availability);

    donors[donorCount++] = newDonor;
    printf("\n\n\t\t\t\t\t      Donor added successfully...\n");

    fflush(stdin);
    getchar();
    mainmenu();
}

void searchByBloodType()
{
    system("cls");
    char bloodType[9];
    printf("\n\n\t\t\tEnter the blood type you want to search for (A+,A-,B+,B-,AB+,AB-,O+,O-): ");
    fflush(stdin);
    gets(bloodType);

    printf("\n\t\t\t\t\t   Search Results for Blood Type %s:\n",bloodType);
    printf("\n\t\t\t\t    Name\t    Contact\t\tAvailability\n");
    printf("\n\t\t\t\t--------------------------------------------------------\n");

    int found=0;
    for(int i = 0;i<donorCount;i++)
    {
        if(strcmp(donors[i].bloodType,bloodType)==0)
        {
            printf("\n\t\t\t\t    %s\t  %s\t\t %s\n",donors[i].name,donors[i].contactInfo,donors[i].availability ? "Available" : "Not Available");
            found=1;
        }
    }
    if(!found)
    {
        printf("\n\t\t\t\t   No donors found for the specified blood type...\n");
    }

    fflush(stdin);
    getchar();
    mainmenu();
}

void recordDonation()
{
    system("cls");
    char bloodType[9];
    printf("\n\n\t\t\t   Enter blood type of the donation (A+,A-,B+,B-,AB+,AB-,O+,O-): ");
    fflush(stdin);
    gets(bloodType);

    if(strcmp(bloodType,"A+")==0)
    {
        bloodStock[0]++;
    }
    else if (strcmp(bloodType,"A-") == 0)
    {
        bloodStock[1]++;
    }
    else if (strcmp(bloodType,"B+") == 0)
    {
        bloodStock[2]++;
    }
    else if (strcmp(bloodType,"B-") == 0)
    {
        bloodStock[3]++;
    }
    else if (strcmp(bloodType,"AB+") == 0)
    {
        bloodStock[4]++;
    }
    else if (strcmp(bloodType,"AB-") == 0)
    {
        bloodStock[5]++;
    }
    else if (strcmp(bloodType,"O+") == 0)
    {
        bloodStock[6]++;
    }
    else if (strcmp(bloodType,"O-") == 0)
    {
        bloodStock[7]++;
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tInvalid blood type...\n");
        return;
    }
    printf("\n\n\t\t\t\t     Blood donation recorded for blood type %s.\n", bloodType);

    fflush(stdin);
    getchar();
    mainmenu();
}

void viewBloodStock()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\tCurrent Blood Stock:\n");
    printf("\n\t\t\t\tBlood Type A+: %d\n", bloodStock[0]);
    printf("\n\t\t\t\tBlood Type A-: %d\n", bloodStock[1]);
    printf("\n\t\t\t\tBlood Type B+: %d\n", bloodStock[2]);
    printf("\n\t\t\t\tBlood Type B-: %d\n", bloodStock[3]);
    printf("\n\t\t\t\tBlood Type AB+: %d\n", bloodStock[4]);
    printf("\n\t\t\t\tBlood Type AB-: %d\n", bloodStock[5]);
    printf("\n\t\t\t\tBlood Type O+: %d\n", bloodStock[6]);
    printf("\n\t\t\t\tBlood Type O-: %d\n", bloodStock[7]);

    fflush(stdin);
    getchar();
    mainmenu();
}

void saveDataToFile()
{
    FILE *file = fopen("blood_donation_data.txt","w");

    if(file==NULL)
    {
        printf("\n\t\t\t\t\t\tError opening file for saving data...\n");
        return;
    }

    fprintf(file,"No of Donors: %d\n",donorCount);
    fprintf(file,"Name     Blood type     Contact     Availability\n");
    for(int i=0;i<donorCount;i++)
    {
        fprintf(file,"%s          %s      %s         %d\n",donors[i].name, donors[i].bloodType, donors[i].contactInfo, donors[i].availability);
        printf("\n");
    }

    printf("\n");
    fprintf(file,"A+  = %d\n",bloodStock[0]);
    fprintf(file,"A-  = %d\n",bloodStock[1]);
    fprintf(file,"B+  = %d\n",bloodStock[2]);
    fprintf(file,"B-  = %d\n",bloodStock[3]);
    fprintf(file,"AB+ = %d\n",bloodStock[4]);
    fprintf(file,"AB- = %d\n",bloodStock[5]);
    fprintf(file,"O+  = %d\n",bloodStock[6]);
    fprintf(file,"O-  = %d\n",bloodStock[7]);

    fclose(file);
    printf("\n\t\t\t\t   Data has been saved successfully!\n");

    fflush(stdin);
    getchar();
    mainmenu();
}

void loadDataFromFile()
{
    FILE *file=fopen("blood_donation_data.txt","r");

    if (file == NULL)
    {
        printf("\n\t\t\t\t\t\tNo previous data found.\n");
        return;
    }

    fscanf(file,"%d",&donorCount);

    for(int i =0;i< donorCount;i++)
    {
        fscanf(file, "%s", donors[i].name);
        fscanf(file, "%s", donors[i].bloodType);
        fscanf(file, "%s", donors[i].contactInfo);
        fscanf(file, "%d", &donors[i].availability);
    }

    for (int i=0;i<8;i++)
    {
        fscanf(file,"%d",&bloodStock[i]);
    }

    fclose(file);
    printf("\n\t\t\t\t\t\tData loaded successfully.\n");
}
