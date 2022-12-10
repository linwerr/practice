#include <iostream>
#include <string>
#include <fstream>


int main() {
	int a[1000] = {0};
	int b[1000] = {0};
	std::ifstream in("Текст.txt");
	std::string s;
	in >> s;
	std::string s2;
	in >> s2;

	//Сумма
	int max = 0;
	if (size(s) > size(s2))
		max = size(s) + 1;
	else
	{
		max = size(s2) + 1;
	}

	for (int i = 0; i < size(s); i++)
		a[i] = (int)s[i] - 48;
	for (int i = 0; i < size(s2); i++)
		b[i] = (int)s2[i] - 48;
	for (int i = 0; i < size(s) / 2; i++)
		std::swap(a[i], a[size(s) - i - 1]);
	for (int i = 0; i < size(s2) / 2; i++)
		std::swap(b[i], b[size(s2) - i - 1]);
	//std::cout << a[0] << ' ' << b[0] << ' ';
	int c[1000] = {0};
	int k = 0;
	for (int i = 0; i < max; i++) {
		if ((a[i] + b[i]) > 9) {
			c[i] = (a[i] + b[i]) % 10 + k;
			k = 1;
			//std::cout << (a[i] + b[i]) << " " << k << " ";
		}
		if ((a[i] + b[i]) < 10) {
			c[i] = (a[i] + b[i]) % 10 + k;
			k = 0;
			//std::cout << (a[i] + b[i]) << " " << k << " ";
		}
	}
	
	//std::cout << c[0] << ' ' << c[1] << ' ' << c[2] << ' ';


	for (int i = 0; i < max / 2; i++)
		std::swap(c[i], c[max - i - 1]);
	
	if (c[0] == 0) {
		max--;
		for (int i = 0; i < max; i++)
			c[i] = c[i + 1];
	}

	for (int i = 0; i < max; i++)
		std::cout << c[i];
	std::cout << std::endl;

	//Произведение
	int dlina = size(s) + size(s2) + 1;
	//std::cout << dlina;
	int d[100000] = { 0 };

	for (int i = 0; i < size(s); i++)
		for (int j = 0; j < size(s2); j++)
			d[i + j] += a[i] * b[j];

	for (int i = 0; i < dlina; i++) {
		d[i + 1] += d[i] / 10;
		d[i] %= 10;
	}

	while (d[dlina-1] == 0)
	{
		dlina--;
	}
	for (int i = 0; i < dlina / 2; i++)
		std::swap(d[i], d[dlina - i - 1]);
	for (int i = 0; i < dlina; i++)
		std::cout << d[i];
}