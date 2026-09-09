#include "Header.h"

using namespace std;

void generateArr(vector<int>& arr, int size) {
    srand(time(0));
    arr.resize(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void printArr(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int findMax(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    if (right - left == 1) {
        return max(arr[left], arr[right]);
    }

    int mid = (left + right) / 2;

    int leftMax = findMax(arr, left, mid);

    int rightMax = 0;
    if (mid + 1 <= right) {
        int tempMax = findMax(arr, mid + 1, right);
        rightMax = max(arr[mid + 1] / 2, tempMax);
    }

    return max(leftMax, rightMax);
}

int getN(const string& prompt) {
    int num;
    bool ok;

    do {
        cout << prompt;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ќшибка! ¬ведите число.\n";
            ok = false;
        }
        else {
            ok = true;
        }
    } while (!ok);

    cin.ignore(10000, '\n');
    return num;
}