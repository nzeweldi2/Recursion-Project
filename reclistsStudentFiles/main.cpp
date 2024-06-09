#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{

    std::cout << "Enter a list: ";
    list p = read_list();

    std::cout << "Enter another list: ";
    list q = read_list();

    std::cout << "Echoing the list(s) that you entered below." << std::endl;
    write_list(p);
    write_list(q);

    //std::cout << "Is lat: " << is_lat(p) << std::endl;
    //std::cout << "Member: " << member(p,q) << std::endl;

    //std::cout << "Last: ";
    //write_list(last(p));
    //std::cout << "\n";

    //std::cout << "List pair: ";
    //write_list(list_pair(p,q));
    //std::cout << "\n";

    //std::cout << "Firsts: ";
    //write_list(firsts(p));
    //std::cout << "\n";

    //std::cout << "Flat: ";
    //write_list(flat(p));
    //std::cout << "\n";

    //std::cout << "Two the same: " << two_the_same(p,q) << std::endl;
    //std::cout << "Equal: " << equal(p,q) << std::endl;

    //std::cout << "Total reverse: ";
    //write_list(total_reverse(p))
    //std::cout << "\n";

    //std::cout << "Shape: ";
    //write_list(shape(p));
    //std::cout << "\n";

    //std::cout << "Intersection: ";
    //write_list(intersection(p,q));
    //std::cout << "\n";

    std::cout << "List union: ";
    write_list(list_union(p,q));
    std::cout << "\n";

    return 0;
}
