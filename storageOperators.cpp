/*
Here's a C++ project that uses storage operators new and delete to 
implement a simple dynamic array for storing integers. This project 
allows you to add, remove, and display integers in the dynamic array

*/

#include <iostream>

class DynamicArray {
public:
    DynamicArray() {
        size = 0;
        capacity = 5;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void Add(int value) {
        if (size == capacity) {
            // If the array is full, double its capacity
            int* tempArr = new int[capacity * 2];
            for (int i = 0; i < size; ++i) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr = tempArr;
            capacity *= 2;
        }
        arr[size++] = value;
    }

    void Remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index. Cannot remove element." << std::endl;
            return;
        }

        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void Display() {
        std::cout << "Dynamic Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* arr;
    int size;
    int capacity;
};

int main() {
    DynamicArray myArray;

    myArray.Add(5);
    myArray.Add(10);
    myArray.Add(15);
    myArray.Add(20);

    myArray.Display(); // Output: Dynamic Array: 5 10 15 20

    myArray.Remove(1); // Remove the element at index 1 (10)
    myArray.Display(); // Output: Dynamic Array: 5 15 20

    return 0;
}


/*
In this project, we create a DynamicArray class that uses new to 
allocate memory dynamically for an integer array. The array's 
capacity is doubled when it's full to accommodate more elements. 
The Add method adds elements to the array, the Remove method 
removes an element by its index, and the Display method displays 
the contents of the dynamic array. Finally, the destructor 
(~DynamicArray) deallocates the memory when the object goes out 
of scope.
*/