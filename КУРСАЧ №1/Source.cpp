#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include <clocale>
#include <fstream>

using namespace std;

//���������� ���������� ����������
string userName_1, userName_2;
string winner;
string povtor = "Y";
int green_sqr = 0;
int red_sqr = 0;
bool per1, per2 = false;

//������� ��� ������ id �����
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

//��������� ����� �� id �� ������� ConsoleColor
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//����� �� ����� ����������� ����������� ����������, ��� ���������� � �����
void priz(string winner)
{
	system("cls");

	SetColor(5, 0);
	cout << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr << endl;
	cout << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl << endl;
	SetColor(14, 0);
	SetColor(14, 0);
	if (winner == userName_1)
	{
		cout << "		  " << winner << " �������!\n\n";
	}
	else if (winner == userName_2)
	{
		cout << "		  " << winner << " �������!\n\n";
	}
	else
	{
		cout << "		    " << " �����!!!\n\n";
	}
	cout << "          vo�����������������������������\n";
	cout << "           �����������������������������v\n";
	cout << "            ���������������������������v\n";
	cout << "             �������������������������v\n";
	cout << "      oooov   �����������������������o  vo��ov\n";
	cout << "  v��ov   vo�oo����������������������v��v    o��ov\n";
	cout << " ��v        v�����������������������o          ��o\n";
	cout << "��v           v���������������������o            ��v\n";
	cout << "��            v���������������������o            o�v\n";
	cout << "o�v            ���������������������v            ��v\n";
	cout << "v�o           v���������������������o            v�o\n";
	cout << " o�v          o����������������������           ��v\n";
	cout << "  ��v         �����������������������o         ��v\n";
	cout << "   o�v       o������������������������        ��v\n";
	cout << "    o�o      �������������������������v     v��\n";
	cout << "     v�o    v��������������������������    v�o\n";
	cout << "      v�o   o��������������������������   v�o\n";
	cout << "        ��  ���������������������������v o�v\n";
	cout << "         o�v���������������������������oo�v\n";
	cout << "          o������������������������������\n";
	cout << "           o����������������������������\n";
	cout << "            ���������������������������v\n";
	cout << "            v�������������������������o\n";
	cout << "             v������������������������\n";
	cout << "               v���������������������o\n";
	cout << "                o������������������\n";
	cout << "                  o��������������\n";
	cout << "                     v�������o\n";
	cout << "                      o������\n";
	cout << "                      v�����o\n";
	cout << "                      o������v\n";
	cout << "                      o������v\n";
	cout << "                    vo��������o\n";
	cout << "                    v���������o\n";
	cout << "                  v�������������o\n";
	cout << "              o���������������������v\n";
	cout << "              �����������������������v\n";
	cout << "               o�������������������o\n";
	SetColor(15, 0);
}

//������� ����������� ����������� ���������� ������� � ������� ������
void result(int a, int** color)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (color[i][j] == 1)
			{
				green_sqr += 1;
			}
			else if (color[i][j] == 2)
			{
				red_sqr += 1;
			}
		}
	}

	if (green_sqr > red_sqr)
	{
		winner = userName_1;
	}
	else if (green_sqr < red_sqr)
	{
		winner = userName_2;
	}
	else if (green_sqr == red_sqr)
	{
		winner = "�����!!!";
	}
	priz(winner);
}

//���� ���� ������ � ������� �� �����
void pole(int a, int** color)
{

	a++;
	int b = a;

	cout << " ";
	for (int i = 1; i < a; i++)
	{
		if (i <= 10)
		{
			cout << "   " << i;
		}
		else
		{
			cout << "  " << i;
		}
	}

	cout << endl;

	a = a * 2;
	int n = 1;

	for (int i = 0; i < a - 1; i++)
	{
		if (i % 2 == 0)
		{
			cout << "  ";
			for (int j = 0; j < b - 1; j++)
			{
				SetColor(5, 0);
				cout << " ===";
				SetColor(15, 0);
			}
			cout << endl;
		}
		else
		{
			if (n < 10)
			{
				cout << " " << n;
			}
			else
			{
				cout << n;
			}

			SetColor(5, 0);
			cout << "|";
			SetColor(15, 0);

			for (int j = 0; j < b - 1; j++)
			{
				if (color[i / 2][j] == 1)
				{
					SetColor(10, 10);
					cout << "xxx";
					SetColor(5, 0);
					cout << "|";
					SetColor(15, 0);
				}
				else if (color[i / 2][j] == 2)
				{
					SetColor(12, 12);
					cout << "xxx";
					SetColor(5, 0);
					cout << "|";
					SetColor(15, 0);
				}
				else
				{
					SetColor(5, 0);
					cout << "   |";
					SetColor(15, 0);
				}
			}
			if (n < 10)
			{
				cout << " " << n;
			}
			else
			{
				cout << n;
			}
			n++;

			cout << endl;
		}
	}

	cout << " ";
	for (int i = 1; i < a / 2; i++)
	{
		if (i <= 10)
		{
			cout << "   " << i;
		}
		else
		{
			cout << "  " << i;
		}
	}
	cout << "\n\n";
}

//��������� ����� ��� ������ �� ����� �����
int step()
{
	int a, x = 0;

	Sleep(1000);

	a = rand() % 600 + 1;

	if (a > 0 and a < 101)
	{
		x = 1;
	}
	else if (a > 100 and a < 201)
	{
		x = 2;
	}
	else if (a > 200 and a < 301)
	{
		x = 3;
	}
	else if (a > 300 and a < 401)
	{
		x = 4;
	}
	else if (a > 400 and a < 501)
	{
		x = 5;
	}
	if (a > 500 and a < 601)
	{
		x = 6;
	}

	return x;
}

//����� �� ����� ����� � ������������ �� ��������������� ������
void cube(int x)
{
	switch (x)
	{
	case 1:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|         |" << endl;
		cout << "|    ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "    |" << endl;
		cout << "|         |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;

	case 2:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|    ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "    |" << endl;
		cout << "|         |" << endl;
		cout << "|    ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "    |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;

	case 3:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "      |" << endl;
		cout << "|    ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "    |" << endl;
		cout << "|      ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;

	case 4:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "|         |" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;

	case 5:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "|    ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "    |" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;

	case 6:
		SetColor(4, 0);
		cout << "===========" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "|  ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "   ";
		SetColor(15, 0);
		cout << "*";
		SetColor(4, 0);
		cout << "  |" << endl;
		cout << "===========\n" << endl;
		SetColor(15, 0);
		break;
	}
	Sleep(1500);
}

//�������� ������� main ��� ���������� ������
int main();

//��� ������� ������
int user_1(int a, int** color)
{
	string choice = "Y";
	bool check = true;
	int corX, corY;
	int perX, perY;
	int temp = 0;

	//������ �� ����������� ����
	cout << "���������� ����?(";
	SetColor(2, 0);
	cout << "Y";
	SetColor(15, 0);
	cout << "/";
	SetColor(4, 0);
	cout << "N";
	SetColor(15, 0);
	cout << ")\n-> ";
	cin >> choice; //����� ������������

	system("cls");
	pole(a, color);

	if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
	{
		while (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			bool checkPlace = true;
			bool proverkaPlace = true;
			bool control = true;
			bool rerol = true;

			if (check)
			{
				//����� �� ����� �������� ������ �������
				for (int i = 0; i < 2; i++)
				{
					if (i == 0)
					{
						cout << "������ ��������������:\n\n";
						corX = step();
						cube(corX);
					}
					else if (i == 1)
					{
						cout << "������ ��������������:\n\n";
						corY = step();
						cube(corY);
					}
				}
			}
			check = true;

			system("cls");
			pole(a, color);

			while (checkPlace)
			{
				checkPlace = false;

				//������ �� ����� ������
				SetColor(10, 0);
				cout << userName_1 << " �����!\n";
				SetColor(15, 0);
				cout << "������: " << corX << endl;
				cout << "�����: " << corY << endl;
				cout << "������� ���������� ����� (";
				SetColor(9, 0);
				cout << "Y";
				SetColor(15, 0);
				cout << ";";
				SetColor(9, 0);
				cout << "X";
				SetColor(15, 0);
				cout << ")" << endl;
				cin >> perX >> perY; //���� ��������� ������

				//�������� �� ������� ����� ����������
				if (perX - 1 < a and perY - 1 < a)
				{
					for (int i = perX - 1; i <= (perX + corX - 2); i++)
					{
						for (int j = perY - 1; j <= (perY + corY - 2); j++)
						{
							//�������� �� ������������� ��������� ������ � ������� ����� ����
							if ((i == 0 and j == 0))
							{
								//������ �� ����������� ����
								system("cls");
								pole(a, color);
								cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
								cout << "���������� ����?(";
								SetColor(2, 0);
								cout << "Y";
								SetColor(15, 0);
								cout << "/";
								SetColor(4, 0);
								cout << "N";
								SetColor(15, 0);
								cout << ")\n-> ";
								cin >> choice; //����� ������������

								//���� ����� �������������
								if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
								{
									result(a, color);
									SetColor(5, 0);
									cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
									SetColor(15, 0);

									//������ ����������� � ����
									ofstream file;
									file.open("RESULT.txt");
									for (int i = 0; i < a; i++)
									{
										for (int j = 0; j < a; j++)
										{
											file << color[i][j] << " ";
										}
										file << endl;
									}
									file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
									file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
									file << endl << winner << " �������!";
									file.close();

									//������ �� �������� ����������� � �����
									SetColor(5, 0);
									cout << "������� ���������� ����������?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										//�������� �����
										system("notepad.exe RESULT.txt");
									}
									else
									{
										return 0;
									}

									//������ �� ������ ����
									SetColor(15, 0);
									SetColor(5, 0);
									cout << "\n\n������� ������� ��� ���?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										main();
									}
									else
									{
										return 0;
									}
									return 0;
								}
								else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
								{
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

									checkPlace = false;
									control = false;
									rerol = false;
								}
								break;
							}
							//�������� �� ������������� ��������� ������ �� �������� ���� ����
							else if (i == 0)
							{
								//�������� �������� ������
								if (color[i][perY - 2] == 1)
								{
									if (color[i][j] == 1)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� �������� ����������� � �����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ��������� ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = false;
											control = false;
											rerol = false;
										}
										break;
									}
								}
								else
								{
									//������ �� ����������� ����
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
									{
										result(a, color);
										SetColor(5, 0);
										cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
										SetColor(15, 0);

										//������ ����������� � ����
										ofstream file;
										file.open("RESULT.txt");
										for (int i = 0; i < a; i++)
										{
											for (int j = 0; j < a; j++)
											{
												file << color[i][j] << " ";
											}
											file << endl;
										}
										file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
										file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
										file << endl << winner << " �������!";
										file.close();

										//������ �� �������� ����������� � �����
										SetColor(5, 0);
										cout << "������� ���������� ����������?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											//�������� �����
											system("notepad.exe RESULT.txt");
										}
										else
										{
											return 0;
										}

										//������ �� ������ ����
										SetColor(15, 0);
										SetColor(5, 0);
										cout << "\n\n������� ������� ��� ���?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											main();
										}
										else
										{
											return 0;
										}
										return 0;
									}
									else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

										checkPlace = false;
										control = false;
										rerol = false;
									}
									break;
								}
							}
							//�������� �� ������������� ��������� ������ �� ������ ���� ����
							else if (j == 0)
							{
								//�������� �������� ������
								if (color[perX - 2][j] == 1)
								{
									if (color[i][j] == 1)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� ����������� ����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ������ ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											//������ �� ����������� ����

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = false;
											control = false;
											rerol = false;
										}
										break;
									}
								}
								else
								{
									//������ �� ����������� ����
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									checkPlace = false;
									control = false;
									rerol = false;

									break;
								}
							}
							else
							{
								if ((color[i][perY - 2] == 1 or color[perX - 2][j] == 1))
								{
									if (color[i][j] == 1)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� �������� ����������� � �����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ������ ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = true;
											control = false;
											rerol = false;
										}
									}
								}
								//�������� �� ������������� ��������� ������ �� ��� ����, �� � �������� � ���� ������ �� ����
								else if (color[i][perY - 2] != 1 or color[perX - 2][j] != 1)
								{
									//������ �� ����������� ����
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
									{
										result(a, color);
										SetColor(5, 0);
										cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
										SetColor(15, 0);

										//������ ����������� � ����
										ofstream file;
										file.open("RESULT.txt");
										for (int i = 0; i < a; i++)
										{
											for (int j = 0; j < a; j++)
											{
												file << color[i][j] << " ";
											}
											file << endl;
										}
										file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
										file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
										file << endl << winner << " �������!";
										file.close();

										//������ �� �������� ����������� � �����
										SetColor(5, 0);
										cout << "������� ���������� ����������?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											//�������� �����
											system("notepad.exe RESULT.txt");
										}
										else
										{
											return 0;
										}

										//������ �� ������ ����
										SetColor(15, 0);
										SetColor(5, 0);
										cout << "\n\n������� ������� ��� ���?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											main();
										}
										else
										{
											return 0;
										}
										return 0;
									}
									else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

										checkPlace = true;
										control = false;
										rerol = false;
									}
								}
							}
							if (checkPlace == false)
							{
								//���� ������� �������������� ���������� � ����
								if ((a > corX + perX - 2) and (a > corY + perY - 2))
								{
									//�������� �� ������������� ������ � ������� ��������������
									for (int i = perX - 1; i <= (perX + corX - 2); i++)
									{
										for (int j = perY - 1; j <= (perY + corY - 2); j++)
										{
											if (color[i][j] == 1 or color[i][j] == 2)
											{
												proverkaPlace = false;
												rerol = false;
											}
										}
									}
									if (proverkaPlace == true)
									{
										//�������� ��������� ����������
										for (int i = perX - 1; i <= (perX + corX - 2); i++)
										{
											for (int j = perY - 1; j <= (perY + corY - 2); j++)
											{
												if (corX > a - perX + 1 or corY > a - perY + 1)
												{
													checkPlace = true;
													rerol = false;
													break;
												}
												else
												{
													color[i][j] = 1;
													control = false;
												}
											}
										}
									}
								}
							}
							if (control)
							{
								checkPlace = true;
								proverkaPlace = true;

								//������ �� ����������� ����
								system("cls");
								pole(a, color);
								cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
								cout << "���������� ����?(";
								SetColor(2, 0);
								cout << "Y";
								SetColor(15, 0);
								cout << "/";
								SetColor(4, 0);
								cout << "N";
								SetColor(15, 0);
								cout << ")\n-> ";
								cin >> choice; //����� ������������

								if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
								{
									result(a, color);
									SetColor(5, 0);
									cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
									SetColor(15, 0);

									//������ ����������� � ����
									ofstream file;
									file.open("RESULT.txt");
									for (int i = 0; i < a; i++)
									{
										for (int j = 0; j < a; j++)
										{
											file << color[i][j] << " ";
										}
										file << endl;
									}
									file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
									file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
									file << endl << winner << " �������!";
									file.close();

									//������ �� �������� ����������� � �����
									SetColor(5, 0);
									cout << "������� ���������� ����������?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										//�������� �����
										system("notepad.exe RESULT.txt");
									}
									else
									{
										return 0;
									}

									//������ �� ������ ����
									SetColor(15, 0);
									SetColor(5, 0);
									cout << "\n\n������� ������� ��� ���?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										main();
									}
									else
									{
										return 0;
									}
									return 0;
								}
								else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
								{
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

									checkPlace = true;
									rerol = false;
								}
								break;
							}
							else
							{
								system("cls");
								pole(a, color);

								checkPlace = true;
								break;
							}
						}
						break;
					}
					break;
				}
				else
				{
					system("cls");
					pole(a, color);

					checkPlace = true;
					check = false;

					cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
				}
			}

			//�������� �� ����������� ������� ������
			if (temp < 3)
			{
				if (rerol == false)
				{
					//������ �� ��������� ������ �������
					system("cls");
					pole(a, color);
					cout << "������� ������?(";
					SetColor(2, 0);
					cout << "Y";
					SetColor(15, 0);
					cout << "/";
					SetColor(4, 0);
					cout << "N";
					SetColor(15, 0);
					cout << ")\n-> ";
					cin >> choice; //����� ������������

					if ((choice == "N" or choice == "n" or choice == "�" or choice == "�") and rerol == false)
					{
						choice = "Y";
						check = false;
					}
					else if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
					{
						return 0;
					}
					else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
					{
						if (rerol == false)
						{
							checkPlace = true;
							temp += 1;
						}
						else
						{
							checkPlace = true;
						}
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				checkPlace = false;
				per1 = true;

				system("cls");
				pole(a, color);
				SetColor(5, 0);
				cout << "������� ���������! :)\n��� ��������� ������ " << userName_2 << endl;
				SetColor(15, 0);

				return 1;
			}
		}
	}
	else if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
	{
		result(a, color);
		SetColor(5, 0);
		cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
		SetColor(15, 0);

		//������ ����������� � ����
		ofstream file;
		file.open("RESULT.txt");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				file << color[i][j] << " ";
			}
			file << endl;
		}
		file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
		file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
		file << endl << winner << " �������!";
		file.close();

		//������ �� �������� ����������� � �����
		SetColor(5, 0);
		cout << "������� ���������� ����������?(";
		SetColor(2, 0);
		cout << "Y";
		SetColor(15, 0);
		cout << "/";
		SetColor(4, 0);
		cout << "N";
		SetColor(15, 0);
		cout << ")\n-> ";
		cin >> choice; //����� ������������

		if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			//�������� �����
			system("notepad.exe RESULT.txt");
		}


		//������ �� ������ ����
		SetColor(15, 0);
		SetColor(5, 0);
		cout << "\n������� ������� ��� ���?(";
		SetColor(2, 0);
		cout << "Y";
		SetColor(15, 0);
		cout << "/";
		SetColor(4, 0);
		cout << "N";
		SetColor(15, 0);
		cout << ")\n-> ";
		cin >> choice; //����� ������������

		if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			main();
		}
		else
		{
			return 0;
		}
	}
	else
	{
		user_1(a, color);
	}
}

//��� ������� ������
int user_2(int a, int** color)
{
	string choice = "Y";
	bool first = true;
	bool check = true;
	int corX, corY;
	int perX, perY;
	int temp = 0;

	//������ �� ����������� ����
	cout << "���������� ����?(";
	SetColor(2, 0);
	cout << "Y";
	SetColor(15, 0);
	cout << "/";
	SetColor(4, 0);
	cout << "N";
	SetColor(15, 0);
	cout << ")\n-> ";
	cin >> choice; //����� ������������

	system("cls");
	pole(a, color);

	if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
	{
		while (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			bool checkPlace = true;
			bool proverkaPlace = true;
			bool control = true;
			bool rerol = true;

			if (check)
			{
				for (int i = 0; i < 2; i++)
				{
					if (i == 0)
					{
						cout << "������ ��������������:\n\n";
						corX = step();
						cube(corX);
					}
					else if (i == 1)
					{
						cout << "������ ��������������:\n\n";
						corY = step();
						cube(corY);
					}
				}
			}

			check = true;
			system("cls");
			pole(a, color);

			while (checkPlace)
			{
				checkPlace = false;
				SetColor(12, 0);
				cout << userName_2 << " �����!\n";
				SetColor(15, 0);
				cout << "������: " << corX << endl;
				cout << "�����: " << corY << endl;
				cout << "������� ���������� ����� (";
				SetColor(9, 0);
				cout << "Y";
				SetColor(15, 0);
				cout << ";";
				SetColor(9, 0);
				cout << "X";
				SetColor(15, 0);
				cout << ")" << endl;
				cin >> perX >> perY; //���� ��������� ������

				if (perX - 1 < a and perY - 1 < a)
				{
					for (int i = perX - 1; i <= (perX + corX - 2); i++)
					{
						for (int j = perY - 1; j <= (perY + corY - 2); j++)
						{
							//�������� �� ������������� ��������� ������ � ������ ������ ����
							if ((i == a - 1 and j == a - 1))
							{
								//������ �� ����������� ����
								system("cls");
								pole(a, color);
								cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
								cout << "���������� ����?(";
								SetColor(2, 0);
								cout << "Y";
								SetColor(15, 0);
								cout << "/";
								SetColor(4, 0);
								cout << "N";
								SetColor(15, 0);
								cout << ")\n-> ";
								cin >> choice; //����� ������������

								if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
								{
									result(a, color);
									SetColor(5, 0);
									cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
									SetColor(15, 0);

									//������ ����������� � ����
									ofstream file;
									file.open("RESULT.txt");
									for (int i = 0; i < a; i++)
									{
										for (int j = 0; j < a; j++)
										{
											file << color[i][j] << " ";
										}
										file << endl;
									}
									file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
									file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
									file << endl << winner << " �������!";
									file.close();

									//������ �� �������� ����������� � �����
									SetColor(5, 0);
									cout << "������� ���������� ����������?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										//�������� �����
										system("notepad.exe RESULT.txt");
									}
									else
									{
										return 0;
									}

									//������ �� ������ ����
									SetColor(15, 0);
									SetColor(5, 0);
									cout << "\n\n������� ������� ��� ���?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										main();
									}
									else
									{
										return 0;
									}
									return 0;
								}
								else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
								{
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

									checkPlace = false;
									control = false;
									rerol = false;
								}
								break;
							}
							//�������� �� ������������� ��������� ������ ����� ������� ���� ����
							else if (i == a - 1)
							{
								//�������� �������� ������
								if (color[i][perY] == 2)
								{
									if (color[i][j] == 2)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� �������� ����������� � �����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ������ ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = false;
											control = false;
											rerol = false;
										}
										break;
									}
								}
								else
								{
									//������ �� ����������� ����
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
									{
										result(a, color);
										SetColor(5, 0);
										cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
										SetColor(15, 0);

										//������ ����������� � ����
										ofstream file;
										file.open("RESULT.txt");
										for (int i = 0; i < a; i++)
										{
											for (int j = 0; j < a; j++)
											{
												file << color[i][j] << " ";
											}
											file << endl;
										}
										file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
										file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
										file << endl << winner << " �������!";
										file.close();

										//������ �� �������� ����������� � �����
										SetColor(5, 0);
										cout << "������� ���������� ����������?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											//�������� �����
											system("notepad.exe RESULT.txt");
										}
										else
										{
											return 0;
										}

										//������ �� ������ ����
										SetColor(15, 0);
										SetColor(5, 0);
										cout << "\n\n������� ������� ��� ���?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											main();
										}
										else
										{
											return 0;
										}
										return 0;
									}
									else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

										checkPlace = false;
										control = false;
										rerol = false;
									}
									break;
								}
							}
							//�������� �� ������������� ��������� ������ �������� ���� ����
							else if (j == a - 2)
							{
								//�������� �������� ������
								if (color[perX][j] == 2)
								{
									if (color[i][j] == 2)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� �������� ����������� � �����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ������ ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = false;
											control = false;
											rerol = false;
										}
										break;
									}
								}
								else
								{
									cin >> choice; //����� ������������
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									checkPlace = false;
									control = false;
									rerol = false;

									break;
								}
							}
							else
							{
								if ((color[i][perY] == 2 or color[perX][j] == 2))
								{
									if (color[i][j] == 2)
									{
										//������ �� ����������� ����
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
										cout << "���������� ����?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
										{
											result(a, color);
											SetColor(5, 0);
											cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
											SetColor(15, 0);

											//������ ����������� � ����
											ofstream file;
											file.open("RESULT.txt");
											for (int i = 0; i < a; i++)
											{
												for (int j = 0; j < a; j++)
												{
													file << color[i][j] << " ";
												}
												file << endl;
											}
											file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
											file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
											file << endl << winner << " �������!";
											file.close();

											//������ �� �������� ����������� � �����
											SetColor(5, 0);
											cout << "������� ���������� ����������?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												//�������� �����
												system("notepad.exe RESULT.txt");
											}
											else
											{
												return 0;
											}

											//������ �� ������ ����
											SetColor(15, 0);
											SetColor(5, 0);
											cout << "\n\n������� ������� ��� ���?(";
											SetColor(2, 0);
											cout << "Y";
											SetColor(15, 0);
											cout << "/";
											SetColor(4, 0);
											cout << "N";
											SetColor(15, 0);
											cout << ")\n-> ";
											cin >> choice; //����� ������������

											if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
											{
												main();
											}
											else
											{
												return 0;
											}
											return 0;
										}
										else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											system("cls");
											pole(a, color);
											cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

											checkPlace = true;
											control = false;
											rerol = false;
										}
									}
								}
								//�������� �������� ������
								else if (color[i][perY + 2] != 2 or color[perX + 2][j] != 2)
								{
									//������ �� ����������� ����
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
									cout << "���������� ����?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
									{
										result(a, color);
										SetColor(5, 0);
										cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
										SetColor(15, 0);

										//������ ����������� � ����
										ofstream file;
										file.open("RESULT.txt");
										for (int i = 0; i < a; i++)
										{
											for (int j = 0; j < a; j++)
											{
												file << color[i][j] << " ";
											}
											file << endl;
										}
										file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
										file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
										file << endl << winner << " �������!";
										file.close();

										//������ �� �������� ����������� � �����
										SetColor(5, 0);
										cout << "������� ���������� ����������?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											//�������� �����
											system("notepad.exe RESULT.txt");
										}
										else
										{
											return 0;
										}

										//������ �� ������ ����
										SetColor(15, 0);
										SetColor(5, 0);
										cout << "\n\n������� ������� ��� ���?(";
										SetColor(2, 0);
										cout << "Y";
										SetColor(15, 0);
										cout << "/";
										SetColor(4, 0);
										cout << "N";
										SetColor(15, 0);
										cout << ")\n-> ";
										cin >> choice; //����� ������������

										if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
										{
											main();

										}
										else
										{
											return 0;
										}
										return 0;
									}
									else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										system("cls");
										pole(a, color);
										cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

										checkPlace = true;
										control = false;
										rerol = false;
									}
								}
							}
							if (checkPlace == false)
							{
								//�������� ������ �� ������������� � ������� ����
								if ((a - (a - perX) >= corX) and (a - (a - perY) >= corY))
								{
									//�������� ������� �������������� �� ������� �� ����������� ������
									for (int i = perX - 1; i >= perX - corX; i--)
									{
										for (int j = perY - 1; j >= perY - corY; j--)
										{
											if (color[i][j] == 1 or color[i][j] == 2)
											{
												proverkaPlace = false;
												rerol = false;
											}
										}
									}
									if (proverkaPlace == true)
									{
										//�������� ��������������
										for (int i = perX - 1; i >= perX - corX; i--)
										{
											for (int j = perY - 1; j >= perY - corY; j--)
											{
												//������ �� ������������� � ������� ����
												if ((a - (a - perX) <= corX) and (a - (a - perY) <= corY))
												{
													checkPlace = true;
													rerol = false;
													break;
												}
												else
												{
													color[i][j] = 2;
													control = false;
												}
											}
										}
									}
								}
							}
							if (control)
							{
								checkPlace = true;
								proverkaPlace = true;

								//������ �� ����������� ����
								system("cls");
								pole(a, color);
								cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;
								cout << "���������� ����?(";
								SetColor(2, 0);
								cout << "Y";
								SetColor(15, 0);
								cout << "/";
								SetColor(4, 0);
								cout << "N";
								SetColor(15, 0);
								cout << ")\n-> ";
								cin >> choice; //����� ������������

								if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
								{
									result(a, color);
									SetColor(5, 0);
									cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
									SetColor(15, 0);

									//������ ����������� � ����
									ofstream file;
									file.open("RESULT.txt");
									for (int i = 0; i < a; i++)
									{
										for (int j = 0; j < a; j++)
										{
											file << color[i][j] << " ";
										}
										file << endl;
									}
									file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
									file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
									file << endl << winner << " �������!";
									file.close();

									//������ �� �������� ����������� � �����
									SetColor(5, 0);
									cout << "������� ���������� ����������?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										//�������� �����
										system("notepad.exe RESULT.txt");
									}
									else
									{
										return 0;
									}

									//������ �� ������ ����
									SetColor(15, 0);
									SetColor(5, 0);
									cout << "\n\n������� ������� ��� ���?(";
									SetColor(2, 0);
									cout << "Y";
									SetColor(15, 0);
									cout << "/";
									SetColor(4, 0);
									cout << "N";
									SetColor(15, 0);
									cout << ")\n-> ";
									cin >> choice; //����� ������������

									if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
									{
										main();
									}
									else
									{
										return 0;
									}
									return 0;
								}
								else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
								{
									system("cls");
									pole(a, color);
									cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

									checkPlace = true;
									rerol = false;
								}
								break;
							}
							else
							{
								system("cls");
								pole(a, color);

								checkPlace = true;

								break;
							}
						}
						break;
					}
					break;
				}
				else
				{
					system("cls");
					pole(a, color);
					cout << "������� �� ���������� ����������, ��� ����� ��������� ������� ����" << endl;

					check = false;
					checkPlace = true;
				}
			}
			if (temp < 3)
			{
				if (rerol == false)
				{
					//������ �� ��������� ������ �������
					system("cls");
					pole(a, color);
					cout << "������� ������?(";
					SetColor(2, 0);
					cout << "Y";
					SetColor(15, 0);
					cout << "/";
					SetColor(4, 0);
					cout << "N";
					SetColor(15, 0);
					cout << ")\n-> ";
					cin >> choice; //����� ������������

					if ((choice == "N" or choice == "n" or choice == "�" or choice == "�") and rerol == false)
					{
						choice = "Y";
						check = false;
					}
					else if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
					{
						return 0;
					}
					else if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
					{
						if (rerol == false)
						{
							checkPlace = true;
							temp += 1;
						}
						else
						{
							checkPlace = true;
						}
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				checkPlace = false;
				per2 = true;

				system("cls");
				pole(a, color);
				SetColor(5, 0);
				cout << "������� ���������! :)\n��� ��������� ������ " << userName_1 << endl;
				SetColor(15, 0);

				return 1;
			}
		}
	}
	else if (choice == "N" or choice == "n" or choice == "�" or choice == "�")
	{
		result(a, color);
		SetColor(5, 0);
		cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
		SetColor(15, 0);

		//������ ����������� � ����
		ofstream file;
		file.open("RESULT.txt");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				file << color[i][j] << " ";
			}
			file << endl;
		}
		file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
		file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
		file << endl << winner << " �������!";
		file.close();

		//������ �� �������� ����������� � �����
		SetColor(5, 0);
		cout << "������� ���������� ����������?(";
		SetColor(2, 0);
		cout << "Y";
		SetColor(15, 0);
		cout << "/";
		SetColor(4, 0);
		cout << "N";
		SetColor(15, 0);
		cout << ")\n-> ";
		cin >> choice; //����� ������������

		if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			//�������� �����
			system("notepad.exe RESULT.txt");
		}

		//������ �� ������ ����
		SetColor(15, 0);
		SetColor(5, 0);
		cout << "\n������� ������� ��� ���?(";
		SetColor(2, 0);
		cout << "Y";
		SetColor(15, 0);
		cout << "/";
		SetColor(4, 0);
		cout << "N";
		SetColor(15, 0);
		cout << ")\n-> ";
		cin >> choice; //����� ������������

		if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
		{
			main();
		}
		else
		{
			return 0;
		}
	}
	else
	{
		user_2(a, color);
	}
}

//������� �������
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int a;
	int choise = 0;
	bool proverka = true;
	bool size = true;
	bool game = true;

	while (proverka)
	{
		//����� ����
		system("cls");
		SetColor(9, 0);
		cout << "	��������������: ������ ����������\n";
		SetColor(15, 0);
		cout << "1. ������ ����\n2. ������� ����\n3. �����\n";
		cout << "-> ";
		cin >> choise; //����� ������������

		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n');
		}
		else if (choise > 0 and choise < 4)
		{
			if (choise == 1)
			{
				//������ ��� �������������
				system("cls");
				SetColor(5, 0);
				cout << "������� ��� ������� ������(��� �������)\n";
				SetColor(10, 0);
				cout << "->";
				SetColor(15, 0);
				cin >> userName_1;
				SetColor(5, 0);
				cout << "������� ��� ������� ������(��� �������)\n";
				SetColor(12, 0);
				cout << "->";
				SetColor(15, 0);
				cin >> userName_2;

				while (size)
				{
					//������ ����������� ����
					system("cls");
					SetColor(5, 0);
					cout << userName_1 << " � " << userName_2 << ", ����������� ��� � ����!\n";
					cout << "������� ������� ����������� ���� �� 12 �� 30: ";
					SetColor(15, 0);
					cin >> a;

					if (!cin)
					{
						cin.clear();
						while (cin.get() != '\n');
					}
					else
					{
						if (a >= 12 and a <= 30)
						{
							size = false;
						}
						else
						{
							system("cls");
							SetColor(5, 0);
							cout << "������� �� ������ ����������, ���������� ��� ��� :)\n";
							SetColor(5, 0);
							system("pause");
						}
					}
				}

				system("cls");

				int x, y;
				int** color = new int* [a];

				for (int i = 0; i < a; i++)
				{
					color[i] = new int[a];
				}
				for (int i = 0; i < a; i++)
				{
					for (int j = 0; j < a; j++)
					{
						color[i][j] = 0;
					}
				}

				string choice = "Y";
				int corX, corY;
				int perX, perY;

				system("cls");
				pole(a, color);

				for (int i = 0; i < 2; i++)
				{
					if (i == 0)
					{
						cout << "������ ��������������:\n\n";
						corX = step();
						cube(corX);
					}
					else if (i == 1)
					{
						cout << "������ ��������������:\n\n";
						corY = step();
						cube(corY);
					}
				}
				for (int i = 0; i < corX; i++)
				{
					for (int j = 0; j < corY; j++)
					{
						color[i][j] = 1;
					}
				}

				system("cls");
				pole(a, color);

				for (int i = 0; i < 2; i++)
				{
					if (i == 0)
					{
						cout << "������ ��������������:\n\n";
						corX = step();
						cube(corX);
					}
					else if (i == 1)
					{
						cout << "������ ��������������:\n\n";
						corY = step();
						cube(corY);
					}
				}
				for (int i = a - 1; i >= a - corX; i--)
				{
					for (int j = a - 1; j >= a - corY; j--)
					{
						color[i][j] = 2;
					}
				}

				system("cls");
				pole(a, color);

				while (game)
				{
					if (per1 && per2)
					{
						result(a, color);
						SetColor(5, 0);
						cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
						SetColor(15, 0);

						//������ ����������� � ����
						ofstream file;
						file.open("RESULT.txt");
						for (int i = 0; i < a; i++)
						{
							for (int j = 0; j < a; j++)
							{
								file << color[i][j] << " ";
							}
							file << endl;
						}
						file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
						file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
						file << endl << winner << " �������!";
						file.close();

						//������ �� �������� ����������� � �����
						SetColor(5, 0);
						cout << "������� ���������� ����������?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							//�������� �����
							system("notepad.exe RESULT.txt");
						}
						else
						{
							return 0;
						}

						//������ �� ������ ����
						SetColor(15, 0);
						SetColor(5, 0);
						cout << "\n\n������� ������� ��� ���?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							main();
						}
						else
						{
							return 0;
						}
						return 0;
					}

					int temp = 0;

					if (user_1(a, color) == 0)
					{
						return 0;
					}

					//�������� �� ������� ����������� ������
					for (int i = 0; i < a - 1; i++)
					{
						for (int j = 0; j < a - 1; j++)
						{
							if (color[i][j] == 1)
							{
								temp += 1;
							}
						}
					}
					if (temp == 0)
					{
						result(a, color);
						SetColor(5, 0);
						cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
						SetColor(15, 0);

						//������ ����������� � ����
						ofstream file;
						file.open("RESULT.txt");
						for (int i = 0; i < a; i++)
						{
							for (int j = 0; j < a; j++)
							{
								file << color[i][j] << " ";
							}
							file << endl;
						}
						file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
						file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
						file << endl << winner << " �������!";
						file.close();

						//������ �� �������� ����������� � �����
						SetColor(5, 0);
						cout << "������� ���������� ����������?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							//�������� �����
							system("notepad.exe RESULT.txt");
						}
						else
						{
							return 0;
						}

						//������ �� ������ ����
						SetColor(15, 0);
						SetColor(5, 0);
						cout << "\n\n������� ������� ��� ���?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							main();
						}
						else
						{
							return 0;
						}
						return 0;
					}
					if (per1 && per2)
					{
						result(a, color);
						SetColor(5, 0);
						cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
						SetColor(15, 0);

						//������ ����������� � ����
						ofstream file;
						file.open("RESULT.txt");
						for (int i = 0; i < a; i++)
						{
							for (int j = 0; j < a; j++)
							{
								file << color[i][j] << " ";
							}
							file << endl;
						}
						file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
						file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
						file << endl << winner << " �������!";
						file.close();

						//������ �� �������� ����������� � �����
						SetColor(5, 0);
						cout << "������� ���������� ����������?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							//�������� �����
							system("notepad.exe RESULT.txt");
						}
						else
						{
							return 0;
						}

						//������ �� ������ ����
						SetColor(15, 0);
						SetColor(5, 0);
						cout << "\n\n������� ������� ��� ���?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							main();
						}
						else
						{
							return 0;
						}
						return 0;
					}

					if (user_2(a, color) == 0)
					{
						return 0;
					}

					//�������� �� ������� ����������� ������
					for (int i = 0; i < a - 1; i++)
					{
						for (int j = 0; j < a - 1; j++)
						{
							if (color[i][j] == 1)
							{
								temp += 1;
							}
						}
					}
					//���� ��������� ��� ����������� ������
					if (temp == 0)
					{
						result(a, color);
						SetColor(5, 0);
						cout << "\n	���������� ����� ���������� � ��������� ����� ���������!\n";
						SetColor(15, 0);

						//������ ����������� � ����
						ofstream file;
						file.open("RESULT.txt");
						for (int i = 0; i < a; i++)
						{
							for (int j = 0; j < a; j++)
							{
								file << color[i][j] << " ";
							}
							file << endl;
						}
						file << endl << "����� ���������� ������ ������: " << userName_1 << " " << green_sqr;
						file << endl << "����� ���������� ������ ������: " << userName_2 << " " << red_sqr << endl;
						file << endl << winner << " �������!";
						file.close();

						//������ �� �������� ����������� � �����
						SetColor(5, 0);
						cout << "������� ���������� ����������?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							//�������� �����
							system("notepad.exe RESULT.txt");
						}
						else
						{
							return 0;
						}

						//������ �� ������ ����
						SetColor(15, 0);
						SetColor(5, 0);
						cout << "\n\n������� ������� ��� ���?(";
						SetColor(2, 0);
						cout << "Y";
						SetColor(15, 0);
						cout << "/";
						SetColor(4, 0);
						cout << "N";
						SetColor(15, 0);
						cout << ")\n-> ";
						cin >> choice; //����� ������������

						if (choice == "Y" or choice == "y" or choice == "�" or choice == "�")
						{
							main();
						}
						else
						{
							return 0;
						}
						return 0;
					}
				}
			}
			else if (choise == 2)
			{
				//������� ����
				system("cls");
				SetColor(5, 0);
				cout << "	������� ����:\n";
				cout << "1. ���� ������� ��� ���� �������, ������� �� ������� ������� ��� �����:\n   �) ������ ����� - ������ ��������������(�� ����� Y);\n   �) ������ ����� - ����� ��������������(�� ����� X);\n\n";
				cout << "2.       �����\n    === === === ===\n   |";
				SetColor(10, 10);
				cout << "   ";
				SetColor(5, 0);
				cout << "|   |   |   |\n    === === === ===   ������\n   |   |   |   |";
				SetColor(12, 12);
				cout << "   ";
				SetColor(5, 0);
				cout << "| \n    === === === === \n\n";
				cout << "   ";
				SetColor(10, 10);
				cout << "   ";
				SetColor(5, 0);
				cout << " - ������ ���������� �������������� ������� ������.\n\n";
				cout << "   ";
				SetColor(12, 12);
				cout << "   ";
				SetColor(5, 0);
				cout << " - ������ ���������� �������������� ������� ������.\n\n";
				cout << "3. ������� ���������� ��������������:\n   �) ��������� ������ ������������� � ����������� ����������� ������ ���� �����;\n   �) ��������� ������ ������ ���� �����������;\n   �) ������������� �� ����� �������� �� ����������� ����������, ������ �� �����������;\n\n";
				cout << "4. ���� �� ������� ������������ ����������, �� � ��� ���� ����������� �������� ������ ���� ����������� ������. ����������� ����� 3 ����.\n\n";
				cout << "5. ������� ��������� ����:\n   a) ���� ������ � ������ ����� �� ������ ��������� ����������;\n   �) ���� ��� ������ ��������;\n\n";
				SetColor(15, 0);
				system("pause");
			}
			else if (choise == 3)
			{
				return 0;
			}
		}
	}
	return 0;
}