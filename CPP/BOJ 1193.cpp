#include <cstdio>
#include <iostream>
#include <vector>

std::vector<int> my(int a) {
	int i=0, sum = 1;
	while(1) {
		sum += i++;
		if(sum>a) {
			sum -= i-1;
			break;
		}
	}
	if(i%2 == 0) {
		// printf("%d/%d\n", i-(a%sum+1),a%sum+1);
		return std::vector<int>{i-(a%sum+1), a%sum + 1};
	} else {
		// printf("%d/%d\n", a%sum+1, i-(a%sum+1));
		return std::vector<int>{a%sum+1, i-(a%sum+1)};
	}
}

std::vector<int> test(int x){
	int i = 0, j = 0, sum = 0, temp, n1, n2;
	if(x == 1){
		return std::vector<int>{1, 1};
	}
	
	while(1){
		i++;
		temp = sum;
		sum += i;
		if(temp < x && x <= sum) break;
	}
	
	i++;
	
	n1 = i - (x - temp);
	n2 = i - n1;
	// std::cout << x << " : " << n1 << ", " << n2 << '\n';
	if(i % 2 == 0) return std::vector<int>{n1, n2};
	else return std::vector<int>{n2, n1};
}

int main() {
	for(int input = 1; input <= 10000000; input++) {
		auto myr = my(input);
		auto testr = test(input);
		if(myr[0] != testr[0] || myr[1] != testr[1]) {
			std::cout << "ERROR ON " << input << " : (" << myr[0] << ", " << myr[1] << ") vs (" << testr[0] << ", " << testr[1] << ")\n";
		}
	}
	return 0;
}
