#pragma once

#include"other.h"

class Admin{
  char username[LEN] = "admin";
  char password[LEN] = "admin";

  public:
    ~Admin(){
      cout << "Admin is destroyed! " << endl;
    }
    bool authenticate();            // function to authenticate admin

    void set_username_password(User* user);

    static void add_to_denied_list(User* list,int N,char* username);

    static void remove_from_denied_list(User* list, int N,char*username);

    static char** get_denied_list();
    
    //void set_password(User* user);
};
