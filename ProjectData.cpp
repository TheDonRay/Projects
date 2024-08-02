#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Filereader
{
public:
    static string detectfile(const string &filename)
    {
        if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".csv")
        {
            return "CSV";
        }
        else if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".tsv")
        {
            return "TSV";
        }
        else if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".txt")
        {
            return "TXT";
        }
        else
        {
            return "unknown";
        }
    }

    static void
    listOptions_for_file(const string &fileType)
    {
        cout << "Here are some of the options for this file type: " << endl;
        cout << "1. Count rows" << endl;
        cout << "2. Display content" << endl;
        cout << "3. Get average of values in file provided assuming file type: CSV." << endl;
    }

    static void conductOption(const string &option, ifstream &fin)
    {
        if (option == "1")
        {
            countRows(fin);
        }
        else if (option == "2")
        {
            displayContent(fin);
        }
        else if (option == "3")
        {
            getAverage(fin);
        }
        else
        {
            cout << "Invalid option selected." << endl;
        }
    }

private:
    static void countRows(ifstream &fin)
    {
        int count = 0;
        string line;
        while (getline(fin, line))
        {
            count++;
        }
        cout << "Number of rows in the file: " << count << endl;
    }

    static void displayContent(ifstream &fin)
    {
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
    }

    static void getAverage(ifstream &fin)
    {
        string line;
        double sum = 0.0;
        int count = 0;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            while (getline(ss, token, ','))
            {
                sum += stod(token);
                count++;
            }
        }
        if (count > 0)
        {
            double average = sum / count;
            cout << "Average of values in the file: " << fixed << setprecision(2) << average << endl;
        }
        else
        {
            cout << "No values found in the file." << endl;
        }
    }
};

class type_input
{
public:
    static string getInputfrom_user(const string &text)
    {
        string get_input;
        cout << text;
        getline(cin, get_input);

        while (get_input.empty())
        {
            cout << "Error. Command or action not recognized. " << endl;
            cout << text;
            getline(cin, get_input);
        }
        return get_input;
    }
};

int main()
{
    string filetypeInput = type_input::getInputfrom_user("Enter the type of file you will be using: ");

    string filetype = Filereader::detectfile(filetypeInput);
    if (filetype != " " || filetype != "Unknown")
    {
        cout << filetype << " " << "file has been detected." << endl;
        cout << endl;
    }
    else
    {
        cout << "File type not recognized please specify if you want csv, tsv, or txt." << endl;
        return 1;
    }

    string openFile = type_input::getInputfrom_user("Would you like to open the file you have provided? : ");
    if (openFile == "yes" || openFile == "Yes")
    {
        string getfilename = type_input::getInputfrom_user("Please insert file name, an example would be 'example.txt': ");

        ifstream fin(getfilename);

        if (!fin.is_open())
        {
            cout << "Error opening file! " << endl;
            return 1;
        }
        else
        {
            cout << "File opened. " << endl;
            Filereader::listOptions_for_file(filetype);
            string option = type_input::getInputfrom_user("Choose an option: ");
            Filereader::conductOption(option, fin);
            fin.close();
        }
    }
}