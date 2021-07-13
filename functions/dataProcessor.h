#include "dataProcessorIncludes.h"

using namespace std;

map<int, vector<vector<string>>> readFile(string filename)
{
    ifstream FILE(filename);
    FILE.open(filename);
    if (!FILE) {
        cerr << "Error reading " << filename << endl;
    }

    string unit;
    string name;
    string phone;
    string email;
    string ic;

    map<int, vector<vector<string>>> data;

    auto storeData = [](auto &data, int unit, string name, string phone, string email, string ic)
    {
        if (data[unit][0].size() < 4)
        {
            data[unit][0].push_back(name);
            data[unit][0].push_back(phone);
            data[unit][0].push_back(email);
            data[unit][0].push_back(ic);
        }
        else if (data[unit][0].size() > 3 && data[unit][1].size() < 4)
        {
            data[unit][1].push_back(name);
            data[unit][1].push_back(phone);
            data[unit][1].push_back(email);
            data[unit][1].push_back(ic);
        }
        else
        {
            cout << "ERROR unit registration is full" << endl;
        }
    };

    while (getline(FILE, unit, ','))
    {
        getline(FILE, name, ',');
        getline(FILE, phone, ',');
        getline(FILE, email, ',');
        getline(FILE, ic, '\n');

        if (data.find(stoi(unit)) == data.end())
        {
            data[stoi(unit)] = {{}, {}};
            storeData(data, stoi(unit), name, phone, email, ic);
        }
        else
        {
            storeData(data, stoi(unit), name, phone, email, ic);
        }
    }

    FILE.close();

    return data;
}

void searchData(map<int, vector<vector<string>>> data, int unit)
{
    try
    {
        for (int i = 0; i < data.at(unit).size(); i++)
        {
            for (int j = 0; j < data.at(unit)[i].size(); j++)
            {
                cout << data.at(unit)[i][j] << endl;
            }
            cout << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }
}

vector<string> returnNames(map<int, vector<vector<string>>> data, int unit)
{
    vector<string> names;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data[unit][i].size() > 3)
            {
                names.push_back(data[unit][i][0]);
            }
        }
        for (int i = 0; i < names.size(); i++)
        {
            cout << names[i] << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }

    return names;
}

vector<string> returnPhones(map<int, vector<vector<string>>> data, int unit)
{
    vector<string> phones;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data[unit][i].size() > 3)
            {
                phones.push_back(data[unit][i][1]);
            }
        }
        for (int i = 0; i < phones.size(); i++)
        {
            cout << phones[i] << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }

    return phones;
}

vector<string> returnEmails(map<int, vector<vector<string>>> data, int unit)
{
    vector<string> emails;

    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data[unit][i].size() > 3)
            {
                emails.push_back(data[unit][i][2]);
            }
        }
        for (int i = 0; i < emails.size(); i++)
        {
            cout << emails[i] << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }

    return emails;
}

vector<string> returnICs(map<int, vector<vector<string>>> data, int unit)
{
    vector<string> ics;

    try
    {
        for (int i = 0; i < 2; i++)
        {
            if (data[unit][i].size() > 3)
            {
                ics.push_back(data[unit][i][3]);
            }
        }
        for (int i = 0; i < ics.size(); i++)
        {
            cout << ics[i] << endl;
        }
    }
    catch (const out_of_range)
    {
        cout << "Unit has not registered" << endl;
    }

    return ics;
}