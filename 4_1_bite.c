#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p1=0;
    int p2=0;
    int temp=0;
    int count=0;
    int tmp=0;
    while(p1<nums1Size){
        if(nums1[p1]==0){
            while(p2<nums2Size){
                nums1[p1++]=nums2[p2++];
            }
        }
        if(nums1[p1]>nums2[p2]){
            temp=nums1[p1];
            while(temp>nums2[p2] && p2<nums2Size){
                nums1[p1++]=nums2[p2++];
            }
            nums2[--p2]=temp;
        }else{
            p1++;
        }
    }
    
}
int main(){
    int nums1[6]={1,2,3,0,0,0};
    int nums2[3] = {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3,3);
    for (int i = 0; i < 6;i++){
        printf("%d ", nums1[i]);
    }
        return 0;
}