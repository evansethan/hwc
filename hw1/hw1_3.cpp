#include <iostream>
#include <string>
#include <vector>
#include <format>
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
    int rows;
    cin >> rows;
    int w = 4;

    vector<vector<int>> tri = genTriangle(rows);

    for(int i = 0; i < tri.size(); i++) {
        string row;
        for(int j = 0; j < tri[i].size(); j++) {
            row += format("{:^{}}", tri[i][j], w);    
        }
        cout << format("{:^{}}", row, rows * w) << endl;
    }
    return 0;
}
