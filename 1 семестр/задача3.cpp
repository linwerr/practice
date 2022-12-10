#include <iostream>
#include <string>
#include <fstream>
int main() {
	setlocale(LC_ALL, "rus");
	std::ifstream in("Текст.txt", std::ios::in);
	std::ofstream out("output.txt", std::ios::out);
	std::string a;
	int alf[32][2];
	char alf8[8];
	std::string skob;
	
	for (int i = 0; i < 32; i++)
	{
		alf[i][0] = -32+i;
		alf[i][1] = 0;
	};
	//std::cout << (char)alf[31][0] << ' ';
	while (in >> a) {
		for (int i = 0; i < size(a); i++) {
			int p = (int)a[i];
			//std::cout << p << ' ';
			if (-33 < p && p < 0)
			{
				alf[p + 32][1] += 1;
				//std::cout << a[i] << ' ' << p << " " << p + 33 << std::endl;
			}

			if (-33 < p + 32 && p + 32 < 0)
				alf[p + 32 + 32][1] += 1;
		}
		//std::cout << (char)alf[0][0] << ' ' << alf[0][1];
	}
	int max = 0;
	char b;
	int ind = 0;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 32; i++) {
			if (alf[i][1] > max) {
				max = alf[i][1];
				b = (char)alf[i][0];
				ind = i;
			}
		}
		alf8[j] = b;
		max = 0;
		alf[ind][1] = 0;
	}
	std::cout << alf8[0] << ' ' << alf8[1] << ' ' << alf8[2] << ' ' << alf8[3] << ' ' << alf8[4] << ' ' << alf8[5] << ' ' << alf8[6] << ' ' << alf8[7] << std::endl;

	in.close();

	std::ifstream on("Текст.txt", std::ios::in);
	while (on >> a) {
		char alf8cher[8];
		for (int i = 0; i < 8; i++)
			alf8cher[i] = alf8[i];
		int k = 0;
		for (int i = 0; i < size(a); i++) {
			for (int j = 0; j < 8; j++) {
				if (a[i] == alf8cher[j] || (char)((int)a[i]+32) == alf8cher[j]) {
					k++;
					skob += alf8cher[j];
					alf8cher[j] = ' ';
				}
				//std::cout << k << ' ';
			}
		}
		if (k>=5)
			for (int i = 0; i < size(a); i++) {
				for (int j = 0; j < 8; j++) {
					if (a[i] == alf8[j]) {
						a[i] = (char)((int)a[i] - 32);
						
					}
				}
			}
		out << a;
		if (skob.length() != 0 && k>=5)
			out << "(" << skob << ")";
		out << " ";
		skob = "";
	}
}