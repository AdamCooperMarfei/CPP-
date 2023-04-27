#### stl常用算法

##### 1.常用遍历算法

###### 1.1for_each

函数原型

```c++
//begin 开始迭代器
//end 结束迭代器
//_func 函数或函数对象
for_each(iterator begin, iterator end, _func);
```

示例：

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1，常用遍历算法for_each

//普通函数
void print01(int val) {
	cout << val << " ";
}

//仿函数
class print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test01() {
	vector<int> v1;
	v1.push_back(6);
	v1.push_back(66);
  v1.push_back(666);
  v1.push_back(6666);
	v1.push_back(66666);
	
	//最后一项参数是函数指针
	for_each(v1.begin(), v1.end(), print01);
        cout<< endl;
	cout << "-----------------------" << endl;

	for_each(v1.begin(), v1.end(), print02());
}

int main() {
	test01();

	return 0;
}
```

###### 1.2transform

