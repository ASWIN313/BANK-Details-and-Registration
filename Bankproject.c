#include <stdio.h>
#include <string.h>

// A more robust way to get a line of input
void get_line(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the trailing newline character
}

int validpass(char pass[]) {
    int capital = 0, small = 0, number = 0, spl = 0;
    int len = strlen(pass);

    if (len < 8)
    {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; pass[i]; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
            capital = 1;
        else if (pass[i] >= 'a' && pass[i] <= 'z')
            small = 1;
        else if (pass[i] >= '0' && pass[i] <= '9')
            number = 1;
        else
            spl = 1;
    }

    if (capital && small && number && spl)
        return 1;
    else {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 0;
    }
}

struct Member {
    char name[20], user[20], pass[20], acc[20], gen[20], dob[20], num[20], add[20];
    float balance;
};

struct Member members[10];
int memberCount = 0;

void setDefaultMembers() {
    strcpy(members[0].name, "VIGNESH S R");
    strcpy(members[0].user, "Vignesh");
    strcpy(members[0].pass, "vikki@123");
    strcpy(members[0].acc, "12345678890099980");
    strcpy(members[0].gen, "Male");
    strcpy(members[0].dob, "07/11/1985");
    strcpy(members[0].num, "9360137756");
    strcpy(members[0].add, "Coimbatore");
    members[0].balance = 199000;

    strcpy(members[1].name, "AKSHAYA K");
    strcpy(members[1].user, "Akshaya");
    strcpy(members[1].pass, "akshu$987");
    strcpy(members[1].acc, "12345678890099981");
    strcpy(members[1].gen, "Female");
    strcpy(members[1].dob, "09/01/2004");
    strcpy(members[1].num, "9894459908");
    strcpy(members[1].add, "Udumalapettai");
    members[1].balance = 500000;

    strcpy(members[2].name, "MEERA SAHIB N");
    strcpy(members[2].user, "Sahib");
    strcpy(members[2].pass, "meera#2024");
    strcpy(members[2].acc, "12345678890099982");
    strcpy(members[2].gen, "Male");
    strcpy(members[2].dob, "09/01/2004");
    strcpy(members[2].num, "9894089908");
    strcpy(members[2].add, "Thirunalveli");
    members[2].balance = 9900000;

    strcpy(members[3].name, "YOGISHA M");
    strcpy(members[3].user, "Yogisha");
    strcpy(members[3].pass, "yogi@123");
    strcpy(members[3].acc, "12345678890099983");
    strcpy(members[3].gen, "Female");
    strcpy(members[3].dob, "25/11/2003");
    strcpy(members[3].num, "86672440530");
    strcpy(members[3].add, "Cuddalore");
    members[3].balance = 770000;

    strcpy(members[4].name, "ASWIN K A");
    strcpy(members[4].user, "Aswin");
    strcpy(members[4].pass, "acchu#987");
    strcpy(members[4].acc, "12345678890099984");
    strcpy(members[4].gen, "Male");
    strcpy(members[4].dob, "31/03/2003");
    strcpy(members[4].num, "9869636030");
    strcpy(members[4].add, "Erode");
    members[4].balance = 1500000;

    strcpy(members[5].name, "CELCIA V");
    strcpy(members[5].user, "Celcia");
    strcpy(members[5].pass, "pearlie@19");
    strcpy(members[5].acc, "12345678890099985");
    strcpy(members[5].gen, "Female");
    strcpy(members[5].dob, "19/09/2003");
    strcpy(members[5].num, "9864536030");
    strcpy(members[5].add, "Thoothukudi");
    members[5].balance = 100000;

    memberCount = 6;
}

void registerMember() {
    if (memberCount >= 10) {
        printf("Database full!\n");
        return;
    }
    printf("\n=====WELCOME TO OUR BANK=======\n");
    printf("\n\t---Register---\n\n");

    // Clear the input buffer before reading new strings
    while (getchar() != '\n');

    printf("Name            : ");
    get_line(members[memberCount].name, 20);
    printf("Username        : ");
    get_line(members[memberCount].user, 20);
    while (1) {
        printf("Password        : ");
        get_line(members[memberCount].pass, 20);
        if (validpass(members[memberCount].pass)) {
            break;
        } else {
            printf("Invalid password. Try again.\n");
        }
    }
    printf("Account Number  : ");
    get_line(members[memberCount].acc, 20);
    printf("Gender          : ");
    get_line(members[memberCount].gen, 20);
    printf("Date of Birth   : ");
    get_line(members[memberCount].dob, 20);
    printf("Phone Number    : ");
    get_line(members[memberCount].num, 20);
    printf("Address         : ");
    get_line(members[memberCount].add, 20);

    members[memberCount].balance = 0;
    memberCount++;
    printf("\n=========Registered!!!=======\n");
}

int login() {
    char u[20], p[20];
    printf("\n---- Login ----\n");
    // Clear input buffer before login
    while (getchar() != '\n');

    printf("Username: ");
    get_line(u, 20);
    printf("Password: ");
    get_line(p, 20);

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(u, members[i].user) == 0 && strcmp(p, members[i].pass) == 0)
            return i;
    }
    printf("Invalid!\n");
    return -1;
}

void menu(int idx) {
    int c;
    float amt;
    while (1) {
        printf("\n1.View Info\t2.Deposit\t3.Withdraw\t4.Logout\n\nOPTION: ");
        scanf("%d", &c);
        // Clear input buffer after reading integer
        while (getchar() != '\n');

        if (c == 1) {
            printf("\nName            :%s\nAccount Number  :%s\nGender          :%s\nDate of Birth   :%s\nPhone Number    :%s\nAddress         :%s\nBalance         :%.2f\n",
                   members[idx].name, members[idx].acc, members[idx].gen, members[idx].dob, members[idx].num, members[idx].add, members[idx].balance);
        } else if (c == 2) {
            printf("Deposit: ");
            scanf("%f", &amt);
            members[idx].balance += amt;
            printf("New Balance: %.2f\n", members[idx].balance);
        } else if (c == 3) {
            printf("Withdraw: ");
            scanf("%f", &amt);
            if (amt <= members[idx].balance) {
                members[idx].balance -= amt;
                printf("New Balance: %.2f\n", members[idx].balance);
            } else {
                printf("No Balance!\n");
            }
        } else if (c == 4) {
            printf("\nSUCCESSFULLY LOGGED OUT!\n");
            break;
        } else {
            printf("Invalid!\n");
        }
    }
}

int main() {
    int c, idx;
    setDefaultMembers();
    printf("========== Helloo...==========\n\n\tGreeting!!!!\n\n==============================\n\nWELCOME TO OUR BANK\n");
    while (1) {
        printf("\n\n1)Register\t2)Login\t\t3)Exit\n\nOPTION: ");
        scanf("%d", &c);

        if (c == 1) {
            registerMember();
        } else if (c == 2) {
            idx = login();
            if (idx != -1)
                menu(idx);
        } else if (c == 3) {
            printf("\n========THANKS FOR VISITING OUR BANK==========\n");
            printf("\n==============KINDLY VISIT AGAIN==============\n");
            break;
        } else {
            printf("Try Again!\n");
        }
    }
    return 0;
}
