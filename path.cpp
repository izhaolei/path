#include <string>
#include <io.h>
#include <vector>
#include <iostream>

using namespace std;

/************************************************************************/
/*  获取文件夹下所有文件名
输入：
path	:	文件夹路径
format		:   所要获取的文件名后缀，如jpg、png等；如果希望获取所有
文件名, format = ""
输出：
files	:	获取的文件名列表

shao, 20140707
*/
/************************************************************************/
void GetAllFormatFiles(string path, vector<string>& files, string format)
{
	//文件句柄    
	long   hFile = 0;
	//文件信息    
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
	//文件信息    
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
	//获取该路径下的所有bmp文件
	GetAllSubPath(filePath, path);
	GetAllFormatFiles(path[1], files, "bmp");
	int size = files.size();
	
	for (int i = 1; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
}