#include "Control.h"

string Control::GetProjectName()
{
    cout << endl;
    cout << "--- Select a project ---" << endl;
    vector<string> foldersName = GetFoldersName();
    PrintFoldersName(foldersName);

    int option = GetIntRange("Select a project", 0, foldersName.size() - 1);

    cout << "Project selected: " << foldersName[option] << endl;
    cout << "-----------------------" << endl;
    cout << endl;

    return foldersName[option];
}

vector<string> Control::GetFoldersName()
{
    vector<string> foldersName;
    const char *path = "./data/";
    DIR *folder = opendir(path);
    struct dirent *entry;

    if (folder == NULL)
    {
        cout << "Unable to open the directory \n\n";
        return foldersName;
    }

    while ((entry = readdir(folder))) 
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            foldersName.push_back(entry->d_name);
        }
    }

    closedir(folder);
    return foldersName;
}

void Control::PrintFoldersName(vector<string> foldersName)
{
    cout << "Projects name: " << endl;
    for (int i = 0; i < foldersName.size(); i++)
    {
        cout << "\t" << i << ") - " << foldersName[i] << endl;
    }
    cout << endl;
}