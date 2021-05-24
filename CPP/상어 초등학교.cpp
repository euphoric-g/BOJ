#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define BLANK -1

// #define DEBUG

class Student {
    public:
    int num;
    std::vector<int> prefer;
    Student() {}
    Student(int n) { num = n; }
};

class Classroom {
    public:
    int **seat;
    int size;
    Classroom() {}
    Classroom(int sz) {
        size = sz;
        seat = new int *[size];
        for(int i=0; i<size; i++) {
            seat[i] = new int[size];
            for(int j=0; j<size; j++) {
                seat[i][j] = BLANK;
            }
        }
    }
    void clear(int n) {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                seat[i][j] = n;
            }
        }
    }
    void close() { delete[] seat; }
};

const int xdiff[4] = {0, -1, 0, 1};
const int ydiff[4] = {1, 0, -1, 0};

bool compare_seat(const std::pair<int, int>&a, const std::pair<int, int> &b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

bool compare_students(const Student &a, const Student &b) {
    return a.num < b.num;
}

int main() {
    int n;
    std::cin >> n;
    Classroom room = Classroom(n);
    std::queue<Student> wait;
    std::vector<Student> students;
    for(int i=1; i<=n*n; i++) {
        int num_in;
        std::cin >> num_in;
        Student s = Student(num_in);
        for(int j=0; j<4; j++) {
            int tmp;
            std::cin >> tmp;
            s.prefer.push_back(tmp);
        }
        wait.push(s);
        students.push_back(s);
    }
    while(!wait.empty()) {
        Student cur = wait.front(); wait.pop();
        Classroom temp = Classroom(n);
        temp.clear(0);
        int max_prefer = 0;
        for(const auto& like : cur.prefer) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(room.seat[i][j] == like) {
                        for(int x=0; x<4; x++) {
                            if(i+xdiff[x] >= 0 && i+xdiff[x] < n && j+ydiff[x] >= 0 && j+ydiff[x] < n && room.seat[i+xdiff[x]][j+ydiff[x]] == BLANK) {
                                max_prefer = std::max(max_prefer, ++temp.seat[i+xdiff[x]][j+ydiff[x]]);
                            }
                        }
                    }
                }
            }
        }
        #ifdef DEBUG
        std::cout << "current student number is " << cur.num << std::endl;
        std::cout << "max_prefer = " << max_prefer << std::endl;
        #endif
        std::vector<std::pair<int, int>> good_seat;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(room.seat[i][j] == BLANK && temp.seat[i][j] == max_prefer) {
                    good_seat.push_back(std::pair<int, int>(i, j));
                }
            }
        }
        #ifdef DEBUG
        std::cout << "good_seat.size() = " << good_seat.size() << std::endl;
        for(const auto &seats : good_seat) {
            std::cout << "[" << seats.first << ", " << seats.second << "]\n";
        }
        #endif
        temp.clear(0);
        int max_blank = 0;
        for(const auto& seat : good_seat) {
            for(int x=0; x<4; x++) {
                std::pair<int, int> next = std::pair<int, int>(seat.first + xdiff[x], seat.second + ydiff[x]);
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && room.seat[next.first][next.second] == BLANK) {
                    max_blank = std::max(max_blank, ++temp.seat[seat.first][seat.second]);
                }
            }
        }
        std::vector<std::pair<int, int>> better_seat;
        for(const auto& seat : good_seat) {
            if(room.seat[seat.first][seat.second] == BLANK && temp.seat[seat.first][seat.second] == max_blank) {
                better_seat.push_back(seat);
            }
        }
        std::sort(better_seat.begin(), better_seat.end(), compare_seat);
        #ifdef DEBUG
        std::cout << "better_seat.size() = " << better_seat.size() << std::endl;
        for(const auto &seats : better_seat) {
            std::cout << seats.first << ", " << seats.second << std::endl;
        }
        #endif
        std::pair<int, int> selected = better_seat.front();
        room.seat[selected.first][selected.second] = cur.num;
        temp.close();
    }
    #ifdef DEBUG
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << room.seat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    #endif
    int satisfact = 0;
    std::sort(students.begin(), students.end(), compare_students);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Student st = students[room.seat[i][j]-1];
            int student_cnt = 0;
            for(int x=0; x<4; x++) {
                std::pair<int, int> next = std::pair<int, int>(i+xdiff[x], j+ydiff[x]);
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) {
                    for(const auto &like : st.prefer) {
                        if(room.seat[next.first][next.second] == like) student_cnt++;
                    }
                }
            }
            switch(student_cnt) {
                case 4 :
                satisfact += 1000;
                break;
                case 3 :
                satisfact += 100;
                break;
                case 2:
                satisfact += 10;
                break;
                case 1:
                satisfact++;
                break;
            }
        }
    }
    std::cout << satisfact << std::endl;
}