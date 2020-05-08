#include <iostream>
#include <ostream>
#include "Fixed.hpp"
#include <sstream>
#include <string>
#include <list>

float parse_factor(std::string *temp, int k, float calc, int end, std::list<float> *list); 

float   parse_member(std::string *temp, int k, std::list<float> *list, int inside)
{
    float calc;
    float tmp = 0;
    for (int l = k; l >= 0; l--)
    {
        // while (temp[l] != ")" && l >= 0)
        // {
        //     if (temp[l] == "+" || temp[l] == "-" || temp[l] == "/" || temp[l] == "*")
        //     {
        //         calc = list->front();
        //         list->pop_front();
        //         if (temp[l] == "+")
        //             calc = list->front() + calc;
        //         else if (temp[l] == "-" )
        //             calc = list->front() - calc;
        //         else if (temp[l] == "*")
        //             calc = list->front() * calc;
        //         else if (temp[l] == "/")
        //             calc = list->front() / calc;
        //         list->pop_front();
        //         list->push_front(calc);
        //         std::cout << "calc" << calc << std::endl;
        //     }
        //     l--;
        // }

        std::cout << l << std::endl;
        if (inside == 0)
        { 
            while (temp[l - 2] != ")" && l >= 0)
                l--;
            calc = parse_factor(temp, k, 0, l, list);
            std::cout << "calc" << calc << std::endl;
            inside = 1;
        }
        if (temp[l] == ")")
        {
            std::string ope = temp[l + 1];
            if (l < k - 1)
            {
                tmp = list->front();
                list->pop_front();
                std::cout << tmp << std::endl;
                std::cout << list->front() << std::endl;
            }
            if (ope == "*")
                return (parse_member(temp, l-1, list, 1) * tmp);
            else if (ope == "/")
                return (parse_member(temp, l-1, list, 1) / tmp);
            else if (ope == "-")
                return (parse_member(temp, l-1, list, 1) - tmp);
            else if (ope == "+")
            {
                return (parse_member(temp, l-1, list, 1) + tmp);
                std::cout << "tmp" << tmp << std::endl;
                calc = tmp;
                calc = calc + list->front();
                list->pop_front();
                list->push_front(calc);
            }
            else 
            {
                return (parse_member(temp, l-1, list, 1) + tmp);
            }
        }
        if (temp[l] == "(")
        {
            calc = parse_factor(temp, k, 0, l, list);
            k = l;
            inside = 0;
        }
    }
    list->push_front(calc);
    return calc;
}

float parse_factor(std::string *temp, int k, float calc, int end, std::list<float> *list)
{
    for (int l = k; l >= end; l--)
    {
        if (temp[l] == "*")
        {
            calc = list->front();
            list->pop_front();
            calc = calc * list->front();
            list->pop_front();
            list->push_front(calc);
        }
        else if (temp[l] == "/")
        {
            calc = list->front();
            list->pop_front();
            calc = list->front() / calc ;
            list->pop_front();
            list->push_front(calc);
        }
        else if (temp[l] == "-")
         {
            float tmp = list->front();
            list->pop_front();
            if (temp[l - 2] ==  "*" || temp[l - 2] == "/")
                return (parse_factor(temp, l - 2, 0,end, list) - tmp);
            calc = tmp;
            calc = list->front() - calc;
            list->pop_front();
            list->push_front(calc);
        }
        else if (temp[l] == "+")
        {
            float tmp = list->front();
            list->pop_front();
            if (temp[l - 2] ==  "*" || temp[l - 2] == "/")
                 return (parse_factor(temp, l - 2, 0, end, list) + tmp);
            calc = tmp;
            calc = calc + list->front();
            list->pop_front();
            list->push_front(calc);
        }
    }
    calc = list->front();
    return calc;
}

int main(int argc, char *argv[1])
{
   
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::stringstream ss;     
    
    if (argc != 2)
        return 1;
    ss << argv[1]; 
    std::string *temp= new std::string[1000]; 
    float input;
    Fixed calc;
    //float  *dec = new float[1000];
    Fixed *dec = new Fixed[1000];
    std::list<float> *list = new std::list<float>;
    int j = 0;
    while (!ss.eof()) { 
  
        /* extracting word by word from stream */
        
        ss >> temp[j]; 
        int i = 0;
        if (temp[j].substr(0, 1) == "(")
        {
            std::string tmp = temp[j];
            temp[j] = "(";
            j++;
            temp[j] = tmp;
            temp[j] = tmp.substr(1, tmp.size() -1);
        }
        else if  (temp[j].substr(temp[j].size() - 1, 1) == ")")
        {
            std::string tmp = temp[j];
            temp[j] = temp[j].substr(0, tmp.size() -1);
            std::stringstream(temp[j]) >> input;
            list->push_front(input);
            j++;
            temp[j] = ")";
        }
        if (std::stringstream(temp[j]) >> input)
        {
            dec[i] = Fixed(input); 
            list->push_front(input);
            i++;
        }
        j++;
        /* To save from space at the end of string */
        //temp = "";
    }

    //calc = parse_factor(temp, j, 0, 0, list);
    std::cout << calc << std::endl;
    calc = parse_member(temp, j, list, 0);
    std::cout << calc << std::endl;
}



