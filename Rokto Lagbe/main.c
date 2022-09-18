#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>


struct blooddonor
{
    long ph;
    char name[20],add[20],donor[30];
}
list;
char query[20], name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
    char donor[30];
main:
    system("cls");
    /* ************Main menu ***********************  */
    printf("\n\t      **** Welcome to ROKTO LAGBE ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Donor\n\t\t[2] List all Donors\n\t\t[3] Search for Blood Group\n\t\t[4] Edit a Donor\n\t\t[5] Delete a Donor\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

    /* *********************Add new donors************  */

    case 1:

        system("cls");

        fp=fopen("Donor.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the blood Group input\n\nBlood Group:");
            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);

            printf("Mobile no.:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("Name:");

            scanf("%[^\n]",&list.donor);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

    /* *********************list of Donors*************************  */

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF Donors\n\t\t================================\n\nGroup\t\tPhone No\t\tAddress\t\tName\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("Donor.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n%s\t\t%ld\t\t%s\t\t%s\t\t\n",list.name, list.ph,list.add,list.donor);

                    found++;

                }

            }


            if(found!=0)

            {
                printf("\n=========================================================== [%c]-(%d)\n\n",i-32,found);
                printf("Press any key to continue\n");
                getch();
            }

            fclose(fp);

        }

        break;


    /* *******************search Donors**********************  */

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::DONOR SEARCH\n\t===========================\n\t..::Name of Blood Group to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("Donor.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Group Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Donor Name\t: %s\n",list.name,list.ph,list.add,list.donor);

                    found++;

                    if (found>=1)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

    /* *********************edit donors************************/

    case 4:
        system("cls");
        fp=fopen("Donor.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit donor\n===============================\n\n\t..::Enter the name of donor to edit:");
        scanf("%[^\n]",&list.donor);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(donor,list.donor)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",donor);

        printf("..::Blood group:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::Donor name:");

        gets(list.donor);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("donor.dll");

        rename("temp.dat","donor.dll");

        break;

    /* ********************delete donors**********************/

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A DONOR\n\t==========================\n\t..::Enter the name of donor to delete:");

        scanf("%[^\n]",&donor);

        fp=fopen("donor.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(donor,list.donor)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("donor.dll");

        rename("temp.dat","donor.dll");

        break;

    default:

        printf("Invalid choice");

        break;

    }
    //printf("Successfully Removed!!\n\n");
    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}
