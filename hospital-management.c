#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Simple Hospital Management System by Mohamed Mostafa

// functions declaration
void addp(void);
void sp(void);
void dt(void);
void em(void);
void bills_center(void);
void payment(int c,char* pname,int bill_amount);
void insurance(int c,char* pname,int bill_amount);
void rerun(void);

//structure
typedef struct 
{
    char *name;
    int age;
    char *phone;
    char *gender;
    char *address;
    char *city;
    char *disease;
    char *drug_test;
    int bills;
}s1;
//main function
int main(void)
{
    int select;
    printf("\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t+\t\tHospital Managment System\t\t+\n");
    printf("\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\n(1) Add New Patient.\n\n(2) Search Patient.\n\n(3) Display Patient Drug Test Records\n\n(4) Pay Patient Bills.\n\n(5) Exit.\n");
    do
    {
        select = get_int("\n\n[*] Select From Menu: ");        
        if(select == 1)
        {
            addp();
        }
        else if(select == 2)
        {
            sp();
        }
        else if(select == 3)
        {
            dt();
        }
        else if(select == 4)
        {
            bills_center();
        }
        else if(select == 5)
        {
            return 0;
        }
    } while (select < 1 || select > 5);
}
// re run program
void rerun(void)
{   

    char q1;
    do
    {
        q1 = get_char("\n\n[?] Do You Wanna Perform Another Action? (Y = Continue / N = Exit): ");
        if(q1 == 'Y' || q1 == 'y')
        {
            main();
        }
        else if(q1 == 'N' || q1 == 'n')
        {
            printf("\n\n[*] Hospital Management Has Been Terminated.\n");
            return;
        }
    } while(q1 != 'Y' && q1 != 'y' && q1 != 'N' && q1 != 'n');
}
// function for registering patient data in csv file,all inputs are validated.
void addp(void)
{
    char *name;int age;char *phone;char *gender;char *address;char *city;char* disease;
    FILE* patientsdb = fopen("new_patients.csv","a");
    printf("\n+++++++++++++++++++++++++++\n+ Add New Patient\t  +\n+++++++++++++++++++++++++++\n");
    do{name = get_string("\n[?] Enter Patient Full Name: ");} while (strlen(name) > 40 || strlen(name) < 15);
    do{age = get_int("\n[?] Enter Patient Age: ");} while (age < 1 || age > 100);
    do{phone = get_string("\n[?] Enter Patient Phone Number: ");} while(strlen(phone) > 11 || strlen(phone) < 11);
    do{gender = get_string("\n[?] Enter Patient Gender: ");} while(strcmp(gender,"male") != 0 && strcmp(gender,"female") != 0);
    do{address = get_string("\n[?] Enter Patient Address: ");} while(strlen(address) > 35 || strlen(address) < 15);
    do{city = get_string("\n[?] Enter Patient City: ");} while(strlen(city) > 15);
    do{disease = get_string("\n[?] Enter Patient Disease: ");} while(strlen(disease) > 60 || strlen(disease) < 5);
    fprintf(patientsdb,"%s, %i, %s, %s, %s, %s, %s\n",name,age,phone,gender,address,city,disease);
    printf("\n[+] Patient Data Has Been Saved Successfully.\n");
    fclose(patientsdb);
    rerun();
}
// function for searching for a patient data
void sp(void)
{
    s1 patients[3];char *search;
    patients[0].name = "ahmed mohamed elsherbiny";patients[0].age = 23;patients[0].phone = "01225885214";patients[0].address = "Abass Elakad, Nasr City";patients[0].city = "Cairo";patients[0].disease = "Angioedema";
    patients[1].name = "hanan ahmed elmohammady";patients[1].age = 29;patients[1].phone = "01014714741";patients[1].address = "2 Shalshla, St Elwrak, Giza";patients[1].city = "Elwrak";patients[1].disease = "Bulimia";
    patients[2].name = "khaled mostafa elmahlawy";patients[2].age = 29;patients[2].phone = "01200032112";patients[2].address = "33 El Kasr El Einy, Garden City";patients[2].city = "Cairo";patients[2].disease = "Chronic pain";
    printf("\n+++++++++++++++++++++++++++\n+ Search Patients\t  +\n+++++++++++++++++++++++++++\n");
    do
    {
        search = get_string("\n[?] Enter Patient Full Name: ");
    } while (strlen(search) < 15 || strlen(search) > 40);
    printf("\n----------------------------------------------------------------------------------");
    printf("\n| [!] If No Data Showed Up Down Here It Means That Patient Records Is Not Found. |\n");
    printf("----------------------------------------------------------------------------------\n");

    for(int x = 0; x < 3; x++)
    {
        if(strcmp(search,patients[x].name) == 0)
        {
            printf("\n--------------------------------------------------------------------\n");
            printf("|\t\t\t[!] Patient Record");
            printf("\n--------------------------------------------------------------------\n");
            printf("| Patient Name:  %s\n",patients[x].name);
            printf("--------------------------------------------------------------------\n");
            printf("| Patient Age:  %i\n",patients[x].age);
            printf("--------------------------------------------------------------------\n");
            printf("| Patient Phone:  %s\n",patients[x].phone);
            printf("--------------------------------------------------------------------\n");
            printf("| Patient Address:  %s\n",patients[x].address);
            printf("--------------------------------------------------------------------\n");
            printf("| Patient City:  %s\n",patients[x].city);
            printf("--------------------------------------------------------------------\n");
            printf("| Patient Disease:  %s\n",patients[x].disease);
            printf("--------------------------------------------------------------------\n");
        }
    }
    rerun();
}
// function for searching about drug test records for individual
void dt(void)
{
    s1 dtest[2];char *search;
    dtest[0].name = "ahmed mohamed ramzy";dtest[0].drug_test = "POSITIVE";
    dtest[1].name = "ali samy refaat";dtest[1].drug_test = "NEGATIVE";
    printf("\n+++++++++++++++++++++++++++\n+ Drug Test Records\t  +\n+++++++++++++++++++++++++++\n");
    do
    {
        search = get_string("\n[?] Enter Full Name: ");
    } while (strlen(search) < 15 || strlen(search) > 40);
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n| [!] If No Data Showed Up Down Here It Means That Patient Drug Test Records Is Not Found. |\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for(int x = 0; x < 3;x++)
    {
        if(strcmp(search,dtest[x].name) == 0)
        {
            printf("\n--------------------------------------------------------------------\n");
            printf("| Name\t\t\t\t\tResult\n");
            printf("--------------------------------------------------------------------\n");
            printf("| %s\t\t\t%s\n",dtest[x].name,dtest[x].drug_test);
            printf("--------------------------------------------------------------------\n");
        }
    }
    rerun();
}
// function for displaying hospital bills for a patient 
void bills_center(void)
{
    s1 pdata[2];char* name;char q;
    pdata[0].name = "ahmed mohamed elsherbiny";pdata[0].bills = 7500;
    pdata[1].name = "khaled mostafa elmahlawy";pdata[1].bills = 12000;
    printf("\n+++++++++++++++++++++++++++\n+ Patient Bills\t\t  +\n+++++++++++++++++++++++++++\n");
    do
    {
        name = get_string("\n[?] Enter Patient Name: ");
    } while (strlen(name) < 15 || strlen(name) > 40);
    printf("\n----------------------------------------------------------------------------------------");
    printf("\n| [!] If No Data Showed Up Down Here It Means That Patient Bills Records Is Not Found. |\n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int x = 0; x < 2;x++)
    {
        if(strcmp(name,pdata[x].name) == 0)
        {
            printf("\n----------------------------------------------------------\n");
            printf("| Name\t\t\t\t\tBill Amount\n");
            printf("----------------------------------------------------------\n");
            printf("| %s\t\t%i$\n",pdata[x].name,pdata[x].bills);
            printf("----------------------------------------------------------\n");
            do
            {
                q = get_char("\n[?] Do You Have A Health Insurance? (y / n): ");
                if(q == 'y' || q == 'Y')
                {
                    insurance(3,pdata[x].name,pdata[x].bills);
                }
                else if(q == 'n' || q == 'N')
                {
                    payment(3,pdata[x].name,pdata[x].bills);
                }
            } while (q != 'y' && q != 'n' && q != 'Y' && q != 'N');
        }
    }
}
// function for managing payments
void payment(int c,char* pname,int bill_amount)
{
    s1 pdata[2];
    int choice;char* credit_card;char* credit_ccv;
    int credit_balance = 15000;char* credit = "1478523690000";char* ccv = "225";
    if(c == 0)
    {
        printf("\n\n[!] Sorry, Too Many Attempts Program Exited :(\n");
        return;
    }
    printf("\n-------------------------------------------------------------------");
    printf("\n[!] *** Bills Payment For Patient: %s ***\n",pname);
    printf("-------------------------------------------------------------------");

    printf("\n\n[$] Choose Payment Method\n\n(1) Cash.\n\n(2) Credit Card.\n");
    do
    {
        choice = get_int("\n[*] Select: ");
        if(choice == 1)
        {
            printf("\n[$] Cash Payment Total %i$, Thanks For Choosing Us As Your Primary Health Care.\n",bill_amount);
            return;
        }
        else if(choice == 2)
        {
            do
            {
                credit_card = get_string("\n[?] Enter Credit Card Number: ");
                if(strlen(credit_card) != 13)
                {
                    printf("\n[!] Invalid Credit Card Number Length, (Credit Card Length = 13 Digits).\n");
                }
            } while (strlen(credit_card) != 13);
            do
            {
                credit_ccv = get_string("\n[?] Enter Credit Card CCV Number: ");
                if(strlen(credit_ccv) != 3)
                {
                    printf("\n[!] Invalid Credit Card CCV Length, (Credit Card CCV Length = 3 Digits).\n");
                }
            } while (strlen(credit_ccv) != 3);
            if(strcmp(credit_card,credit) == 0 && strcmp(credit_ccv,ccv) == 0 && credit_balance >= bill_amount)
            {
                credit_balance -= bill_amount;
                printf("\n[$] Credit Card Payment Done Successfully.\n\n[$] Your Credit Card Balance After Payment Is: %i$",credit_balance);
            }
            else if(strcmp(credit_card,credit) != 0 || strcmp(credit_ccv,ccv) != 0)
            {
                printf("\n[!] Invalid Credit Card Information, You Have %i Attempts Left. \n",c - 1);
                payment(c - 1,pname,bill_amount);
                return;
            }
            else if(credit_balance < bill_amount)
            {
                printf("\n[!] Insufficient Credit Card Balance.\n");
                return;
            }
        }
    } while (choice < 1 || choice > 2);
    rerun();
}
// function for health insurance discount
void insurance(int c,char* pname,int bill_amount)
{
    char* insurance_id = "123456";char* insurance_in;int ins_dis;
    if(c == 0)
    {
        printf("\n\n[!] Sorry, Too Many Attempts Program Exited :(\n");
        return;
    }
    do
    {
        insurance_in = get_string("\n\n[?] Enter Insurance ID: ");
        if(strlen(insurance_in) != 6)
        {
            printf("\n[!] Invalid Insurance ID Length, (Insurance ID Length = 6 Digits).");
        }
        else if(strcmp(insurance_id,insurance_in) == 0)
        {
            ins_dis = bill_amount * (100 - 50)/100;
            printf("\n[$] Health Insurance Discount Done Successfully, Your Bill Amount After Insurance Discount Is :%i$ \n",ins_dis);
            payment(c,pname,ins_dis);
        }
        else
        {
            printf("\n[!] Invalid Insurance ID, You Have %i Attempts Left. ",c - 1);
            insurance(c - 1,pname,bill_amount);
            return;
        }
    } while (strlen(insurance_in) != 6);
}