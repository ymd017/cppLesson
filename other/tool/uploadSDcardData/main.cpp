/*
*SD�J�[�h��raw�t�@�C�����w��T�[�o�[�̏ꏊ�Ƀt�H���_������ăA�b�v���[�h����
*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <fileapi.h>
#include <filesystem>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <format>
using namespace std;
namespace fs = std::filesystem;

/*=============================================================================
* �A�b�v���[�h��̏ꏊ�̎擾
* �����@�F
* �߂�l�Fstring		// �A�b�v���[�h��̏ꏊ�̃p�X
=============================================================================*/
string getUploadPath() {
	// �A�b�v���[�h��̏ꏊ�������Ă���t�@�C�����J��
	ifstream file("uploadPath.txt");

	if (!file) {
		cout << "�A�b�v���[�h�悪������Ă���t�@�C�����J���܂���ł����B";
	}

	// �A�b�v���[�h��̏ꏊ���擾����
	string path;
	getline(file, path);
	path += "\\";

	return path;
}

/*=============================================================================
* SD�J�[�h�̃h���C�u�����o
* �����@�F
* �߂�l�Fstring		// SD�J�[�h�h���C�u�̃p�X
=============================================================================*/
string detectSDCardDrive() {
	// �S�Ă̘_���h���C�u�����o�A�_���h���C�u������΂P�̃r�b�g�}�X�N��Ԃ�
	DWORD drives = GetLogicalDrives();

	//cout << bitset<32>(drives);

	// �e�_���h���C�u�̎�ނ���肷��
	//cout << GetDriveTypeA("H:/");
	for (char i = 'A'; i <= 'Z'; i++) {

		if (drives & (1 << (i - 'A'))) {		// ���ׂĂ���h���C�u�̃r�b�g�}�X�N��1�ł����

			// �h���C�u�p�X�̐���
			string drivePath = string(1, i) + ":\\";

			// �h���C�u�̎�ނ𒲂ׂ�
			UINT driveType = GetDriveTypeA(drivePath.c_str());

			// �h���C�u�̎�ނ������[�o�u�����f�B�A�����ׂ�
			if (driveType == DRIVE_REMOVABLE) {

				// �����[�o�u�����f�B�A(SD�J�[�h, USB)�̃h���C�u�̃p�X��ԋp����
				return drivePath;
			}
		}
	}
}

/*=============================================================================
* SD�J�[�h��raw�t�@�C���̂���t�H���_�����o
* �����@�F
* �߂�l�F
=============================================================================*/
vector<string> detectRawFolders() {
	vector<string> rawFolders;
	unordered_set<string> checkedFolders;

	// �ċA�I(�t�H���_�̒��̃t�H���_���S��)�ɑS�Ẵt�@�C���𑖍�����
	for (const fs::directory_entry& x : fs::recursive_directory_iterator("H:\\")) {

		// �g���q��RAW�܂���CR2�ł������ꍇ�A�e�t�H���_�̃p�X���擾����
		if ((x.path().extension() == ".RAW") || (x.path().extension() == ".CR2")) {
			string parentPath = x.path().parent_path().string();

			// �e�t�H���_�����Ƀ��X�g�ɒǉ�����Ă��Ȃ����𒲂ׂ�
			if (checkedFolders.contains(parentPath) == false) {
				// �܂����X�g�ɂȂ���Βǉ�����
				checkedFolders.insert(parentPath);
				rawFolders.push_back(parentPath);
			}
		}
	}
	return rawFolders;
}


/*=============================================================================
* �A�b�v���[�h��̏ꏊ�ɍ����̓��t�̃t�H���_���쐬����
* �����@�F
* �߂�l�F
=============================================================================*/
string createDateFolder(string uploadPath) {
	auto now = chrono::system_clock::now();
	string today = format("{:%Y%m%d}", now);

	string folderPath = uploadPath + today;
	fs::create_directory(folderPath);

	return folderPath;
}

/*=============================================================================
* ���t�t�H���_�̒��ɁAraw, rc, tiff, model�t�H���_���쐬����
* �����@�F
* �߂�l�F
=============================================================================*/
void createFolders(string folderPath) {
	fs::create_directory(folderPath + "\\raw");
	fs::create_directory(folderPath + "\\rc");
	fs::create_directory(folderPath + "\\tiff");
	fs::create_directory(folderPath + "\\model");
}


/*=============================================================================
* raw�t�H���_�̃t�@�C�����A�b�v���[�h��̏ꏊ�ɃA�b�v���[�h����
* �����@�F
* �߂�l�F
=============================================================================*/

int main() {

	// �A�b�v���[�h��̏ꏊ�̎擾
	string uploadPath = getUploadPath();

	// SD�J�[�h�����o����
	string drivePath = detectSDCardDrive();

	// �A�b�v���[�h��ɓ��t�t�H���_�̍쐬
	string dateFolderPath = createDateFolder(uploadPath);

	// ���t�t�H���_�̒���raw,rc,tiff,model�t�H���_�̍쐬
	createFolders(dateFolderPath);

	// SD�J�[�h��raw�t�@�C���̂���t�H���_�����o
	vector<string> rawFolders = detectRawFolders();

	// �v�f2�ڈȍ~�̓t�H���_����ς���悤�ɂ��Ȃ��Ƃ����Ȃ��i��Łj
	//for (string rawFolder : rawFolders) {}
	string rawFolder = rawFolders[0];




	

}
