#define _CRT_SECURE_NO_WARNINGS
#include "huffman.h"
#include "compress.h"
#include "decompress.h"
#include<string>

void compressfile()
{
	cout << "�������ļ���:";
	char filename[256];
	char f[50];
	int len1;
	int len2;
	double percent;
	cin >> filename;
	strcpy(f, filename);
	strcat(f, ".huf");
	compress(filename);
	getFileLength(&len1, &len2);
	cout <<"ԭ�ļ�"<< len1 << "�ֽ�" << endl;
	cout <<"���ļ�"<< len2 << "�ֽ�" << endl;
	percent = 1.0*len2 / len1 * 100;
	printf("ѹ������:%.2f", percent);
	cout << "%" << endl;
}

void decompressfile()
{
	char filename[256];
	int len1;
	int len2;
	cout << "�������ļ���:";
	cin >> filename;
	decompress(filename);
	getFileLen(&len1, &len2);
	cout << "ԭ�ļ�" << len1 << "�ֽ�" << endl;
	cout << "���ļ�" << len2 << "�ֽ�" << endl;
}

int main()
{
	cout << "=============Huffman�ļ���ѹ��=============" << endl;
	cout << "1.ѹ���ļ�" << endl;
	cout << "2.��ѹ�ļ�" << endl;
	int choice;
	while (true)
	{
		cout << "�������ѡ��:";
		cin >> choice;
		if (choice == 1) {
			cout << "-------------Huffman�ļ�ѹ��-------------"<<endl;
			compressfile();
		}
		else if (choice == 2) {
			cout << "-------------Huffman�ļ���ѹ-------------"<<endl;
			decompressfile();
		}
		else {
			cout << "ϵͳ�˳���ллʹ��!" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}