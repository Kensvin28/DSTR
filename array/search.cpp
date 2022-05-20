#include "data.hpp"
#include "sort.hpp"
#include "display.hpp"
#include "array.hpp"
#include <iostream>
using namespace std;

//dummy
Tutor clone_array[100];
Tutor tutor_array[100];

//binary search
int search_by_tutor_id(Tutor* input_array, int low, int high, int id){
    if (low <= high) {
        int middle = (low + high)/2;
        if (input_array[middle].tutor_ID == id) return middle;
        else if (input_array[middle].tutor_ID > id) return search_by_tutor_id(input_array, low, middle - 1, id);
        else return search_by_tutor_id(input_array, middle + 1, high, id);
    }
    return -1;
}

int search_by_tutor_rating(Tutor* input_array, int low, int high, int rating){
    int index = -1;
    while (low <= high){
        int middle = (low + high) / 2;
        if (input_array[middle].rating == rating){
            index = middle;
            high = middle - 1;
        }
        else if (rating < input_array[middle].rating){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    return index;
}

void print_tutor_by_rating(Tutor* input_array, int rating, int index){
    while (input_array[index].rating == rating){
        display_detailed(input_array, index);
        index = index + 1;
    }
}

void search(){
    int choice;
    int array_size = get_tutor_array_size();
    
    do {
        display_separator();
        cout << "Search Tutor";
        display_separator();
        cout << endl;
        cout << "1. Search tutor by tutor ID" << endl;
        cout << "2. Search tutor by rating" << endl;
        cout << "0. Return to main menu" << endl;
        cin >> choice;
        
        //copy array
        for(int i = 0; i < array_size; i++){
            clone_array[i] = tutor_array[i];
        }

        if (choice == 1) {
            int id;
            do {
                quick_sort(clone_array, 0, array_size - 1, "ID");
                cout << "Input tutor ID to be searched: ";
                cin >> id;
                
                int index = search_by_tutor_id(clone_array, 0, array_size - 1, id);
                if (index == -1) {
                    cout << "Tutor is not registered in the database.";
                } 
                else {
                    display_detailed(tutor_array, index);
                }

                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
            } while (choice == 1);
        }
        else if (choice == 2) {
            int rating;
            do {
                count_sort(clone_array, array_size);
                cout << "Input tutor rating to be searched: ";
                cin >> rating;
                
                int index = search_by_tutor_rating(clone_array, 0, array_size - 1, rating);
                if (index == -1) {
                    cout << "Tutor with rating " << rating << "is not found.";
                } 
                else {
                    print_tutor_by_rating(clone_array, rating, index);
                }

                cout << "Type 1 to do another search or any other key to return: ";
                cin >> choice;
            } while (choice == 1);
        }
        else if (choice != 0) {
            cout << "Invalid input";
        }
    } while(choice <= 0 && choice >= 2);
}
