void moveZeroes(int* nums, int numsSize){
    int a=0,b=0;
while(a<numsSize)
{
    if(nums[a]==0)
    {
        while(nums[b]==0&&b!=0)
        {
            printf("%d",b);
            b--;
        }
        nums[a]=nums[b];
        nums[b]=0;
        b--;
    }
    a++;
}
return *nums;
}