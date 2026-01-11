#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> genTriangle(int rows) {
    vector<vector<int>> triangle;

    for (int i = 0; i < rows; i++) {
        vector<int> row;

        for (int j = 0; j < i + 1; j++) {

            if (j == 0 || j == i ) {row.push_back(1); continue;};
            
            int num = triangle[i-1][j] + triangle[i-1][j-1];
            row.push_back(num);
        }
        triangle.push_back(row);
    }
    return triangle;
}

int main() {

    cout << "How many rows? ";
    string rows;
    cin >> rows;

    vector<vector<int>> v = genTriangle(stoi(rows));

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
