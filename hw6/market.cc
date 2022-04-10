#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Item{
    public:
        Item(string str, int num, int pr, int mar);
        void set_price(int pr);
        void set_margin(int mar);
        void set_number(int num);
        int get_price();
        int get_margin();
        int get_number();
        string get_name();
    private:
        string name;
        int number;
        int price;
        int margin;
};

int main(){
    int balance;
    cin >> balance;

    int balance_tmp = balance;

    vector<Item> items;

    while(1)
    {
        string oper;
        cin >> oper;
        
        if(oper == "buy")
        {
            string name;
            int number, price, margin;
            cin >> name >> number >> price >> margin;
            
            if(number * price > balance)
            {
                cout << "can't buy ";
            }
            else
            {
                int i;
                for(i=0;i<items.size();i++)
                {
                    if(items[i].get_name() == name)
                    {
                        balance -= number * price;
                        items[i].set_price(price);
                        items[i].set_margin(margin);
                        items[i].set_number(items[i].get_number() + number);
                        break;
                    }
                }
                if(i == items.size())
                {
                    balance -= number * price;
                    Item item(name, number, price, margin);
                    items.push_back(item);
                }   
            }
        }
        else if(oper == "sell")
        {
            string name;
            int number;
            cin >> name >> number;
            
            int lee_seung_tae = 0;
            int i;
            for(i=0;i<items.size();i++)
            {
                if(items[i].get_name() == name)
                {
                    if(items[i].get_number() > number)
                    {
                        balance += number * (items[i].get_margin() + items[i].get_price());
                        items[i].set_number(items[i].get_number() - number);
                    }
                    else if(items[i].get_number() == number)
                    {
                        balance += number * (items[i].get_margin() + items[i].get_price());
                        items.erase(items.begin() + i);
                        lee_seung_tae = 1;
                    }
                    else
                    {
                        cout << "can't sell ";
                    }
                    break;
                }
            }
            if(i == items.size() && lee_seung_tae == 0)
            {
                cout << "not exist ";
            }
        }
        else if(oper == "check")
        {
            string name;
            cin >> name;
        
            int i;
            for(i=0;i<items.size();i++)
            {
                if(items[i].get_name() == name)
                {
                    cout << items[i].get_number() << " " << items[i].get_margin() + items[i].get_price() << " ";
                    break;
                }
            }
            if(i == items.size())
            {
                cout << "not exist ";
            }
        }
        else if(oper == "balance")
        {
            cout << balance << " ";
        }
        else if(oper == "exit")
        {
            cout << balance - balance_tmp;
            break;
        }
        else
        {
            cout << "wrong operation " << endl;
        }
    }
}

Item::Item(string str, int num, int pr, int mar){name = str; number = num; price = pr; margin = mar;}
void Item::set_price(int pr){price = pr;}
void Item::set_margin(int mar){margin = mar;}
void Item::set_number(int num){number = num;}
int Item::get_price(){return price;}
int Item::get_margin(){return margin;}
int Item::get_number(){return number;}
string Item::get_name(){return name;}






