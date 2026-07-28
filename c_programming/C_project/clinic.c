/*
 * Clinic Management System
 * ------------------------------------------------------------
 * Admin mode : password-protected (default "1234", 3 attempts)
 *              - Add new patient record
 *              - Edit patient record
 *              - Reserve a slot with the doctor
 *              - Cancel reservation
 * User mode  : no password required
 *              - View patient record
 *              - View today's reservations
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS   100
#define NUM_SLOTS      5
#define MAX_NAME_LEN   50
#define ADMIN_PASSWORD "1234"
#define MAX_TRIES      3

/*  Data structures */

typedef struct {
    int  id;
    char name[MAX_NAME_LEN];
    int  age;
    char gender;      /* 'M' or 'F' */
    int  active;       /* 1 = record in use, 0 = empty slot */
} Patient;

typedef struct {
    const char *label;
    int  reserved;     /* 0 = free, 1 = reserved */
    int  patientID;    /* valid only if reserved == 1 */
} Slot;

/*  Global data  */

static Patient patients[MAX_PATIENTS];
static int     patientCount = 0;

static Slot slots[NUM_SLOTS] = {
    { "2:00pm - 2:30pm", 0, -1 },
    { "2:30pm - 3:00pm", 0, -1 },
    { "3:00pm - 3:30pm", 0, -1 },
    { "4:00pm - 4:30pm", 0, -1 },
    { "4:30pm - 5:00pm", 0, -1 }
};



static char toUpperChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return (char)(c - 'a' + 'A');
    }
    return c;
}

static void flushInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* Reads an integer robustly. Reprompts on invalid input. */
static int readInt(const char *prompt) {
    int value;
    char buffer[128];

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

static void readLine(const char *prompt, char *dest, size_t destSize) {
    printf("%s", prompt);
    if (fgets(dest, (int)destSize, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }
    } else {
        dest[0] = '\0';
    }
}

/* Reads a single gender character ('M'/'F', case-insensitive). */
static char readGender(void) {
    char buffer[16];
    char g;
    while (1) {
        printf("Enter gender (M/F): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
        if (sscanf(buffer, " %c", &g) == 1) {
            g = toUpperChar(g);
            if (g == 'M' || g == 'F') return g;
        }
        printf("Invalid gender. Please enter M or F.\n");
    }
}

/*  Patient helpers  */

/* Returns index of patient with given ID in patients[], or -1. */
static int findPatientIndex(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active && patients[i].id == id) {
            return i;
        }
    }
    return -1;
}

static int isIDUnique(int id) {
    return findPatientIndex(id) == -1;
}

/*  Admin features  */

static void addPatient(void) {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient database is full. Cannot add more patients.\n");
        return;
    }

    int id = readInt("Enter patient ID: ");
    if (!isIDUnique(id)) {
        printf("Error: A patient with ID %d already exists. Entry rejected.\n", id);
        return;
    }

    Patient p;
    p.id = id;
    readLine("Enter patient name: ", p.name, sizeof(p.name));
    p.age = readInt("Enter patient age: ");
    p.gender = readGender();
    p.active = 1;

    patients[patientCount++] = p;
    printf("Patient '%s' (ID: %d) added successfully.\n", p.name, p.id);
}

static void editPatient(void) {
    int id = readInt("Enter patient ID to edit: ");
    int idx = findPatientIndex(id);

    if (idx == -1) {
        printf("Incorrect ID. No patient found with ID %d.\n", id);
        return;
    }

    printf("Editing patient ID %d (leave a field blank to keep it unchanged).\n", id);

    char nameBuf[MAX_NAME_LEN];
    readLine("Enter new name: ", nameBuf, sizeof(nameBuf));
    if (strlen(nameBuf) > 0) {
        strncpy(patients[idx].name, nameBuf, MAX_NAME_LEN - 1);
        patients[idx].name[MAX_NAME_LEN - 1] = '\0';
    }

    char ageBuf[32];
    printf("Enter new age (blank to keep %d): ", patients[idx].age);
    if (fgets(ageBuf, sizeof(ageBuf), stdin) != NULL) {
        int newAge;
        if (sscanf(ageBuf, "%d", &newAge) == 1) {
            patients[idx].age = newAge;
        }
    }

    char genderBuf[16];
    printf("Enter new gender M/F (blank to keep %c): ", patients[idx].gender);
    if (fgets(genderBuf, sizeof(genderBuf), stdin) != NULL) {
        char g;
        if (sscanf(genderBuf, " %c", &g) == 1) {
            g = toUpperChar(g);
            if (g == 'M' || g == 'F') {
                patients[idx].gender = g;
            }
        }
    }

    printf("Patient record updated successfully.\n");
}

static void displayAvailableSlots(void) {
    printf("\n--- Available Slots ---\n");
    int anyFree = 0;
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (!slots[i].reserved) {
            printf("  [%d] %s\n", i + 1, slots[i].label);
            anyFree = 1;
        }
    }
    if (!anyFree) {
        printf("  (No slots available)\n");
    }
    printf("-----------------------\n");
}

static void reserveSlot(void) {
    displayAvailableSlots();

    int hasFreeSlot = 0;
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (!slots[i].reserved) { hasFreeSlot = 1; break; }
    }
    if (!hasFreeSlot) {
        return;
    }

    int id = readInt("Enter patient ID for reservation: ");
    if (findPatientIndex(id) == -1) {
        printf("Incorrect ID. No patient found with ID %d.\n", id);
        return;
    }

    int choice = readInt("Enter the slot number to reserve: ");
    if (choice < 1 || choice > NUM_SLOTS) {
        printf("Invalid slot number.\n");
        return;
    }

    int slotIdx = choice - 1;
    if (slots[slotIdx].reserved) {
        printf("That slot is already reserved. Please choose another.\n");
        return;
    }

    slots[slotIdx].reserved = 1;
    slots[slotIdx].patientID = id;
    printf("Slot '%s' reserved for patient ID %d.\n", slots[slotIdx].label, id);
}

static void cancelReservation(void) {
    int id = readInt("Enter patient ID to cancel reservation: ");

    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i].reserved && slots[i].patientID == id) {
            slots[i].reserved = 0;
            slots[i].patientID = -1;
            printf("Reservation for patient ID %d ('%s') cancelled. Slot is now available.\n",
                   id, slots[i].label);
            return;
        }
    }
    printf("No active reservation found for patient ID %d.\n", id);
}

/* User features  */

static void viewPatientRecord(void) {
    int id = readInt("Enter patient ID: ");
    int idx = findPatientIndex(id);

    if (idx == -1) {
        printf("Incorrect ID. No patient found with ID %d.\n", id);
        return;
    }

    Patient *p = &patients[idx];
    printf("\n--- Patient Record ---\n");
    printf("  ID     : %d\n", p->id);
    printf("  Name   : %s\n", p->name);
    printf("  Age    : %d\n", p->age);
    printf("  Gender : %c\n", p->gender);
    printf("-----------------------\n");
}

static void viewTodayReservations(void) {
    printf("\n--- Today's Reservations ---\n");
    int any = 0;
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i].reserved) {
            printf("  %s -> Patient ID: %d\n", slots[i].label, slots[i].patientID);
            any = 1;
        } else {
            printf("  %s -> (available)\n", slots[i].label);
        }
    }
    if (!any) {
        printf("  No reservations for today yet.\n");
    }
    printf("-----------------------------\n");
}

/*  Mode menus  */

static int adminLogin(void) {
    char attempt[64];

    for (int tries = 0; tries < MAX_TRIES; tries++) {
        printf("Enter admin password: ");
        if (fgets(attempt, sizeof(attempt), stdin) != NULL) {
            size_t len = strlen(attempt);
            if (len > 0 && attempt[len - 1] == '\n') attempt[len - 1] = '\0';

            if (strcmp(attempt, ADMIN_PASSWORD) == 0) {
                printf("Login successful.\n");
                return 1;
            }
        }
        printf("Incorrect password. %d attempt(s) remaining.\n", MAX_TRIES - tries - 1);
    }

    printf("Too many incorrect attempts. Closing the system.\n");
    return 0;
}

static void adminMenu(void) {
    if (!adminLogin()) {
        exit(EXIT_FAILURE); /* system shall close */
    }

    int choice;
    do {
        printf("\n===== Admin Menu =====\n");
        printf("1. Add new patient record\n");
        printf("2. Edit patient record\n");
        printf("3. Reserve a slot with the doctor\n");
        printf("4. Cancel reservation\n");
        printf("5. View today's reservations\n");
        printf("0. Return to main menu\n");
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1: addPatient();            break;
            case 2: editPatient();           break;
            case 3: reserveSlot();           break;
            case 4: cancelReservation();     break;
            case 5: viewTodayReservations(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);
}

static void userMenu(void) {
    int choice;
    do {
        printf("\n===== User Menu =====\n");
        printf("1. View patient record\n");
        printf("2. View today's reservations\n");
        printf("0. Return to main menu\n");
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1: viewPatientRecord();      break;
            case 2: viewTodayReservations();  break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);
}


int main(void) {
    int choice;

    printf("======================================\n");
    printf("     Welcome to the Clinic System      \n");
    printf("======================================\n");

    do {
        printf("\n1. Admin mode\n");
        printf("2. User mode\n");
        printf("0. Exit\n");
        choice = readInt("Select mode: ");

        switch (choice) {
            case 1: adminMenu(); break;
            case 2: userMenu();  break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}