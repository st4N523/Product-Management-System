#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <conio.h>
using namespace std;


class Login_detail {
public:
    string login_n;
    string login_p;
    string username="123";
    string password="123";
    string newpassword;
    string confirmpassword;


    //default username=pmsystem
    //default pwd=pms12345

    Login_detail()
    {

        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;

    }

    ~Login_detail() {
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                       THANK YOU                                                        "<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl<<"Press any key to continue...";
        cout<<endl;
    }
    void userid();
    void forget_password();
};

void Login_detail::userid() {
    char opt;
    cout<<"========================================================================================================================"<<endl;
    cout<<"                                                            LOGIN                                                       "<<endl;
    cout<<"========================================================================================================================"<<endl;
    cout<<"Please enter username : ";
    getline(cin,login_n);

    while (username != login_n) {
        cout<<"Username incorrect"<<endl;
        cout<<"Please enter username : ";
        getline(cin, login_n);
    }

    if (login_n == username) {
        cout<<"Enter your password : ";
        cin>>login_p;

        while (login_p != password) {
            fflush(stdin);
            cout<<endl<<"Password Error. Forget Password? "<<endl;
            cout<<"Y to continue process / N to try again password): ";
            cin>>opt;

            if (opt == 'Y' || opt == 'y') {
                cout<<endl;
                forget_password();
            }
            else if (opt == 'N' || opt == 'n') {
                cout<<"Please enter password : ";
                cin.ignore();
                cin>>login_p;
            }
        }

        if (login_p == password) {
            cout<<"Successful login";
            cout<<endl<< "Press any key to continue..."<<endl;
            getch();
            cout<<endl;

        }
    }
}

void Login_detail::forget_password() {
    system("CLS");
    cout<<"========================================================================================================================"<<endl;
    cout<<"                                                     RESET PASSWORD                                                     "<<endl;
    cout<<"========================================================================================================================"<<endl;
    cout<< "Please Enter Your Account Username: ";
    cin>>login_n;

    if (login_n == username)
    {
        fflush(stdin);
        cout<<"Please Enter New Password: ";
        //cin.ignore();
        getline(cin, newpassword);
        cout<<"Please confirm Your New Password: ";
        //cin.ignore();
        getline(cin, confirmpassword);
        if (newpassword == confirmpassword)
        {
            fstream forget;
            forget.open("login.txt", ios::out);
            cout<<"Password change successfully...";
            forget<<login_n<<endl<<newpassword;
            password=newpassword;
            forget.close();
            getch();
            cout<<endl;
            system("CLS");
            userid();
        }
        else
        {
            cout<<"Password Not Matched."<<endl;
        }
    }
}

class ItemInfo{

public:

    void setproductID(int ida){
        productID = ida;
    }

    int getproductID(){
        return productID;
    }

public:
    void setName(string xa){
        productName = xa;
    }
    string getName(){
        return productName;
    }

public:
    void setCostPrice(double za){
        productCostPrice = za;
    }
    double getCostPrice(){
        return productCostPrice;
    }

public:
    void setSellPrice(double z1a){
        productSellPrice = z1a;
    }
    double getSellPrice(){
        return productSellPrice;
    }

public:
    void setQuantity(int ya){
        productQuantity = ya;
    }

    int getProductQuantity(){
        return productQuantity;
    }


//----------------------------Class Variable------------------------------------
private:
    int productID;
    static const int SIZE = 10;
    double productCostPrice = 0,productSellPrice = 0;
    string productName;
    int productQuantity;
public:
    int Dis_productIDarray[SIZE] = {0};
    string Dis_productNameArray[SIZE] = {""};
    double Dis_productCostPriceArray[SIZE] = {0.0};
    double Dis_productSellPriceArray[SIZE] = {0.0};
    int Dis_productQuantityArray[SIZE] = {0};
    int counter;
public:
    int productIDarray[SIZE] = {0};
    string productNameArray[SIZE] = {""};
    double productCostPriceArray[SIZE] = {0.0};
    double productSellPriceArray[SIZE] = {0.0};
    int productQuantityArray[SIZE] = {0} ;


//--------------------------------------------------------------------------------
void getItemInfo();
void setItemToFile();
void inputItemFromFile();
void printItemInfo();
void DisplayItemFromFile();
void EditProduct();
int getCounter();
void DeleteProduct();
void Checkout();
void GenerateSalesReport();
};

int ItemInfo :: getCounter()
{
    int tempX;
    int counterB;

    ifstream get5("counter.txt");

    if (!get5.is_open())
    {
        ofstream outFile5("counter.txt");
        if(outFile5.is_open())
        {
            tempX = 1;
            outFile5 << tempX;
            outFile5.close();
        }
        else
        {
            cout << "Error: Unable to Create Txt" << endl;
            return 1;
        }
    }
    else
    {
        get5 >> tempX;
        get5.close();

        if (tempX < 0 || tempX > 11)
        {
            tempX = 1;
        }
    }

    counterB = tempX;

    //For testing
    //cout << "tempX is " << tempX << endl;
    //cout << "counterB is " << counterB << endl;

    return counterB;

}


void ItemInfo :: getItemInfo()
{
    string x;
    int y;
    double z, z1;
    counter = getCounter();

    cout << "Enter The Product Name:";
    cin >> x;
    setName(x);
//---------------------------------------------------------------
    cout << "Enter The Product Cost Price(RM):";
    cin >> z;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> z;
    }
    setCostPrice(z);
//---------------------------------------------------------------
    cout << "Enter The Product Sell Price(RM):";
    cin >> z1;
        while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> z1;
    }
    while (z >= z1)
        {
            cout << "========================================================================================================================"<<endl;
            cout << "|                                     Error: Selling price must be higher than the cost price.                         |" << endl;
            cout << "========================================================================================================================"<<endl;
            cout << "Please enter a higher selling price(RM): ";
            cin >> z1;
            while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid. Enter Again: ";
                    cin >> z1;
                }
        }
    setSellPrice(z1);

    cout << "Enter The Product Quantity:";
    cin >> y;
        while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> y;
    }
    setQuantity(y);

    setproductID(counter);
}


void ItemInfo :: setItemToFile()
{
    int counterA = counter;
    const int SIZE = 10;
    productIDarray[counterA] = getproductID();
    productNameArray[counterA] = getName();
    productCostPriceArray[counterA] =getCostPrice();
    productSellPriceArray[counterA] = getSellPrice();
    productQuantityArray[counterA] = getProductQuantity();
    ofstream outFile("productsID.txt", ios::app);
    if (outFile.is_open())
        {
            outFile << setw(4) << setfill('0') << dec << productIDarray[counterA] << " ";
            outFile.close();
        }

    ofstream outFile2("productsName.txt", ios::app);
    if (outFile2.is_open())
        {
            outFile2 << productNameArray[counterA] << " ";
            outFile2.close();
        }

    ofstream outFile3("productCostPrice.txt", ios::app);
    if (outFile3.is_open())
        {
            outFile3 << productCostPriceArray[counterA] << " ";
            outFile3.close();
        }

    ofstream outFile4("productSellPrice.txt", ios::app);
    if (outFile4.is_open())
        {
            outFile4 << productSellPriceArray[counterA] << " ";
            outFile4.close();
        }

    ofstream outFile6("productQuantity.txt", ios::app);
    if (outFile6.is_open())
        {
            outFile6 << productQuantityArray[counterA] << " ";
            outFile6.close();
        }

    ofstream outFile5("counter.txt", ios::trunc);
    if (outFile5.is_open())
        {
            counterA ++ ;
            outFile5 << counterA;
            outFile5.close();
            cout << endl << "Product saved to file." << endl;
        }


}


void ItemInfo :: inputItemFromFile()
{
    ifstream fin("productsID.txt");
    ifstream fin1("productsName.txt");
    ifstream fin2("productCostPrice.txt");
    ifstream fin3("productSellPrice.txt");
    ifstream fin4("productQuantity.txt");


    if (!fin.is_open() || !fin1.is_open() || !fin2.is_open() || !fin3.is_open()|| !fin4.is_open())
    {
        cout << "Error: Unable to open one or more files." << endl;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        fin >> Dis_productIDarray[i];
        cout << "Read product ID: " << Dis_productIDarray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin1 >> Dis_productNameArray[i];
        cout << "Read product Name: " << Dis_productNameArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin2 >> Dis_productCostPriceArray[i];
        cout << "Read product Cost: " << Dis_productCostPriceArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin3 >> Dis_productSellPriceArray[i];
        cout << "Read product Sell: " << Dis_productSellPriceArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++){
        fin4 >> Dis_productQuantityArray[i];
        cout << "Read product Quantity: " << Dis_productQuantityArray[i] << endl;

    }


    fin.close();
    fin1.close();
    fin2.close();
    fin3.close();
    fin4.close();

}



void ItemInfo :: printItemInfo()
{
        system ("CLS");
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "|ID                            :" <<setw(4) << setfill('0') << dec << getproductID() << endl;
        cout << "|Name                          :" << getName() << endl;
        cout << "|Cost Price Per Item(RM)       :" << getCostPrice() <<endl;
        cout << "|Sell Price Per Item(RM)       :" << getSellPrice() <<endl;
        cout << "|Product Quantity              :" << getProductQuantity() << endl;
        cout << "========================================================================================================================" << endl;
}

void ItemInfo :: DisplayItemFromFile()
{
            int SIZE = 10;
            int nothing =0;
            int nothing1 =0;
            ItemInfo getInfo;
            getInfo.inputItemFromFile();
                    system ("CLS");
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                         VIEW PRODUCT                                                 |"<<endl;
        cout << "************************************************************************************************************************"<<endl;

                    for (int i = 1; i < SIZE; i++)
                        {
                            int currentID = getInfo.Dis_productIDarray[i];
                            int nextID = getInfo.Dis_productIDarray[i + 1];

                            if (currentID == 0 && nextID == 0)
                            {
                                break;
                            }
                            else
                            {
                                    cout << "|Product ID                        :" << setw(4) << setfill('0') << dec << currentID << endl;
                                    cout << "|Product Name                      :" << getInfo.Dis_productNameArray[i] << endl;
                                    cout << "|Product Cost Price Per Item(RM)   :" << getInfo.Dis_productCostPriceArray[i] << endl;
                                    cout << "|Product Sell Price Per Item(RM)   :" << getInfo.Dis_productSellPriceArray[i] << endl;
                                    cout << "|Product Quantity                  :" << getInfo.Dis_productQuantityArray[i] << endl;
                                    cout << "========================================================================================================================" << endl;
                            }
}

}

void ItemInfo :: EditProduct()
{
    ifstream fin("productsID.txt");
    ifstream fin1("productsName.txt");
    ifstream fin2("productCostPrice.txt");
    ifstream fin3("productSellPrice.txt");
    ifstream fin4("productQuantity.txt");


    if (!fin.is_open() || !fin1.is_open() || !fin2.is_open() || !fin3.is_open()|| !fin4.is_open())
    {
        cout << "Error: Unable to open one or more files." << endl;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        fin >> Dis_productIDarray[i];
        //cout << "Read product ID: " << Dis_productIDarray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin1 >> Dis_productNameArray[i];
        //cout << "Read product Name: " << Dis_productNameArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin2 >> Dis_productCostPriceArray[i];
        //cout << "Read product Cost: " << Dis_productCostPriceArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++) {
        fin3 >> Dis_productSellPriceArray[i];
        //cout << "Read product Sell: " << Dis_productSellPriceArray[i] << endl;
    }

    for (int i = 1; i < SIZE; i++){
        fin4 >> Dis_productQuantityArray[i];
        //cout << "Read product Quantity: " << Dis_productQuantityArray[i] << endl;

    }

    fin.close();
    fin1.close();
    fin2.close();
    fin3.close();
    fin4.close();
//--------------------------------------------------------------------------------------------------
    char choice;
    int editID;
    int k = 1;

    cout << "Enter the ID of the product you want to edit(Press 0 to quit): ";
    cin >> editID;
    while (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> editID;
        }


    if (editID == '0')
    {
        return;
    }

    k = editID;

    if ( Dis_productIDarray[k] == 0)
    {
        system("CLS");
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                    No Product Information.                                           |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "*                                            Going back to Menu.....Press Enter to continue                            *";
        getch();
        system("CLS");
        return;
    }


    system("CLS");
    //cout << "i is " << i << endl;(for testing)
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                         EDIT PRODUCT                                                 |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "Current details of the product         " << endl;
        cout << "Product ID                             : " << setw(4) << setfill('0') << dec << Dis_productIDarray[k] << endl;
        cout << "Product Name                           : " << Dis_productNameArray[k] << endl;
        cout << "Product Cost Price Per Item(RM)        : " << Dis_productCostPriceArray[k] << endl;
        cout << "Product Sell Price Per Item(RM)        : " << Dis_productSellPriceArray[k] << endl;
        cout << "Product Quantity                       : " << Dis_productQuantityArray[k] << endl;
        cout << "************************************************************************************************************************"<<endl;

    cout << "Confirm You Want To Change(Y/N):";
    cin >> choice;
    system("CLS");

    if (choice == 'Y' || choice == 'y')
    {
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                         EDIT PRODUCT                                                 |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        ItemInfo getInfo;
        cout << "Enter new details for the product:" << endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "Product Name                       : ";
        cin >> Dis_productNameArray[k];

        cout << "Product Cost Price Per Item(RM)    : ";
        cin >> Dis_productCostPriceArray[k];
        while (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> Dis_productCostPriceArray[k];
        }

        cout << "Sell PricePrice Per Item(RM)       : ";
        cin >> Dis_productSellPriceArray[k];
        while (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> Dis_productSellPriceArray[k];
        }

        while (Dis_productCostPriceArray[k] >= Dis_productSellPriceArray[k])
        {
            cout << "========================================================================================================================"<<endl;
            cout << "|                                  Error: Selling price must be higher than the cost price.                            |" << endl;
            cout << "========================================================================================================================"<<endl;
            cout << "Please enter a higher selling price(RM): ";
            cin >> Dis_productSellPriceArray[k];
            while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid. Enter Again: ";
                    cin >> Dis_productSellPriceArray[k];
                }
        }

        cout << "Product Quantity                   : ";
        cin >> Dis_productQuantityArray[k];
        while (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> Dis_productQuantityArray[k];
        }
        system("CLS");


        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                    New Product Infomation                                            |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "New Product ID                         : " << setw(4) << setfill('0') << dec << Dis_productIDarray[k] << endl;
        cout << "New Product Name                       : " << Dis_productNameArray[k] << endl;
        cout << "New Product Cost Price Per Item(RM)    : " << Dis_productCostPriceArray[k] << endl;
        cout << "New Sell Price Per Item(RM)            : " << Dis_productSellPriceArray[k] << endl;
        cout << "New Product Quantity                   : " << Dis_productQuantityArray[k] << endl;
        cout << "************************************************************************************************************************"<<endl;

    ofstream outFile2("productsName.txt", ios::out|ios::trunc);
    if (outFile2.is_open())
    {
        for (int i = 1; i < SIZE; i++)
        {
            outFile2 << Dis_productNameArray[i] << " ";
            //cout << Dis_productNameArray[i] << endl ;
        }
        outFile2.close();
    }

    ofstream outFile3("productCostPrice.txt", ios::out|ios::trunc);
    if (outFile3.is_open())
    {
        for (int i = 1; i < SIZE; i++)
        {
            outFile3 << Dis_productCostPriceArray[i] << " ";
            //cout << Dis_productCostPriceArray[i] << endl ;
        }
        outFile3.close();
    }

    ofstream outFile4("productSellPrice.txt", ios::out|ios::trunc);
    if (outFile4.is_open())
    {
        for (int i = 1; i < SIZE; i++)
        {
            outFile4 << Dis_productSellPriceArray[i] << " ";
            //cout << Dis_productSellPriceArray[i] << endl ;
        }
        outFile4.close();
    }

    ofstream outFile6("productQuantity.txt", ios::out|ios::trunc);
    if (outFile6.is_open())
    {
        for (int i = 1; i < SIZE; i++)
        {
            outFile6 << Dis_productQuantityArray[i] << " ";
            //cout << Dis_productQuantityArray[i] << endl ;
        }
        outFile6.close();
    }

    cout << "Press Enter to continue";
    getch();
    system("CLS");




    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                         EDIT PRODUCT                                                 |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "*Product details remain unchanged.                                    *" << endl;
        cout << "*Press Enter to continue                                              *";
        getch();
        system("CLS");
    }



}

void ItemInfo :: DeleteProduct()
{
    ifstream fin("productsID.txt");
    ifstream fin1("productsName.txt");
    ifstream fin2("productCostPrice.txt");
    ifstream fin3("productSellPrice.txt");
    ifstream fin4("productQuantity.txt");


    if (!fin.is_open() || !fin1.is_open() || !fin2.is_open() || !fin3.is_open()|| !fin4.is_open())
    {
        cout << "Error: Unable to open one or more files." << endl;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        fin >> Dis_productIDarray[i];
    }

    for (int i = 1; i < SIZE; i++) {
        fin1 >> Dis_productNameArray[i];
    }

    for (int i = 1; i < SIZE; i++) {
        fin2 >> Dis_productCostPriceArray[i];
    }

    for (int i = 1; i < SIZE; i++) {
        fin3 >> Dis_productSellPriceArray[i];
    }

    for (int i = 1; i < SIZE; i++){
        fin4 >> Dis_productQuantityArray[i];
    }

    fin.close();
    fin1.close();
    fin2.close();
    fin3.close();
    fin4.close();
//--------------------------------------------------------------------------------------------------
    char choice;
    int deleteID;
    int k = 1;

    cout << "Enter the ID of the product you want to Delete(Press 0 to quit): ";
    cin >> deleteID;
    while (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter Again: ";
        cin >> deleteID;
        }
    k = deleteID;

    if (deleteID == '0')
    {
        return;
    }
    else if ( Dis_productIDarray[k] == 0)
    {
        system("CLS");
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                    No Product Information.                                           |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "*                                            Going back to Menu.....Press Enter to continue                            *";
        getch();
        system("CLS");
        return;
    }


    system("CLS");
    //cout << "i is " << i << endl;(for testing)
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                        DELETE PRODUCT                                                |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "Current details of the product         " << endl;
        cout << "Product ID                             : " << setw(4) << setfill('0') << dec << Dis_productIDarray[k] << endl;
        cout << "Product Name                           : " << Dis_productNameArray[k] << endl;
        cout << "Product Cost Price Per Item(RM)        : " << Dis_productCostPriceArray[k] << endl;
        cout << "Product Sell Price Per Item(RM)        : " << Dis_productSellPriceArray[k] << endl;
        cout << "Product Quantity                       : " << Dis_productQuantityArray[k] << endl;
        cout << "************************************************************************************************************************"<<endl;

    cout << "Confirm You Want To Delete(Y/N):";
    cin >> choice;
    system("CLS");

        if (choice == 'Y' || choice == 'y')
{
    // Remove the product details from arrays
    //Dis_productIDarray[k] = 0;
    Dis_productNameArray[k] = "(Deleted)";
    Dis_productCostPriceArray[k] = 0.0;
    Dis_productSellPriceArray[k] = 0.0;
    Dis_productQuantityArray[k] = 0;

    // Open files for writing
    ofstream fout("productsID.txt");
    ofstream fout2("productsName.txt");
    ofstream fout3("productCostPrice.txt");
    ofstream fout4("productSellPrice.txt");
    ofstream fout6("productQuantity.txt");

    // Check if files are open
    if (!fout.is_open() || !fout2.is_open() || !fout3.is_open() || !fout4.is_open() || !fout6.is_open())
    {
        cout << "Error: Unable to open one or more files for writing." << endl;
        return;
    }

    // Write the updated data to files
    for (int i = 1; i < SIZE; i++)
    {
        int currentID = Dis_productIDarray[i];
        int nextID =Dis_productIDarray[i + 1];

        if (currentID == 0 && nextID == 0)
        {
            break;
        }

        else
        {
        fout << Dis_productIDarray[i] << " ";
        //cout << "ID: " << Dis_productIDarray[i] << endl;

        fout2 << Dis_productNameArray[i] << " ";
        //cout << "Name: " << Dis_productNameArray[i] << endl;

        fout3 << Dis_productCostPriceArray[i] << " ";
        //cout << "Cost: " << Dis_productCostPriceArray[i] << endl;

        fout4 << Dis_productSellPriceArray[i] << " ";
        //cout << "Sell: " << Dis_productSellPriceArray[i] << endl;

        fout6 << Dis_productQuantityArray[i] << " ";
        //cout << "Quantity: " << Dis_productQuantityArray[i] << endl;
        }

    }

    // Close files
    fout.close();
    fout2.close();
    fout3.close();
    fout4.close();
    fout6.close();

        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                        DELETE PRODUCT                                                |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "                                               The Product successfully deleted:                                        "<<endl;
        cout << "*                                                    Press Enter to continue                                           *";
    getch();
    system("CLS");
}



    else if (choice == 'N' || choice == 'n')
    {
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                        DELETE PRODUCT                                                |"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "*                                                 Product details remain unchanged.                                    *" << endl;
        cout << "*                                                    Press Enter to continue                                           *";
        getch();
        system("CLS");
    }

}

void ItemInfo::Checkout()
{
    string proID;
    string productId;
    string productName;
    float costPrice;
    float sellPrice;
    float profit;
    int quantity;
    int purchaseQuantity;

    DisplayItemFromFile();

    cout<<"Enter the product ID you want to purchase [Press 0 back to menu]: ";
    cin>>proID;

    if (proID == "0")
    {
        system("CLS");
        return;
    }

    while (cin.fail() || ! all_of(proID.begin(), proID.end(), ::isdigit)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Invalid input. Please enter a valid product ID (numeric): ";
        cin>>proID;
    }

    system("CLS");

    ifstream idFile("productsID.txt");
    ifstream nameFile("productsName.txt");
    ifstream costPriceFile("productCostPrice.txt");
    ifstream sellPriceFile("productSellPrice.txt");
    ifstream quantityFile("productQuantity.txt");

    ofstream temp1("temp1.txt");
    ofstream temp2("temp2.txt");
    ofstream temp3("temp3.txt");
    ofstream temp4("temp4.txt");
    ofstream temp5("temp5.txt");

    bool found = false;

    while (idFile >> productId && nameFile >> productName &&
           costPriceFile >> costPrice && sellPriceFile >> sellPrice &&
           quantityFile >> quantity)
    {
        if (productId == proID || stoi(productId) == stoi(proID))
        {
            found = true;
            cout << "========================================================================================================================"<<endl;
            cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
            cout << "========================================================================================================================"<<endl;
            cout << "************************************************************************************************************************"<<endl;
            cout << "|                                                           Checkout                                                   |"<<endl;
            cout << "************************************************************************************************************************"<<endl;
            cout << "+-----------------------------------+-------------+--------------+-----+-----------+-----------------------------------+"<<endl;
            cout << "| Product Name               : " <<productName<<endl;
            cout << "| Product Cost Price         : RM" <<costPrice<<endl;
            cout << "| Product Sell Price         : RM" <<sellPrice<<endl;
            cout << "| Product Available Quantity : " <<quantity<<endl;
            cout << "+-----------------------------------+-------------+--------------+-----+-----------+-----------------------------------+"<<endl;

            cout<<"Enter the quantity you want to purchase: ";
            cin>>purchaseQuantity;

            if (purchaseQuantity <= quantity)
            {
                system("CLS");
                profit=(sellPrice-costPrice)*purchaseQuantity;
            cout << "========================================================================================================================"<<endl;
            cout << "+---------------------------------+-------------+--------------------+------------+------------------------------------+"<<endl;
            cout << "|                                                  CHECK OUT SUCCESSFULLY                                              |"<<endl;
            cout << "+---------------------------------+-------------+--------------------+------------+------------------------------------+"<<endl;
            cout << "+---------------------------------+-------------+--------------------+------------+------------------------------------+"<<endl;
            cout << "|Product Name        :" <<productName<<endl;
            cout << "|Total Cost          :RM"<<costPrice*purchaseQuantity<<endl;
            cout << "|Total Sell Price    :RM"<<sellPrice*purchaseQuantity<<endl;
            cout << "|Profit              :RM"<<profit<<endl;
            cout << "+---------------------------------+-------------+--------------------+------------+------------------------------------+"<<endl<<endl<<endl<<endl;

                quantity -= purchaseQuantity; // use this to update

                ofstream salesLog("salesLog.txt", ios::app);
                if (salesLog.is_open()) {
                    salesLog << productId << " " << purchaseQuantity << " " << (sellPrice * purchaseQuantity) << " " << profit << "\n";
                    salesLog.close();
                }

            }

            else
            {
                cout << "========================================================================================================================"<<endl;
                cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
                cout << "========================================================================================================================"<<endl;
                cout << "************************************************************************************************************************"<<endl;
                cout << "|                                                           Checkout                                                   |"<<endl;
                cout << "************************************************************************************************************************"<<endl;
                cout << "+----------------------------------------------------------------------------------------------------------------------+"<<endl;
                cout << "                                                  !!!Insufficient quantity available!!!.                                " << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------------+"<<endl;
            }

            temp1<<productId<<" ";
            temp2<<productName<<" ";
            temp3<<costPrice<<" ";
            temp4<<sellPrice<<" ";
            temp5<<quantity<<" ";
        }
        else
        {
            temp1<<productId<< " ";
            temp2<<productName<< " ";
            temp3<<costPrice<< " ";
            temp4<<sellPrice<< " ";
            temp5<<quantity<<" ";
        }
    }

    idFile.close();
    nameFile.close();
    costPriceFile.close();
    sellPriceFile.close();
    quantityFile.close();
    temp1.close();
    temp2.close();
    temp3.close();
    temp4.close();
    temp5.close();

    remove("productsID.txt");
    rename("temp1.txt", "productsID.txt");

    remove("productsName.txt");
    rename("temp2.txt", "productsName.txt");

    remove("productCostPrice.txt");
    rename("temp3.txt", "productCostPrice.txt");

    remove("productSellPrice.txt");
    rename("temp4.txt", "productSellPrice.txt");

    remove("productQuantity.txt");
    rename("temp5.txt", "productQuantity.txt");

    if (!found)
    {
        cout << "========================================================================================================================"<<endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+"<<endl;
        cout << "                                   Product not found. Please enter a valid product ID."                                  << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------+"<<endl;
    }

    cout<<"Press enter to main menu..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("CLS");

}

void ItemInfo::GenerateSalesReport() {
    string productId;
    int quantitySold;
    double saleAmount, profit;
    double totalRevenue = 0;
    double totalProfit = 0;


    system("CLS");
    cout << "========================================================================================================================"<<endl;
    cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
    cout << "========================================================================================================================"<<endl;
    cout << "************************************************************************************************************************"<<endl;
    cout << "|                                                        SALES REPORT                                                  |"<<endl;
    cout << "************************************************************************************************************************"<<endl;

    ifstream salesLog("salesLog.txt");
    if (!salesLog.is_open()) {
            cout << "You do not have any sales" << endl;
            cout << "========================================================================================================================"<<endl;
            cout << "Press enter to go back main menu..."<<endl;
            getch();
            system("CLS");
            return;
    }

    while (salesLog >> productId >> quantitySold >> saleAmount >> profit) {
        cout << "| Product ID                 : " << productId << endl;
        cout << "| Quantity Sold              : " << quantitySold << endl;
        cout << "| Sale Amount                : RM" << saleAmount << endl;
        cout << "| Profit                     : RM" << profit << endl;
        cout << "========================================================================================================================"<<endl;

        totalRevenue += saleAmount;
        totalProfit += profit;
    }
    cout << "| Total Revenue              : RM" << totalRevenue << endl;
    cout << "| Total Profit               : RM" << totalProfit << endl;
    cout << "========================================================================================================================" << endl;
    cout << "Press enter to continue..."<<endl;

    salesLog.close();
    getch();

    system("CLS");

}

void InsertScreen()
{
    system("CLS");
        cout << "========================================================================================================================"<<endl;
        cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
        cout << "========================================================================================================================"<<endl;
        cout << "************************************************************************************************************************"<<endl;
        cout << "|                                                        INSERT PRODUCT                                                |"<<endl;
        cout << "************************************************************************************************************************"<<endl;

}

void DeleteScreen()
{
     system("CLS");
    cout << "========================================================================================================================"<<endl;
    cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
    cout << "========================================================================================================================"<<endl;
    cout << "************************************************************************************************************************"<<endl;
    cout << "|                                                       DELETE PRODUCT                                                 |"<<endl;
    cout << "************************************************************************************************************************"<<endl;

}


void displayMenu() {
    cout << "========================================================================================================================"<<endl;
    cout << "|                                                  PRODUCT MANAGEMENT SYSTEM                                           |"<<endl;
    cout << "========================================================================================================================"<<endl;
    cout << "************************************************************************************************************************"<<endl;
    cout << "|                                                         MAIN MENU                                                    |"<<endl;
    cout << "************************************************************************************************************************"<<endl;
    cout << "|1. Insert Product                                                                                                     |"<<endl;
    cout << "|2. View Product                                                                                                       |"<<endl;
    cout << "|3. Edit Product                                                                                                       |"<<endl;
    cout << "|4. Delete Product                                                                                                     |"<<endl;
    cout << "|5. Check Out Product                                                                                                  |"<<endl;
    cout << "|6. Generate Sales Report                                                                                              |"<<endl;
    cout << "|7. Exit                                                                                                               |"<<endl;
    cout << "************************************************************************************************************************"<<endl;
}



int main(){

    int id1 = 1, SIZE=10;
    string x;
    int y;
    double z, z1;
    char product_ctn;
    ItemInfo getInfo;
//---------------------------------------------------------------

//-------------------------登入Part----------------------------
    Login_detail L;

	fstream file;
	file.open("login.txt",ios::in);
	file>>L.username>>L.password;
    L.userid();
    file.close();
    system("CLS");
//-------------------------Display Menu Part------------------
    int choice;
    do
    {
        displayMenu();
        cout << "Enter Your Choice: ";
        cin >> choice;

        while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "You can only enter numbers[1-7].";
                cout << "Enter your choice again: ";
                cin >> choice;
            }
//-------------------------选择 Part------------------

        switch (choice) {
            case 1:
                {
                        do
                        {
                            if (getInfo.getCounter() == SIZE)
                            {
                                cout << "Reserve is Full" << endl ;
                                cout << "Press Enter to continue";
                                getch();
                                system("CLS");
                                break;
                            }
                            InsertScreen();
                            getInfo.getItemInfo();
                            //getInfo.setproductID();
                            getInfo.setItemToFile();
                            getInfo.printItemInfo();

                            cout << endl << "Do you want to insert more product? (Y/N): ";
                            cin >> product_ctn;
                            cout << endl << "========================================================================================================================" << endl;
                            system("CLS");
                        } while (product_ctn == 'y' || product_ctn == 'Y');
                }
                break;
            case 2:
                {
                    //getInfo.inputItemFromFile();
                    getInfo.DisplayItemFromFile();
                    cout << "Press Enter to continue";
                    getch();
                    system("CLS");
                }

                break;
            case 3:
                {
                    getInfo.DisplayItemFromFile();
                    getInfo.EditProduct();
                }

                break;
            case 4:
                {
                    getInfo.DisplayItemFromFile();
                    getInfo.DeleteProduct();
                }

                break;
            case 5:
                {
                system("CLS");
                ItemInfo itemInfo;
                itemInfo.DisplayItemFromFile();
                itemInfo.Checkout();
                }
                break;
            case 6:
                {
                    getInfo.GenerateSalesReport();
                }
                break;
            case 7:
                system("CLS");
                    cout << "========================================================================================================================" << endl ;
                    cout << "                                                 [Logout Successfully !]" << endl ;
                    cout << "========================================================================================================================" << endl << endl << endl;

                    cout << "                                    ==================== DEVELOPERS ====================" << endl;
                    cout << "                                   |                                                    |" << endl;
                    cout << "                                  |           TONG DUNG SHING   (1211105439)             |" << endl;
                    cout << "                                  |           SANDY LEE WENXUAN (1211105941)             |" << endl;
                    cout << "                                  |           LEE ZHI QI        (1211105809)             |" << endl;
                    cout << "                                  |           KONG LEE JIE      (1211105824)             |" << endl;
                    cout << "                                  |           IVAN TEE HONG WEI (1211105898)             |" << endl;
                    cout << "                                   |                                                    |" << endl;
                    cout << "                                    ====================================================" << endl << endl;

                break;
            default:
                cout << "**Invalid choice, please try again. Thank you!**" << endl;
                cin.ignore();
        }

    } while (choice != 7);

}






