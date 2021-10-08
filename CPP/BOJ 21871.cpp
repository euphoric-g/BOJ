#include <iostream>

int main() {
    long long n, k;
    std::cin >> n >> k;
}

/*

|y| = |y-k| 이면 오염
|x| >= |y| && |x| >= |y-k| 이면 오염

max(|x|, |y|)

3 3 3 3 3 3 3
3 2 2 2 2 2 3
3 2 1 1 1 2 3
3 2 1 0 1 2 3
3 2 1 1 1 2 3
3 2 2 2 2 2 3
3 3 3 3 3 3 3

max(|x|, |y-3|)

3 2 1 0 1 2 3
3 2 1 1 1 2 3
3 2 2 2 2 2 3
3 3 3 3 3 3 3
4 4 4 4 4 4 4
5 5 5 5 5 5 5
6 6 6 6 6 6 6

max(|x|, |y-2|)

3 2 1 1 1 2 3
3 2 1 0 1 2 3
3 2 1 1 1 2 3
3 2 2 2 2 2 3
3 3 3 3 3 3 3
4 4 4 4 4 4 4
5 5 5 5 5 5 5

max(|x|, |y-1|)

3 2 2 2 2 2 3
3 2 1 1 1 2 3
3 2 1 0 1 2 3
3 2 1 1 1 2 3
3 2 2 2 2 2 3
3 3 3 3 3 3 3
4 4 4 4 4 4 4

compare(1)

X X O O O X X
X X X O X X X
X X X O X X X
X X O O O X X
X O O O O O X
O O O O O O O
O O O O O O O

compare(2)

X O O O O O X
X X O O O X X
X X X X X X X
X X O O O X X
X O O O O O X
O O O O O O O
O O O O O O O

compare(3)

X O O O O O X
X X O O O X X
X X O O O X X
X O O O O O X
O O O O O O O
O O O O O O O
O O O O O O O

사이드 ( x = 1 ~ x = n )

y = k 인 지점


|x|

3 2 1 0 1 2 3
3 2 1 0 1 2 3
3 2 1 0 1 2 3
3 2 1 0 1 2 3
3 2 1 0 1 2 3
3 2 1 0 1 2 3
3 2 1 0 1 2 3

|y-2|

1 1 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 1 1
2 2 2 2 2 2 2
3 3 3 3 3 3 3
4 4 4 4 4 4 4
5 5 5 5 5 5 5