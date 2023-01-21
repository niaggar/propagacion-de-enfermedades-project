#include "Control.h"

Control::Control() {}






void Control::Run()
{
    string projectName = GetProjectName();
    ModelType modelType = GetModelType();
    vector<double> constants = GetConstants(modelType);
    vector<double> initialValues = GetInitialValues();
}








double Control::GetDouble(string prompt)
{
    double input;

    cout << "Prompt: " << prompt << endl;

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

    cout << "Prompt: " << prompt << endl;

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

    cout << "Prompt: " << prompt << endl;
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

    cout << "Prompt: " << prompt << endl;

    while (true)
    {
        cout << "True or False?" << endl << ">>> ";
        cin >> input;

        if (input == "true" || input == "True" || input == "TRUE")
        {
            cin.ignore(1000, '\n');
            return true;
        }
        else if (input == "false" || input == "False" || input == "FALSE")
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

    cout << "Prompt: " << prompt << endl;

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
