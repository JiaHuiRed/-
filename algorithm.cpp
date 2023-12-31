#include<string>
#include <iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
//#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS


/*��һ�� ����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target ��
дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��*/

class Solution {//���ֲ���˼��
public:
	int search(vector<int>& nums, int target) {//����һ������nums���������� 
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {//ֻҪѭ����������
			//int middle = left+((right-left) / 2);//��ֹ�����ʵ���Ͼ��� (right+left)/2
			int middle = (right + left) / 2;//�������ݲ��ÿ����������
			int num = nums[middle];
			if (num > target) {//Ѱ��Ԫ�ر��м���С��Ҳ�������������Ѱ��
				right = middle - 1;
			}else if (nums[middle] < target) {
				left = middle + 1;
			}else{
				return middle;
			}
		}
		return -1;//ʧ�ܷ���-1
	}
};
/*�ڶ��� ����һ������ nums �����顸��̬�͡��ļ��㹫ʽΪ��runningSum[i] = sum(nums[0]��nums[i]) 
�뷵�� nums �Ķ�̬��*/
class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		int n = nums.size();
		for (int i=1;i < nums.size();i++) {
			nums[i] += nums[i - 1];
		}
	}
};
/*������ ����һ������ n ���ҳ��� 1 �� n ���������� Fizz Buzz ��ʾ�������ַ������� answer���±�� 1 ��ʼ�����ؽ�������У�
answer[i] == "FizzBuzz" ��� i ͬʱ�� 3 �� 5 �ı�����
answer[i] == "Fizz" ��� i �� 3 �ı�����
answer[i] == "Buzz" ��� i �� 5 �ı�����
answer[i] == i �����ַ�����ʽ�������������ȫ�����㡣
*/

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> answer;//����һ��string���͵�������answer
		for (int i = 1; i <= n; i++) {
			string curr;
			if (i % 3 == 0) {
				curr += "Fizz";
			}
			if (i % 5 == 0) {
				curr += "Buzz";
			}
			if (curr.size() == 0) {  // ���curr�ַ����ĳ���Ϊ0��˵�����Ȳ���FizzҲ����Buzz������curr�ַ���������ӵ�ǰ����i���ַ�����ʾ��
				curr += to_string(i);
			}
			answer.emplace_back(curr);//����һ�����󣬲�����ֱ����ӵ� vector ��ĩβ
		}
		return answer;
	}
};

/*������ ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int middle = (left + right) / 2;
			int n = nums[middle];
			if (n >= target) {
				right = middle - 1;
			}else {
				left = middle + 1;
			}
		}
		return left;
	}
};

/*������ ����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target��
�����ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á���������в�����Ŀ��ֵ target������ [-1, -1]��
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int leftBorder = GetLeftBorder(nums, target);//Ѱ����߽�
		int rightBorder = GetRightBorder(nums, target);//Ѱ���ұ߽�
		if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
		if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
		return { -1, -1 };
	}
private:
	int GetRightBorder(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
		while (left <= right) {
			int middle = (right + left) / 2;
			int n = nums[middle];
			if (n> target) {
				right = middle - 1;
			}
			else { // Ѱ���ұ߽磬nums[middle] == target��ʱ�����left
				left = middle + 1;
				rightBorder = left;
			}
		}
		return rightBorder;
	}
	int GetLeftBorder(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int leftBorder = -2; // ��¼һ��leftBorderû�б���ֵ�����
		while (left <= right) {
			int middle = (right + left) / 2;
			int n = nums[middle];
			if (n >= target) { // Ѱ����߽磬nums[middle] == target��ʱ�����right
				right = middle - 1;
				leftBorder = right;
			}
			else {
				left = middle + 1;
			}
		}
		return leftBorder;
	}
};
//������ ��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
struct ListNode {
	int data;
	ListNode* next;
	ListNode() : data(0), next(nullptr) {}
	ListNode(int x) : data(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : data(x), next(next) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode(-1), *p= dummy;//����һ���ƽ��
		ListNode* p1 = list1, * p2 = list2;
		while (p1 != NULL && p2 != NULL) {
			if (p1->data > p2->data) {
				p->next = p2;
				p2= p2->next;
			}else {
				p -> next = p1;
				p1 = p1->next;
			}
			p = p->next;//p����ǰ��
		}
		if (p1 != NULL) {
			p->next = p1;
		}
		if (p2 != NULL) {
			p->next = p2;
		}
		return dummy->next;
	}
};
/*������ ����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� �����ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��
ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x** 0.5 ��*/

class Solution {//ʹ��expָ������
public:
	int mySqrt(int x) {
		if (x <= 0) return 0;
		int ans = exp(0.5 * log(x));
		return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
	}
};
//���ֲ���
class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x, ans = -1;
		while (left <= right) {
			int middle = left + (right - left) / 2;
			if ((long long)middle * middle <= x) {
				ans = middle;
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return ans;
	}
};
/*�ڰ��� ����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�*/

class Solution {//�����ⷨ
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		for (int i = 0;i < n;i++) {
			if (nums[i] == val) {
				for (int j = i + 1;j < n;j++) {
					nums[j - 1] = nums[j];
				}
				i--;//��Ϊʵ����i�����Ԫ�ض���ǰһλ��ԭ��iλ���Ѿ�����Ԫ�أ����ֱ��for i++����©Ԫ��
				n--;//�൱��ɾ����һ���������飬����-1��
			}
		}
		return n;
	}
};
class Solution {//����ָ��
public:
	int removeElement(vector<int>& nums, int val) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;
		while (leftIndex <= rightIndex) {
			// ����ߵ���val��Ԫ��
			while (leftIndex <= rightIndex && nums[leftIndex] != val) {
				++leftIndex;
			}
			// ���ұ߲�����val��Ԫ��
			while (leftIndex <= rightIndex && nums[rightIndex] == val) {
				--rightIndex;
			}
			// ���ұ߲�����val��Ԫ�ظ�����ߵ���val��Ԫ��
			if (leftIndex < rightIndex) {
				nums[leftIndex++] = nums[rightIndex--];
			}
		}
		return leftIndex;   // leftIndexһ��ָ������������ĩβ����һ��Ԫ��
	}
};
/*�ھ��� ����һ�����ϸ�������е�����nums ������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص����˳��Ӧ�ñ���һ�� ��
Ȼ�󷵻� nums ��ΨһԪ�صĸ��������� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����
�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
���� k ��*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

	}
};

//��ʮ�� ����һ���� �ǵݼ�˳�� ������������� nums������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳�� ����

class Solution {//�����ⷨ
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0;i < n;i++) {
			nums[i] = nums[i] * nums[i];
		}
		sort(nums.begin(), nums.end());//����
		return nums;
	}
};
//˫ָ��
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int k = nums.size()-1;
		vector<int>result(nums.size(), 0);//����������������ʼ����Ϊ0
		for (int i = 0;int j = nums.size()-1;i <= j) {
			if (nums[i] * nums[i] < nums[j] * nums[j]) {
				result[k--] = nums[j] * nums[j];
				j--;
			}else {
				result[k--] = nums[i] * nums[i];
				i++;
			}
		}
		return result;
	}
};

/*//��ת����
struct Color {
	int r;
	int g;
	int b;
};
class Rotate {
public:
	// ��ת����
	Color* RotatePic90(int width, int height, Color input[]) {
		Color* rotated = new Color[height * width]; // �����ڴ�
		int centerX = width / 2;
		int centerY = height / 2;
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				int new_x = centerY - (x - centerX);
				int new_y = centerY + (y - centerY);
				// ȷ����ת�������û��Խ��
				if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height) {
					rotated[new_y * width + new_x] = input[y * width + x];
				}
			}
		}
		return rotated;
	}
};

int main(int argc,char const*argv[]) {
	// ��ʼ��ͼ�����ݣ�����ֻ��һ��ʾ����ʵ��Ӧ����Ӧ�ô��ļ�����Դ��ȡ
	Color input[400] = {
		// ... ͼ�����ݳ�ʼ��
	};
	// ����Reverse���ʵ��
	Rotate* rev = new Rotate();
	// ������ת����
	Color* rotated = rev->RotatePic90(20, 20, input);
	// �����ת���ͼ����������֤
	for (int i = 0; i < 400; ++i) {
		std::cout << "Color(" << rotated[i].r << ", " << rotated[i].g << ", " << rotated[i].b << ")" << std::endl;
	}
	// �ͷ��ڴ�
	delete[] rotated;
	delete rev;
	return 0;
}*/
//Ѱ��Ԫ��
/*class Solution {
public:
	int getValue(vector<int>& nums, int n) {//Ѱ��һ��������������һ�����Ԫ��
		int i, Major, count = 1;//Major���������ѡԪ��
		Major = nums[0];
		for (i = 1;i < n;i++) {
			if (nums[i] == Major) {
				count++;//��������Ԫ�ؼ���
			}else {
				if (count > 0) {//��������Ԫ�ص����
					count--;
				}else {
					Major = nums[i];//������ѡԪ�أ����¼���
					count = 1;
				}
			}
		}
		if (count > 0) {
			for (i = count = 0;i < n;i++) {
				if (nums[i] == Major) {//ͳ�ƺ�ѡԪ�س��ֵ�ʵ�ʴ���
					count++;
				}
			}
		}
		if (count > n / 2) {
			return Major;//ȷ��Ԫ��
		}else {
			return 0;//�������򷵻�
		}
	}
};//Ҳ����ʹ�ü������򣬵��ǻ�ʹ�ø������飬������ռ価��С��Ҫ��
*/

