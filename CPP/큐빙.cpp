#include <iostream>
#include <algorithm>

#define WHITE 0
#define YELLOW 1
#define RED 2
#define ORANGE 3
#define GREEN 4
#define BLUE 5

#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

#define ROTATE_CW 1
#define ROTATE_CCW -1

class Cube {
    public:
    short cell[54];
    Cube() {
        for(int i=0; i<6; i++) for(int j=0; j<9; j++) cell[9*i+j] = i;
    }
    short get_color(short face, short point) { return cell[9*face + point]; }
    short i(short face, short point) { return 9*face + point; }
    short locate_face(short target) { return target/9; }
    short locate_point(short target) { return target%9; }
    void print(short face) {
        const char value[] = {'w', 'y', 'r', 'o', 'g', 'b'};
        for(int i=0; i<9; i++) {
            std::cout << value[get_color(face, i)];
            if(i%3 == 2) std::cout << std::endl;
        }
    }
    void rotate(short face, short rotate) {
        short route[3][4];
        if(face == U) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(F,z);
                    route[z][1] = i(R,z);
                    route[z][2] = i(B,z);
                    route[z][3] = i(L,z);
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(F,z);
                    route[z][1] = i(L,z);
                    route[z][2] = i(B,z);
                    route[z][3] = i(R,z);
                }
            }
        } else if(face == D) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(F,z+6);
                    route[z][1] = i(L,z+6);
                    route[z][2] = i(B,z+6);
                    route[z][3] = i(R,z+6);
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(F,z+6);
                    route[z][1] = i(R,z+6);
                    route[z][2] = i(B,z+6);
                    route[z][3] = i(L,z+6);
                }
            }
        } else if(face == F) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,z+6);
                    route[z][1] = i(L,((2-z)*3)+2);
                    route[z][2] = i(D,2-z);
                    route[z][3] = i(R,3*z);
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,z+6);
                    route[z][1] = i(R,3*z);
                    route[z][2] = i(D,2-z);
                    route[z][3] = i(L,((2-z)*3)+2);
                }
            }
        } else if(face == B) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,z);
                    route[z][1] = i(R,3*z+2);
                    route[z][2] = i(D,8-z);
                    route[z][3] = i(L,3*(2-z));
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,z);
                    route[z][1] = i(L,3*(2-z));
                    route[z][2] = i(D,8-z);
                    route[z][3] = i(R,3*z+2);
                }
            }
        } else if(face == L) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,3*z);
                    route[z][1] = i(B,3*(2-z)+2);
                    route[z][2] = i(D,3*z);
                    route[z][3] = i(F,3*z);
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,3*z);
                    route[z][1] = i(F,3*z);
                    route[z][2] = i(D,3*z);
                    route[z][3] = i(B,3*(2-z)+2);
                }
            }
        } else if(face == R) {
            if(rotate == ROTATE_CW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,3*z+2);
                    route[z][1] = i(F,3*z+2);
                    route[z][2] = i(D,3*z+2);
                    route[z][3] = i(B,3*(2-z));
                }
            } else if(rotate == ROTATE_CCW) {
                for(int z=0; z<3; z++) {
                    route[z][0] = i(U,3*z+2);
                    route[z][1] = i(B,3*(2-z));
                    route[z][2] = i(D,3*z+2);
                    route[z][3] = i(F,3*z+2);
                }
            }
        }
        for(int z=0; z<3; z++) {
            short temp = cell[route[z][0]];
            cell[route[z][0]] = cell[route[z][1]];
            cell[route[z][1]] = cell[route[z][2]];
            cell[route[z][2]] = cell[route[z][3]];
            cell[route[z][3]] = temp;
        }
        rotate_face(face, rotate);
    }
    void rotate_face(short face, short rotate) {
        short temp = cell[i(face, 0)];
        short temp2 = cell[i(face, 1)];
        if(rotate == ROTATE_CW) {
            cell[i(face, 0)] = cell[i(face, 6)];
            cell[i(face, 6)] = cell[i(face, 8)];
            cell[i(face, 8)] = cell[i(face, 2)];
            cell[i(face, 2)] = temp;
            cell[i(face, 1)] = cell[i(face, 3)];
            cell[i(face, 3)] = cell[i(face, 7)];
            cell[i(face, 7)] = cell[i(face, 5)];
            cell[i(face, 5)] = temp2;
        } else if(rotate == ROTATE_CCW) {
            cell[i(face, 0)] = cell[i(face, 2)];
            cell[i(face, 2)] = cell[i(face, 8)];
            cell[i(face, 8)] = cell[i(face, 6)];
            cell[i(face, 6)] = temp;
            cell[i(face, 1)] = cell[i(face, 5)];
            cell[i(face, 5)] = cell[i(face, 7)];
            cell[i(face, 7)] = cell[i(face, 3)];
            cell[i(face, 3)] = temp2;
        }
    }
};

int main() {
    int t;
    std::cin >> t;
    while(t-->0) {
        Cube c = Cube();
        int cnt;
        std::cin >> cnt;
        while(cnt-->0) {
            std::string op;
            std::cin >> op;
            short face, rotate;
            switch(op[0]) {
                case 'F':
                face = F;
                break;
                case 'B':
                face = B;
                break;
                case 'L':
                face = L;
                break;
                case 'R':
                face = R;
                break;
                case 'U':
                face = U;
                break;
                case 'D':
                face = D;
                break;
            }
            switch(op[1]) {
                case '+':
                rotate = ROTATE_CW;
                break;
                case '-':
                rotate = ROTATE_CCW;
            }
            c.rotate(face, rotate);
        }
        c.print(U);
    }
}