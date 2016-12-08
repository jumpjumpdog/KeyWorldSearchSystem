#include"iostream"
#include"fstream"
#include"string"
#include"algorithm"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;
using std::transform;




int keyWordSearch(string&, string&);
void  tranverse(string&);

int main() {


	string text,keyWord, fileName;
	ifstream inPut;
	ofstream outPut;
	cout << "�ؼ��ּ���ϵͳ" << endl;
	cout << "�������ļ�����";
	cin >> fileName;
	outPut.open(fileName.c_str());
	if (!outPut.is_open()) {
		cout << "��outPut�ļ�ʧ��";
		exit(0);
	}
	cout  << "������һ��Ӣ�ģ�" << endl;

	getline(cin, text, '#');
	text=text.erase(0,1);
	outPut << text;
	outPut.close();


	
	cout << "������Ҫ�����Ĺؼ��֣�";
	cin >> keyWord;
	keyWord += " ";
	keyWord = " " + keyWord;
	cout << "��ʾԴ�ļ�"<<"\""<<fileName<<"\":"<<endl;
	inPut.open(fileName.c_str());
	if (!inPut.is_open()) {
		cout << "��inPut�ļ�ʧ��" << endl;
		exit(0);
	}
	
	getline(inPut,text,'\0');
	cout << text ;
	text += " ";
	text = " " + text;
	tranverse(text);
	transform(text.begin(), text.end(),text.begin(), tolower);
	transform(keyWord.begin(),keyWord.end(),keyWord.begin(),tolower);
	cout << "keyword:" << keyWord << "#" << endl;
	cout << "text:" << text << "#" << endl;

	cout << keyWordSearch(text,keyWord)<<endl;
	return 0;
	
}


void tranverse(string &text) {
	for (auto &x : text) {
		if (ispunct(x)||x=='\n') {
			x = ' ';
		}		
   }
}

int keyWordSearch(string&text, string&key) {
	int pos=0,count=0;
	while (1) {
		pos=text.find(key, pos);
		if (-1 == pos)
			break;
		else {
			count++;
			pos++;
		}	
	}
	return count;
}

