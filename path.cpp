#include <string>
#include <io.h>
#include <vector>
#include <iostream>

using namespace std;

/************************************************************************/
/*  ��ȡ�ļ����������ļ���
���룺
path	:	�ļ���·��
format		:   ��Ҫ��ȡ���ļ�����׺����jpg��png�ȣ����ϣ����ȡ����
�ļ���, format = ""
�����
files	:	��ȡ���ļ����б�

shao, 20140707
*/
/************************************************************************/
void GetAllFormatFiles(string path, vector<string>& files, string format)
{
	//�ļ����    
	long   hFile = 0;
	//�ļ���Ϣ    
	struct _finddata_t fileinfo;
	string p;

	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
					GetAllFormatFiles(p.assign(path).append("/").append(fileinfo.name), files, format);
				}
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);

	}
	if ((hFile = _findfirst(p.assign(path).append("/*." + format).c_str(), &fileinfo)) != -1)
	{
		do
		{

			files.push_back(p.assign(path).append("/").append(fileinfo.name));


		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}

}

void GetAllSubPath(string path, vector<string>& files)
{
	long   hFile = 0;
	//�ļ���Ϣ    
	struct _finddata_t fileinfo;
	string p;

	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
				}
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);

	}
}

void main()
{
	char * filePath = "E:/reg/data";
	vector<string> path,files;
	//��ȡ��·���µ�����bmp�ļ�
	GetAllSubPath(filePath, path);
	GetAllFormatFiles(path[1], files, "bmp");
	int size = files.size();
	
	for (int i = 1; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
}