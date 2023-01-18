#include "Control.h"

Control::Control() {}

void Control::run()
{
    cout << "Hello World!" << endl;
}

double Control::getDouble(string prompt)
{
    double input;

    while (true)
    {
        cout << prompt << endl;
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, ' ');
            cout << "Invalid input. Please try again." << endl;
        }
        else
        {
            cin.ignore(1000, ' ');
            break;
        }
    }

    return input;
}

int Control::getIntRange(string prompt, int min, int max)
{
    int input;

    while (true)
    {
        cout << prompt << endl;
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, ' ');
            cout << "Invalid input. Please try again." << endl;
        }
        else if (input < min || input > max)
        {
            cin.clear();
            cin.ignore(1000, ' ');
            cout << "Input outside the bounds. Please try again." << endl;
        }
        else
        {
            cin.ignore(1000, ' ');
            break;
        }
    }

    return input;
}

bool Control::getBool(string prompt)
{
    bool input;

    while (true)
    {
        cout << prompt << endl;
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, ' ');
            cout << "Invalid input. Please try again." << endl;
        }
        else
        {
            cin.ignore(1000, ' ');
            break;
        }
    }

    return input;
}

string Control::getString(string prompt)
{
    string input;

    while (true)
    {
        cout << prompt << endl;
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, ' ');
            cout << "Invalid input. Please try again." << endl;
        }
        else
        {
            cin.ignore(1000, ' ');
            break;
        }
    }

    return input;
}
