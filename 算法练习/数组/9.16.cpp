class Solution {
public:
    int mapVER(vector<int>& numbers)
    {
        unordered_map<int, int> map;
        int half=numbers.size()/2;
        for(int i=0;i<numbers.size();i++)
        {
            auto it=map.find(numbers[i]);
            if(it==map.end())
            {
                map.insert({numbers[i], 1});
                
            }else{
            map[numbers[i]]++;
            }
            if(map[numbers[i]]>half)
            {
                return numbers[i];
            }
        }
        return 0;
    }
    int sortVER(vector<int>& numbers)
    {
        sort(numbers.begin(), numbers.end());
            int target=numbers[numbers.size()/2];
        int count=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(target==numbers[i])
                count++;
        }
        if(count>numbers.size()/2)
            return target;
        return 0;
    }
        int searchVER(vector<int>& numbers)
    {

        if(numbers.empty()) return 0;
        int result = numbers[0];
        int times = 1;
        
        for(int i=1;i<numbers.size();++i)
        {
            if(times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
            {
                ++times; 
            }
            else
            {
                --times; 
            }
        }
        times = 0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] == result) ++times;
        }
         
        return (times > numbers.size()/2) ? result : 0;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
       return sortVER(numbers);
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        if(array.size()==0)
        {
            return array;
        }
        int k=0;
        for(int i=0;i<array.size();i++)
        {
            if((array[i]&1)==1)
            {
                int temp=array[i];
                int j=i;
                while(j>k)
                {
                    array[j]=array[j-1];
                    j--;
                }
                array[k++]=temp;
            }
        }
        return array;
    }
};