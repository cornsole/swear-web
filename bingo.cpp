#include <iostream>
using namespace std;

int main() {
	int board[3][3] = {0};
	int x, y, turn=0;
    int gameFinish=0;
	while (gameFinish!=0) {
		turn++;
		cin >> x >> y;
		// 선택된 장소인지 확인
		if (board[x][y] == 0) {
			// 1 = O / 2 = X
			if (turn % 2 == 0) {
				board[x][y] = 1;
			}
			else {
				board[x][y] = 2;
			}
			// 판출력
			for (int i = 0;i < 3;i++) {
				for (int j = 0;j < 3;j++) {
					if (board[i][j] == 1) {
						cout << 'X';
					}else if (board[i][j] == 2) {
						cout << 'O';
					}
					else {
						cout << ' ';
					}
					cout << ' ';
				}
				cout << '\n';
			}

			// 승부 확인
            for (int i=0;i<3;i++){
                int wideCountX=0;
                int wideCountO=0;
                for (int j=0;j<3;j++){
                    if(board[i][j]==1){
                        wideCountX++;
                    }else if(board[i][j]==2){
                        wideCountO++;
                    }
                }
                if(wideCountX==3){
                    cout << "X승리";
                    break;
                }else if(wideCountO==3){
                    cout << "O승리";
                    break;
                }

                
            }

		}
		else {
			cout << "이미선택된.\n";
		}
	}
}