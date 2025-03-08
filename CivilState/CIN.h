#pragma once

#include <iostream>
#include <string>

namespace CivilState {
    template<class Obj>
    class CIN 
    {
    public: 
        CIN();
        ~CIN();

        std::string getName() const;
        std::string getFirstName() const;

    private:
        std::string name;
        std::string firstName;  
        Obj *obj;
    };
}