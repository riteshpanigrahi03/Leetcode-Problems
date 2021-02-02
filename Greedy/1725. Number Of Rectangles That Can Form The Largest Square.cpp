class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        
        int maxlen=0; //to store max length
        int count=0; // to store count of number of rectangles with max length
        
        for(vector<int>rectangle: rectangles){
            
            //[5,6], you can get a square with a side length of at most  5.
            int maxLenOfCurrent = min(rectangle[0],rectangle[1]);
            
            //compare maxlen with new current max length
            if(maxLenOfCurrent > maxlen){
                maxlen = maxLenOfCurrent;
                count=1;
            }else if(maxlen == maxLenOfCurrent){  // if current max len is same as overall max len then count++
                count++;
            }
        }
        return count;
        
    }
};