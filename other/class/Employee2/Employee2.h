class Employee2 {
private:
	int number;
	int salary;
	char name[80];
public:
	void setNumber(int num);
	void setSalary(int sal);
	void setName(const char* nm);
	void showData();
};