#ifndef USER_HPP
#define USER_HPP
#include <iostream>

using namespace std;

class User
{
private:
    int idUser;
    string username, password;

public:
    //getData
    int getidUser()
    {
        return this->idUser;
    }
    string getUsername()
    {
        return this->username;
    }
    string getPassword()
    {
        return this->password;
    }

    void setUsername(string username)
    {
        this->username = username;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
};


#endif // USER_HPP
