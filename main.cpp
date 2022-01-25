#include"User.cpp"
#include"Admin.cpp"
#include"other.cpp"

int main(){
    int option =0;
    char temp[LEN];
    int number;
    char cont = 'y';
    Admin *admin = new Admin[1];
    bool login = false;
    while ((!login)){
        login = admin->authenticate();
        if(!login) cout <<"Please try again!!\n\n";
    }
    cout<<"How many users do you want to add:\t";
    cin >> number;
    cin.ignore();
    User *user = new User [LEN];
    for (int i=0; i < number; i++){
        user[i] = Add_user (i);
        admin->set_username_password(&user[i]);
        cout<<endl;
        cout<<"\n   ----------User "<< i + 1 <<"----------"<< endl;
        cout<<user[i].get_info()<<endl;
    }
    while(option!=9){
        cout << "1: Add user to Denied_list" << endl;
        cout << "2: Remove user from Denied_list" << endl;
        cout << "3: print Denied_list" << endl;
        cout << "4: Search user" << endl;
        cout << "5: Set permissions for users" << endl;
        cout << "6: Print set of permission of users" << endl;
        cout << "7: Check permission of users" << endl;
        cout << "8: Add new user to list"<<endl;
        cout << "9: Quit" << endl;
        cout << "Type your option: \t";
        cin >> option;
        cout << endl;
        cin.ignore();
        switch (option){
        case 1:{
            if (admin->authenticate()){
                char name[LEN];
                cout<<"Enter the username to add denied list:\t";
                cin >> name;
                admin->add_to_denied_list(user, number, name);
                cout <<User::denied_len<<" user(s) in list!!\n";
                break;
            }
            else{
                cout <<"Access denied!!\n";
                break;                
            }
        }

        case 2:{
            if (admin->authenticate()){
                char re_name[LEN]; // remove name;
                cout<<"Enter the username to remove from denied list:\t";
                cin >> re_name;
                admin->remove_from_denied_list(user, number, re_name);
                cout <<User::denied_len<<" user(s) in list!!\n";
                break;
            }
            else{
                cout <<"Access denied!!\n";
                break;                
            }
        }

        case 3:{
            for(int i=0; i < User::denied_len; i++){
                if(User::denied_len = 0){
                    cout <<"Dont have anything in list!!\n";
                    break;
                }
                else{
                cout<<admin->get_denied_list()[i]<<endl;
                }
            }
            cout<<endl;
            break;
        }

        case 4:{
            if (admin->authenticate()){
                char se_name[LEN];
                cout<<"Enter the username to search information:\t";
                cin >> se_name;
                int flag = 0;
                for(int i=0; i < number; i++){
                    if(user[i].search(se_name)!=NULL){
                        cout<<user[i].search(se_name)->get_info()<<endl;
                        flag= 1;
                    }
                }
                if(flag =0) cout <<"Dont have this username!!"<<endl;
                break;
            }
            else{
                cout <<"Access denied!!\n";
                break;                
            }
        }
        case 5:{
            if (admin->authenticate()){
                User::set_permission();
                break;
            }
            else{
                cout <<"Access denied!!\n";
                break;                
            }
        }

        case 6:{
            for(int i=0; i < PER; i++){
                if(User::get_permission()[i][0] != '0'){
                    cout<<User::get_permission()[i]<<endl;
                }
            }
            break;
        }

        case 7:{
            char type_permission[LEN];
            cout<<"Enter your permission:\t";
            cin >> type_permission;
            bool check = User::check_permission(type_permission);
            if(check) cout<<type_permission<<" is added to your account!!\n";
            else cout<<"Dont have this permisson!!\n";
            break;
            }
        
        case 8:{
            if (admin->authenticate()){
                user[number] = Add_user(number);
                admin->set_username_password(&user[number]);
                cout<<endl;
                cout<<"\n   ----------User "<< number + 1<<"----------"<< endl;
                cout<<user[number].get_info()<<endl;
                number++;
                break;
            }
        }
       default:{
           cout<<"Do you want to continue? [y/n]:\t";
           cin >> cont;
           exit;
           }
       }
   }
   return 0;
}

        
