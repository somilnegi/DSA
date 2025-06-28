int findPivot(vector<int>& arr, int n)
{
    int start=0, end=n-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}
int binarySearch(vector<int>& arr,int s, int e ,int key){
    int start = s;
    int end = e;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int search(vector<int>& arr, int n, int k){
    int pivot = findPivot(arr, n);
    if(k >= arr[pivot] && k <= arr[n - 1]){
        return binarySearch(arr, pivot, n - 1, k);
    }
    else{
        return binarySearch(arr, 0, pivot - 1, k);
    }

}