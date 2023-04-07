#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter a year  :  ";
    unsigned int year;
    cin >> year;

    cout << "Enter the first day of the year [1: Monday, ... 7:Sunday]: ";
    unsigned int first_day;
    cin >> first_day;

    cout << endl;
    cout << "Calendar for " << year << endl;

    int number_of_days_in_a_month = 0;
    unsigned int starting_point{first_day};
    unsigned int day_counter{0}; // After we print the day, we increment
    unsigned int date_width{6};

    // Display calendar for each month
    for (int month = 1; month <= 12; month++)
    {
        // Print the title and get number of days in a month
        switch (month)
        {
        case 1:
            number_of_days_in_a_month = 31;
            cout << "--January " << year << " --" << endl;
            break;
        case 2:
            // Check for Leap years
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                number_of_days_in_a_month = 29;
            else
                number_of_days_in_a_month = 28;
            cout << "--February " << year << " --" << endl;

            break;
        case 3:
            number_of_days_in_a_month = 31;
            cout << "--March " << year << " --" << endl;

            break;
        case 4:
            number_of_days_in_a_month = 30;
            cout << "--April " << year << " --" << endl;
            break;
        case 5:
            number_of_days_in_a_month = 31;
            cout << "--May " << year << " --" << endl;
            break;
        case 6:
            number_of_days_in_a_month = 30;
            cout << "--June " << year << " --" << endl;
            break;
        case 7:
            number_of_days_in_a_month = 31;
            cout << "--July " << year << " --" << endl;
            break;
        case 8:
            number_of_days_in_a_month = 31;
            cout << "--August " << year << " --" << endl;
            break;
        case 9:
            number_of_days_in_a_month = 30;
            cout << "--September " << year << " --" << endl;
            break;
        case 10:
            number_of_days_in_a_month = 31;
            cout << "--October " << year << " --" << endl;
            break;
        case 11:
            number_of_days_in_a_month = 30;
            cout << "--November " << year << " --" << endl;
            break;
        case 12:
            number_of_days_in_a_month = 31;
            cout << "--December " << year << " --" << endl;
            break;
        }

        // Print day header. Make sure each date takes up date_width characters
        cout << setw(date_width) << "Mon"
             << setw(date_width) << "Tue"
             << setw(date_width) << "Wed"
             << setw(date_width) << "Thu"
             << setw(date_width) << "Fri"
             << setw(date_width) << "Sat"
             << setw(date_width) << "Sun" << endl;

        // Print empty day slots in calendar
        for (unsigned int j{1}; j < starting_point; ++j)
        {
            cout << setw(date_width) << "";
            ++day_counter;
            if (day_counter == 7)
            {
                cout << endl; // Move to the next week
                day_counter = 0;
            }
        }

        // Print actual days in the calendar
        for (unsigned int i{1}; i <= number_of_days_in_a_month; ++i)
        {
            cout << setw(date_width) << i;
            ++day_counter;

            if (day_counter == 7)
            {
                cout << endl;
                day_counter = 0;
            }
        }

        // Do the set up for the next month
        starting_point = day_counter + 1;
        day_counter = 0;
        cout << "\n\n";
    }

    return 0;
}