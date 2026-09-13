/**
Name: Vincent Dao
Honor Pledge: I solomnly swear that this is my own work, and not plagerized
*/
//Grok 3.1 used 9/12/26 to help and check with printResult function

#include <iostream>
#include <vector>
using namespace std;

/**
Name: BinarySearch_I
Purpose: to iteratively search through a sorted vector to find key
Return: index of key if it exists, otherwise -1
*/
int BinarySearch_I(vector<int> & numbers, int key) {
    int low = 0;
    int high = numbers.size()-1;

    while (high >= low) {
        int mid = (high + low) / 2;

        if (numbers[mid] < key) {

            low = mid + 1;
        }

        else if (numbers[mid] > key) {

            high = mid - 1;
        }

        else {
            return mid; // found
        }
    }

    return -1; // not found
}

/**
Name: BinarySearch_R
Purpose: to recursively search through a sorted vector to find key
Return: index of key if it exists, otherwise -1
*/
int BinarySearch_R(vector<int> & numbers, int low, int high, int key) {

    if (low > high) {
        
        return -1; // not found
    }

    int mid = (high + low) / 2;

    // Upper range
    if (numbers[mid] < key) {

        return BinarySearch_R(numbers, mid + 1, high, key);
    }

    // Lower Range
    else if (numbers[mid] > key) {

        return BinarySearch_R(numbers, low, mid - 1, key);
    }

    return mid; // found
}

/**
Name: printResult
Purpose: prints the search result in a consistent format
*/
void printResult(int key, int index, const string& label) {
    cout << label << endl;

    if (index == -1) {

        cout << key << " was not found." << endl;
    }

    else {

        cout << "Found " << key << " at index " << index << "." << endl;
    }

    cout<<endl;
}

/**
Name: runTests
Purpose: tests the limits and bounds of binarySearch_R and binarySearch_I
*/
void runTests() {

    vector<int> numbers = {2, 4, 7, 9, 10, 11, 32, 45, 87};
    int key;
    int keyIndex1;
    int keyIndex2;


    //Test1: First Element
    key = 2;
    keyIndex1 = BinarySearch_I(numbers, key);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key);

    printResult(key, keyIndex1, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, "Key Index #2 (Recursive)");

    //Test2: Last Element
    key = 87;
    keyIndex1 = BinarySearch_I(numbers, key);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key);

    printResult(key, keyIndex1, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, "Key Index #2 (Recursive)");

    //Test3: Middle Element
    key = 10;
    keyIndex1 = BinarySearch_I(numbers, key);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key);

    printResult(key, keyIndex1, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, "Key Index #2 (Recursive)");

    //Test4: Missing value below the range
    key = 1;
    keyIndex1 = BinarySearch_I(numbers, key);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key);

    printResult(key, keyIndex1, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, "Key Index #2 (Recursive)");

    //Test5: Missing value above the range
    key = 90;
    keyIndex1 = BinarySearch_I(numbers, key);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key);

    printResult(key, keyIndex1, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, "Key Index #2 (Recursive)");
}


int main() {

    runTests();

    return 0;
}   