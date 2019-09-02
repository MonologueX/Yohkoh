#include <iostream>
#include <vector>
using namespace std;

int main(){
	std::vector<int> position(100);
	int T;
	cin >> T;
	while (T--) 
	{
		int length, ant_num, k;
		while (cin >> length >> ant_num)
		{
			for (int i = 0; i < ant_num; ++i){
				cin >> k;
				position[i] = k;
			}
			int speed = 1; //蚂蚁的速度
			int max_time = 0; //最长时间
			int min_time = 0; //最短时间

			int temp_max = 0;
			int temp_min = 0;

			for (int i = 0; i < ant_num; i++)
			{
				temp_max = 0;
				temp_min = 0;

				if (position[i] < length / 2) //中点左边
				{
					temp_max = (length - position[i]) / speed;
					temp_min = position[i] / speed;
				}
				else //中点右边
				{
					temp_max = position[i] / speed;
					temp_min = (length - position[i]) / speed;
				}

				if (max_time < temp_max)
					max_time = temp_max;
				if (min_time < temp_min)
					min_time = temp_min;
			}

			cout << min_time << " " << max_time << endl;
		}
	}

	return 0;
}
