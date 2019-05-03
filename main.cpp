#define _CRT_SECURE_NO_WARNINGS
#include "huffman.h"
#include "compress.h"
#include "decompress.h"
#include<string>

void compressfile()
{
	cout << "请输入文件名:";
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
	cout <<"原文件"<< len1 << "字节" << endl;
	cout <<"现文件"<< len2 << "字节" << endl;
	percent = 1.0*len2 / len1 * 100;
	printf("压缩比率:%.2f", percent);
	cout << "%" << endl;
}

void decompressfile()
{
	char filename[256];
	int len1;
	int len2;
	cout << "请输入文件名:";
	cin >> filename;
	decompress(filename);
	getFileLen(&len1, &len2);
	cout << "原文件" << len1 << "字节" << endl;
	cout << "现文件" << len2 << "字节" << endl;
}

int main()
{
	cout << "=============Huffman文件解压缩=============" << endl;
	cout << "1.压缩文件" << endl;
	cout << "2.解压文件" << endl;
	int choice;
	while (true)
	{
		cout << "输入你的选择:";
		cin >> choice;
		if (choice == 1) {
			cout << "-------------Huffman文件压缩-------------"<<endl;
			compressfile();
		}
		else if (choice == 2) {
			cout << "-------------Huffman文件解压-------------"<<endl;
			decompressfile();
		}
		else {
			cout << "系统退出，谢谢使用!" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}