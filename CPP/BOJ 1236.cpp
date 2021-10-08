#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, m;
    std::cin >> n >> m;
    bool row[51];
    bool column[51];
    for(int i=0; i<n; i++) {
        row[i] = false;
    }
    for(int i=0; i<m; i++) {
        column[i] = false;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char get;
            std::cin >> get;
            if(get == 'X') {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    std::vector<int> false_row;
    std::vector<int> false_column;
    for(int i=0; i<n; i++) {
        if(!row[i]) false_row.push_back(i);
    }
    for(int i=0; i<m; i++) {
        if(!column[i]) false_column.push_back(i);
    }
    std::cout << std::max(false_row.size(), false_column.size()) << std::endl;
}