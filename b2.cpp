#include <iostream>

using namespace std;

template <typename T>
class Vector {
public:
	Vector(int initCapa = 16){
		size = 0;
		capa = initCapa;
		arr = new T[capa];
	}

	void pushBack(T val) {
		if (size == capa) expand(2 * size);
		arr[size] = val;
		size++;
	}

	void ins(int pos, T val) {
		if (size == capa) expand(2 * size);
		for (int i = size; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = val;
		size++;
	}

	void delElem(int pos) { //xoa phan tu
		for (int i = pos; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}

	void findMaxMin() {
		int maxx = arr[0], minn = arr[0];
		for (int i = 0; i < size; i++) {
			if (maxx < arr[i]) maxx = arr[i];
			if (minn > arr[i]) minn = arr[i];
		}
		cout << "\nGia tri lon nhat la " << maxx << "\nGia tri nho nhat la " << minn;
	}

	void outp() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}

private:
	int size;
	int capa;
	T* arr;

	void expand(int newCapa) {
		if (size < capa) return;
		T* old = arr;
		arr = new T[newCapa];
		for (int i = 0; i < size; i++) {
			arr[i] = old[i];
		}
		delete[] old;
	}
};

int main() {
	Vector<int> v;
	int size, val, pos;


	cout << "Nhap kich thuoc cua Vector = "; cin >> size;
	cout << "Nhap gia tri Vector = ";
	for (int i = 0; i < size; i++) { //Nhap du lieu cho Vector
		cin >> val;
		v.pushBack(val);
	}

	cout << "Nhap gia tri muon chen = "; cin >> val; //chen gia tri vao Vector
	cout << "Nhap vi tri muon chen = "; cin >> pos;
	if (pos > size) v.pushBack(val);
	else v.ins(pos, val);
    cout << "Vector sau khi chen: "; v.outp();

	cout << "\nNhap vi tri muon xoa phan tu = "; cin >> pos;
	v.delElem(pos);
	cout << "Vector sau khi xoa: "; v.outp();
	v.findMaxMin();
}