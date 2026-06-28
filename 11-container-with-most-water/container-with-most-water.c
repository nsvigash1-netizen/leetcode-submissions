int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxVol = 0;
    
    while (left < right) {
        int tmpVol = 0;
        if (height[left] > height[right]) 
            tmpVol = (right - left) * height[right--];            
        else 
            tmpVol = (right - left) * height[left++];
        if (tmpVol > maxVol)
            maxVol = tmpVol;        
      /*      
        int h = height[left] < height[right] ? height[left++] : height[right--];
        int vol =  (right  - left + 1) * h;
        if (vol > maxVol)
            maxVol = vol
      */
    }
    return maxVol;
}