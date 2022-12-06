#include <iostream>
#include <string>

using namespace std;

struct menu {
    string name;
    double price;
};

menu foods[] = {
    {"Chicken Burger\t\t", 20000}, {"Beef Burger\t\t", 25000}, {"Double Beef Burger\t", 35000}, {"French Fries\t\t", 15000}, {"Snack Plater\t\t", 20000}
};
    
menu beverages[] = {
    {"Lemonade\t\t", 15000}, {"Hot/Iced Lemon Tea \t", 12000}, {"Hot/Iced Jasmine Tea \t", 12000}, {"Hot/Iced Latte \t\t", 18000}, {"Americano\t\t", 15000}, {"Hot/Iced Chocolate \t", 18000}
};

double tax(double subTotal){
    int taxedPrice;
    taxedPrice = subTotal * 10/100;
    return subTotal + taxedPrice;
}

void display(menu item[], int size){
    for(int i = 0; i < size; i++){
        cout << i+1 << ".\t" << item[i].name << '\t' << "Price: \t" << item[i].price << endl;
    }
}

int main() {
    double subTotal = 0.0;
    startover:
    cout<<"======================================================"<<endl;
    cout<<"Choose Your Desire Menu"<<endl;
    cout<<"======================================================"<<endl;
    cout<<"1. Food"<<"\n2. Beverage"<<endl;
    cout<<"======================================================"<<endl;
    
    int menu;
    cin>>menu;
    system("clear");
    
    int temp, size, quantity;
    if (menu == 1){
        cout<<"======================================================"<<endl;
        size = sizeof(foods)/sizeof(foods[0]);
        display(foods, size);
        cout<<"======================================================"<<endl;
        cout<<"FOODS"<<endl;
        cout<<"======================================================"<<endl;
        cout<<"Coose your menu item"<<endl;
        
        cin>>temp;
        
        cout<<"How many "; cin>>quantity;
        subTotal += foods[temp-1].price*quantity;
    } else {
        cout<<"======================================================"<<endl;
        size = sizeof(beverages)/sizeof(beverages[0]);
        display(beverages, size);
        cout<<"======================================================"<<endl;
        cout<<"BEVERAGES"<<endl;
        cout<<"======================================================"<<endl;
        cout<<"Coose your menu item"<<endl;
        
        cin>>temp;
        cout<<"How many "; cin>>quantity;
        subTotal += beverages[temp-1].price*quantity;
    }
    
    system("clear");
    char option;
    cout<<"any other item \nyou want to add? [y/n] "; cin>>option;
    
    if (option == 'y' || option == 'Y') {
        goto startover;
    }
    cout<<"======================================================"<<endl;
    cout<<"Your Subtotal is: \t\t"<<subTotal;
    cout<<"\nTax is: \t\t\t 10%\n";
    cout<<"Your Total: \t\t\t"<<tax(subTotal)<<'\n';
    cout<<"======================================================"<<endl;
    
    return 0;
}
