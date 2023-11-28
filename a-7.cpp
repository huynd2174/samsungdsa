#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

void floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    if (sr < 0 || sc < 0 || sr >= ROWS || sc >= COLS || image[sr][sc] != oldColor) {
        return;
    }

    image[sr][sc] = newColor;

    floodFillDFS(image, sr + 1, sc, newColor, oldColor);
    floodFillDFS(image, sr - 1, sc, newColor, oldColor);
    floodFillDFS(image, sr, sc + 1, newColor, oldColor);
    floodFillDFS(image, sr, sc - 1, newColor, oldColor);
}

void printImage(const vector<vector<int>>& image) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1}
    };

    cout << "Original Image:" << endl;
    printImage(image);

    floodFillDFS(image, 1, 2, 2, image[1][2]);

    cout << "\nImage after Flood Fill:" << endl;
    printImage(image);

    return 0;
}
