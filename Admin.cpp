#include"other.h"
#include"Admin.h"
bool Admin::authenticate(){
  cout << "Login as Admin:"<<endl;
  char name[LEN], pass[LEN];
  cout << "Enter username: ";
  cin >> name;
  cout << "Enter password: ";
  cin >> pass;
  if (strcmp(this->username,name) == 0 && strcmp(this->password, pass) == 0){      // check the username and password of admin
    cout << endl;
    return true;
    
  }
  return false;
}



void Admin::set_username_password(User* user){
  char name[LEN];
  char pass[LEN];
  cout << "set username and password: " << endl;
  while(!this->authenticate()){           // authenticate the admin to set username
    cout << "Action failed, please try again!"<< endl;
  }
    cout << "enter the username for new user: ";
    cin.ignore();
    cin.getline(name,LEN);
    strcpy(user->username,name);
    cout << "enter the password for new user: ";
    cin.getline(pass,LEN);
    strcpy(user->password,pass);
    
}

void Admin::add_to_denied_list(User* list, int N, char* username){
    int check = 0;
    for (int i = 0; i < N; i++){
        if (!strcmp(list[i].get_username(),username)) {
            check = 1;
        }
    }

    if (check != 0) {
        char** temp_list = User::Denied_list;           

        User::denied_len++;         
        User::Denied_list = new char*[User::denied_len];  

        for (int i = 0; i < User::denied_len;i++) {
            User::Denied_list[i] = new char[LEN];
        }

        for (int i = 0; i < User::denied_len-1;i++){
            strcpy(User::Denied_list[i],temp_list[i]);
        }
        strcpy(User::Denied_list[User::denied_len-1],username);    
        cout << username << " is added to Denied list! "<< endl;
    } 

    else cout << "the username is not available!" << endl;
    cout << endl;
}

void Admin::remove_from_denied_list(User*list, int N, char* username){
    int pos = -1;   
    for (int i = 0; i < User::denied_len; i++){
        if(!strcmp(User::Denied_list[i],username)){             
          pos = i;
        }
    }
    if (pos < 0) {
        cout << "This username is not in Denied List!\n" << endl;
        return;
    } 
    User::denied_len--;
    for(int i=0; i< User::denied_len; i++){
        User::Denied_list[i] = User::Denied_list[i+1];
    }
    cout << username << " is successfully removed from Denied List!" << endl;
    cout << endl;
}

char** Admin::get_denied_list(){
    return User::Denied_list;
}