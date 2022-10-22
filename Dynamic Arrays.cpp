#include <iostream>
#include <stdio.h>
using namespace std;

///////1
void addColumn(int** arr, int rows, int cols, int index);
///////2
void delColumn(int** arr, int rows, int cols, int index);
///////3
bool isSymbols(string str);

int main() {
    
    
    ////////1
    cout << "////////////////////////////////// 1 ///////////////////////////////" << endl;
    int rows1 = 5;
    int cols1 = 5;
    int** array1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        array1[i] = new int[cols1];
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            array1[i][j] = i * cols1 + j;
        }
    }
    cout << "ARRAY: " << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }

    addColumn(array1, rows1, cols1, 3);
    cols1++;

    cout << endl << "NEW ARRAY: " << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < rows1; i++) {
        delete[] array1[i];
    }
    delete[] array1;
    cout << "////////////////////////////////// 1 ///////////////////////////////" << endl << endl;

    
    
    
    
    ///////2
    cout << "////////////////////////////////// 2 ///////////////////////////////" << endl;
    int rows2 = 5;
    int cols2 = 5;
    int** array2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        array2[i] = new int[cols2];
    }
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            array2[i][j] = i * cols2 + j;
        }
    }
    cout << "ARRAY: " << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }

    delColumn(array2, rows2, cols2, 3);
    cols2--;

    cout << endl << "NEW ARRAY: " << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < rows2; i++) {
        delete[] array2[i];
    }
    delete[] array2;
    cout << "////////////////////////////////// 2 ///////////////////////////////" << endl << endl;

    
    
    
    
    ///////3
    cout << "////////////////////////////////// 3 ///////////////////////////////" << endl << endl;
    int answer;
    int count = 1, info = 2;
    string** db = new string * [count];
    for (int i = 0; i < info; i++) {
        db[i] = new string[info];
    }
    do {
        cout << "What do you wnat to do?" << endl << "1. Add new data" << endl << "2. Search data" << endl << "3. See all data" << endl << "4. Exit" << endl;
        cin >> answer;
        if (answer == 1) {
            string name, phone;
            do {
            newDate:
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new phone: ";
                cin >> phone;
                if (phone[0] != '+') {
                    goto newDate;
                }
            } while (isSymbols(phone));
            db[count - 1][0] = name;
            db[count - 1][1] = phone;
            count++;
        }
        else if (answer == 2) {
            string name, phone;
            do {
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone: ";
                cin >> phone;
            } while (phone[1] != '+' && isSymbols(phone));
            for (int i = 0; i < count; i++) {
                if (db[i][0] == name && db[i][1] == phone) {
                    char ans;
                question:
                    cout << "I found it! Do you want to change data? (y / n): ";
                    cin >> ans;
                    if (ans == 'n') {
                        cout << "Ok" << endl;
                        break;
                    }
                    else if (ans == 'y') {
                        string newName, newPhone;
                        do {
                        updateDate:
                            cout << "Enter new name: ";
                            cin >> newName;
                            cout << "Enter new phone: ";
                            cin >> newPhone;
                            if (newPhone[0] != '+') {
                                goto updateDate;
                            }
                        } while (isSymbols(newPhone));
                        db[i][0] = newName;
                        db[i][1] = newPhone;
                        break;
                    }
                    else {
                        goto question;
                    }
                }
            }
        }
        else if (answer == 3) {
            for (int i = 0; i < count - 1; i++) {
                cout << db[i][0] << ": " << db[i][1] << endl;
            }
        }
        else if (answer == 4) {
            cout << "Goodbye!" << endl;
            for (int i = 0; i < count; i++) {
                delete[] db[i];
            }
            delete[] db;
        }
    } while (answer != 4);
}

void addColumn(int** arr, int rows, int cols, int index) {
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols + 1];
        int tmp = 0;
        for (int j = 0; j < cols; j++) {
            if (j == index) {
                newRow[tmp] = 0;
                tmp++;
            }
            newRow[tmp] = arr[i][j];
            tmp++;
        }
        delete[] arr[i];
        arr[i] = newRow;
    }
}

void delColumn(int** arr, int rows, int cols, int index) {
    for (int i = 0; i < rows; i++) {
        int* newRow = new int[cols - 1];
        int tmp = 0;
        for (int j = 0; j < cols; j++) {
            if (j != index) {
                newRow[tmp] = arr[i][j];
                tmp++;
            }
        }
        delete[] arr[i];
        arr[i] = newRow;
    }
}

bool isSymbols(string str) {
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i + 1] < 48 || str[i + 1] > 57) {
            return true;
        }
        return false;
    }
}
