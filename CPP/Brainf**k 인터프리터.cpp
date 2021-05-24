#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define MAX_EXEC 50000010
#define MINUS 0
#define PLUS 1
#define SHIFT_LEFT 2
#define SHIFT_RIGHT 3
#define OPEN_JUNCTION 4
#define CLOSE_JUNCTION 5
#define PRINT 6
#define GET 7

#define NO_VISIT 0
#define PASS 1
#define FAIL 2

#define INIT 0
#define RUNNING 1
#define TERMINATES 2
#define LOOPS 3

typedef uint8_t DATA;

class Operation {
    public:
    int type;
    bool simple;
    bool junction;
    int junction_num;
    int next_cur;
    Operation() {}
    Operation(int init) {
        type = init;
        switch(init) {
            case OPEN_JUNCTION:
            simple = false; junction = true;
            break;
            case CLOSE_JUNCTION:
            simple = false; junction = true;
            break;
            default:
            simple = true; junction = false;
            break;
        }
    }
    void set_junction_num(int n) { if(junction) junction_num = n; }
    void set_next(int ind) { if(junction) next_cur = ind; }
};

class InputStream {
    public:
    std::queue<DATA> stream;
    InputStream() {}
    void put(std::string input) {
        for(int i=0; i<input.size(); i++) {
            stream.push(input[i]);
        }
    }
    DATA get() {
        if(!stream.empty()) {
            DATA ret = stream.front();
            stream.pop();
            return ret;
        } else {
            return EOF;
        }
    }
};

class Memory {
    public:
    DATA *array;
    int size;
    int cursor;
    Memory(){}
    Memory(int memsz) {
        size = memsz;
        array = new DATA[memsz];
        for(int i=0; i<memsz; i++) array[i] = DATA(0);
        cursor = 0;
    }
    void free() { delete(array); }
    void move_left() {
        cursor = (cursor+size-1)%size;
    }
    void move_right() {
        cursor = (cursor + 1) % size;
    }
    void plus() { array[cursor]++; }
    void minus() { array[cursor]--; }
    void print() {
        // std::cout << +array[cursor];
    }
    void get(InputStream *pt) { array[cursor] = pt->get(); if(array[cursor] == EOF) array[cursor] = DATA(255); }
    DATA mem_return() { return array[cursor]; }
    void print_debug() {
        for(int i=0; i<size; i++) {
            std::cout << +array[i];
            if(i==cursor) std::cout << "<";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
};

class Program {
    public:
    Operation *code;
    InputStream istream;
    Memory memory;
    int pc;
    int state;
    int code_len;
    int junction_counter;
    std::vector<std::pair<int, int>> junction_entrance;
    std::pair<int, int> last_failed_junc;
    Program() {}
    Program(InputStream is, Memory mem) {
        istream = is; memory = mem; pc = 0;
        state = INIT;
    }
    void close() {
        delete code;
        memory.free();
    }
    int run() {
        int cnt = 0;
        // memory.print_debug();
        while(cnt++ <= MAX_EXEC && state != TERMINATES) {
            exec();
        }
        if(cnt > MAX_EXEC) {
            // memory.print_debug();
            int entrance = junction_entrance[last_failed_junc.first].second;
            int exit = last_failed_junc.second;
            std::cout << "Loops " << entrance << " " << exit << std::endl;
        }
        if(state == TERMINATES) {
            std::cout << "Terminates" << std::endl;
            return TERMINATES;
        }
        return LOOPS;
    }
    int exec() {
        if(state == INIT) {
            state = RUNNING;
        }
        switch(code[pc].type) {
            case PLUS:
            memory.plus();
            pc++;
            break;
            case MINUS:
            memory.minus();
            pc++;
            break;
            case SHIFT_LEFT:
            memory.move_left();
            pc++;
            break;
            case SHIFT_RIGHT:
            memory.move_right();
            pc++;
            break;
            case PRINT:
            memory.print();
            pc++;
            break;
            case GET:
            memory.get(&istream);
            pc++;
            break;
            case OPEN_JUNCTION:
            if(memory.mem_return() == DATA(0)) {
                pc = code[pc].next_cur+1;
            } else {
                pc++;
            }
            break;
            case CLOSE_JUNCTION:
            if(memory.mem_return() != DATA(0)) {
                last_failed_junc = std::pair<int, int>(code[pc].junction_num, pc);
                pc = code[pc].next_cur+1;
            } else {
                pc++;
            }
            break;
        }
        if(pc > code_len) {
            state = TERMINATES;
            return TERMINATES;
        }
        // memory.print_debug();
        return RUNNING;
    }
    static bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.first < b.first;
    }
    void set_code(int cdsz, std::string cin) {
        code_len = cdsz;
        code = new Operation[code_len];
        junction_counter = 0;
        std::vector<std::pair<int, int>> stack;
        for(int i=0; i<code_len; i++) {
            switch(cin[i]) {
                case '-':
                code[i] = Operation(MINUS);
                break;
                case '+':
                code[i] = Operation(PLUS);
                break;
                case '<':
                code[i] = Operation(SHIFT_LEFT);
                break;
                case '>':
                code[i] = Operation(SHIFT_RIGHT);
                break;
                case '.':
                code[i] = Operation(PRINT);
                break;
                case ',':
                code[i] = Operation(GET);
                break;
                case '[':
                code[i] = Operation(OPEN_JUNCTION);
                code[i].set_junction_num(junction_counter);
                junction_entrance.push_back(std::pair<int, int>(junction_counter++, i));
                stack.push_back(std::pair<int, int>(code[i].junction_num, i));
                break;
                case ']':
                code[i] = Operation(CLOSE_JUNCTION);
                code[i].next_cur = stack.back().second;
                code[i].set_junction_num(stack.back().first);
                code[stack.back().second].next_cur = i;
                stack.pop_back();
                break;
            }
        }
    }
};

int main() {
    int t;
    std::cin >> t;
    while(t-->0) {
        int sm, sc, si;
        std::cin >> sm >> sc >> si;
        std::string cmd, input;
        Memory mem = Memory(sm);
        InputStream istream = InputStream();
        std::cin >> cmd;
        std::cin >> input;
        istream.put(input);
        Program program = Program(istream, mem);
        program.set_code(cmd.size(), cmd);
        program.run();
        program.close();
    }
}