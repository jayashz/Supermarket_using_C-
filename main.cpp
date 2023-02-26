#include <iostream>
#include <fstream>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t_____________________________________________" << endl
         << endl;
    cout << "\t-----------------Login page------------------" << endl;
    cout << "\t_____________________________________________" << endl
         << endl
         << endl;
    cout << "\t\t|--------1) Login------------|" << endl;
    cout << "\t\t|--------2) Register---------|" << endl;
    cout << "\t\t|--------3) Forgot Password?-|" << endl;
    cout << "\t\t|--------4) Exit ?-----------|" << endl;
    cout << endl;
    cout << "\t\tPlease enter your choice:";
    cin >> c;
    switch (c)
    {
    case 1:
    {
        login();
        break;
    }
    case 2:
    {
        registration();
        break;
    }
    case 3:
    {
        forgot();
        break;
    }
    case 4:
    {
        cout << "\t\tThank you....." << endl;
        return (0);
    }
    default:
    {
        system("clear");
        cout << "\t---------Invalid choice!!!----------" << endl;
        main();
    }
    }
}
void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("clear");
    cout << "\t\t-------------login page------------" << endl;

    cout << "\t\tEnter the your username and password" << endl;
    cout << "\t\tusername:";
    cin >> userId;
    cout << "\t\tpassword:";
    cin >> password;
    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("clear");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\t" << userId << " ,Your login was succesful" << endl;
        main();
    }
    else
    {
        cout << "\n\t\tInvalid username or password!!!" << endl;
        main();
    }
}
void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("clear");
    cout << "\t-------------Registration page---------------" << endl;
    cout << "\t\tEnter your desired username and password" << endl;
    cout << "\t\tUsername:";
    cin >> ruserId;
    cout << "\t\tPassword:";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("clear");
    cout << "\n\t\tRegistration is succesful!!!" << endl;
    main();
}
void forgot()
{
    int option;
    system("clear");
    cout << "\t\tLooks like you forgot your password" << endl;
    cout << "\t_____________________________________________________" << endl;
    cout << "\t\tChoose from the following options:" << endl;
    cout << "\t\t1) Search by the username" << endl;
    cout << "\t\t2) Go to the main menu" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        system("clear");
        cout << "\t---------Finding password by the username--------" << endl;
        string fuserId, fId, fpass;
        cout << "\t\tEnter the user name:";
        cin >> fuserId;
        ifstream f2("records.txt", ios::in);
        while (f2 >> fId >> fpass)
        {
            if (fId == fuserId)
            {
                count = 1;
                break;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\t\t Your id has been found!!!" << endl;
            cout << "\t\tThe password is " << fpass << endl;
            main();
        }
        else
        {
            cout << "\n\t\tThe username doesnot exist!!!" << endl;
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
    {
        cout << "\t\tInvalid choice!!!!!" << endl;
        forgot();
    }
    }
}
