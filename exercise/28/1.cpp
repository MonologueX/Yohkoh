class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i = 0, j = 1;
        while(i < len && j < len)
        {
            // 判断偶数位是否是偶数，若不为偶数则停下
            while(i < len && (arr[i] % 2) == 0) 
                i += 2;
            //判断奇数位是否是奇数，若不是奇数则停下
            while(j < len && (arr[j] % 2) != 0) 
                j += 2;
            //将这两个数字进行位置替换
            if(i < len && j < len) 
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
};
