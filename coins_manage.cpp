#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> BUY_COIN;
vector<float> BUY_QNT;
vector<float> BUY_PRICE;

vector<string> SELL_COIN;
vector<float> SELL_QNT;
vector<float> SELL_PRICE;
void saving();
void sell();
void buy();
void display_buys();
void display_sells();
void load();
bool check = true;

int main()
{
    if(check)
        load();
    check = false;
    system("cls");
    int ans;
    cout << "  *==============   MENU   ==============*" << "\n\n";
    cout << "    BUY            -------->     Press 1                            " << "\n";
    cout << "    SELL           -------->     Press 2                            " << "\n";
    cout << "    DISPLAY BUYS   -------->     Press 3                            " << "\n";
    cout << "    DISPLAY SELLS  -------->     Press 4                            " << "\n";
    cout << "    EXIT           -------->     Press 0                            " << "\n";
    cout << "    Select >> ";
    cin >> ans;
    switch (ans)
    {
    case 1:
        buy();
        break;
    case 2:
        sell();
        break;
    case 3:
        display_buys();
        break;
    case 4:
        display_sells();
        break;
    case 0:
        saving();
        exit(0);
    default:
        main();
    }
}

void buy()
{
    system("cls");
    string coin, u_coin;
    float qnt, price;
    cout << "<<BUY>> \n Enter the coin, quantity, and price in order \n\n >>";
    cin >> coin >> qnt >> price;

    for (int letter : coin)
        u_coin += toupper(letter); 
    BUY_COIN.push_back(u_coin);
    BUY_QNT.push_back(qnt);
    BUY_PRICE.push_back(price);
    main();
}

void sell()
{
    system("cls");
    string coin, u_coin;
    float qnt, price;
    cout << "<<SELL>> \n Enter the coin, quantity, and price in order \n\n >>";
    cin >> coin >> qnt >> price;

    for (int letter : coin)
        u_coin += toupper(letter);

    SELL_COIN.push_back(u_coin);
    SELL_QNT.push_back(qnt);
    SELL_PRICE.push_back(price);
    main();
}

void display_buys()
{
    system("cls");
    int i = 0;
    cout << "===================================================\n";
    cout << "      COIN      |      QNT      |      PRICE       \n";
    cout << "===================================================\n";
    while (i < BUY_COIN.size())
    {
        cout << "      " << BUY_COIN[i] << "              " << BUY_QNT[i] << "               $" << BUY_PRICE[i] << endl;
        i++;
    }
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    main();
}

void display_sells()
{
    system("cls");
    int i = 0;
    cout << "===================================================\n";
    cout << "      COIN      |      QNT      |      PRICE       \n";
    cout << "===================================================\n";
    while (i < SELL_COIN.size())
    {
        cout << "      " << SELL_COIN[i] << "            " << SELL_QNT[i] << "            $" << SELL_PRICE[i] << endl;
        i++;
    }
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    main();
}

void saving()
{
    ofstream buy_c("buy.txt");
    ofstream sell_c("sell.txt");

    for (int i = 0; i < BUY_COIN.size(); i++)
        buy_c << BUY_COIN[i] << "," << BUY_QNT[i] << "," << BUY_PRICE[i] << endl;

    for (int i = 0; i < SELL_COIN.size(); i++)
        sell_c << SELL_COIN[i] << "," << SELL_QNT[i] << "," << SELL_PRICE[i] << endl; 
    buy_c.close();
    sell_c.close();

}

void load()
{
    ifstream buy_c;
    ifstream sell_c;
    buy_c.open("buy.txt");
    sell_c.open("sell.txt");
    string coin, qnt, price, line;

    while(getline(buy_c, line))
    {
        int counter = 0;
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == ',')
            {
                counter++;
                j++;
            }
            switch (counter)
            {
                case 0: coin += line[j]; break;
                case 1: qnt += line[j]; break;
                case 2: price += line[j]; break;
            }
            

        } 
        BUY_COIN.push_back(coin);
        BUY_QNT.push_back(stof(qnt));
        BUY_PRICE.push_back(stof(price));
        
        coin = "";
        qnt = "";
        price = "";
    }

    while(getline(sell_c, line))
    {
        int counter = 0;
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] == ',')
            {
                counter++;
                j++;
            }
            switch (counter)
            {
                case 0: coin += line[j]; break;
                case 1: qnt += line[j]; break;
                case 2: price += line[j]; break;
            }
        } 
        SELL_COIN.push_back(coin);
        SELL_QNT.push_back(stof(qnt));
        SELL_PRICE.push_back(stof(price));
        
        coin = "";
        qnt = "";
        price = "";
    }
    buy_c.close();
    sell_c.close();
}