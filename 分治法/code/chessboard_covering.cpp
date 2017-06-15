#include <iostream>
#include <vector>
using namespace std;


/**
 * @brief �������
 * @param[in] chessboard ��������
 * @return ��
 */
void 
print_chessboard(vector<vector<char>>& chessboard) {
	int n_rows = chessboard.size();
	int n_columns = chessboard[0].size();
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_columns; j++) {
			cout << chessboard[i][j];
		}
		cout << endl;
	}
}

class ChessboardCovering {
private:
	char mark_;
	struct Coord {
		int row;
		int column;
		Coord(int x, int y) : row(x), column(y) {}
	};
public:
	ChessboardCovering() : mark_('c') {}
private:
	/**
	 * @brief ���̸�����������.
	 * @param[inout] chessboard ��������,��ά����
	 * @param[in] topleft �������Ͻǵ�λ��,���λ������ȷ���������̵�����
	 * @param[in] special ������������λ��
	 * @param[in] size ���̵ĳ��Ϳ�Ĵ�С
	 * @return ��
	 */
	void
	covering_solver(vector<vector<char>>& chessboard, Coord topleft, Coord special, int board_size)
	{
		if (board_size == 1) return; /* �ݹ���ֹ���� */
		int subboard_size = board_size / 2; /* �����̵Ĵ�С */
		char mark = mark_++;

		{ /* �����λ�����ϵ��������� */
			if (special.row < topleft.row + subboard_size &&
				special.column < topleft.column + subboard_size) {
				covering_solver(chessboard, topleft, special, subboard_size);
			}
			else { /* ����鲻λ��������������,�������������̵����½� */
				Coord fake_special(topleft.row + subboard_size - 1, topleft.column + subboard_size - 1);
				chessboard[fake_special.row][fake_special.column] = mark;
				covering_solver(chessboard, topleft, fake_special, subboard_size);
			}
		}

		{ /* �����λ�����ϵ�����֮�� */
			Coord fake_topleft(topleft.row, topleft.column + subboard_size);
			if (special.row < topleft.row + subboard_size &&
				special.column >= topleft.column + subboard_size) {
				covering_solver(chessboard, fake_topleft, special, subboard_size);
			}
			else {
				/* ���Ⲣ�������ϵ�����֮��,��Ҫ�����ٵ������ */
				Coord fake_special(topleft.row + subboard_size - 1, topleft.column + subboard_size);
				chessboard[fake_special.row][fake_special.column] = mark;
				covering_solver(chessboard, fake_topleft, fake_special, subboard_size);
			}
		}

		{ /* ���½� */
			Coord fake_topleft(topleft.row + subboard_size, topleft.column);
			if (special.row >= topleft.row + subboard_size &&
				special.column <= topleft.column + subboard_size - 1) {
				covering_solver(chessboard, fake_topleft, special, subboard_size);
			}
			else {
				Coord fake_special(topleft.row + subboard_size, topleft.column + subboard_size - 1);
				chessboard[fake_special.row][fake_special.column] = mark;
				covering_solver(chessboard, fake_topleft, fake_special, subboard_size);
			}
		}

		{ /* ���½� */
			Coord fake_topleft(topleft.row + subboard_size, topleft.column + subboard_size);
			if (special.row > topleft.row + subboard_size - 1 &&
				special.column > topleft.column + subboard_size - 1) {
				covering_solver(chessboard, fake_topleft, special, subboard_size);
			}
			else {
				Coord fake_special(topleft.row + subboard_size, topleft.column + subboard_size);
				chessboard[fake_special.row][fake_special.column] = mark;
				covering_solver(chessboard, fake_topleft, fake_special, subboard_size);
			}
		}
	}
public:
	/**
	 * @brief ������̸�������
	 * @param[inout] chessboard ��������
	 * @param[in] special_row, special_cloumn ��������ڵ��к���,���ҽ���һ�������
	 * @return ��
	 */
	void
	solve(vector<vector<char>>& chessboard, int special_row, int special_cloumn)
	{
		covering_solver(chessboard, Coord(0, 0), Coord(special_row, special_cloumn), chessboard.size());
	}
};

int main()
{
	vector<char> r1 = { 'a', 'a', 'a', 'b', 'a', 'a', 'a', 'a' };
	vector<char> r2 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r3 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r4 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r5 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r6 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r7 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<char> r8 = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	vector<vector<char>> chessboard;
	chessboard.push_back(r1);
	chessboard.push_back(r2);
	chessboard.push_back(r3);
	chessboard.push_back(r4);
	chessboard.push_back(r5);
	chessboard.push_back(r6);
	chessboard.push_back(r7);
	chessboard.push_back(r8);
	ChessboardCovering cc;
	cc.solve(chessboard, 0, 3);
	print_chessboard(chessboard);
	getchar();
}