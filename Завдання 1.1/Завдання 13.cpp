
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

#include "myfunc.h"

enum Country {
    Ukraine,
    USA,
    Canada,
    France,
    Germany,
    Australia,
    Japan,
    China,
    India,
    Brazil
};

const char* country_to_str(Country c) {
    switch (c)
    {
    case Ukraine:
        return "Ukraine";
    case USA:
        return "USA";
    case Canada:
        return "Canada";
    case France:
        return "France";
    case Germany:
        return "Germany";
    case Australia:
        return "Australia";
    case Japan:
        return "Japan";
    case China:
        return "China";
    case India:
        return "India";
    case Brazil:
        return "Brazil";
    default:
        return "Undefined";
    }
}

struct Node {
    string name;
    int count_calories = 0;
    Country country = Brazil;
    Node* next = nullptr;

    void print() {
        cout << "{ name: " << this->name
            << "; count calories: " << this->count_calories
            << "; country: " << country_to_str(this->country)
            << "}";
    }
};

class List {
private:
    Node* Head = nullptr;
    Node* Tail = nullptr;
    int length = 0;
public:
    void append(Node* item) {
        if (this->length) {
            this->Tail->next = item;
            this->Tail = item;
        }
        else {
            this->Head = item;
            this->Tail = item;
        }
        this->length++;
    }

    Node* append_new(string name, int count_calories, Country country) {
        Node* new_node = new Node;
        new_node->name = name;
        new_node->count_calories = count_calories;
        new_node->country = country;
        append(new_node);
        return new_node;
    }

    void appendleft(Node* item) {
        if (this->length) {
            this->Head->next = item;
            this->Head = item;
        }
        else {
            this->Head = item;
            this->Tail = item;
        }
        this->length++;
    }

    void remove(Node* item) {
        for (Node* current_item = this->Head; current_item != nullptr; current_item = current_item->next) {
            if (current_item->next == item)
            {
                if (item == this->Head)
                    this->Head = item->next;
                if (item == this->Tail)
                    this->Tail = current_item;

                current_item->next = item->next;
                this->length--;
                return;
            }
            current_item = current_item->next;
        }
    }

    void print() {
        cout << "[";
        for (Node* item = this->Head; item != nullptr; item = item->next) {
            item->print();
            if (item != this->Tail)
                cout << ", ";
        }
        cout << "]" << endl;
    }


    Node* begin() {
        return this->Head;
    }

    Node* end() {
        return nullptr;
    }

    int size() {
        return this->length;
    }
};



void task_13() {
    List list = List();

    list.append_new("Apple", 52, Country::USA);
    list.append_new("Banana", 96, Country::Brazil);
    list.append_new("Orange", 43, Country::Japan);
    list.append_new("Strawberry", 29, Country::USA);
    list.append_new("Grapes", 69, Country::India);
    list.append_new("Pineapple", 50, Country::Ukraine);
    list.append_new("Watermelon", 30, Country::China);
    list.append_new("Mango", 60, Country::India);
    list.append_new("Peach", 39, Country::USA);
    list.append_new("Pear", 57, Country::China);

    cout << "length : " << list.size() << endl;

    int count = 0;
    for (Node* item = list.begin(); item != list.end(); item = item->next) {
        if (item->country == Ukraine) {
            item->print();
            cout << endl;
        }
        if (item->count_calories < 300)
            count++;
    }

    cout << "count food on (count_calories<300) : " << count << " food(s)" << endl;
}