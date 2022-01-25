#include"other.h"

User Add_user(int i){
  char first[LEN], sur[LEN];
  int phone;
  User temp_obj;
  cout << "Enter infomation of User " << i+1 <<":"<<endl;
  fflush(stdin);
  cout << "Enter Firstname of new User: ";
  //cin.ignore();
  cin.getline(first,LEN,'\n');
  cout << "Enter Surname of new User : ";
  //cin.ignore();
  cin.getline(sur,LEN,'\n');
  cout << "Enter phone number: ";
  cin >> phone;
  
  temp_obj.update(first,sur,phone);         // add new user
  return temp_obj;
}