#include <iostream>
#include <vector>

using namespace std;

struct Hexagon {
    Hexagon(const char& name, const int& i, const int& j, const int& n, const int& m) {
        Name = name;
        Line = i;
        Column = j;
        reflect(n, m);
    }

    void reflect(const int& n, const int& m) {
        Line = n - 1 - Line;
        Column = m - 1 - Column;
    }

    char Name;
    int Line;
    int Column;
};

char find_a_letter(const vector<Hexagon>& v, const int& i, const int& j) {
    for (Hexagon h : v) {
        if (h.Line == i && h.Column == j) return h.Name;
    }
    return ' ';
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Hexagon> hexagons;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ij;
            cin >> ij;
            if (ij >= 'A' && ij <= 'Z') {
                hexagons.push_back(Hexagon(ij, i, j, n, m));
            }
        }
    }
    //cout << "\n\n\n\n";
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m ; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) cout << '.';
            else if (find_a_letter(hexagons, i, j) != ' ') cout << find_a_letter(hexagons, i, j);
            else if (find_a_letter(hexagons, i - 1, j) != ' ' || find_a_letter(hexagons, i + 1, j) != ' ') cout << '_';
            else if (find_a_letter(hexagons, i, j + 1) != ' ' || find_a_letter(hexagons, i - 1, j - 1) != ' ') cout << '/';
            else if (find_a_letter(hexagons, i, j - 1) != ' ' || find_a_letter(hexagons, i - 1, j + 1) != ' ') cout << '\\';
            else cout << '.';
        }
        cout << endl;
    }


    return 0;
}

