#include <iostream>
using namespace std;
string month_name;
int current_date;
int current_year;
int current_mon;

bool check_leap(int year);

int Max_date(int mon);

void print_dates(int n);

int main()
{
    int n;

    cout << "Enter the number of times you want to get the dates:";
    cin >> n;

    int check = 0;

    while (check != 1)
    {
        cout << "Enter current year [YYYY] formate:";
        cin >> current_year;
        cout << "Enter current month in [MM] formate:";
        cin >> current_mon;
        if (current_mon > 12 || current_mon < 1)
        {
            cout<<"*Invalid input* \nEnter month between 1 to 12\n";
            continue;
        }
        cout << "Enter current date IN [DD]:";
        cin >> current_date;
        if (current_date > Max_date(current_mon) || current_date<1)
        {
            cout<<"*Invalid input* \nEnter between 1 to"<<Max_date(current_mon)<<endl;
            continue;
        }
        print_dates(n);
        check=1;
    }
}

void print_dates(int n)
{
    int max_date;
    for (int i = 0; i < n; i++)
    {
        cout << "date " << i + 1 << " :";
        cout << current_date << "\\" << current_mon << "\\" << current_year << endl;
        current_date += 7;
        if (current_date > Max_date(current_mon))
        {
           
        current_date =  (current_date - Max_date(current_mon));
           current_mon += 1;
            if (current_mon > 12)
            {
                current_mon = 1;
                current_year++;
            }
        
        }
        
    }
}

bool check_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Max_date(int month)
{
    switch (month)
    {
    case 1:
        month_name = "JANUARY";
        return 31;
        break;
    case 2:
        if (check_leap(current_year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
        month_name = "FEBRUARY";
        break;
    case 3:
        month_name = "MARCH";
        return 31;
        break;
    case 4:
        month_name = "APRIL";
        return 30;
        break;
    case 5:
        month_name = "MAY";
        return 31;
        break;
    case 6:
        month_name = "JUNE";
        return 30;
        break;
    case 7:
        month_name = "JULY";
        return 31;
        break;
    case 8:
        month_name = "AUGUST";
        return 31;
        break;
    case 9:
        month_name = "SEPTEMBER";
        return 30;
        break;
    case 10:
        month_name = "OCTOBER";
        return 31;
        break;
    case 11:
        month_name = "NOVEMBER";
        return 30;
        break;
    case 12:
        month_name = "DECEMBER";
        return 31;
        break;
    default:
        return -1;
        break;
    }
}