#include<stdio.h>
#include<string.h>
#include<windows.h>


char filename[]="householdersignup.txt";
int number_of_accounts;
struct login
{
    char id[50],pass[50];
};
struct login loginInfo[10000];
struct signup
{
    char id[100], password[20];
};

int number_of_householder;
struct signup signuplist[10000];
int i;
struct area
{

    char address[100],mobile[25],extrainfo[250],holding_number[25];
    int bedrooms,bathrooms, floor,rent;

};
struct area houselist[10000];
int noh,f=0;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

int main()
{

            gotoxy(35,12);printf("TTTTT   OOO      L     EEEE  TTTTT\n");
            gotoxy(35,13);printf("  T    O   O     L     E       T  \n");
            gotoxy(35,14);printf("  T   O     O ~  L     EEE     T  \n");
            gotoxy(35,15);printf("  T    O   O     L     E       T  \n");
            gotoxy(35,16);printf("  T     OOO      LLLL  EEEE    T  \n");
            gotoxy(42,18);printf("Your Stop To Find Home");
            gotoxy(48,19);printf("Loading");

            for(i=0;i<15;i++){

                    gotoxy(55,19);
                    printf("...");fflush(stdout);
                    Sleep(100);
                    gotoxy(55,19);
                    printf("   ");fflush(stdout);
                    Sleep(100);
       }
        Sleep(800);
        system("cls");
        int opt;
        while(1)
        {
        gotoxy(30,8);printf("---Menu---\n");
        gotoxy(30,10);printf("1. House Holder\n");
        gotoxy(30,12);printf("2. House Seeker\n");
        gotoxy(30,14);printf("3. About\n");
        gotoxy(30,16);printf("4. Exit Program\n");
        gotoxy(30,18);printf("Select Option: ");
        scanf("%d", &opt);
        system("cls");

        if(opt == 1)
        {
            while(1)
            {
                ///House Holder
                gotoxy(30,8);printf("---House Holder---\n");
                gotoxy(30,10);printf("1. Login\n");
                gotoxy(30,12);printf("2. Sign up\n");
                gotoxy(30,14);printf("3. Back\n");
                gotoxy(30,16);printf("Select Option: ");
                scanf("%d", &opt);
                system("cls");
                if(opt == 1)
                {
                    ///Login

                    FILE *fr,*fw;
                    fr=fopen(filename,"r");
                    if(fr==0)
                    {
                        fw=fopen(filename,"w");
                        fclose(fw);
                    }
                    fclose(fr);
                    char idInput[50],passInput[50];
                    gotoxy(30,8);printf("---Login to your account---\n");
                    gotoxy(30,10);printf("1. Enter your id: ");
                    scanf("\n%[^\n]",idInput);
                    gotoxy(30,12);printf("2. Enter your password: ");
                    scanf("%s",passInput);
                    int i=0;
                    FILE *fin=fopen(filename,"r");
                    while(fscanf(fin,"\n%[^\n]",loginInfo[i].id)==1)
                    {
                        fscanf(fin," %[^\n]",loginInfo[i].pass);
                        i++;
                    }
                    number_of_accounts=i;
                    fclose(fin);
                    int idcom,passcom,f=0;
                    for(i=0; i<number_of_accounts; i++)
                    {
                        idcom=strcmp(loginInfo[i].id,idInput);
                        passcom=strcmp(loginInfo[i].pass,passInput);
                        if(idcom==0 && passcom==0)
                        {
                            f=1;
                            break;
                        }
                    }
                    if(f==1)
                    {
                        printf("\033[1;32m");
                        gotoxy(30,14);printf("Access Granted\n");
                        printf("\033[0m");
                        Sleep(1000);
                        while(1)
                        {

                            system("cls");
                            gotoxy(30,8);printf("---Home Owner---\n");
                            gotoxy(30,10);printf("1.Add new House\n");
                            gotoxy(30,12);printf("2.Delete Existing\n");
                            gotoxy(30,14);printf("3.Back\n");
                            gotoxy(30,16);printf("Select Option: ");
                            scanf("%d", &opt);
                            system("cls");

                            if(opt == 1)
                            {
                                ///Add New House
                                gotoxy(30,8);printf("---Select the area of your house:---\n");

                                gotoxy(30,10);printf("1.Chandgaon R/A\n");
                                gotoxy(30,12);printf("2.Nasirabad\n");
                                gotoxy(30,14);printf("New Areas Coming soon.....");
                                gotoxy(30,16);printf("Select Option: ");
                                scanf("%d",&opt);
                                system("cls");

                                if(opt == 1)
                                {
                                    ///AddHouse-->Chandgaon
                                    ///Fileopen --- read --- stdList array ----add---write


                                    FILE *area= fopen("chandgaon.txt", "r");
                                    if(area==0)
                                    {
                                        area=fopen("chandgaon.txt","w");
                                        fclose(area);
                                    }
                                    else if(area != 0)
                                    {
                                        int i = 0, j;
                                        while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                                        {

                                            fscanf(area, "%s", houselist[i].holding_number);
                                            fscanf(area, "%d", &houselist[i].bedrooms);
                                            fscanf(area, "%d", &houselist[i].bathrooms);
                                            fscanf(area, "%d", &houselist[i].floor);
                                            fscanf(area, "%d", &houselist[i].rent);
                                            fscanf(area, "%s", houselist[i].mobile);
                                            fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                            i++;
                                        }
                                        noh = i;

                                    }
                                    fclose(area);

                                    ///add new------>array
                                    struct area a;
                                    int i, j;
                                    gotoxy(30,4);printf("---Add new House---\n");
                                    gotoxy(30,6);printf("Enter Address: ");
                                    scanf("\n%[^\n]", a.address);
                                    gotoxy(30,8);printf("Enter Holding Number: ");
                                    scanf("\n%[^\n]", a.holding_number);
                                    gotoxy(30,10);printf("Enter bedrooms: ");
                                    scanf("%d", &a.bedrooms);
                                    gotoxy(30,12);printf("Enter bathrooms: ");
                                    scanf("%d", &a.bathrooms);
                                    gotoxy(30,14);printf("Enter floor: ");
                                    scanf("%d", &a.floor);
                                    gotoxy(30,16);printf("Enter Monthly Rent: ");
                                    scanf("%d",&a.rent);
                                    gotoxy(30,18);printf("Enter Mobile: ");
                                    scanf(" %s", a.mobile);
                                    gotoxy(30,20);printf("Enter Extra info: ");
                                    scanf("\n%[^\n]", a.extrainfo);


                                    houselist[noh] = a;
                                    noh++;

                                    ///array -------------write

                                    FILE *areaAdd = fopen("chandgaon.txt","w");
                                    for(i = 0; i < noh; i++)
                                    {

                                        fprintf(areaAdd, "%s\n", houselist[i].address);
                                        fprintf(areaAdd, "%s\n", houselist[i].holding_number);
                                        fprintf(areaAdd, "%d\n", houselist[i].bedrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].bathrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].floor);
                                        fprintf(areaAdd, "%d\n", houselist[i].rent);
                                        fprintf(areaAdd, "%s\n", houselist[i].mobile);
                                        fprintf(areaAdd, "%s\n", houselist[i].extrainfo);

                                    }
                                    fclose(areaAdd);
                                }
                                else if(opt==2)
                                {
                                    ///AddHouse--> Nasirabad

                                    ///Fileopen --- read --- stdList array ----add---write


                                    FILE *area= fopen("nasirabad.txt", "r");
                                    if(area==0)
                                    {
                                        area=fopen("nasirabad.txt","w");
                                        fclose(area);
                                    }
                                    else if(area != 0)
                                    {
                                        int i = 0, j;
                                        while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                                        {
                                            fscanf(area, "%s", houselist[i].holding_number);
                                            fscanf(area, "%d", &houselist[i].bedrooms);
                                            fscanf(area, "%d", &houselist[i].bathrooms);
                                            fscanf(area, "%d", &houselist[i].floor);
                                            fscanf(area, "%d", &houselist[i].rent);
                                            fscanf(area, "%s", houselist[i].mobile);
                                            fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                            i++;
                                        }
                                        noh = i;


                                    }
                                    fclose(area);

                                    ///add new------>array
                                    struct area a, temp;
                                    int i, j;
                                    gotoxy(30,4);printf("---Add new House---\n");
                                    gotoxy(30,6);printf("Enter Address: ");
                                    scanf("\n%[^\n]", a.address);
                                    gotoxy(30,8);printf("Enter Holding Number: ");
                                    scanf("\n%[^\n]", a.holding_number);
                                    gotoxy(30,10);printf("Enter bedrooms: ");
                                    scanf("%d", &a.bedrooms);
                                    gotoxy(30,12);printf("Enter bathrooms: ");
                                    scanf("%d", &a.bathrooms);
                                    gotoxy(30,14);printf("Enter floor: ");
                                    scanf("%d", &a.floor);
                                    gotoxy(30,16);printf("Enter Monthly Rent: ");
                                    scanf("%d",&a.rent);
                                    gotoxy(30,18);printf("Enter Mobile: ");
                                    scanf(" %s", a.mobile);
                                    gotoxy(30,20);printf("Enter Extra info: ");
                                    scanf("\n%[^\n]", a.extrainfo);


                                    houselist[noh] = a;
                                    noh++;

                                    ///array -------------write

                                    FILE *areaAdd = fopen("nasirabad.txt","w");
                                    for(i = 0; i < noh; i++)
                                    {

                                        fprintf(areaAdd, "%s\n", houselist[i].address);
                                        fprintf(areaAdd, "%s\n", houselist[i].holding_number);
                                        fprintf(areaAdd, "%d\n", houselist[i].bedrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].bathrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].floor);
                                        fprintf(areaAdd, "%d\n", houselist[i].rent);
                                        fprintf(areaAdd, "%s\n", houselist[i].mobile);
                                        fprintf(areaAdd, "%s\n", houselist[i].extrainfo);

                                    }

                                    fclose(areaAdd);

                                }

                                printf("\033[1;32m");
                                gotoxy(30,22);printf("Successfully Added\n");
                                printf("\033[0m");


                                gotoxy(30,24);printf("Press any key to continue...");
                                getchar();
                                getchar();
                            }

                            else if(opt==2)
                            {
                                ///Delete Existing House

                                gotoxy(30,8);printf("---Delete---\n");
                                gotoxy(30,10);printf("AREAS: \n");
                                gotoxy(30,12);printf("1.Chandgaon R/A\n");
                                gotoxy(30,14);printf("2.Nasirabad\n");
                                gotoxy(30,16);printf("New Areas Coming Soon......\n");
                                gotoxy(30,18);printf("Select Area: ");
                                scanf("%d",&opt);
                                system("cls");

                                if(opt == 1)
                                {
                                    FILE *area= fopen("chandgaon.txt", "r");
                                    if(area==0)
                                    {
                                        area=fopen("chandgaon.txt","w");
                                        fclose(area);
                                    }
                                    else if(area != 0)
                                    {
                                        int i = 0, j;
                                        while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                                        {

                                            fscanf(area, "%s", houselist[i].holding_number);
                                            fscanf(area, "%d", &houselist[i].bedrooms);
                                            fscanf(area, "%d", &houselist[i].bathrooms);
                                            fscanf(area, "%d", &houselist[i].floor);
                                            fscanf(area, "%d", &houselist[i].rent);
                                            fscanf(area, "%s", houselist[i].mobile);
                                            fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                            i++;
                                        }
                                        noh = i;
                                        fclose(area);
                                    }

                                    int i, j, holding_num[20], pos = -1;
                                    gotoxy(30,14);printf("Enter Holding Number: ");
                                    scanf("%s",holding_num);

                                    for(i = 0; i < noh; i++)
                                    {


                                        if(strcmp(houselist[i].holding_number,holding_num)==0)
                                        {
                                            pos = i;
                                            break;
                                        }
                                    }

                                    for(i = pos + 1; i < noh; i++)
                                    {
                                        houselist[i - 1] = houselist[i];
                                    }

                                    if(pos != -1)
                                    {
                                        noh--;
                                    }
                                    FILE *areaAdd = fopen("chandgaon.txt","w");
                                    for(i = 0; i < noh; i++)
                                    {

                                        fprintf(areaAdd, "%s\n", houselist[i].address);
                                        fprintf(areaAdd, "%s\n", houselist[i].holding_number);
                                        fprintf(areaAdd, "%d\n", houselist[i].bedrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].bathrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].floor);
                                        fprintf(areaAdd, "%d\n", houselist[i].rent);
                                        fprintf(areaAdd, "%s\n", houselist[i].mobile);
                                        fprintf(areaAdd, "%s\n", houselist[i].extrainfo);

                                    }
                                    fclose(areaAdd);
                                if(pos==-1){
                                    printf("\033[1;31m");
                                    gotoxy(30,18);printf("No Match Found!\n");
                                    printf("\033[0m");

                                }else {
                                printf("\033[1;32m");
                                gotoxy(30,18);printf("Successfully Deleted\n");
                                printf("\033[0m");

                                }

                                }
                                else if(opt == 2)
                                {
                                    FILE *area= fopen("nasirabad.txt", "r");
                                    if(area==0)
                                    {
                                        area=fopen("nasirabad.txt","w");
                                        fclose(area);
                                    }
                                    else if(area != 0)
                                    {
                                        int i = 0, j;
                                        while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                                        {

                                            fscanf(area, "%s", houselist[i].holding_number);
                                            fscanf(area, "%d", &houselist[i].bedrooms);
                                            fscanf(area, "%d", &houselist[i].bathrooms);
                                            fscanf(area, "%d", &houselist[i].floor);
                                            fscanf(area, "%d", &houselist[i].rent);
                                            fscanf(area, "%s", houselist[i].mobile);
                                            fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                            i++;
                                        }
                                        noh = i;
                                        fclose(area);
                                    }


                                    int i, j, holding_num[20], pos = -1;
                                    gotoxy(30,14);printf("Enter Holding Number: ");
                                    scanf("%s",holding_num);

                                    for(i = 0; i < noh; i++)
                                    {


                                        if(strcmp(houselist[i].holding_number,holding_num)==0)
                                        {
                                            pos = i;
                                            break;
                                        }
                                    }

                                    for(i = pos + 1; i < noh; i++)
                                    {
                                        houselist[i - 1] = houselist[i];
                                    }

                                    if(pos != -1)
                                    {
                                        noh--;
                                    }
                                    FILE *areaAdd = fopen("nasirabad.txt","w");
                                    for(i = 0; i < noh; i++)
                                    {

                                        fprintf(areaAdd, "%s\n", houselist[i].address);
                                        fprintf(areaAdd, "%s\n", houselist[i].holding_number);
                                        fprintf(areaAdd, "%d\n", houselist[i].bedrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].bathrooms);
                                        fprintf(areaAdd, "%d\n", houselist[i].floor);
                                        fprintf(areaAdd, "%d\n", houselist[i].rent);
                                        fprintf(areaAdd, "%s\n", houselist[i].mobile);
                                        fprintf(areaAdd, "%s\n", houselist[i].extrainfo);

                                    }
                                    fclose(areaAdd);
                                }
                                else if(opt == 3)
                                {
                                    break;
                                }


                                gotoxy(30,20);printf("Press any key to continue...");
                                getchar();
                                getchar();


                            }
                            else if(opt==3)
                                {
                                    ///Back
                                    break;
                                }

                            else
                                {
                                    printf("\033[1;31m");
                                    gotoxy(30,14);printf("Invalid Input!!\n");
                                    printf("\033[0m");
                                    Sleep(700);
                                    system("cls");
                                }

                        }
                    }
                    else
                    {
                        printf("\033[1;31m");
                        gotoxy(30,14);printf("Account Not Found!!\n");
                        printf("\033[0m");

                        Sleep(700);
                        system("cls");
                    }
                }
                else if(opt == 2)
                {
                    ///Sign up----->read file---->copy in array--->write file

                    ///read
                    FILE *sup = fopen(filename, "r");
                    if(sup == 0)
                    {
                        sup = fopen(filename, "w");
                        fclose(sup);
                    }

                    else if(sup != 0)
                    {
                        int i = 0;
                        while(fscanf(sup, "\n%[^\n]",signuplist[i].id)==1)
                        {
                            fscanf(sup, "\n%[^\n]",signuplist[i].password);
                            i++;
                        }
                        number_of_householder = i;
                    }
                    fclose(sup);


                    struct signup a ;

                    gotoxy(30,14);printf(" ---Sign Up---\n");
                    gotoxy(30,16);printf("Enter your ID: ");
                    scanf("\n%[^\n]",a.id);
                    gotoxy(30,18);printf("Enter your password: ");
                    scanf("\n%[^\n]",a.password);

                    signuplist[number_of_householder] = a;
                    number_of_householder++;

                    ///array-->write
                    FILE *fout = fopen(filename, "w");
                    for (i = 0; i < number_of_householder; i++)
                    {
                        fprintf(fout, "%s\n", signuplist[i].id);
                        fprintf(fout, "%s\n", signuplist[i].password);
                    }
                    fclose(fout);
                    system("cls");
                    printf("\033[1;32m");
                    gotoxy(30,14);printf("Account created successfully!\n");
                    printf("\033[0m");
                    Sleep(1000);
                    system("cls");


                }
                else if(opt == 3)
                {
                    break;
                }
                else
                {
                    printf("\033[1;31m");
                    gotoxy(30,14);printf("Invalid Input!\n");
                    printf("\033[0m");
                    Sleep(1000);
                    system("cls");
                }
            }
        }

        else if(opt == 2)
        {
            while(1)
            {
                gotoxy(30,8);printf(" ---House Seeker---\n");
                gotoxy(30,10);printf("1. Select Area.\n");
                gotoxy(30,12);printf("2. Search.\n");
                gotoxy(30,14);printf("3. Back\n");
                gotoxy(30,16);printf("Select Option: ");
                scanf("%d",&opt);
                system("cls");

                if(opt==1)
                {
                    ///Show Houses inside an area

                    gotoxy(30,8);printf("---Select the area for house:---\n");

                    gotoxy(30,12);printf("1.Chandgaon R/A\n");
                    gotoxy(30,14);printf("2.Nasirabad\n");
                    gotoxy(30,16);printf("3.Back");
                    gotoxy(30,18);printf("New Area Coming Soon.......\n");
                    gotoxy(30,20);printf("Select Option: ");
                    scanf("%d",&opt);
                    printf("\n");
                    system("cls");

                    if(opt == 1)
                    {
                        //Fileopen --- read --- array------show


                        FILE *area= fopen("chandgaon.txt", "r");
                        if(area==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,14);printf("No House Is Vacant\n");
                            printf("\033[0m");

                        }
                        else if(area != 0)
                        {
                            int i = 0, j;
                            while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                            {

                                fscanf(area, "%s", houselist[i].holding_number);
                                fscanf(area, "%d", &houselist[i].bedrooms);
                                fscanf(area, "%d", &houselist[i].bathrooms);
                                fscanf(area, "%d", &houselist[i].floor);
                                fscanf(area, "%d", &houselist[i].rent);
                                fscanf(area, "%s", houselist[i].mobile);
                                fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                i++;
                            }
                            noh = i;

                        }
                        fclose(area);

                        ///show in monitor
                        for(i=0 ; i < noh ; i++)
                        {
                            printf("Address: %s\n", houselist[i].address);
                            printf("Bedrooms: %d\n", houselist[i].bedrooms);
                            printf("Bathrooms: %d\n", houselist[i].bathrooms);
                            printf("Floor: %d\n", houselist[i].floor);
                            printf("Rent: %d\n", houselist[i].rent);
                            printf("Mobile: %s\n", houselist[i].mobile);
                            printf("Extra Info: %s\n", houselist[i].extrainfo);

                            printf("\n");


                        }
                    printf("Press any key to continue...");
                    getchar();
                    getchar();

                    system("cls");

                    }
                    else if(opt == 2)
                    {
                        FILE *area= fopen("nasirabad.txt", "r");
                        if(area==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,14);printf("No House Is Vacant\n");
                            printf("\033[0m");

                        }
                        else if(area != 0)
                        {
                            int i = 0, j;
                            while(fscanf(area, "\n%[^\n]", houselist[i].address) == 1)
                            {

                                fscanf(area, "%s", houselist[i].holding_number);
                                fscanf(area, "%d", &houselist[i].bedrooms);
                                fscanf(area, "%d", &houselist[i].bathrooms);
                                fscanf(area, "%d", &houselist[i].floor);
                                fscanf(area, "%d", &houselist[i].rent);
                                fscanf(area, "%s", houselist[i].mobile);
                                fscanf(area, "\n%[^\n]", houselist[i].extrainfo);
                                i++;
                            }
                            noh = i;

                        }
                        fclose(area);

                        ///show in monitor
                        for(i=0 ; i < noh ; i++)
                        {
                            printf("Address: %s\n", houselist[i].address);
                            printf("Bedrooms: %d\n", houselist[i].bedrooms);
                            printf("Bathrooms: %d\n", houselist[i].bathrooms);
                            printf("Floor: %d\n", houselist[i].floor);
                            printf("Rent: %d\n", houselist[i].rent);
                            printf("Mobile: %s\n", houselist[i].mobile);
                            printf("Extra Info: %s\n", houselist[i].extrainfo);

                            printf("\n");


                        }
                    printf("Press any key to continue...");
                    getchar();
                    getchar();

                    system("cls");
                    }

                }
                else if(opt==2)
                {
                    ///Searching
                    gotoxy(30,8);printf("---Search Your House---\n");
                    gotoxy(30,10);printf("1.Search By Rent\n");
                    gotoxy(30,12);printf("2.Advanced Searching\n");
                    gotoxy(30,14);printf("3.Back\n");
                    gotoxy(30,16);printf("Select Option: ");
                    scanf("%d", &opt);
                    system("cls");


                    if(opt == 1)
                    {
                        int f=0;
                        gotoxy(30,8);printf("---Select Area---\n");
                        gotoxy(30,10);printf("1.Chandgaon R/A\n");
                        gotoxy(30,12);printf("2.Nasirabad\n");
                        gotoxy(30,14);printf("3.Back\n ");
                        gotoxy(30,16);printf("New Areas Coming Soon......\n");
                        gotoxy(30,18);printf("Select Option: ");
                        scanf("%d",&opt);
                        system("cls");

                        if(opt==1)
                        {
                        FILE *search=fopen("chandgaon.txt","r");
                        int i = 0, j;
                        while(fscanf(search, "\n%[^\n]", houselist[i].address) == 1)
                        {

                            fscanf(search, "%s", houselist[i].holding_number);
                            fscanf(search, "%d", &houselist[i].bedrooms);
                            fscanf(search, "%d", &houselist[i].bathrooms);
                            fscanf(search, "%d", &houselist[i].floor);
                            fscanf(search, "%d", &houselist[i].rent);
                            fscanf(search, "%s", houselist[i].mobile);
                            fscanf(search, "\n%[^\n]", houselist[i].extrainfo);
                            i++;
                        }
                        noh = i;
                        fclose(search);
                        int rent;
                        gotoxy(30,8);printf("---Search---\n");
                        gotoxy(30,10);printf("Enter Monthly Rent: ");
                        scanf("%d", &rent);
                        printf("\n");
                        for( i = 0 ; i < noh ; i++ )
                        {
                            if(houselist[i].rent<=rent)
                            {
                                f=1;
                                printf("Address: %s\n", houselist[i].address);
                                printf("Bedrooms: %d\n", houselist[i].bedrooms);
                                printf("Bathrooms: %d\n", houselist[i].bathrooms);
                                printf("Floor: %d\n", houselist[i].floor);
                                printf("Rent: %d\n", houselist[i].rent);
                                printf("Mobile: %s\n", houselist[i].mobile);
                                printf("Extra Info: %s\n", houselist[i].extrainfo);
                                printf("\n");
                            }

                        }
                        if(f==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,12);printf("No Match Found!\n");
                            printf("\033[0m");
                            gotoxy(30,14);printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                        if(f!=0)
                        {
                            printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                    }

                    if(opt==2)
                        {
                        FILE *search=fopen("nasirabad.txt","r");
                        int i = 0, j;
                        while(fscanf(search, "\n%[^\n]", houselist[i].address) == 1)
                        {

                            fscanf(search, "%s", houselist[i].holding_number);
                            fscanf(search, "%d", &houselist[i].bedrooms);
                            fscanf(search, "%d", &houselist[i].bathrooms);
                            fscanf(search, "%d", &houselist[i].floor);
                            fscanf(search, "%d", &houselist[i].rent);
                            fscanf(search, "%s", houselist[i].mobile);
                            fscanf(search, "\n%[^\n]", houselist[i].extrainfo);
                            i++;
                        }
                        noh = i;
                        fclose(search);
                        int rent;
                        gotoxy(30,8);printf("---Search---\n");
                        gotoxy(30,10);printf("Enter Monthly Rent: ");
                        scanf("%d", &rent);
                        printf("\n");
                        for( i = 0 ; i < noh ; i++ )
                        {
                            if(houselist[i].rent<=rent)
                            {
                                f=1;
                                printf("Address: %s\n", houselist[i].address);
                                printf("Bedrooms: %d\n", houselist[i].bedrooms);
                                printf("Bathrooms: %d\n", houselist[i].bathrooms);
                                printf("Floor: %d\n", houselist[i].floor);
                                printf("Rent: %d\n", houselist[i].rent);
                                printf("Mobile: %s\n", houselist[i].mobile);
                                printf("Extra Info: %s\n", houselist[i].extrainfo);
                                printf("\n");
                            }

                        }
                        if(f==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,12);printf("No Match Found!\n");
                            printf("\033[0m");
                            gotoxy(30,14);printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                        if(f!=0)
                        {
                            printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                    }

                    }

                    else if(opt == 2){
                    ///Advanced searching

                    int f=0;
                    gotoxy(30,8);printf("---Select Area---\n");
                    gotoxy(30,10);printf("1.Chandgaon R/A\n");
                    gotoxy(30,12);printf("2.Nasirabad\n");
                    gotoxy(30,14);printf("3.Back\n");
                    gotoxy(30,16);printf("New Areas Coming Soon......\n");
                    gotoxy(30,18);printf("Select Option: ");
                    scanf("%d",&opt);
                    system("cls");

                    if(opt==1)
                    {
                        FILE *search=fopen("chandgaon.txt","r");
                        int i = 0, j;
                        while(fscanf(search, "\n%[^\n]", houselist[i].address) == 1)
                        {

                            fscanf(search, "%s", houselist[i].holding_number);
                            fscanf(search, "%d", &houselist[i].bedrooms);
                            fscanf(search, "%d", &houselist[i].bathrooms);
                            fscanf(search, "%d", &houselist[i].floor);
                            fscanf(search, "%d", &houselist[i].rent);
                            fscanf(search, "%s", houselist[i].mobile);
                            fscanf(search, "\n%[^\n]", houselist[i].extrainfo);
                            i++;
                        }
                        noh = i;
                        fclose(search);
                        int bedrooms,bathrooms,floor,rent;
                        gotoxy(30,8);printf("---Search---\n");

                        gotoxy(30,10);printf("Enter bedrooms: ");
                        scanf("%d", &bedrooms);
                        gotoxy(30,12);printf("Enter bathrooms: ");
                        scanf("%d", &bathrooms);
                        gotoxy(30,14);printf("Enter floor: ");
                        scanf("%d", &floor);
                        gotoxy(30,16);printf("Enter Monthly Rent: ");
                        scanf("%d", &rent);
                        printf("\n");
                        system("cls");
                        for( i = 0 ; i < noh ; i++ )
                        {
                            if(bedrooms==houselist[i].bedrooms
                                    && bathrooms>=houselist[i].bathrooms
                                    && floor==houselist[i].floor
                                    && houselist[i].rent<=rent)
                            {
                                f=1;
                                printf("Address: %s\n", houselist[i].address);
                                printf("Bedrooms: %d\n", houselist[i].bedrooms);
                                printf("Bathrooms: %d\n", houselist[i].bathrooms);
                                printf("Floor: %d\n", houselist[i].floor);
                                printf("Rent: %d\n", houselist[i].rent);
                                printf("Mobile: %s\n", houselist[i].mobile);
                                printf("Extra Info: %s\n", houselist[i].extrainfo);
                                printf("\n");
                            }

                        }
                        if(f==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,18);printf("No Match Found!\n");
                            printf("\033[0m");
                            gotoxy(30,20);printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                        if(f!=0)
                        {
                            printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                    }

                    if(opt==2)
                    {
                        FILE *search=fopen("nasirabad.txt","r");
                        int i = 0, j;
                        while(fscanf(search, "\n%[^\n]", houselist[i].address) == 1)
                        {

                            fscanf(search, "%s", houselist[i].holding_number);
                            fscanf(search, "%d", &houselist[i].bedrooms);
                            fscanf(search, "%d", &houselist[i].bathrooms);
                            fscanf(search, "%d", &houselist[i].floor);
                            fscanf(search, "%d", &houselist[i].rent);
                            fscanf(search, "%s", houselist[i].mobile);
                            fscanf(search, "\n%[^\n]", houselist[i].extrainfo);
                            i++;
                        }
                        noh = i;
                        fclose(search);
                        int bedrooms,bathrooms,floor,rent;
                        gotoxy(30,8);printf("---Search---\n");

                        gotoxy(30,10);printf("Enter bedrooms: ");
                        scanf("%d", &bedrooms);
                        gotoxy(30,12);printf("Enter bathrooms: ");
                        scanf("%d", &bathrooms);
                        gotoxy(30,14);printf("Enter floor: ");
                        scanf("%d", &floor);
                        gotoxy(30,16);printf("Enter Monthly Rent: ");
                        scanf("%d", &rent);
                        printf("\n");
                        system("cls");
                        for( i = 0 ; i < noh ; i++ )
                        {
                            if(bedrooms==houselist[i].bedrooms
                               && bathrooms>=houselist[i].bathrooms
                               && floor==houselist[i].floor
                               && houselist[i].rent<=rent)
                            {
                                f=1;
                                printf("Address: %s\n", houselist[i].address);
                                printf("Bedrooms: %d\n", houselist[i].bedrooms);
                                printf("Bathrooms: %d\n", houselist[i].bathrooms);
                                printf("Floor: %d\n", houselist[i].floor);
                                printf("Rent: %d\n", houselist[i].rent);
                                printf("Mobile: %s\n", houselist[i].mobile);
                                printf("Extra Info: %s\n", houselist[i].extrainfo);
                                printf("\n");
                            }

                        }
                        if(f==0)
                        {
                            printf("\033[1;31m");
                            gotoxy(30,18);printf("No Match Found!\n");
                            printf("\033[0m");
                            gotoxy(30,20);printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                        if(f!=0)
                        {
                            printf("Press any key to continue...");
                            getchar();
                            getchar();
                            system("cls");
                        }
                    }

                }
                }
                else if(opt == 3)
                {
                    ///Back
                    break;
                }
                else
                {
                    printf("\033[1;31m");
                    gotoxy(30,14);printf("Invalid Input!\n");
                    printf("\033[0m");
                    Sleep(1000);
                }
            }
        }

        else if(opt == 3)
        {
            gotoxy(30,8);printf("---About us---\n");
            gotoxy(30,10); printf("Group Leader: Mashrur Ibne Mamun.\n");
            gotoxy(30,12);printf("ID:C233023\n");
            gotoxy(30,14);printf("Group Member: Jabir Siddique Talim\n");
            gotoxy(30,16);printf("ID:C233005\n");
            gotoxy(30,18); printf("Group Member: Masad Rayan\n");
            gotoxy(30,20);printf("ID:C233007\n");
            gotoxy(30,22);printf("Semester : 1st\n");
            gotoxy(30,24); printf("Section : 1AM\n\n");
            gotoxy(30,26); printf("Press any key to continue...");
            getchar();
            getchar();
            system("cls");

        }
        else if(opt == 4)
        {
            printf("\033[1;32m");
            gotoxy(30,14);printf("Thank You for staying with us!\n");
            printf("\033[0m");
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            printf("\033[1;31m");
            gotoxy(30,14);printf("Invalid Input!\n");
            printf("\033[0m");
            Sleep(1000);
            system("cls");
        }
    }
    return 0;
}