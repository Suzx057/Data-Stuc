#include <iostream>
#include <vector>
using namespace std;

int main() {

    int rows , cols , extreaCols;
    cin>>rows>>cols>>extreaCols;
    // สร้าง Matrix 6x2 จากอินพุต
    vector<vector<int>> matrix(rows, vector<int>(cols));
    vector<int> rowSums(rows, 0);   // เก็บผลรวมแต่ละแถว
    vector<int> colSums(cols, 0);   // เก็บผลรวมแต่ละคอลัมน์

    // รับอินพุต
    cout << "Enter " << rows * cols << " numbers:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
            rowSums[i] += matrix[i][j]; // คำนวณผลรวมแต่ละแถว
            colSums[j] += matrix[i][j]; // คำนวณผลรวมแต่ละคอลัมน์
        }
    }

    // แสดง Matrix พร้อมผลรวมแต่ละแถว
    cout << "Matrix with Row Sums:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << rowSums[i] << endl; // แสดงผลรวมแถว
    }

    // แสดงผลรวมคอลัมน์
    cout << "Col Sums: ";
    for (int j = 0; j < cols; ++j) {
        cout << colSums[j] << " ";
    }
    cout << endl;

    return 0;
}
