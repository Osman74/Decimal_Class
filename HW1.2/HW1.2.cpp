#include "cls_Hex.h"
#include "cls_Decimal.h"
#include <clocale>

const int NotUsed = system("color F0");

void menuHex()
{
	std::cout << "1.Сложение двух чисел" << std::endl;
	std::cout << "2.Разность двух чисел" << std::endl;
	std::cout << "3.Умножение двух чисел" << std::endl;
	std::cout << "4.Сравнение двух чисел" << std::endl;
	std::cout << "5.Перевод в десятичную  систему счисления" << std::endl;
	std::cout << "6.Выход" << std::endl;
}

void menuDecimal()
{
	std::cout << "1.Сложение двух чисел" << std::endl;
	std::cout << "2.Разность двух чисел" << std::endl;
	std::cout << "3.Умножение двух чисел" << std::endl;
	std::cout << "4.Сравнение двух чисел" << std::endl;
	std::cout << "5.Выход" << std::endl;
}

int main()
{
	try {
		setlocale(0, "RUSSIAN");
		int choose = 1;
		while (choose != 3)
		{
			system("cls");
			cls_Hex A, B;
			cls_Decimal C, D;
			int size;
			std::cout << "1.Шестнадцатеричная система счисления" << std::endl;
			std::cout << "2.Десятичная система счисления" << std::endl;
			std::cout << "3.Выход" << std::endl;
			std::cout << "Выберите пункт меню" << std::endl;
			std::cin >> choose;
			if (choose == 1)
				while (choose != 6)
				{
					system("cls");
					menuHex();
					std::cout << "Выберите пункт меню" << std::endl;
					std::cin >> choose;
					switch (choose)
					{
					case(1):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						A.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> A;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						B.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> B;
						std::cout << A << " + " << B << " = ";
						std::cout << A + B << std::endl;
						system("pause");
						break;
					case(2):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						A.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> A;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						B.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> B;
						std::cout << A << " - " << B << " = " << A - B << std::endl;
						system("pause");
						break;
					case(3):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						A.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> A;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						B.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> B;
						std::cout << A << " * " << B << " = " << A * B << std::endl;
						system("pause");
						break;
					case(4):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						A.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> A;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						B.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> B;
						if (A > B)
							std::cout << A << " > " << B << std::endl;
						if (A < B)
							std::cout << A << " < " << B << std::endl;
						if (A == B)
							std::cout << A << " = " << B << std::endl;
						system("pause");
						break;
					case(5):
						system("cls");
						std::cout << "Введите размер  числа" << std::endl;
						std::cin >> size;
						A.resetSize(size);
						std::cout << "Введите  число" << std::endl;
						std::cin >> A;
						std::cout << "Десятичная запись : " << A.toInt() << std::endl;
						system("pause");
						break;
					default:
						break;
					}
				}
			if (choose == 2)
			{
				while (choose != 5)
				{
					system("cls");
					menuDecimal();
					std::cout << "Выберите пункт меню" << std::endl;
					std::cin >> choose;
					switch (choose)
					{
					case(1):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						C.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> C;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						D.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> D;
						std::cout << C << " + " << D << " = " << C + D << std::endl;
						system("pause");
						break;
					case(2):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						C.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> C;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						D.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> D;
						std::cout << C << " - " << D << " = ";
						std::cout  << C - D << std::endl;
						system("pause");
						break;
					case(3):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						C.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> C;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						D.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> D;
						std::cout << C << " * " << D << " = " << C * D << std::endl;
						system("pause");
						break;
					case(4):
						system("cls");
						std::cout << "Введите размер 1-го числа" << std::endl;
						std::cin >> size;
						C.resetSize(size);
						std::cout << "Введите 1-ое число" << std::endl;
						std::cin >> C;
						std::cout << "Введите размер 2-го числа" << std::endl;
						std::cin >> size;
						D.resetSize(size);
						std::cout << "Введите 2-ое число" << std::endl;
						std::cin >> D;
						if (C > D)
							std::cout << C << " > " << D << std::endl;
						if (C < D)
							std::cout << C << " < " << D << std::endl;
						if (C == D)
							std::cout << C << " = " << D << std::endl;
						system("pause");
						break;
					default:
						break;
					}
				}
			}

		}
		return 0;
	}
	catch (cls_Hex::UnexpectedNum e)
	{
		std::cerr << e.what() << std::endl;
		system("pause");
	}
	catch (cls_Decimal::UnexpectedNum e)
	{
		std::cerr << e.what() << std::endl;
		system("pause");
	}
}