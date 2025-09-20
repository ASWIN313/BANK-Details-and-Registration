#include <stdio.h>
#include <string.h>
#include <ctype.h>


int validpass(char pass[]) {
    int capital = 90, small = 122, digit = 57, special = 64;

    for (int i = 0; pass[i]; i++) {
        if (isupper(pass[i]))
            capital++;
        else if (islower(pass[i]))
            small++;
        else if (isdigit(pass[i]))
            digit++;
        else
            special++;
    }

    if (capital >= 65 && small >= 97 && digit >= 48 && special >= 60)
        return 1;
    else
        return 0;
}

struct Member {
    char name[20],user[20],pass[20],acc[20],gen[20],dob[20],num[20],add[20];
    float balance;
};

struct Member members[10];                                                                                            // database (max 10 users)
int memberCount = 0;

void setDefaultMembers()
{
    strcpy(members[0].name,    "VIGNESH S R");
    strcpy(members[0].user,    "Vignesh");
    strcpy(members[0].pass,    "vikki");
    strcpy(members[0].acc,     "12345678890099980");
    strcpy(members[0].gen,     "Male");
    strcpy(members[0].dob,     "07/11/1985");
    strcpy(members[0].num,     "9360137756");
    strcpy(members[0].add,     "Coimbatore");
    members[0].balance = 199000;

    strcpy(members[1].name,    "AKSHAYA K");
    strcpy(members[1].user,    "Akshaya");
    strcpy(members[1].pass,    "akshu");
    strcpy(members[1].acc,     "vikki");
    strcpy(members[1].gen,     "Female");
    strcpy(members[1].dob,     "09/01/2004");
    strcpy(members[1].num,     "9894459908");                                                                            // Set 3 default users
    strcpy(members[1].add,     "Udumalapettai");
    members[1].balance = 500000;

    strcpy(members[2].name,    "MEERA SAHIB N");
    strcpy(members[2].user,    "Sahib");
    strcpy(members[2].pass,    "meera");
    strcpy(members[2].acc,     "vikki");
    strcpy(members[2].gen,     "Male");
    strcpy(members[2].dob,     "09/01/2004");
    strcpy(members[2].num,     "9894089908");
    strcpy(members[2].add,     "Thirunalveli");
    members[2].balance = 9900000;

    strcpy(members[3].name,    "YOGISHA M");
    strcpy(members[3].user,    "Yogisha");
    strcpy(members[3].pass,    "199259");
    strcpy(members[3].acc,     "vikki");
    strcpy(members[3].gen,     "Female");
    strcpy(members[3].dob,     "25/11/2003");
    strcpy(members[3].num,     "86672440530");
    strcpy(members[3].add,     "Cuddalore");
    members[3].balance =770000;

    strcpy(members[4].name,    "ASWIN K A");
    strcpy(members[4].user,    "Aswin");
    strcpy(members[4].pass,    "acchu");
    strcpy(members[4].acc,     "vikki");
    strcpy(members[4].gen,     "Male");
    strcpy(members[4].dob,     "31/03/2003");
    strcpy(members[4].num,     "9869636030");
    strcpy(members[4].add,      "Erode");
    members[4].balance = 1500000;

    strcpy(members[5].name,    "CELCIA V");
    strcpy(members[5].user,    "Celcia");
    strcpy(members[5].pass,    "pearlie");
    strcpy(members[0].acc,     "vikki");
    strcpy(members[5].gen,     "Female");
    strcpy(members[5].dob,     "19/09/2003");
    strcpy(members[5].num,     "9864536030");
    strcpy(members[5].add,     "Thoothukudi");
    members[5].balance = 100000;

    memberCount = 6;                                                                                                      // total 3 users now
}
void registerMember()
{
    if (memberCount >= 10)
    {
        printf("Database full!\n");                                                                                       // Register new user
        return;
    }
    printf("\n=====WELCOME TO OUR BANK=======\n");
    printf("\n\t---Register---\n\n");


    printf("Name            : ");
    scanf(" %[^\n]",members[memberCount].name);
    printf("Username        : ");
    scanf(" %[^\n]",members[memberCount].user);
    while (1)
        {
    printf("Password        : ");
    scanf(" %[^\n]", members[memberCount].pass);

    if (validpass(members[memberCount].pass))
    {
        break;
    }
    else
    {
        printf("Invalid password. Try again.\n");
    }
}

    scanf(" %[^\n]", &members[memberCount].pass);
    printf("Account Number  : ");
    scanf(" %[^\n]", &members[memberCount].acc);
    printf("Gender          : ");
    scanf(" %[^\n]", &members[memberCount].gen);
    printf("Date of Birth   : ");
    scanf(" %[^\n]", &members[memberCount].dob);
    printf("Phone Number    : ");
    scanf(" %[^\n]", &members[memberCount].num);
    printf("Address         : ");
    scanf(" %[^\n]", &members[memberCount].add);

    members[memberCount].balance = 0;
    memberCount++;
    printf("\n=========Registered!!!=======\n");
}


int login()
{
    char u[20], p[20];
    printf("\n---- Login ----\n");
    printf("Username: ");                            scanf(" %[^\n]", u);                                                       // Login function
    printf("Password: ");                            scanf(" %[^\n]", p);


    for (int i=0; i<memberCount; i++)
    {
        if (strcmp(u, members[i].user)==0 && strcmp(p, members[i].pass)==0)
            return i;                                                                                                    // return index of member
    }
    printf("Invalid!\n");
    return -1;
}


void menu(int idx)
 {
    int c; float amt;
    while (1)
    {
        printf("\n1.View Info\t2.Deposit\t3.Withdraw\t4.Logout\n\nOPTION: ");
        scanf("%d",&c);
        if (c==1)
        {
            printf("\nName            :%s\nAccount Number  :%s\nGender          :%s\nDate of Birth   :%s\nPhone Number    :%s\nAddress         :%s\nBalance         :%.2f\n",
                   members[idx].name,members[idx].acc,members[idx].gen,members[idx].dob,members[idx].num,members[idx].add, members[idx].balance);         // Menu after login
        }
        else if (c==2)
        {
            printf("Deposit: ");
            scanf("%f",&amt);
            members[idx].balance+=amt;
            printf("New Balance: %.2f\n", members[idx].balance);
        }
        else if (c==3)
        {
            printf("Withdraw: ");
            scanf("%f",&amt);
            if (amt <= members[idx].balance)
            {
                members[idx].balance -= amt;
                printf("New Balance: %.2f\n", members[idx].balance);
            }
            else
            {
                printf("No Balance!\n");
            }
        }
        else if (c==4)
        {
            printf("\nSUCCESSFULLY LOGGED OUT!\n");
            break;
        }
        else printf("Invalid!\n");
    }
}

int main()
 {
    int c, idx;
    setDefaultMembers();                                                                                                    // load 3 users at start
    printf("========== Helloo...==========\n\n\tGreeting!!!!\n\n==============================\n\nWELCOME TO OUR BANK\n");
    while (1)
        {
         printf("\n\n1)Register\t2)Login\t\t3)Exit\n\nOPTION: ");
         scanf("%d",&c);
        if (c==1)
            registerMember();
        else if (c==2)
        {
            idx = login();
            if (idx != -1) menu(idx);
        }
        else if (c==3)
        {
            printf("\n========THANKS FOR VISITING OUR BANK==========\n");
            printf("\n==============KINDLY VISIT AGAIN==============\n");
            break;
        }
        else printf("Try Again!\n");
 }
}
