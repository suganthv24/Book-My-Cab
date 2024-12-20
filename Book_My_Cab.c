#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Booking {
    int booking_id;
    char customer_name[101];
    char pickup_location[101];
    char dropoff_location[101];
    char pickup_time[20];
};

struct Booking bookings[100];
int count = 0;

void display_menu() 
{
    printf("\n========== Taxi Booking Application ==========\n");
    printf("1. Add Booking\n");
    printf("2. View Bookings\n");
    printf("3. Delete Booking\n");
    printf("4. Update Booking\n");
    printf("5. Search Booking\n");
    printf("6. Exit\n");
    printf("==============================================\n");
}

void add() 
{
    
    struct Booking new_booking;
    new_booking.booking_id = count + 1;

    printf("Enter customer name: ");
    scanf(" %[^\n]", new_booking.customer_name);
    printf("Enter pickup location: ");
    scanf(" %[^\n]", new_booking.pickup_location);
    printf("Enter dropoff location: ");
    scanf(" %[^\n]", new_booking.dropoff_location);
    printf("Enter pickup time (HH:MM): ");
    scanf(" %[^\n]", new_booking.pickup_time);

    bookings[count++] = new_booking;

    printf("Booking added successfully! Booking ID: %d\n", new_booking.booking_id);
}

void view() 
{
    if (count == 0) 
    {
        printf("No bookings available.\n");
        return;
    }
    for (int i = 0; i < count; i++) 
    {
        printf("\nBooking ID: %d\n", bookings[i].booking_id);
        printf("Customer Name: %s\n", bookings[i].customer_name);
        printf("Pickup Location: %s\n", bookings[i].pickup_location);
        printf("Dropoff Location: %s\n", bookings[i].dropoff_location);
        printf("Pickup Time: %s\n", bookings[i].pickup_time);
        printf("-----------------------------------\n");
    }
}

void delete() 
{
    if (count == 0) 
    {
        printf("No bookings available to delete.\n");
        return;
    }
    int booking_id;
    printf("Enter Booking ID to delete: ");
    scanf("%d", &booking_id);

    if (booking_id <= 0 || booking_id > count) 
    {
        printf("Invalid Booking ID.\n");
        return;
    }
    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (bookings[i].booking_id == booking_id) 
        {
            found = 1;
            for (int j = i; j < count - 1; j++) 
                bookings[j] = bookings[j + 1];
            count--;
            printf("Booking ID %d deleted successfully.\n", booking_id);
            break;
        }
    }
    if (found==0) 
        printf("Booking ID %d not found.\n", booking_id);
}

void update() 
{
    if (count == 0) 
    {
        printf("No bookings available to update.\n");
        return;
    }
    int booking_id;
    printf("Enter Booking ID to update: ");
    scanf("%d", &booking_id);

    if (booking_id <= 0 || booking_id > count) 
    {
        printf("Invalid Booking ID.\n");
        return;
    }
    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (bookings[i].booking_id == booking_id) 
        {
            found = 1;
            printf("Enter new customer name: ");
            scanf(" %[^\n]", bookings[i].customer_name); 
            printf("Enter new pickup location: ");
            scanf(" %[^\n]", bookings[i].pickup_location); 
            printf("Enter new dropoff location: ");
            scanf(" %[^\n]", bookings[i].dropoff_location); 
            printf("Enter new pickup time (HH:MM): ");
            scanf(" %[^\n]", bookings[i].pickup_time); 
            printf("Booking ID %d updated successfully.\n", booking_id);
            break;
        }
    }
    if (found==0) 
        printf("Booking ID %d not found.\n", booking_id);
}

void search() 
{
    char search_name[101];
    printf("Enter customer name to search: ");
    scanf(" %[^\n]", search_name); 

    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (strcasecmp(bookings[i].customer_name, search_name) == 0) 
        {
            found = 1;
            printf("\nBooking ID: %d\n", bookings[i].booking_id);
            printf("Customer Name: %s\n", bookings[i].customer_name);
            printf("Pickup Location: %s\n", bookings[i].pickup_location);
            printf("Dropoff Location: %s\n", bookings[i].dropoff_location);
            printf("Pickup Time: %s\n", bookings[i].pickup_time);
            printf("-----------------------------------\n");
        }
    }
    if (found==0) 
        printf("No bookings found for customer: %s\n", search_name);
}
int main() 
{
    int choice;
    while (100) 
    {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: add(); break;
            case 2: view(); break;
            case 3: delete(); break;
            case 4: update(); break;
            case 5: search(); break;
            case 6: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

