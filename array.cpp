#include <iostream>
using namespace std;

int main() {
	int num[11] = { 23, 58, 46, 17, 33, 98, 5, 68, 72, 12, 51 };
	int temp = 0;

	for (int i = 0;i < 11;i++) {
		int max = 0;
		for (int j = 0;j < 11-i;j++) {
			if (num[max] < num[j]) {
				max = j;
			}
		}
		//cout << num[max] << '\n';
		temp = num[10-i];
		num[10 - i] = num[max];
		num[max] = temp;

	}
    
    for (int i = 0;i < 11;i++) {
    	cout << num[i] << ' ';
    }
    cout << '\n';

}