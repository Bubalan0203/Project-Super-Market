#include<iostream>
#include<fstream>

using namespace std;

class shopping {
private:
    int pcode; // product code
    float price, discount; // discount
    string pname; // product name

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void receipt();
    void list();
};

void shopping::menu() {
    m: // goto declared
    int choice;
    string email, password;

    cout << "\t\t\t\t________________________________________________________\n";
cout<<"\t\t\t\t                                                        \n";
cout<<"\t\t\t\t                SUPER MARKET MAIN MENU                  \n";
cout<<"\t\t\t\t                                                        \n";
cout<<"\t\t\t\t________________________________________________________\n";
cout<<"\t\t\t\t                                                        \n";
cout<<"\t\t\t\t|   1) Administrator  |  \n";
cout<<"\t\t\t\t|                     |  \n";
cout<<"\t\t\t\t|   2) Buyer          |  \n";
cout<<"\t\t\t\t|                     |  \n";
cout<<"\t\t\t\t|   3) Exit           |  \n";
cout<<"\t\t\t\t|                     |  \n";
cout<<"\n\t\t\t Please select!";
cin>>choice;

switch(choice)
{
    case 1:
    cout<<"\t\t\t Please Login    \n";
    cout<<"\t\t\t Enter Email     \n";
    cin>>email;
    cout<<"\t\t\t Enter password  \n";
    cin>>password;

    if(email=="babloo2003@gmail.com" && password=="babloo123") 
    {
        administrator();
    }
    else
    {
        cout<<" Invalid Email  or Password ";
    }
    break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout<<"Please Enter from given Options";
    }

}
goto m; //goto main menu

}

void shopping::administrator() {
    m: // goto declared
    int choice;
    cout << "\n\n\n\t\t\t Administrator Menu";
    cout<<"\n \t\t\t|____1) Add the product____|";
    cout<<"\n \t\t\t|                          |";
    cout<<"\n \t\t\t|___2)Modify the product___|";
    cout<<"\n \t\t\t|                          |";
    cout<<"\n \t\t\t|___3)Delete the product___|";
    cout<<"\n \t\t\t|                          |";
    cout<<"\n \t\t\t|___4)Back to Main Menu____|";
    cout<<"\n \t\t\t|                          |";

    cout<<"\n\t\t\t Please Enter your choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default :
        cout<<"Invalid option"; 
    }
    goto m;  //goto administrator 

}

void shopping::buyer() {
    m:
    int choice;
    cout << "\t\t\t     Buyer \n";
    cout<<"\t\t\t________________\n";
    cout<<"                       \n";
    cout<<"\t\t\t 1) Buy Product  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 2) Go Back       \n";
    cout<<"                       \n";
    cout<<"\t\t\t Enter Your choice :";
    cin>>choice;

    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default :
        cout<<" Invalid choice";
    }
    goto m;
}

void shopping::add() {
    m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product ";
    cout << "\n\n\t Product code of the product";
    cin >> pcode;
    cout << "\n\n\t Name of the product";
    cin >> pname;
    cout << "\n\n\t Price of the product"; // Corrected prompt
    cin >> price; // Corrected variable name
    cout << "\n\n\t Discount on product";
    cin >> discount;

    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    } else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1) {
        goto m;
    } else {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    cout << "\n\n\t\t Record Inserted";
}

void shopping::edit() {
    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << "\n\t\t\t Modify the record"; // Corrected prompt
    cout<<"\n\t\t\t____________________\n";
    cout<<"\n\t\t\t Product Code :";
    cin>>pkey;
    
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t File Dosen't Exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t New Product  code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Inserted ";
                token++;
            }
            else
            {
               data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n"; 
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token==0)
        {
          cout<<"\n\n Record Not Found Sorry !";
        }
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\n\t Delete Product ";
    cout<<"\n\n\t product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File Doesn't Exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n"; 
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token==0)
        {
          cout<<"\n\n Record Not Found Sorry !";
        }

    }

}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_____________________________________________________________|";
    cout << "ProNo \t\t Name \t\t Price \t\t Discount\n";
    cout << "\n\n|_____________________________________________________________|";
    while (data >> pcode >> pname >> price >> discount) { // Corrected reading
        cout << "\n" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << discount << "\n";
    }
    data.close();
}

void shopping::receipt() {
    m:
    fstream data;

    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, discountedAmount = 0, total = 0; // Corrected initialization
    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty Database";
    } else {
        data.close();

        list();
        cout << "\n\n|_____________________________________________________________|";
        cout << "\n\n|                                                             |";
        cout << "\n\n|                   Please place the order                    |";
        cout << "\n\n|                                                             |";
        cout << "\n\n|_____________________________________________________________|";
        do {
            cout << "\n\n Enter Product code :";
            cin >> arrc[c];
            cout << "\n\n Enter Product Quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product Code Please try again !";
                    goto m;
                }
            }
            c++;
            cout << "\n\nDo you want to buy another product ? if YES press Y else N";
            cin >> choice;
        } while (choice == 'Y');

        cout << "\n\n\t\t\t_____________________________RECEIPT_________________________________________";
        cout << "\nProduct No\t Product Name\t Product Quantity \tPrice \t Amount with Discount\n\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    discountedAmount = amount - (amount * discount / 100);
                    total=discountedAmount;
                    cout << pcode << "\t\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << amount << "\t\t\t" << discountedAmount << "\n";
                }
                data >> pcode >> pname >> price >> discount;
            }
            data.close();
        }
    }
    cout << "\n\n\t\t\t____________________________________________________________________________________";
    cout << "\n Total Amount :\t\t" << total;
    cout << "\n\n\t\t\t____________________________________________________________________________________\n\n";
}

int main() {
    shopping s;
    s.menu();
    return 0;
}
