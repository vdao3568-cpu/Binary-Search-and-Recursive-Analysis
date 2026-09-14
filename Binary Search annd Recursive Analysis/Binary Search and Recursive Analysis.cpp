/**
Name: Vincent Dao
Honor Pledge: I solomnly swear that this is my own work, and not plagerized
*/
//Grok 3.1 used 9/12/26 to help and check with printResult function

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
Name: BinarySearch_I
Purpose: to iteratively search through a sorted vector to find key and to count the amount of comparisons occuring
Return: index of key if it exists, otherwise -1
*/
int BinarySearch_I(vector<int> & numbers, int key, int& comparisons) {
    int low = 0;
    int high = numbers.size()-1;
    comparisons = 0;

    while (high >= low) {
        int mid = (high + low) / 2;

        comparisons++;
        if (numbers[mid] < key) {

            low = mid + 1;
        }

        else if (numbers[mid] > key) {
            comparisons++;
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
Purpose: to recursively search through a sorted vector to find key and to count the amount of comparisons occuring
Return: index of key if it exists, otherwise -1
*/
int BinarySearch_R(vector<int> & numbers, int low, int high, int key, int& comparisons) {

    if (low > high) {
        
        return -1; // not found
    }

    int mid = (high + low) / 2;
    comparisons++;
    // Upper range
    if (numbers[mid] < key) {

        return BinarySearch_R(numbers, mid + 1, high, key, comparisons);
    }

    // Lower Range
    else if (numbers[mid] > key) {
        comparisons++;
        return BinarySearch_R(numbers, low, mid - 1, key, comparisons);
    }

    return mid; // found
}

/**
Name: printResult
Purpose: prints the search result in a consistent format
*/
void printResult(int key, int index, int comparisons, const string& label) {
    cout << label << endl;

    if (index == -1) {

        cout << key << " was not found." << endl;
    }

    else {

        cout << "Found " << key << " at index " << index << "." << endl;
    }

    cout << "Comparisons performed: " << comparisons << endl << endl;
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
    int compsI;
    int compsR;


    //Test1: First Element
    key = 2;
    compsI = 0;
    compsR = 0;
    keyIndex1 = BinarySearch_I(numbers, key, compsI);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key, compsR);

    printResult(key, keyIndex1, compsI, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, compsR, "Key Index #2 (Recursive)");

    //Test2: Last Element
    key = 87;
    compsI = 0;
    compsR = 0;
    keyIndex1 = BinarySearch_I(numbers, key, compsI);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key, compsR);

    printResult(key, keyIndex1, compsI, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, compsR, "Key Index #2 (Recursive)");

    //Test3: Middle Element
    key = 10;
    compsI = 0;
    compsR = 0;
    keyIndex1 = BinarySearch_I(numbers, key, compsI);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key, compsR);

    printResult(key, keyIndex1, compsI, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, compsR, "Key Index #2 (Recursive)");

    //Test4: Missing value below the range
    key = 1;
    compsI = 0;
    compsR = 0;
    keyIndex1 = BinarySearch_I(numbers, key, compsI);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key, compsR);

    printResult(key, keyIndex1, compsI, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, compsR, "Key Index #2 (Recursive)");

    //Test5: Missing value above the range
    key = 90;
    compsI = 0;
    compsR = 0;
    keyIndex1 = BinarySearch_I(numbers, key, compsI);
    keyIndex2 = BinarySearch_R(numbers, 0, numbers.size() - 1, key, compsR);

    printResult(key, keyIndex1, compsI, "Key Index #1 (Iterative)");
    printResult(key, keyIndex2, compsR, "Key Index #2 (Recursive)");
}


int main() {

    runTests();

    return 0;
}   