#include <iostream>

class Mas {

private:
	int m_razmer = 1;
	int* m_mas = new int[m_razmer];

public:
	Mas(int firstEl) {
		m_razmer = 1;
		m_mas[0] = firstEl;
		//std::cout << firstEl << std::endl;
	}
	~Mas() {
		delete[] m_mas;
		std::cout << "Destructor works!" << std::endl;
	}
	void elEnd(int el) {
		int* cherMas = new int[m_razmer + 1];
		for (int i = 0; i < m_razmer; i++) {
			cherMas[i] = m_mas[i];
		}
		cherMas[m_razmer] = el;
		delete[] m_mas;
		m_mas = cherMas;
		m_razmer++;
		//std::cout << el << ' ' << m_razmer << std::endl;
	}
	int kol() {
		return m_razmer;
	}
	int vozvr(int ind) {
		return m_mas[ind];
	}
	void izm(int el, int ind) {
		m_mas[ind] = el;
		//std::cout << ind << ' ' << el << std::endl;
	}
	void del(int ind) {
		int* cherMas = new int[m_razmer - 1];
		int k = 0;
		for (int i = 0; i < ind; i++) {
			cherMas[k] = m_mas[i];
			k++;
		}
		for (int i = ind + 1; i < m_razmer; i++) {
			cherMas[k] = m_mas[i];
			k++;
		}

		delete[] m_mas;
		m_mas = cherMas;
		m_razmer--;
		//std::cout << ind << std::endl;
	}
	void add(int el, int ind) {
		int* cherMas = new int[m_razmer + 1];
		int k = 0;
		for (int i = 0; i < ind; i++) {
			cherMas[k] = m_mas[i];
			k++;
		}
		cherMas[ind] = el;
		k++;

		for (int i = ind; i < m_razmer; i++) {
			cherMas[k] = m_mas[i];
			k++;
		}
		delete[] m_mas;
		m_mas = cherMas;
		m_razmer++;

		//std::cout << ind << ' ' << el << std::endl;
	}
};
int main() {
	setlocale(LC_ALL, "RUS");

	Mas a(2);
	a.elEnd(5);
	a.izm(7, 0);

	std::cout << a.kol() << std::endl;
	std::cout << a.vozvr(0) << std::endl;
}
