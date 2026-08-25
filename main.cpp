#include <iostream>
#include <string>
using namespace std;    

class Customer {
    protected:
    string name, mail;
    long long int number;
   
    public:
    void getdata () {
        cout<<"Enter Your Name : ";
        getline(cin, name);
        cout<<"Enter Your EMail : ";
        getline(cin, mail);
        cout<<"Enter Your Phone No. : ";
        cin>>number;}
};

class Book: public Customer {
    protected:
    char bed_type, room_type;
    static int single_[2][5], twin_[2][5], double_[3][5];
    int* room_no = nullptr;
    int i, j, entry_time, exit_time, now_time, days;
    string entry_date, exit_date, now_date;

    public:
    void room () {
        cout<<"Please specify your bedding preference:\n (a)Single Bed\n(b) Twin Bed\n(c) Double Bed"<<endl;
        cin>>bed_type;
        if (bed_type=='a') {
            cout<<"Please specify your comfort preference:\n (a) Standerd Room\n(b) AC Room"<<endl;
            cin>>room_type;
            if (room_type=='a') j=0;
            else if (room_type=='b') j=1;
            for(i=0;i<5;i++){
                    if(single_[j][i]==0) {
                        single_[j][i]=1;
                        room_no = &single_[j][i];
                        cout<<"Your Room No. is : 1"<<j+1<<i+1 <<endl;
                        break;}}}
        else if (bed_type=='b') {
            cout<<"Please specify your comfort preference:\n (a) Standerd Room\n(b) AC Room"<<endl;
            cin>>room_type;
            if (room_type=='a') j=0;
            else if (room_type=='b') j=1;
            for(i=0;i<5;i++){
                    if(twin_[j][i]==0) {
                        twin_[j][i]=1;
                        room_no = &twin_[j][i];
                        cout<<"Your Room No. is : 2"<<j+1<<i+1 <<endl;
                        break;}}}
   
        else if (bed_type=='c') {
            cout<<"Please specify your comfort preference:\n (a) Standerd Room\n(b) AC Room\n(c) Deluxe Room"<<endl;
            cin>>room_type;
            if (room_type=='a') j=0;
            else if (room_type=='b') j=1;
            else if (room_type=='c') j=2;
            for(i=0;i<5;i++){
                if(double_[j][i]==0) {
                    double_[j][i]=1;
                    room_no = &double_[j][i];
                    cout<<"Your Room No. is : 3"<<j+1<<i+1 <<endl;
                    break;}}}
    }

    void time () {
      cout<<"\n\t\t\tRead it Before Filling Further Details"<< endl;
     cout<<"A full daily rental fee is charged if the Check-In time occurs before 08:00 or if the Check-Out time occurs after 20:00. However, in cases where both Check-In and Check-Out occur on the same day, the rental fee will be calculated using a specific hourly rate instead of the daily rate."<<endl;
      cout<<"Enter No of Days Including CheckIn and CheckOut Dates : ";
      cin>>days;
      cout<<"Enter CheckIn Year-Month-Date (00-00-00): ";
      cin>>entry_date;
      cout<<"Enter CheckIn 24-Hour Time (int): ";
      cin>>entry_time;
      cout<<"Enter CheckIOut Year-Month-Date (00-00-00): ";
      cin>>exit_date;
      cout<<"Enter CheckOut 24-Hour Time (int): ";
      cin>>exit_time;}

    friend void room_status (Book b);
};

int Book::single_[2][5] = {0}, Book::twin_[2][5] = {0}, Book::double_[3][5] = {0};

void room_status (Book b) {
    cout<<"Enter Today's Year-Month-Date (00-00-00): ";
    cin>>b.now_date;
    cout<<"Enter Real 24-Hour Time (int): ";
    cin>>b.now_time;
    if(b.room_no != nullptr) {
        if ((b.exit_date<b.now_date) || (b.exit_date==b.now_date && b.exit_time<b.now_time)) {
            *b.room_no = 0;
            cout<<"Now Room is Unoccupied"<<endl;}
        else cout<<"Room is Still Occupied"<<endl;}
}

class Calculate: public Book {
    int room_no, day_fee, days_fee, hour_fee, hours_fee, hour=0;
    float tax, total;
   
    public:
    void rent () {
    cout<<"Enter Your Room No. : ";
    cin>>room_no;
    if(room_no<116) {
        day_fee = 1000;
        hour_fee = 50;}
    else if(room_no<126) {
        day_fee = 2500;
        hour_fee = 100;}
    else if(room_no<216) {
        day_fee = 2000;
        hour_fee = 100;}
    else if(room_no<226) {
        day_fee = 5000;
        hour_fee = 200;}
    else if(room_no<316) {
        day_fee = 3500;
        hour_fee = 150;}
    else if(room_no<326) {
        day_fee = 7000;
        hour_fee = 300;}
    else if(room_no<336) {
        day_fee = 10000;
        hour_fee = 500;}
    }

    void time () {
        if (entry_time>8) {
            days = days - 1;
            hour = 24 - entry_time;}
        if (exit_time<20) {
            days = days - 1;
            hour = hour + exit_time;}
    }

    void calculation () {
        days_fee = day_fee*days;
        hours_fee = hour_fee*hour;
        tax = (days_fee + hours_fee)*0.1;
        total = (int) (tax + days_fee + hours_fee);}

    void display () {
     cout<<"\t\t\tHOTEL BOOKING RECEIPT"<<endl;
     cout<<"Name:              "<<name<<endl;
     cout<<"CheckIn  - "<<entry_date<<" "<<entry_time<<":00"<< endl;
     cout<<"CheckOut - "<<exit_date<<" "<<exit_time<<":00"<< endl;
     cout<<"Days Fee:        Rs."<<days_fee<<endl;
     cout<<"Hour Fee:        Rs."<<hours_fee<<endl; 
     cout<<"Tax (10%):      Rs."<<tax<<endl<<endl;
     cout<<"Total:               Rs."<<total<<endl;}
};

int main() {
   cout<<"\t Welcome to Akka Hotels \n\t /__\\ Your Moving Home"<<endl;
   Calculate c1;
   c1.getdata();
   c1.room();
   c1.Book::time();
   c1.rent();
   c1.time();
   c1.calculation();
   c1.display();
   room_status(c1);
}

