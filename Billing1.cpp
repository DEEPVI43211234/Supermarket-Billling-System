 #include<iostream>
 #include<fstream>  // file handling

 using namespace std;

 class shopping
 {
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();  //remove the product
        void list();  //display the list of products;
        void receipt();

 };

 void shopping :: menu()
 {
    m:
    int choice;
    string email;
    string password; //for the login purpose email and password;

    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t           Supermarket Main Menu           \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t|  1) Administrator  |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t|  2) Buyer          |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t|  3) Exit           |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\n\t\t\t Please select!";
    cin >> choice;  //input from user if admin then 1 if buyer then 2 if exit then 3

    switch(choice)
    {
        case 1:
            cout << "\t\t\t Please Login \n";
            cout << "\t\t\t Enter Email  \n";
            cin >> email;
            cout << "\t\t\t Password     \n";
            cin >> password;

            if(email == "coco@email.com" && password == "coco@123")
            {
                administrator();
            }else
            {
                cout << "Invalid email/password";
            }
            break;

        case 2:
        {
            buyer();
        }

        case 3:
        {
            exit(0); // successfull termination of program;
        }
        
        default : //if person selects any other option except 1,2,3 
            {
                cout << "Please select from the given options";
            }
        goto m;
    }
        
}
    


//administrator have different options 
void shopping :: administrator()
{   m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|_____1) Add the product_____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____2) Modify the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____3) Delete the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____4) Back to main menu___|";

    cout << "\n\n\t Please enter yout choice ";
    cin >> choice;

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
            cout << "Invalid choice!";
    }
    goto m;
}

void shopping :: buyer()
{   
    m:
    int choice;
    cout << "\t\t\t  Buyer \n";
    cout << "\t\t\t_____________  \n";                
    cout << "                     \n";
    cout << "\t\t\t1) Buy product \n";
    cout << "                     \n";
    cout << "\t\t\t2) Go back     \n";
    cout << "\t\t\t Enter your choice : ";

    cin >> choice;
    
    switch(choice)
    {
        case 1:
            receipt(); //all the operations of the buyers will take place;
            break;

        case 2:
            menu();

        default :
            cout << "invalid choice";
    }

    goto m;

}
void shopping :: add()
{
    m:
    fstream data;  //object
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    // now we have to create a menu type of a structure 
    // which will ask the customer to enter the product code of the product, price, name, discount, etc;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n\n Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on the product";
    cin >> dis;

    //now we have to open a file since add option is used by the administrator
    //so we have to store these product details inside the particular file
    //so that we can display that we have these products 
    data.open("database.txt", ios :: in );
    // ios::in will open a file in reading mode)

    if(!data) //if file does not exixts then open in writing mode
    {
        data.open("database.txt", ios :: app| ios :: out); //app append mode out- writing mode
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close(); //to close the file;

    }
    else
    { //if file exists then we will read from file
        data >> c >> n >> p >> d; //initializing the index after that using while loop
       // while loop to iterate through the filebuf
       while(!data. eof())  //end of file function will make sure every contect is checked
       {
            if(c == pcode)
            {
                token ++;
            }
            data >> c >> n >> p >> d;
       }
       data.close();
    
        if(token == 1) //if their is duplicacy
        goto m;
        else
        { //if the product is unique then we can again add the product name, code, dis, etc
            data.open("database.txt", ios :: app| ios :: out); //app append mode out- writing mode
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }   
    }
    cout << "\n\n\t\t Record inserted !";
}

//To edit the products
void shopping :: edit()
{
    fstream data, data1;  //two objects 
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey; 
    //open and check the file if that file exists or not

    data.open("database.txt", ios :: in);
    if(!data)
    {
        cout << "\n\nFile doesn't exist!";
    }
    else{ // we will open another file of 1
        data1.open("database1.txt", ios :: app| ios :: out);
        //we will save our data in this file and we will rename it to the original name i.e database.txt

        data >> pcode >> pname >> price >> dis;
        while(!data.eof())
        {
            if(pkey == pcode)  //pkey is the code entered by the administrator which he wants to edit
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p; 
                cout << "\n\t\t Discount :";
                cin >> d;
                // now all the updated deatils of the product will be entered by data1 object
                data1 << " " << c << " " << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited ";
                token ++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        //rem - we will remove the database.txt file
        //replace - will replace the database1.txt to database.txt 

        remove ("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0) //if token value doesnot incremented
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout <<"\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios :: in);
    if(!data)
    {
        cout << "File does not exist";
    }

    else{
        data1.open("database1.txt", ios :: app| ios :: out);
        data >> pcode >> pname >> price >> dis;
        while(!data.eof())
        {
            if(pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {  //pkey entered will check for 1st product code f it matches then if block execute if it does not  match then else block will execute and database1 file will be displayed
            //in other words in else block all the product wll be displayed except the one which you want to remove or delete so we will rename it with prev file i.e database
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txt" , "database.txt");

        if(token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt" , ios :: in);
    cout << "\n\n|___________________________________________________\n";
    cout <<" ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|___________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while(!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();

}

void shopping :: receipt()
{   
    
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("database.txt", ios :: in);
    if(!data)
    {
        cout << "\n\n Empty database";
    }

    else
    {
        data.close();

        list();
        cout << "\n_______________________________________________\n";
        cout << "\n|                                              \n";
        cout << "\n             PLease place the order            \n";
        cout << "\n|                                              \n";
        cout << "\n_______________________________________________\n";
        do
        {
            m:
            cout << "\n\nEnter Product code :";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity :";
            cin >> arrq[c];
            for(int i = 0; i < c; i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else no";
            cin >> choice;
        }
        while(choice == 'y');

        cout << "\n\n\t\t\t_______________________RECEIPT________________________\n";
        cout << "\nProduct No.\t product Name\t product quantity\tprice\tAmount with discount\n";

        for(int i =0 ; i < c; i++)
        {
            data.open("database.txt", ios :: in);
            data >> pcode >> pname >> price >> dis; //initialize the file
            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i]; //quantity;
                    dis = amount - (amount * dis/100);
                    total = total + dis;
                    cout << "\n" <<pcode <<"\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n___________________________________________________________________";
    cout << "\n Total Amount : " << total;

}
int main()
{
    shopping s;
    s.menu();
}