#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

#define separator "============================================== \n";

void wypiszStos(stack <string> stos)
{
    int sequnce = 0;

    while(!stos.empty())
    {
        cout << sequnce << ": " << stos.top() << endl;
        stos.pop();
        sequnce++;
    }

    return;
}

void usunZStosu(stack <string> &stos, int number)
{
    int sequnce = 0;
    stack <string> copy;
    int size= stos.size();

    while(!stos.empty())
    {
        if (sequnce == number)
        {
            // kopiowanie stosu pomocniczego
            stos.pop();
            break;
        }
            copy.push(stos.top());
            stos.pop();
            sequnce++;
    }

    while(!copy.empty())
    {
        stos.push(copy.top());
        copy.pop();
    }

    return;
}

int toInt(std::string number)
{
    int result = 0;
    int sequence = 0;
    //zamien string na int
    while (sequence < number.size())
    {
        result = result*10 + ((char)(number[sequence])-48);
        sequence++;
    }
    return result;
}

int main()
{
    ifstream file("dzienniczek.txt");
    stack <string> stos;
    string read = "";
    if (file.good())
    {
        cout << "Czytanie z pliku." << endl;
        while ( getline(file, read) )
        {
            stos.push(read);
        }
    } 
    file.close();

    cout << separator;
    cout << "Wypisuje liste zadan: \n";
    wypiszStos(stos);
    cout << separator;
    read = "";
    while (1)
    {
        cout << "Podaj zadanie|delete [numer]|0 - wyjdz|delete all:" << endl;
        getline(cin, read);
        if (read == "0")
            break;
        if (read == "delete all")
        {
            while (!stos.empty())
                stos.pop();
            continue;
        }
        int search = read.find("delete", 0);
        if (search != string::npos)
        {
            int index = toInt(read.substr(search+7, read.size()-(search+7)));
            usunZStosu(stos, index);
            cout << separator;
            wypiszStos(stos);
            continue;
        }
        stos.push(read);
        cout << separator;
        wypiszStos(stos);
    }

    ofstream file_out("dzienniczek.txt");
    if (file_out.good())
        while (!stos.empty())
        {
            file_out << stos.top() << endl;
            stos.pop();
        }
    file_out.close();
    return 0;
}