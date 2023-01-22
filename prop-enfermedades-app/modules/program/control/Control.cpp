#include "Control.h"

Control::Control() {}

void Control::Run()
{
    cout << "Welcome to the program" << endl;
    cout << "-----------------------" << endl;
    bool newProject = GetBool("Do you want to start a new project? (y/n)");
    cout << "-----------------------" << endl;

    if (newProject)
    {
        UseNewProject();
    }
    else
    {
        UseExistingProject();
    }
}

double Control::GetDouble(string prompt)
{
    double input;

    cout << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

int Control::GetInt(string prompt)
{
    int input;

    cout << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

int Control::GetIntRange(string prompt, int min, int max)
{
    int input;

    cout << prompt << endl;
    cout << "Min: " << min << " Max: " << max << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;
        if (cin.fail() || input < min || input > max)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

bool Control::GetBool(string prompt)
{
    string input;

    cout << prompt << endl;

    while (true)
    {
        cout << "Yes or No?" << endl
             << ">>> ";
        cin >> input;

        if (input == "yes" || input == "Yes" || input == "YES")
        {
            cin.ignore(1000, '\n');
            return true;
        }
        else if (input == "no" || input == "No" || input == "NO")
        {
            cin.ignore(1000, '\n');
            return false;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
    }
}

string Control::GetString(string prompt)
{
    string input;

    cout << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (input == "")
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}
